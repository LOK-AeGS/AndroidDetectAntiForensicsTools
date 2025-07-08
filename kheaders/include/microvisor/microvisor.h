

#ifndef _MICROVISOR_H_
#define _MICROVISOR_H_




#if defined(__cplusplus) && !defined(_Bool)
#define _OKL4_CPP_BOOL
#define _Bool bool
#endif

#define OKL4_INLINE static inline

#if defined(_lint) || defined(_splint)
#define OKL4_FORCE_INLINE static
#else
#define OKL4_FORCE_INLINE static inline __attribute__((always_inline))
#endif

#if !defined(ALIGNED)
#define _OKL4_CPP_ALIGNED
#define ALIGNED(x) __attribute__((__aligned__(x)))
#endif

#include <microvisor/kernel/types.h>
#include <microvisor/kernel/microvisor.h>
#include <microvisor/kernel/syscalls.h>
#include <microvisor/kernel/offsets.h>




#if defined(_OKL4_CPP_BOOL)
#undef _Bool
#undef _OKL4_CPP_BOOL
#endif

#if defined(_OKL4_CPP_ALIGNED)
#undef ALIGNED
#undef _OKL4_CPP_ALIGNED
#endif

#endif 
