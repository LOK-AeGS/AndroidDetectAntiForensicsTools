
#ifndef __ASM_GENERIC_QSPINLOCK_H
#define __ASM_GENERIC_QSPINLOCK_H

#include <asm-generic/qspinlock_types.h>

#ifdef CONFIG_DEBUG_QSPINLOCK_OWNER
#include <asm/smp.h>
static __always_inline void queued_spin_set_owner(struct qspinlock *lock)
{
	lock->owner_cpu = raw_smp_processor_id();
	lock->owner = current;
}
static __always_inline void queued_spin_clear_owner(struct qspinlock *lock)
{
	lock->owner_cpu = -1;
	lock->owner = SPINLOCK_OWNER_INIT;
}
#else

#define queued_spin_set_owner(lock)
#define queued_spin_clear_owner(lock)
#endif

static __always_inline int queued_spin_is_locked(struct qspinlock *lock)
{
	
	return atomic_read(&lock->val);
}


static __always_inline int queued_spin_value_unlocked(struct qspinlock lock)
{
	return !atomic_read(&lock.val);
}


static __always_inline int queued_spin_is_contended(struct qspinlock *lock)
{
	return atomic_read(&lock->val) & ~_Q_LOCKED_MASK;
}

static __always_inline int queued_spin_trylock(struct qspinlock *lock)
{
	if (!atomic_read(&lock->val) &&
	   (atomic_cmpxchg_acquire(&lock->val, 0, _Q_LOCKED_VAL) == 0)) {
		queued_spin_set_owner(lock);
		return 1;
	}
	return 0;
}

extern void queued_spin_lock_slowpath(struct qspinlock *lock, u32 val);


static __always_inline void queued_spin_lock(struct qspinlock *lock)
{
	u32 val;

	val = atomic_cmpxchg_acquire(&lock->val, 0, _Q_LOCKED_VAL);
	if (likely(val == 0)) {
		queued_spin_set_owner(lock);
		return;
	}
	queued_spin_lock_slowpath(lock, val);
	queued_spin_set_owner(lock);
}

#ifndef queued_spin_unlock

static __always_inline void queued_spin_unlock(struct qspinlock *lock)
{
	
	queued_spin_clear_owner(lock);
	smp_store_release(&lock->locked, 0);
}
#endif

#ifndef virt_spin_lock
static __always_inline bool virt_spin_lock(struct qspinlock *lock)
{
	return false;
}
#endif


#define arch_spin_is_locked(l)		queued_spin_is_locked(l)
#define arch_spin_is_contended(l)	queued_spin_is_contended(l)
#define arch_spin_value_unlocked(l)	queued_spin_value_unlocked(l)
#define arch_spin_lock(l)		queued_spin_lock(l)
#define arch_spin_trylock(l)		queued_spin_trylock(l)
#define arch_spin_unlock(l)		queued_spin_unlock(l)

#endif 
