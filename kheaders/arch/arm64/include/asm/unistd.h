
#ifdef CONFIG_COMPAT
#define __ARCH_WANT_COMPAT_STAT64
#define __ARCH_WANT_SYS_GETHOSTNAME
#define __ARCH_WANT_SYS_PAUSE
#define __ARCH_WANT_SYS_GETPGRP
#define __ARCH_WANT_SYS_LLSEEK
#define __ARCH_WANT_SYS_NICE
#define __ARCH_WANT_SYS_SIGPENDING
#define __ARCH_WANT_SYS_SIGPROCMASK
#define __ARCH_WANT_COMPAT_SYS_SENDFILE
#define __ARCH_WANT_SYS_FORK
#define __ARCH_WANT_SYS_VFORK


#define __NR_compat_restart_syscall	0
#define __NR_compat_exit		1
#define __NR_compat_read		3
#define __NR_compat_write		4
#define __NR_compat_gettimeofday	78
#define __NR_compat_sigreturn		119
#define __NR_compat_rt_sigreturn	173
#define __NR_compat_clock_gettime	263
#define __NR_compat_clock_getres	264
#define __NR_compat_clock_gettime64	403
#define __NR_compat_clock_getres_time64	406


#define __ARM_NR_COMPAT_BASE		0x0f0000
#define __ARM_NR_compat_cacheflush	(__ARM_NR_COMPAT_BASE + 2)
#define __ARM_NR_compat_set_tls		(__ARM_NR_COMPAT_BASE + 5)
#define __ARM_NR_COMPAT_END		(__ARM_NR_COMPAT_BASE + 0x800)

#define __NR_compat_syscalls		435
#endif

#define __ARCH_WANT_SYS_CLONE

#ifndef __COMPAT_SYSCALL_NR
#include <uapi/asm/unistd.h>
#endif

#define NR_syscalls (__NR_syscalls)
