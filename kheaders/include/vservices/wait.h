

#ifndef _VSERVICE_SERVICE_WAIT_H
#define _VSERVICE_SERVICE_WAIT_H

#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/sched/signal.h>


#ifndef lockdep_assert_held_once
#ifdef CONFIG_LOCKDEP
#define lockdep_assert_held_once(l) do {				\
		WARN_ON_ONCE(debug_locks && !lockdep_is_held(l));	\
	} while (0)
#else
#define lockdep_assert_held_once(l) do { } while (0)
#endif
#endif




#define __vs_service_wait_event(_service, _wq, _cond, _state)		\
	({								\
		DEFINE_WAIT(__wait);					\
		int __ret = 0;						\
									\
		lockdep_assert_held_once(&(_service)->state_mutex);	\
		do {							\
			prepare_to_wait(&(_wq), &__wait, (_state));	\
									\
			if (_cond)					\
				break;					\
									\
			if ((_state) == TASK_INTERRUPTIBLE &&		\
					signal_pending(current)) {	\
				__ret = -ERESTARTSYS;			\
				break;					\
			}						\
									\
			vs_service_state_unlock(_service);		\
			schedule();					\
			vs_service_state_lock(_service);		\
		} while (!(_cond));					\
									\
		finish_wait(&(_wq), &__wait);				\
		__ret;							\
	})



#define vs_service_wait_event(_service, _wq, _cond) \
	__vs_service_wait_event(_service, _wq, _cond, TASK_INTERRUPTIBLE)
#define vs_service_wait_event_nointr(_service, _wq, _cond) \
	__vs_service_wait_event(_service, _wq, _cond, TASK_UNINTERRUPTIBLE)


#define __vs_wait_state(_state, _cond, _intr, _timeout, _bh)	\
	({								\
		DEFINE_WAIT(__wait);					\
		int __ret;						\
		int __jiffies __maybe_unused = (_timeout);		\
		struct vs_service_device *__service = (_state)->service;\
									\
		while (1) {						\
			prepare_to_wait(&__service->quota_wq, &__wait,	\
					_intr ? TASK_INTERRUPTIBLE :    \
					TASK_UNINTERRUPTIBLE);		\
									\
			if (!VSERVICE_BASE_STATE_IS_RUNNING(		\
					(_state)->state.base)) {	\
				__ret = -ECANCELED;			\
				break;					\
			}						\
									\
			if (_cond) {					\
				__ret = 0;				\
				break;					\
			}						\
									\
			if (_intr && signal_pending(current)) {		\
				__ret = -ERESTARTSYS;			\
				break;					\
			}						\
									\
			vs_state_unlock##_bh(_state);			\
									\
			if (_timeout >= 0) {				\
				__jiffies = schedule_timeout(__jiffies);\
				if (!__jiffies) {			\
					__ret = -ETIMEDOUT;		\
					break;				\
				}					\
			} else {					\
				schedule();				\
			}						\
									\
			if (!vs_state_lock_safe##_bh(_state)) {		\
				__ret = -ENOLINK;			\
				break;					\
			}						\
		}							\
									\
		finish_wait(&__service->quota_wq, &__wait);		\
		__ret;							\
	})


#define vs_wait_state(_state, _cond) \
	__vs_wait_state(_state, _cond, true, -1,)
#define vs_wait_state_timeout(_state, _cond, _timeout) \
	__vs_wait_state(_state, _cond, true, _timeout,)
#define vs_wait_state_nointr(_state, _cond) \
	__vs_wait_state(_state, _cond, false, -1,)
#define vs_wait_state_nointr_timeout(_state, _cond, _timeout) \
	__vs_wait_state(_state, _cond, false, _timeout,)
#define vs_wait_state_bh(_state, _cond) \
	__vs_wait_state(_state, _cond, true, -1, _bh)
#define vs_wait_state_timeout_bh(_state, _cond, _timeout) \
	__vs_wait_state(_state, _cond, true, _timeout, _bh)
#define vs_wait_state_nointr_bh(_state, _cond) \
	__vs_wait_state(_state, _cond, false, -1, _bh)
#define vs_wait_state_nointr_timeout_bh(_state, _cond, _timeout) \
	__vs_wait_state(_state, _cond, false, _timeout, _bh)


#define __vs_wait_alloc(_state, _alloc_func, _cond, _unlock, _intr, 	\
		_timeout, _bh)						\
	({								\
		DEFINE_WAIT(__wait);					\
		struct vs_mbuf *__mbuf = NULL;				\
		int __jiffies __maybe_unused = (_timeout);		\
		struct vs_service_device *__service = (_state)->service;\
									\
		while (!vs_service_send_mbufs_available(__service)) {	\
			if (_intr && signal_pending(current)) {		\
				__mbuf = ERR_PTR(-ERESTARTSYS);		\
				break;					\
			}						\
									\
			prepare_to_wait_exclusive(			\
					&__service->quota_wq, &__wait,	\
					_intr ? TASK_INTERRUPTIBLE :    \
					TASK_UNINTERRUPTIBLE);		\
									\
			if (_unlock)					\
				vs_state_unlock##_bh(_state);		\
									\
			if (_timeout >= 0) {				\
				__jiffies = schedule_timeout(__jiffies);\
				if (!__jiffies) {			\
					__mbuf = ERR_PTR(-ETIMEDOUT);	\
					break;				\
				}					\
			} else {					\
				schedule();				\
			}						\
									\
			if (_unlock && !vs_state_lock_safe##_bh(	\
						_state)) {		\
				__mbuf = ERR_PTR(-ENOLINK);		\
				break;					\
			}						\
									\
			if (!VSERVICE_BASE_STATE_IS_RUNNING(		\
					(_state)->state.base) ||	\
					!(_cond)) {			\
				__mbuf = ERR_PTR(-ECANCELED);		\
				break;					\
			}						\
		}							\
		finish_wait(&__service->quota_wq, &__wait);		\
									\
		if (__mbuf == NULL)					\
			__mbuf = (_alloc_func);				\
		if (IS_ERR(__mbuf) && (PTR_ERR(__mbuf) != -ENOBUFS))	\
			wake_up(&__service->quota_wq);			\
		__mbuf;							\
	})


#define vs_wait_alloc(_state, _cond, _alloc_func) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, true, -1,)
#define vs_wait_alloc_timeout(_state, _cond, _alloc_func, _timeout) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, true, _timeout,)
#define vs_wait_alloc_nointr(_state, _cond, _alloc_func) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, false, -1,)
#define vs_wait_alloc_nointr_timeout(_state, _cond, _alloc_func, _timeout) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, false, _timeout,)
#define vs_wait_alloc_bh(_state, _cond, _alloc_func) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, true, -1, _bh)
#define vs_wait_alloc_timeout_bh(_state, _cond, _alloc_func, _timeout) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, true, _timeout, _bh)
#define vs_wait_alloc_nointr_bh(_state, _cond, _alloc_func) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, false, -1, _bh)
#define vs_wait_alloc_nointr_timeout_bh(_state, _cond, _alloc_func, _timeout) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, false, _timeout, _bh)
#define vs_wait_alloc_locked(_state, _alloc_func) \
	__vs_wait_alloc(_state, _alloc_func, true, false, true, -1,)



#define vs_service_waiting_alloc(_state, _alloc_func) \
	__vs_wait_alloc(_state, _alloc_func, true, false, true, -1,)
#define vs_service_waiting_alloc_cond_locked(_state, _alloc_func, _cond) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, true, -1,)
#define vs_service_waiting_alloc_cond_locked_nointr(_state, _alloc_func, _cond) \
	__vs_wait_alloc(_state, _alloc_func, _cond, true, false, -1,)


#define __vs_wait_send(_state, _cond, _send_func, _unlock, 		\
		_check_running, _intr, _timeout, _bh)			\
	({								\
		DEFINE_WAIT(__wait);					\
		int __ret = 0;						\
		int __jiffies __maybe_unused = (_timeout);		\
		struct vs_service_device *__service = (_state)->service;\
									\
		while (!vs_service_send_mbufs_available(__service)) {	\
			if (_intr && signal_pending(current)) {		\
				__ret = -ERESTARTSYS;			\
				break;					\
			}						\
									\
			prepare_to_wait_exclusive(			\
					&__service->quota_wq, &__wait,	\
					_intr ? TASK_INTERRUPTIBLE :    \
					TASK_UNINTERRUPTIBLE);		\
									\
			if (_unlock)					\
				vs_state_unlock##_bh(_state);		\
									\
			if (_timeout >= 0) {				\
				__jiffies = schedule_timeout(__jiffies);\
				if (!__jiffies) {			\
					__ret = -ETIMEDOUT;		\
					break;				\
				}					\
			} else {					\
				schedule();				\
			}						\
									\
			if (_unlock && !vs_state_lock_safe##_bh(	\
						_state)) {		\
				__ret = -ENOLINK;			\
				break;					\
			}						\
									\
			if ((_check_running &&				\
					!VSERVICE_BASE_STATE_IS_RUNNING(\
					(_state)->state.base)) ||	\
					!(_cond)) {			\
				__ret = -ECANCELED;			\
				break;					\
			}						\
		}							\
		finish_wait(&__service->quota_wq, &__wait);		\
									\
		if (!__ret)						\
			__ret = (_send_func);				\
		if ((__ret < 0) && (__ret != -ENOBUFS))			\
			wake_up(&__service->quota_wq);			\
		__ret;							\
	})


#define vs_wait_send(_state, _cond, _send_func) \
	__vs_wait_send(_state, _cond, _send_func, true, true, true, -1,)
#define vs_wait_send_timeout(_state, _cond, _send_func, _timeout) \
	__vs_wait_send(_state, _cond, _send_func, true, true, true, _timeout,)
#define vs_wait_send_nointr(_state, _cond, _send_func) \
	__vs_wait_send(_state, _cond, _send_func, true, true, false, -1,)
#define vs_wait_send_nointr_timeout(_state, _cond, _send_func, _timeout) \
	__vs_wait_send(_state, _cond, _send_func, true, true, false, _timeout,)
#define vs_wait_send_bh(_state, _cond, _send_func) \
	__vs_wait_send(_state, _cond, _send_func, true, true, true, -1, _bh)
#define vs_wait_send_timeout_bh(_state, _cond, _send_func, _timeout) \
	__vs_wait_send(_state, _cond, _send_func, true, true, true, \
			_timeout, _bh)
#define vs_wait_send_nointr_bh(_state, _cond, _send_func) \
	__vs_wait_send(_state, _cond, _send_func, true, true, false, -1, _bh)
#define vs_wait_send_nointr_timeout_bh(_state, _cond, _send_func, _timeout) \
	__vs_wait_send(_state, _cond, _send_func, true, true, false, \
			_timeout, _bh)
#define vs_wait_send_locked(_state, _send_func) \
	__vs_wait_send(_state, true, _send_func, false, true, true, -1,)
#define vs_wait_send_locked_nocheck(_state, _send_func) \
	__vs_wait_send(_state, true, _send_func, false, false, true, -1,)



#define vs_service_waiting_send(_state, _send_func) \
	__vs_wait_send(_state, true, _send_func, true, true, true, -1,)
#define vs_service_waiting_send_nointr(_state, _send_func) \
	__vs_wait_send(_state, true, _send_func, true, true, false, -1,)
#define vs_service_waiting_send_cond(_state, _cond, _send_func) \
	__vs_wait_send(_state, _cond, _send_func, true, true, true, -1,)
#define vs_service_waiting_send_cond_nointr(_state, _cond, _send_func) \
	__vs_wait_send(_state, _cond, _send_func, true, true, false, -1,)
#define vs_service_waiting_send_nocheck(_state, _send_func) \
	__vs_wait_send(_state, true, _send_func, true, false, true, -1,)

#endif 
