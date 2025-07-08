







#ifndef __AUTO__USER_SYSCALLS_H__
#define __AUTO__USER_SYSCALLS_H__


#if defined(ASSEMBLY)
#define __hvc_str(x) x
#else
#define _hvc_str(x) #x
#define __hvc_str(x) _hvc_str(x)
#endif
#if (defined(__GNUC__) && !defined(__clang__)) && \
    (__GNUC__ < 4 || ((__GNUC__ == 4) && (__GNUC_MINOR__ < 5)))
#if defined(__thumb2__)
#define hvc(i) __hvc_str(.hword 0xf7e0 | (i & 0xf); .hword 8000 | (i >> 4) @ HVC)
#else
#define hvc(i) __hvc_str(.word 0xe1400070 | (i & 0xf) | (i >> 4 << 8) @ HVC)
#endif
#else
#if defined(__ARM_EABI__)
#if defined(ASSEMBLY) && !defined(__clang__)
    .arch_extension virt
#elif !defined(__clang__)
__asm__(
    ".arch_extension virt\n"
);
#endif
#endif
#define hvc(i) __hvc_str(hvc i)
#endif


#if !defined(ASSEMBLY)

#define OKL4_OK OKL4_ERROR_OK







#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_axon_process_recv_return
_okl4_sys_axon_process_recv(okl4_kcap_t axon_id, okl4_lsize_t transfer_limit)
{
    struct _okl4_sys_axon_process_recv_return result;

    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    register uint32_t r1 asm("r1") = (uint32_t)(transfer_limit        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((transfer_limit >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5184)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    result.error = (okl4_error_t)(r0);
    result.send_empty = (okl4_bool_t)(r1);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_axon_process_recv_return
_okl4_sys_axon_process_recv(okl4_kcap_t axon_id, okl4_lsize_t transfer_limit)
{
    struct _okl4_sys_axon_process_recv_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)transfer_limit;
    __asm__ __volatile__(
            "" hvc(5184) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.send_empty = (okl4_bool_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_halted(okl4_kcap_t axon_id, okl4_bool_t halted)
{
    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    register uint32_t r1 asm("r1") = (uint32_t)halted;
    __asm__ __volatile__(
            ""hvc(5186)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_halted(okl4_kcap_t axon_id, okl4_bool_t halted)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)halted;
    __asm__ __volatile__(
            "" hvc(5186) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_recv_area(okl4_kcap_t axon_id, okl4_laddr_t base,
        okl4_lsize_t size)
{
    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    register uint32_t r1 asm("r1") = (uint32_t)(base        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((base >> 32) & 0xffffffff);
    register uint32_t r3 asm("r3") = (uint32_t)(size        & 0xffffffff);
    register uint32_t r4 asm("r4") = (uint32_t)((size >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5187)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4)
            :
            : "cc", "memory", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_recv_area(okl4_kcap_t axon_id, okl4_laddr_t base,
        okl4_lsize_t size)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)base;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)size;
    __asm__ __volatile__(
            "" hvc(5187) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_recv_queue(okl4_kcap_t axon_id, okl4_laddr_t queue)
{
    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    register uint32_t r1 asm("r1") = (uint32_t)(queue        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((queue >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5188)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_recv_queue(okl4_kcap_t axon_id, okl4_laddr_t queue)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)queue;
    __asm__ __volatile__(
            "" hvc(5188) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_recv_segment(okl4_kcap_t axon_id, okl4_kcap_t segment_id,
        okl4_laddr_t segment_base)
{
    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    register uint32_t r1 asm("r1") = (uint32_t)segment_id;
    register uint32_t r2 asm("r2") = (uint32_t)(segment_base        & 0xffffffff);
    register uint32_t r3 asm("r3") = (uint32_t)((segment_base >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5189)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3)
            :
            : "cc", "memory", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_recv_segment(okl4_kcap_t axon_id, okl4_kcap_t segment_id,
        okl4_laddr_t segment_base)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)segment_id;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_base;
    __asm__ __volatile__(
            "" hvc(5189) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_send_area(okl4_kcap_t axon_id, okl4_laddr_t base,
        okl4_lsize_t size)
{
    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    register uint32_t r1 asm("r1") = (uint32_t)(base        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((base >> 32) & 0xffffffff);
    register uint32_t r3 asm("r3") = (uint32_t)(size        & 0xffffffff);
    register uint32_t r4 asm("r4") = (uint32_t)((size >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5190)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4)
            :
            : "cc", "memory", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_send_area(okl4_kcap_t axon_id, okl4_laddr_t base,
        okl4_lsize_t size)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)base;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)size;
    __asm__ __volatile__(
            "" hvc(5190) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_send_queue(okl4_kcap_t axon_id, okl4_laddr_t queue)
{
    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    register uint32_t r1 asm("r1") = (uint32_t)(queue        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((queue >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5191)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_send_queue(okl4_kcap_t axon_id, okl4_laddr_t queue)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)queue;
    __asm__ __volatile__(
            "" hvc(5191) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_send_segment(okl4_kcap_t axon_id, okl4_kcap_t segment_id,
        okl4_laddr_t segment_base)
{
    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    register uint32_t r1 asm("r1") = (uint32_t)segment_id;
    register uint32_t r2 asm("r2") = (uint32_t)(segment_base        & 0xffffffff);
    register uint32_t r3 asm("r3") = (uint32_t)((segment_base >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5192)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3)
            :
            : "cc", "memory", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_set_send_segment(okl4_kcap_t axon_id, okl4_kcap_t segment_id,
        okl4_laddr_t segment_base)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)segment_id;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_base;
    __asm__ __volatile__(
            "" hvc(5192) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_trigger_send(okl4_kcap_t axon_id)
{
    register uint32_t r0 asm("r0") = (uint32_t)axon_id;
    __asm__ __volatile__(
            ""hvc(5185)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_axon_trigger_send(okl4_kcap_t axon_id)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)axon_id;
    __asm__ __volatile__(
            "" hvc(5185) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_debug_resume(okl4_kcap_t target, okl4_bool_t single_step)
{
    register uint32_t r0 asm("r0") = (uint32_t)target;
    register uint32_t r1 asm("r1") = (uint32_t)single_step;
    __asm__ __volatile__(
            ""hvc(5208)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_debug_resume(okl4_kcap_t target, okl4_bool_t single_step)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)target;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)single_step;
    __asm__ __volatile__(
            "" hvc(5208) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_debug_suspend(okl4_kcap_t target)
{
    register uint32_t r0 asm("r0") = (uint32_t)target;
    __asm__ __volatile__(
            ""hvc(5209)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_debug_suspend(okl4_kcap_t target)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)target;
    __asm__ __volatile__(
            "" hvc(5209) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_interrupt_ack_return
_okl4_sys_interrupt_ack(void)
{
    struct _okl4_sys_interrupt_ack_return result;

    register uint32_t r0 asm("r0");
    register uint32_t r1 asm("r1");
    __asm__ __volatile__(
            ""hvc(5128)"\n\t"
            : "=r"(r0), "=r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    result.irq = (okl4_interrupt_number_t)(r0);
    result.source = (uint8_t)(r1);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_interrupt_ack_return
_okl4_sys_interrupt_ack(void)
{
    struct _okl4_sys_interrupt_ack_return result;

    register okl4_register_t x0 asm("x0");
    register okl4_register_t x1 asm("x1");
    __asm__ __volatile__(
            "" hvc(5128) "\n\t"
            : "=r"(x0), "=r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.irq = (okl4_interrupt_number_t)(x0);
    result.source = (uint8_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_attach_private(okl4_kcap_t vcpu_cap, okl4_kcap_t irq_cap,
        okl4_interrupt_number_t irq_num)
{
    register uint32_t r0 asm("r0") = (uint32_t)vcpu_cap;
    register uint32_t r1 asm("r1") = (uint32_t)irq_cap;
    register uint32_t r2 asm("r2") = (uint32_t)irq_num;
    __asm__ __volatile__(
            ""hvc(5134)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_attach_private(okl4_kcap_t vcpu_cap, okl4_kcap_t irq_cap,
        okl4_interrupt_number_t irq_num)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)vcpu_cap;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)irq_cap;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)irq_num;
    __asm__ __volatile__(
            "" hvc(5134) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_attach_shared(okl4_kcap_t domain_cap, okl4_kcap_t irq_cap,
        okl4_interrupt_number_t irq_num)
{
    register uint32_t r0 asm("r0") = (uint32_t)domain_cap;
    register uint32_t r1 asm("r1") = (uint32_t)irq_cap;
    register uint32_t r2 asm("r2") = (uint32_t)irq_num;
    __asm__ __volatile__(
            ""hvc(5135)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_attach_shared(okl4_kcap_t domain_cap, okl4_kcap_t irq_cap,
        okl4_interrupt_number_t irq_num)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)domain_cap;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)irq_cap;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)irq_num;
    __asm__ __volatile__(
            "" hvc(5135) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_detach(okl4_kcap_t irq_cap)
{
    register uint32_t r0 asm("r0") = (uint32_t)irq_cap;
    __asm__ __volatile__(
            ""hvc(5136)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_detach(okl4_kcap_t irq_cap)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq_cap;
    __asm__ __volatile__(
            "" hvc(5136) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_dist_enable(okl4_bool_t enable)
{
    register uint32_t r0 asm("r0") = (uint32_t)enable;
    __asm__ __volatile__(
            ""hvc(5133)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_dist_enable(okl4_bool_t enable)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)enable;
    __asm__ __volatile__(
            "" hvc(5133) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_eoi(okl4_interrupt_number_t irq, uint8_t source)
{
    register uint32_t r0 asm("r0") = (uint32_t)irq;
    register uint32_t r1 asm("r1") = (uint32_t)source;
    __asm__ __volatile__(
            ""hvc(5129)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_eoi(okl4_interrupt_number_t irq, uint8_t source)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)source;
    __asm__ __volatile__(
            "" hvc(5129) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_interrupt_get_highest_priority_pending_return
_okl4_sys_interrupt_get_highest_priority_pending(void)
{
    struct _okl4_sys_interrupt_get_highest_priority_pending_return result;

    register uint32_t r0 asm("r0");
    register uint32_t r1 asm("r1");
    __asm__ __volatile__(
            ""hvc(5137)"\n\t"
            : "=r"(r0), "=r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    result.irq = (okl4_interrupt_number_t)(r0);
    result.source = (uint8_t)(r1);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_interrupt_get_highest_priority_pending_return
_okl4_sys_interrupt_get_highest_priority_pending(void)
{
    struct _okl4_sys_interrupt_get_highest_priority_pending_return result;

    register okl4_register_t x0 asm("x0");
    register okl4_register_t x1 asm("x1");
    __asm__ __volatile__(
            "" hvc(5137) "\n\t"
            : "=r"(x0), "=r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.irq = (okl4_interrupt_number_t)(x0);
    result.source = (uint8_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_interrupt_get_payload_return
_okl4_sys_interrupt_get_payload(okl4_interrupt_number_t irq)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp payload_tmp;
    struct _okl4_sys_interrupt_get_payload_return result;

    register uint32_t r0 asm("r0") = (uint32_t)irq;
    register uint32_t r1 asm("r1");
    register uint32_t r2 asm("r2");
    __asm__ __volatile__(
            ""hvc(5132)"\n\t"
            : "=r"(r1), "=r"(r2), "+r"(r0)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    result.error = (okl4_error_t)(r0);
    payload_tmp.words.lo = r1;
    payload_tmp.words.hi = r2;
    result.payload = (okl4_virq_flags_t)(payload_tmp.val);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_interrupt_get_payload_return
_okl4_sys_interrupt_get_payload(okl4_interrupt_number_t irq)
{
    struct _okl4_sys_interrupt_get_payload_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq;
    register okl4_register_t x1 asm("x1");
    __asm__ __volatile__(
            "" hvc(5132) "\n\t"
            : "=r"(x1), "+r"(x0)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.payload = (okl4_virq_flags_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_interrupt_limits_return
_okl4_sys_interrupt_limits(void)
{
    struct _okl4_sys_interrupt_limits_return result;

    register uint32_t r0 asm("r0");
    register uint32_t r1 asm("r1");
    __asm__ __volatile__(
            ""hvc(5138)"\n\t"
            : "=r"(r0), "=r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    result.cpunumber = (okl4_count_t)(r0);
    result.itnumber = (okl4_count_t)(r1);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_interrupt_limits_return
_okl4_sys_interrupt_limits(void)
{
    struct _okl4_sys_interrupt_limits_return result;

    register okl4_register_t x0 asm("x0");
    register okl4_register_t x1 asm("x1");
    __asm__ __volatile__(
            "" hvc(5138) "\n\t"
            : "=r"(x0), "=r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.cpunumber = (okl4_count_t)(x0);
    result.itnumber = (okl4_count_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_mask(okl4_interrupt_number_t irq)
{
    register uint32_t r0 asm("r0") = (uint32_t)irq;
    __asm__ __volatile__(
            ""hvc(5130)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_mask(okl4_interrupt_number_t irq)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq;
    __asm__ __volatile__(
            "" hvc(5130) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_raise(okl4_gicd_sgir_t sgir)
{
    register uint32_t r0 asm("r0") = (uint32_t)sgir;
    __asm__ __volatile__(
            ""hvc(5145)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_raise(okl4_gicd_sgir_t sgir)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)sgir;
    __asm__ __volatile__(
            "" hvc(5145) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_binary_point(uint8_t binary_point)
{
    register uint32_t r0 asm("r0") = (uint32_t)binary_point;
    __asm__ __volatile__(
            ""hvc(5139)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_binary_point(uint8_t binary_point)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)binary_point;
    __asm__ __volatile__(
            "" hvc(5139) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_config(okl4_interrupt_number_t irq,
        okl4_gicd_icfgr_t icfgr)
{
    register uint32_t r0 asm("r0") = (uint32_t)irq;
    register uint32_t r1 asm("r1") = (uint32_t)icfgr;
    __asm__ __volatile__(
            ""hvc(5140)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_config(okl4_interrupt_number_t irq,
        okl4_gicd_icfgr_t icfgr)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)icfgr;
    __asm__ __volatile__(
            "" hvc(5140) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_control(okl4_bool_t enable)
{
    register uint32_t r0 asm("r0") = (uint32_t)enable;
    __asm__ __volatile__(
            ""hvc(5141)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_control(okl4_bool_t enable)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)enable;
    __asm__ __volatile__(
            "" hvc(5141) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_priority(okl4_interrupt_number_t irq, uint8_t priority)
{
    register uint32_t r0 asm("r0") = (uint32_t)irq;
    register uint32_t r1 asm("r1") = (uint32_t)priority;
    __asm__ __volatile__(
            ""hvc(5142)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_priority(okl4_interrupt_number_t irq, uint8_t priority)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)priority;
    __asm__ __volatile__(
            "" hvc(5142) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_priority_mask(uint8_t priority_mask)
{
    register uint32_t r0 asm("r0") = (uint32_t)priority_mask;
    __asm__ __volatile__(
            ""hvc(5143)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_priority_mask(uint8_t priority_mask)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)priority_mask;
    __asm__ __volatile__(
            "" hvc(5143) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_targets(okl4_interrupt_number_t irq, uint8_t cpu_mask)
{
    register uint32_t r0 asm("r0") = (uint32_t)irq;
    register uint32_t r1 asm("r1") = (uint32_t)cpu_mask;
    __asm__ __volatile__(
            ""hvc(5144)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_set_targets(okl4_interrupt_number_t irq, uint8_t cpu_mask)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)cpu_mask;
    __asm__ __volatile__(
            "" hvc(5144) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_unmask(okl4_interrupt_number_t irq)
{
    register uint32_t r0 asm("r0") = (uint32_t)irq;
    __asm__ __volatile__(
            ""hvc(5131)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_interrupt_unmask(okl4_interrupt_number_t irq)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq;
    __asm__ __volatile__(
            "" hvc(5131) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE void
_okl4_sys_kdb_interact(void)
{
    __asm__ __volatile__(
            ""hvc(5120)"\n\t"
            :
            :
            : "cc", "memory", "r0", "r1", "r2", "r3", "r4", "r5"
            );

}
#endif

#else

OKL4_FORCE_INLINE void
_okl4_sys_kdb_interact(void)
{
    __asm__ __volatile__(
            "" hvc(5120) "\n\t"
            :
            :
            : "cc", "memory", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );

}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_kdb_set_object_name(okl4_kcap_t object, uint32_t name0, uint32_t name1
        , uint32_t name2, uint32_t name3)
{
    register uint32_t r0 asm("r0") = (uint32_t)object;
    register uint32_t r1 asm("r1") = (uint32_t)name0;
    register uint32_t r2 asm("r2") = (uint32_t)name1;
    register uint32_t r3 asm("r3") = (uint32_t)name2;
    register uint32_t r4 asm("r4") = (uint32_t)name3;
    __asm__ __volatile__(
            ""hvc(5121)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4)
            :
            : "cc", "memory", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_kdb_set_object_name(okl4_kcap_t object, uint32_t name0, uint32_t name1
        , uint32_t name2, uint32_t name3)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)object;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)name0;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)name1;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)name2;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)name3;
    __asm__ __volatile__(
            "" hvc(5121) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4)
            :
            : "cc", "memory", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_ksp_procedure_call_return
_okl4_sys_ksp_procedure_call(okl4_kcap_t agent, okl4_ksp_arg_t operation,
        okl4_ksp_arg_t arg0, okl4_ksp_arg_t arg1, okl4_ksp_arg_t arg2,
        okl4_ksp_arg_t arg3)
{
    struct _okl4_sys_ksp_procedure_call_return result;

    register uint32_t r0 asm("r0") = (uint32_t)agent;
    register uint32_t r1 asm("r1") = (uint32_t)operation;
    register uint32_t r2 asm("r2") = (uint32_t)arg0;
    register uint32_t r3 asm("r3") = (uint32_t)arg1;
    register uint32_t r4 asm("r4") = (uint32_t)arg2;
    register uint32_t r5 asm("r5") = (uint32_t)arg3;
    __asm__ __volatile__(
            ""hvc(5197)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4), "+r"(r5)
            :
            : "cc", "memory"
            );


    result.error = (okl4_error_t)(r0);
    result.ret0 = (okl4_ksp_arg_t)(r1);
    result.ret1 = (okl4_ksp_arg_t)(r2);
    result.ret2 = (okl4_ksp_arg_t)(r3);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_ksp_procedure_call_return
_okl4_sys_ksp_procedure_call(okl4_kcap_t agent, okl4_ksp_arg_t operation,
        okl4_ksp_arg_t arg0, okl4_ksp_arg_t arg1, okl4_ksp_arg_t arg2,
        okl4_ksp_arg_t arg3)
{
    struct _okl4_sys_ksp_procedure_call_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)agent;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)operation;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)arg0;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)arg1;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)arg2;
    register okl4_register_t x5 asm("x5") = (okl4_register_t)arg3;
    __asm__ __volatile__(
            "" hvc(5197) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4), "+r"(x5)
            :
            : "cc", "memory", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.ret0 = (okl4_ksp_arg_t)(x1);
    result.ret1 = (okl4_ksp_arg_t)(x2);
    result.ret2 = (okl4_ksp_arg_t)(x3);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_attach_segment(okl4_kcap_t mmu_id, okl4_kcap_t segment_id,
        okl4_count_t index, okl4_page_perms_t perms)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)segment_id;
    register uint32_t r2 asm("r2") = (uint32_t)index;
    register uint32_t r3 asm("r3") = (uint32_t)perms;
    __asm__ __volatile__(
            ""hvc(5152)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3)
            :
            : "cc", "memory", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_attach_segment(okl4_kcap_t mmu_id, okl4_kcap_t segment_id,
        okl4_count_t index, okl4_page_perms_t perms)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)segment_id;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)index;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)perms;
    __asm__ __volatile__(
            "" hvc(5152) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3)
            :
            : "cc", "memory", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_detach_segment(okl4_kcap_t mmu_id, okl4_count_t index)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)index;
    __asm__ __volatile__(
            ""hvc(5153)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_detach_segment(okl4_kcap_t mmu_id, okl4_count_t index)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)index;
    __asm__ __volatile__(
            "" hvc(5153) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_flush_range(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_lsize_tr_t size)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)vaddr;
    register uint32_t r2 asm("r2") = (uint32_t)size;
    __asm__ __volatile__(
            ""hvc(5154)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_flush_range(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_lsize_tr_t size)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vaddr;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)size;
    __asm__ __volatile__(
            "" hvc(5154) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_flush_range_pn(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_lsize_pn_t count_pn)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)laddr_pn;
    register uint32_t r2 asm("r2") = (uint32_t)count_pn;
    __asm__ __volatile__(
            ""hvc(5155)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_flush_range_pn(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_lsize_pn_t count_pn)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)laddr_pn;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)count_pn;
    __asm__ __volatile__(
            "" hvc(5155) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_mmu_lookup_page_return
_okl4_sys_mmu_lookup_page(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_count_t segment_index)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp size_tmp;
    struct _okl4_sys_mmu_lookup_page_return result;

    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)vaddr;
    register uint32_t r2 asm("r2") = (uint32_t)segment_index;
    register uint32_t r3 asm("r3");
    register uint32_t r4 asm("r4");
    __asm__ __volatile__(
            ""hvc(5156)"\n\t"
            : "=r"(r3), "=r"(r4), "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r5"
            );


    result.error = (okl4_error_t)(r0);
    result.offset = (okl4_psize_tr_t)(r1);
    size_tmp.words.lo = r2;
    size_tmp.words.hi = r3;
    result.size = (okl4_mmu_lookup_size_t)(size_tmp.val);
    result.page_attr = (_okl4_page_attribute_t)(r4);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_mmu_lookup_page_return
_okl4_sys_mmu_lookup_page(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_count_t segment_index)
{
    struct _okl4_sys_mmu_lookup_page_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vaddr;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_index;
    register okl4_register_t x3 asm("x3");
    __asm__ __volatile__(
            "" hvc(5156) "\n\t"
            : "=r"(x3), "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.offset = (okl4_psize_tr_t)(x1);
    result.size = (okl4_mmu_lookup_size_t)(x2);
    result.page_attr = (_okl4_page_attribute_t)(x3);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_mmu_lookup_pn_return
_okl4_sys_mmu_lookup_pn(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_count_t segment_index)
{
    struct _okl4_sys_mmu_lookup_pn_return result;

    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)laddr_pn;
    register uint32_t r2 asm("r2") = (uint32_t)segment_index;
    register uint32_t r3 asm("r3");
    __asm__ __volatile__(
            ""hvc(5157)"\n\t"
            : "=r"(r3), "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r4", "r5"
            );


    result.segment_index = (okl4_mmu_lookup_index_t)(r0);
    result.offset_pn = (okl4_psize_pn_t)(r1);
    result.count_pn = (okl4_lsize_pn_t)(r2);
    result.page_attr = (_okl4_page_attribute_t)(r3);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_mmu_lookup_pn_return
_okl4_sys_mmu_lookup_pn(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_count_t segment_index)
{
    struct _okl4_sys_mmu_lookup_pn_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)laddr_pn;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_index;
    register okl4_register_t x3 asm("x3");
    __asm__ __volatile__(
            "" hvc(5157) "\n\t"
            : "=r"(x3), "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x4", "x5", "x6", "x7"
            );


    result.segment_index = (okl4_mmu_lookup_index_t)(x0);
    result.offset_pn = (okl4_psize_pn_t)(x1);
    result.count_pn = (okl4_lsize_pn_t)(x2);
    result.page_attr = (_okl4_page_attribute_t)(x3);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_map_page(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_count_t segment_index, okl4_psize_tr_t offset, okl4_lsize_tr_t size
        , _okl4_page_attribute_t page_attr)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)vaddr;
    register uint32_t r2 asm("r2") = (uint32_t)segment_index;
    register uint32_t r3 asm("r3") = (uint32_t)offset;
    register uint32_t r4 asm("r4") = (uint32_t)size;
    register uint32_t r5 asm("r5") = (uint32_t)page_attr;
    __asm__ __volatile__(
            ""hvc(5158)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4), "+r"(r5)
            :
            : "cc", "memory"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_map_page(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_count_t segment_index, okl4_psize_tr_t offset, okl4_lsize_tr_t size
        , _okl4_page_attribute_t page_attr)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vaddr;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_index;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)offset;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)size;
    register okl4_register_t x5 asm("x5") = (okl4_register_t)page_attr;
    __asm__ __volatile__(
            "" hvc(5158) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4), "+r"(x5)
            :
            : "cc", "memory", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_map_pn(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_count_t segment_index, okl4_psize_pn_t segment_offset_pn,
        okl4_lsize_pn_t count_pn, _okl4_page_attribute_t page_attr)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)laddr_pn;
    register uint32_t r2 asm("r2") = (uint32_t)segment_index;
    register uint32_t r3 asm("r3") = (uint32_t)segment_offset_pn;
    register uint32_t r4 asm("r4") = (uint32_t)count_pn;
    register uint32_t r5 asm("r5") = (uint32_t)page_attr;
    __asm__ __volatile__(
            ""hvc(5159)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4), "+r"(r5)
            :
            : "cc", "memory"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_map_pn(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_count_t segment_index, okl4_psize_pn_t segment_offset_pn,
        okl4_lsize_pn_t count_pn, _okl4_page_attribute_t page_attr)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)laddr_pn;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_index;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)segment_offset_pn;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)count_pn;
    register okl4_register_t x5 asm("x5") = (okl4_register_t)page_attr;
    __asm__ __volatile__(
            "" hvc(5159) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4), "+r"(x5)
            :
            : "cc", "memory", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_unmap_page(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_lsize_tr_t size)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)vaddr;
    register uint32_t r2 asm("r2") = (uint32_t)size;
    __asm__ __volatile__(
            ""hvc(5160)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_unmap_page(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_lsize_tr_t size)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vaddr;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)size;
    __asm__ __volatile__(
            "" hvc(5160) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_unmap_pn(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_lsize_pn_t count_pn)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)laddr_pn;
    register uint32_t r2 asm("r2") = (uint32_t)count_pn;
    __asm__ __volatile__(
            ""hvc(5161)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_unmap_pn(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_lsize_pn_t count_pn)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)laddr_pn;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)count_pn;
    __asm__ __volatile__(
            "" hvc(5161) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_update_page_attrs(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_count_t segment_index, okl4_lsize_tr_t size,
        okl4_page_cache_t attrs)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)vaddr;
    register uint32_t r2 asm("r2") = (uint32_t)segment_index;
    register uint32_t r3 asm("r3") = (uint32_t)size;
    register uint32_t r4 asm("r4") = (uint32_t)attrs;
    __asm__ __volatile__(
            ""hvc(5162)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4)
            :
            : "cc", "memory", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_update_page_attrs(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_count_t segment_index, okl4_lsize_tr_t size,
        okl4_page_cache_t attrs)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vaddr;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_index;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)size;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)attrs;
    __asm__ __volatile__(
            "" hvc(5162) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4)
            :
            : "cc", "memory", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_update_page_perms(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_count_t segment_index, okl4_lsize_tr_t size,
        okl4_page_perms_t perms)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)vaddr;
    register uint32_t r2 asm("r2") = (uint32_t)segment_index;
    register uint32_t r3 asm("r3") = (uint32_t)size;
    register uint32_t r4 asm("r4") = (uint32_t)perms;
    __asm__ __volatile__(
            ""hvc(5163)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4)
            :
            : "cc", "memory", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_update_page_perms(okl4_kcap_t mmu_id, okl4_laddr_tr_t vaddr,
        okl4_count_t segment_index, okl4_lsize_tr_t size,
        okl4_page_perms_t perms)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vaddr;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_index;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)size;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)perms;
    __asm__ __volatile__(
            "" hvc(5163) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4)
            :
            : "cc", "memory", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_update_pn_attrs(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_count_t segment_index, okl4_lsize_pn_t count_pn,
        okl4_page_cache_t attrs)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)laddr_pn;
    register uint32_t r2 asm("r2") = (uint32_t)segment_index;
    register uint32_t r3 asm("r3") = (uint32_t)count_pn;
    register uint32_t r4 asm("r4") = (uint32_t)attrs;
    __asm__ __volatile__(
            ""hvc(5164)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4)
            :
            : "cc", "memory", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_update_pn_attrs(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_count_t segment_index, okl4_lsize_pn_t count_pn,
        okl4_page_cache_t attrs)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)laddr_pn;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_index;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)count_pn;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)attrs;
    __asm__ __volatile__(
            "" hvc(5164) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4)
            :
            : "cc", "memory", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_update_pn_perms(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_count_t segment_index, okl4_lsize_pn_t count_pn,
        okl4_page_perms_t perms)
{
    register uint32_t r0 asm("r0") = (uint32_t)mmu_id;
    register uint32_t r1 asm("r1") = (uint32_t)laddr_pn;
    register uint32_t r2 asm("r2") = (uint32_t)segment_index;
    register uint32_t r3 asm("r3") = (uint32_t)count_pn;
    register uint32_t r4 asm("r4") = (uint32_t)perms;
    __asm__ __volatile__(
            ""hvc(5165)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4)
            :
            : "cc", "memory", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_mmu_update_pn_perms(okl4_kcap_t mmu_id, okl4_laddr_pn_t laddr_pn,
        okl4_count_t segment_index, okl4_lsize_pn_t count_pn,
        okl4_page_perms_t perms)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)mmu_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)laddr_pn;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)segment_index;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)count_pn;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)perms;
    __asm__ __volatile__(
            "" hvc(5165) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4)
            :
            : "cc", "memory", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_performance_null_syscall(void)
{
    register uint32_t r0 asm("r0");
    __asm__ __volatile__(
            ""hvc(5198)"\n\t"
            : "=r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_performance_null_syscall(void)
{
    register okl4_register_t x0 asm("x0");
    __asm__ __volatile__(
            "" hvc(5198) "\n\t"
            : "=r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_pipe_control(okl4_kcap_t pipe_id, okl4_pipe_control_t control)
{
    register uint32_t r0 asm("r0") = (uint32_t)pipe_id;
    register uint32_t r1 asm("r1") = (uint32_t)control;
    __asm__ __volatile__(
            ""hvc(5146)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_pipe_control(okl4_kcap_t pipe_id, okl4_pipe_control_t control)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)pipe_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)control;
    __asm__ __volatile__(
            "" hvc(5146) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_pipe_recv_return
_okl4_sys_pipe_recv(okl4_kcap_t pipe_id, okl4_vsize_t buf_size, uint8_t *data)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp size_tmp;
    struct _okl4_sys_pipe_recv_return result;

    register uint32_t r0 asm("r0") = (uint32_t)pipe_id;
    register uint32_t r1 asm("r1") = (uint32_t)buf_size;
    register uint32_t r2 asm("r2") = (uint32_t)(uintptr_t)data;
    __asm__ __volatile__(
            ""hvc(5147)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    result.error = (okl4_error_t)(r0);
    size_tmp.words.lo = r1;
    size_tmp.words.hi = r2;
    result.size = (okl4_ksize_t)(size_tmp.val);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_pipe_recv_return
_okl4_sys_pipe_recv(okl4_kcap_t pipe_id, okl4_vsize_t buf_size, uint8_t *data)
{
    struct _okl4_sys_pipe_recv_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)pipe_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)buf_size;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)(uintptr_t)data;
    __asm__ __volatile__(
            "" hvc(5147) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.size = (okl4_ksize_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_pipe_send(okl4_kcap_t pipe_id, okl4_vsize_t size, const uint8_t *data)
{
    register uint32_t r0 asm("r0") = (uint32_t)pipe_id;
    register uint32_t r1 asm("r1") = (uint32_t)size;
    register uint32_t r2 asm("r2") = (uint32_t)(uintptr_t)data;
    __asm__ __volatile__(
            ""hvc(5148)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_pipe_send(okl4_kcap_t pipe_id, okl4_vsize_t size, const uint8_t *data)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)pipe_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)size;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)(uintptr_t)data;
    __asm__ __volatile__(
            "" hvc(5148) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_priority_waive(okl4_priority_t priority)
{
    register uint32_t r0 asm("r0") = (uint32_t)priority;
    __asm__ __volatile__(
            ""hvc(5151)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_priority_waive(okl4_priority_t priority)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)priority;
    __asm__ __volatile__(
            "" hvc(5151) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_remote_get_register_return
_okl4_sys_remote_get_register(okl4_kcap_t target,
        okl4_register_and_set_t reg_and_set)
{
    struct _okl4_sys_remote_get_register_return result;

    register uint32_t r0 asm("r0") = (uint32_t)target;
    register uint32_t r1 asm("r1") = (uint32_t)reg_and_set;
    register uint32_t r2 asm("r2");
    register uint32_t r3 asm("r3");
    register uint32_t r4 asm("r4");
    __asm__ __volatile__(
            ""hvc(5200)"\n\t"
            : "=r"(r2), "=r"(r3), "=r"(r4), "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r5"
            );


    result.reg_w0 = (uint32_t)(r0);
    result.reg_w1 = (uint32_t)(r1);
    result.reg_w2 = (uint32_t)(r2);
    result.reg_w3 = (uint32_t)(r3);
    result.error = (okl4_error_t)(r4);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_remote_get_register_return
_okl4_sys_remote_get_register(okl4_kcap_t target,
        okl4_register_and_set_t reg_and_set)
{
    struct _okl4_sys_remote_get_register_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)target;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)reg_and_set;
    register okl4_register_t x2 asm("x2");
    register okl4_register_t x3 asm("x3");
    register okl4_register_t x4 asm("x4");
    __asm__ __volatile__(
            "" hvc(5200) "\n\t"
            : "=r"(x2), "=r"(x3), "=r"(x4), "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x5", "x6", "x7"
            );


    result.reg_w0 = (uint32_t)(x0);
    result.reg_w1 = (uint32_t)(x1);
    result.reg_w2 = (uint32_t)(x2);
    result.reg_w3 = (uint32_t)(x3);
    result.error = (okl4_error_t)(x4);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_remote_get_registers(okl4_kcap_t target, okl4_register_set_t set,
        void *regs)
{
    register uint32_t r0 asm("r0") = (uint32_t)target;
    register uint32_t r1 asm("r1") = (uint32_t)set;
    register uint32_t r2 asm("r2") = (uint32_t)(uintptr_t)regs;
    __asm__ __volatile__(
            ""hvc(5201)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_remote_get_registers(okl4_kcap_t target, okl4_register_set_t set,
        void *regs)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)target;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)set;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)(uintptr_t)regs;
    __asm__ __volatile__(
            "" hvc(5201) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_remote_read_memory32_return
_okl4_sys_remote_read_memory32(okl4_kcap_t target, okl4_laddr_t address)
{
    struct _okl4_sys_remote_read_memory32_return result;

    register uint32_t r0 asm("r0") = (uint32_t)target;
    register uint32_t r1 asm("r1") = (uint32_t)(address        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((address >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5202)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    result.data = (uint32_t)(r0);
    result.error = (okl4_error_t)(r1);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_remote_read_memory32_return
_okl4_sys_remote_read_memory32(okl4_kcap_t target, okl4_laddr_t address)
{
    struct _okl4_sys_remote_read_memory32_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)target;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)address;
    __asm__ __volatile__(
            "" hvc(5202) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.data = (uint32_t)(x0);
    result.error = (okl4_error_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_remote_set_register(okl4_kcap_t target,
        okl4_register_and_set_t reg_and_set, uint32_t reg_w0, uint32_t reg_w1,
        uint32_t reg_w2, uint32_t reg_w3)
{
    register uint32_t r0 asm("r0") = (uint32_t)target;
    register uint32_t r1 asm("r1") = (uint32_t)reg_and_set;
    register uint32_t r2 asm("r2") = (uint32_t)reg_w0;
    register uint32_t r3 asm("r3") = (uint32_t)reg_w1;
    register uint32_t r4 asm("r4") = (uint32_t)reg_w2;
    register uint32_t r5 asm("r5") = (uint32_t)reg_w3;
    __asm__ __volatile__(
            ""hvc(5203)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4), "+r"(r5)
            :
            : "cc", "memory"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_remote_set_register(okl4_kcap_t target,
        okl4_register_and_set_t reg_and_set, uint32_t reg_w0, uint32_t reg_w1,
        uint32_t reg_w2, uint32_t reg_w3)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)target;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)reg_and_set;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)reg_w0;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)reg_w1;
    register okl4_register_t x4 asm("x4") = (okl4_register_t)reg_w2;
    register okl4_register_t x5 asm("x5") = (okl4_register_t)reg_w3;
    __asm__ __volatile__(
            "" hvc(5203) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3), "+r"(x4), "+r"(x5)
            :
            : "cc", "memory", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_remote_set_registers(okl4_kcap_t target, okl4_register_set_t set,
        void *regs)
{
    register uint32_t r0 asm("r0") = (uint32_t)target;
    register uint32_t r1 asm("r1") = (uint32_t)set;
    register uint32_t r2 asm("r2") = (uint32_t)(uintptr_t)regs;
    __asm__ __volatile__(
            ""hvc(5204)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_remote_set_registers(okl4_kcap_t target, okl4_register_set_t set,
        void *regs)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)target;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)set;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)(uintptr_t)regs;
    __asm__ __volatile__(
            "" hvc(5204) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_remote_write_memory32(okl4_kcap_t target, okl4_laddr_t address,
        uint32_t data)
{
    register uint32_t r0 asm("r0") = (uint32_t)target;
    register uint32_t r1 asm("r1") = (uint32_t)(address        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((address >> 32) & 0xffffffff);
    register uint32_t r3 asm("r3") = (uint32_t)data;
    __asm__ __volatile__(
            ""hvc(5205)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3)
            :
            : "cc", "memory", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_remote_write_memory32(okl4_kcap_t target, okl4_laddr_t address,
        uint32_t data)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)target;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)address;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)data;
    __asm__ __volatile__(
            "" hvc(5205) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_schedule_metrics_status_suspended_return
_okl4_sys_schedule_metrics_status_suspended(okl4_kcap_t scheduler_id)
{
    struct _okl4_sys_schedule_metrics_status_suspended_return result;

    register uint32_t r0 asm("r0") = (uint32_t)scheduler_id;
    register uint32_t r1 asm("r1");
    register uint32_t r2 asm("r2");
    __asm__ __volatile__(
            ""hvc(5206)"\n\t"
            : "=r"(r1), "=r"(r2), "+r"(r0)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    result.error = (okl4_error_t)(r0);
    result.power_suspend_version = (uint32_t)(r1);
    result.power_suspend_running_count = (uint32_t)(r2);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_schedule_metrics_status_suspended_return
_okl4_sys_schedule_metrics_status_suspended(okl4_kcap_t scheduler_id)
{
    struct _okl4_sys_schedule_metrics_status_suspended_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)scheduler_id;
    register okl4_register_t x1 asm("x1");
    register okl4_register_t x2 asm("x2");
    __asm__ __volatile__(
            "" hvc(5206) "\n\t"
            : "=r"(x1), "=r"(x2), "+r"(x0)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.power_suspend_version = (uint32_t)(x1);
    result.power_suspend_running_count = (uint32_t)(x2);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_metrics_watch_suspended(okl4_kcap_t scheduler_id,
        okl4_kcap_t vcpu_id, okl4_bool_t watch)
{
    register uint32_t r0 asm("r0") = (uint32_t)scheduler_id;
    register uint32_t r1 asm("r1") = (uint32_t)vcpu_id;
    register uint32_t r2 asm("r2") = (uint32_t)watch;
    __asm__ __volatile__(
            ""hvc(5207)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_metrics_watch_suspended(okl4_kcap_t scheduler_id,
        okl4_kcap_t vcpu_id, okl4_bool_t watch)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)scheduler_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vcpu_id;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)watch;
    __asm__ __volatile__(
            "" hvc(5207) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_profile_cpu_disable(okl4_kcap_t phys_cpu)
{
    register uint32_t r0 asm("r0") = (uint32_t)phys_cpu;
    __asm__ __volatile__(
            ""hvc(5168)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_profile_cpu_disable(okl4_kcap_t phys_cpu)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)phys_cpu;
    __asm__ __volatile__(
            "" hvc(5168) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_schedule_profile_cpu_enable_return
_okl4_sys_schedule_profile_cpu_enable(okl4_kcap_t phys_cpu)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp timestamp_tmp;
    struct _okl4_sys_schedule_profile_cpu_enable_return result;

    register uint32_t r0 asm("r0") = (uint32_t)phys_cpu;
    register uint32_t r1 asm("r1");
    register uint32_t r2 asm("r2");
    __asm__ __volatile__(
            ""hvc(5169)"\n\t"
            : "=r"(r1), "=r"(r2), "+r"(r0)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    result.error = (okl4_error_t)(r0);
    timestamp_tmp.words.lo = r1;
    timestamp_tmp.words.hi = r2;
    result.timestamp = (uint64_t)(timestamp_tmp.val);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_schedule_profile_cpu_enable_return
_okl4_sys_schedule_profile_cpu_enable(okl4_kcap_t phys_cpu)
{
    struct _okl4_sys_schedule_profile_cpu_enable_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)phys_cpu;
    register okl4_register_t x1 asm("x1");
    __asm__ __volatile__(
            "" hvc(5169) "\n\t"
            : "=r"(x1), "+r"(x0)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.timestamp = (uint64_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_profile_cpu_get_data(okl4_kcap_t phys_cpu,
        struct okl4_schedule_profile_data *profile)
{
    register uint32_t r0 asm("r0") = (uint32_t)phys_cpu;
    register uint32_t r1 asm("r1") = (uint32_t)(uintptr_t)profile;
    __asm__ __volatile__(
            ""hvc(5170)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_profile_cpu_get_data(okl4_kcap_t phys_cpu,
        struct okl4_schedule_profile_data *profile)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)phys_cpu;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)(uintptr_t)profile;
    __asm__ __volatile__(
            "" hvc(5170) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_profile_vcpu_disable(okl4_kcap_t vcpu)
{
    register uint32_t r0 asm("r0") = (uint32_t)vcpu;
    __asm__ __volatile__(
            ""hvc(5171)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_profile_vcpu_disable(okl4_kcap_t vcpu)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)vcpu;
    __asm__ __volatile__(
            "" hvc(5171) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_schedule_profile_vcpu_enable_return
_okl4_sys_schedule_profile_vcpu_enable(okl4_kcap_t vcpu)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp timestamp_tmp;
    struct _okl4_sys_schedule_profile_vcpu_enable_return result;

    register uint32_t r0 asm("r0") = (uint32_t)vcpu;
    register uint32_t r1 asm("r1");
    register uint32_t r2 asm("r2");
    __asm__ __volatile__(
            ""hvc(5172)"\n\t"
            : "=r"(r1), "=r"(r2), "+r"(r0)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    result.error = (okl4_error_t)(r0);
    timestamp_tmp.words.lo = r1;
    timestamp_tmp.words.hi = r2;
    result.timestamp = (uint64_t)(timestamp_tmp.val);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_schedule_profile_vcpu_enable_return
_okl4_sys_schedule_profile_vcpu_enable(okl4_kcap_t vcpu)
{
    struct _okl4_sys_schedule_profile_vcpu_enable_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)vcpu;
    register okl4_register_t x1 asm("x1");
    __asm__ __volatile__(
            "" hvc(5172) "\n\t"
            : "=r"(x1), "+r"(x0)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.timestamp = (uint64_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_profile_vcpu_get_data(okl4_kcap_t vcpu,
        struct okl4_schedule_profile_data *profile)
{
    register uint32_t r0 asm("r0") = (uint32_t)vcpu;
    register uint32_t r1 asm("r1") = (uint32_t)(uintptr_t)profile;
    __asm__ __volatile__(
            ""hvc(5173)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_schedule_profile_vcpu_get_data(okl4_kcap_t vcpu,
        struct okl4_schedule_profile_data *profile)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)vcpu;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)(uintptr_t)profile;
    __asm__ __volatile__(
            "" hvc(5173) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_scheduler_affinity_get_return
_okl4_sys_scheduler_affinity_get(okl4_kcap_t scheduler_id, okl4_kcap_t vcpu_id)
{
    struct _okl4_sys_scheduler_affinity_get_return result;

    register uint32_t r0 asm("r0") = (uint32_t)scheduler_id;
    register uint32_t r1 asm("r1") = (uint32_t)vcpu_id;
    __asm__ __volatile__(
            ""hvc(5182)"\n\t"
            : "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r2", "r3", "r4", "r5"
            );


    result.error = (okl4_error_t)(r0);
    result.cpu_index = (okl4_cpu_id_t)(r1);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_scheduler_affinity_get_return
_okl4_sys_scheduler_affinity_get(okl4_kcap_t scheduler_id, okl4_kcap_t vcpu_id)
{
    struct _okl4_sys_scheduler_affinity_get_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)scheduler_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vcpu_id;
    __asm__ __volatile__(
            "" hvc(5182) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.cpu_index = (okl4_cpu_id_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_scheduler_affinity_set(okl4_kcap_t scheduler_id, okl4_kcap_t vcpu_id,
        okl4_cpu_id_t cpu_index)
{
    register uint32_t r0 asm("r0") = (uint32_t)scheduler_id;
    register uint32_t r1 asm("r1") = (uint32_t)vcpu_id;
    register uint32_t r2 asm("r2") = (uint32_t)cpu_index;
    __asm__ __volatile__(
            ""hvc(5183)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_scheduler_affinity_set(okl4_kcap_t scheduler_id, okl4_kcap_t vcpu_id,
        okl4_cpu_id_t cpu_index)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)scheduler_id;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)vcpu_id;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)cpu_index;
    __asm__ __volatile__(
            "" hvc(5183) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_timer_cancel_return
_okl4_sys_timer_cancel(okl4_kcap_t timer, okl4_timer_flags_t flags)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp remaining_tmp;
    struct _okl4_sys_timer_cancel_return result;

    register uint32_t r0 asm("r0") = (uint32_t)timer;
    register uint32_t r1 asm("r1") = (uint32_t)flags;
    register uint32_t r2 asm("r2");
    register uint32_t r3 asm("r3");
    __asm__ __volatile__(
            ""hvc(5176)"\n\t"
            : "=r"(r2), "=r"(r3), "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r4", "r5"
            );


    remaining_tmp.words.lo = r0;
    remaining_tmp.words.hi = r1;
    result.remaining = (uint64_t)(remaining_tmp.val);
    result.old_flags = (okl4_timer_flags_t)(r2);
    result.error = (okl4_error_t)(r3);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_timer_cancel_return
_okl4_sys_timer_cancel(okl4_kcap_t timer, okl4_timer_flags_t flags)
{
    struct _okl4_sys_timer_cancel_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)timer;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)flags;
    register okl4_register_t x2 asm("x2");
    __asm__ __volatile__(
            "" hvc(5176) "\n\t"
            : "=r"(x2), "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    result.remaining = (uint64_t)(x0);
    result.old_flags = (okl4_timer_flags_t)(x1);
    result.error = (okl4_error_t)(x2);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_timer_get_resolution_return
_okl4_sys_timer_get_resolution(okl4_kcap_t timer)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp tick_freq_tmp;
    struct _okl4_sys_timer_get_resolution_return result;

    register uint32_t r0 asm("r0") = (uint32_t)timer;
    register uint32_t r1 asm("r1");
    register uint32_t r2 asm("r2");
    register uint32_t r3 asm("r3");
    register uint32_t r4 asm("r4");
    __asm__ __volatile__(
            ""hvc(5177)"\n\t"
            : "=r"(r1), "=r"(r2), "=r"(r3), "=r"(r4), "+r"(r0)
            :
            : "cc", "memory", "r5"
            );


    tick_freq_tmp.words.lo = r0;
    tick_freq_tmp.words.hi = r1;
    result.tick_freq = (uint64_t)(tick_freq_tmp.val);
    result.a = (uint32_t)(r2);
    result.b = (uint32_t)(r3);
    result.error = (okl4_error_t)(r4);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_timer_get_resolution_return
_okl4_sys_timer_get_resolution(okl4_kcap_t timer)
{
    struct _okl4_sys_timer_get_resolution_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)timer;
    register okl4_register_t x1 asm("x1");
    register okl4_register_t x2 asm("x2");
    register okl4_register_t x3 asm("x3");
    __asm__ __volatile__(
            "" hvc(5177) "\n\t"
            : "=r"(x1), "=r"(x2), "=r"(x3), "+r"(x0)
            :
            : "cc", "memory", "x4", "x5", "x6", "x7"
            );


    result.tick_freq = (uint64_t)(x0);
    result.a = (uint32_t)(x1);
    result.b = (uint32_t)(x2);
    result.error = (okl4_error_t)(x3);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_timer_get_time_return
_okl4_sys_timer_get_time(okl4_kcap_t timer, okl4_timer_flags_t flags)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp time_tmp;
    struct _okl4_sys_timer_get_time_return result;

    register uint32_t r0 asm("r0") = (uint32_t)timer;
    register uint32_t r1 asm("r1") = (uint32_t)flags;
    register uint32_t r2 asm("r2");
    __asm__ __volatile__(
            ""hvc(5178)"\n\t"
            : "=r"(r2), "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    time_tmp.words.lo = r0;
    time_tmp.words.hi = r1;
    result.time = (uint64_t)(time_tmp.val);
    result.error = (okl4_error_t)(r2);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_timer_get_time_return
_okl4_sys_timer_get_time(okl4_kcap_t timer, okl4_timer_flags_t flags)
{
    struct _okl4_sys_timer_get_time_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)timer;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)flags;
    __asm__ __volatile__(
            "" hvc(5178) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    result.time = (uint64_t)(x0);
    result.error = (okl4_error_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_timer_query_return
_okl4_sys_timer_query(okl4_kcap_t timer, okl4_timer_flags_t flags)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp remaining_tmp;
    struct _okl4_sys_timer_query_return result;

    register uint32_t r0 asm("r0") = (uint32_t)timer;
    register uint32_t r1 asm("r1") = (uint32_t)flags;
    register uint32_t r2 asm("r2");
    register uint32_t r3 asm("r3");
    __asm__ __volatile__(
            ""hvc(5179)"\n\t"
            : "=r"(r2), "=r"(r3), "+r"(r0), "+r"(r1)
            :
            : "cc", "memory", "r4", "r5"
            );


    remaining_tmp.words.lo = r0;
    remaining_tmp.words.hi = r1;
    result.remaining = (uint64_t)(remaining_tmp.val);
    result.active_flags = (okl4_timer_flags_t)(r2);
    result.error = (okl4_error_t)(r3);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_timer_query_return
_okl4_sys_timer_query(okl4_kcap_t timer, okl4_timer_flags_t flags)
{
    struct _okl4_sys_timer_query_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)timer;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)flags;
    register okl4_register_t x2 asm("x2");
    __asm__ __volatile__(
            "" hvc(5179) "\n\t"
            : "=r"(x2), "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    result.remaining = (uint64_t)(x0);
    result.active_flags = (okl4_timer_flags_t)(x1);
    result.error = (okl4_error_t)(x2);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_timer_start(okl4_kcap_t timer, uint64_t timeout,
        okl4_timer_flags_t flags)
{
    register uint32_t r0 asm("r0") = (uint32_t)timer;
    register uint32_t r1 asm("r1") = (uint32_t)(timeout        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((timeout >> 32) & 0xffffffff);
    register uint32_t r3 asm("r3") = (uint32_t)flags;
    __asm__ __volatile__(
            ""hvc(5180)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3)
            :
            : "cc", "memory", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_timer_start(okl4_kcap_t timer, uint64_t timeout,
        okl4_timer_flags_t flags)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)timer;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)timeout;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)flags;
    __asm__ __volatile__(
            "" hvc(5180) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE void
_okl4_sys_tracebuffer_sync(void)
{
    __asm__ __volatile__(
            ""hvc(5199)"\n\t"
            :
            :
            : "cc", "memory", "r0", "r1", "r2", "r3", "r4", "r5"
            );

}
#endif

#else

OKL4_FORCE_INLINE void
_okl4_sys_tracebuffer_sync(void)
{
    __asm__ __volatile__(
            "" hvc(5199) "\n\t"
            :
            :
            : "cc", "memory", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );

}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vcpu_reset(okl4_kcap_t vcpu)
{
    register uint32_t r0 asm("r0") = (uint32_t)vcpu;
    __asm__ __volatile__(
            ""hvc(5122)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vcpu_reset(okl4_kcap_t vcpu)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)vcpu;
    __asm__ __volatile__(
            "" hvc(5122) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vcpu_start(okl4_kcap_t vcpu, okl4_bool_t set_ip, void *ip)
{
    register uint32_t r0 asm("r0") = (uint32_t)vcpu;
    register uint32_t r1 asm("r1") = (uint32_t)set_ip;
    register uint32_t r2 asm("r2") = (uint32_t)(uintptr_t)ip;
    __asm__ __volatile__(
            ""hvc(5123)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vcpu_start(okl4_kcap_t vcpu, okl4_bool_t set_ip, void *ip)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)vcpu;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)set_ip;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)(uintptr_t)ip;
    __asm__ __volatile__(
            "" hvc(5123) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vcpu_stop(okl4_kcap_t vcpu)
{
    register uint32_t r0 asm("r0") = (uint32_t)vcpu;
    __asm__ __volatile__(
            ""hvc(5124)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vcpu_stop(okl4_kcap_t vcpu)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)vcpu;
    __asm__ __volatile__(
            "" hvc(5124) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vcpu_switch_mode(okl4_kcap_t vcpu, okl4_bool_t to_64bit,
        okl4_bool_t set_ip, void *ip)
{
    register uint32_t r0 asm("r0") = (uint32_t)vcpu;
    register uint32_t r1 asm("r1") = (uint32_t)to_64bit;
    register uint32_t r2 asm("r2") = (uint32_t)set_ip;
    register uint32_t r3 asm("r3") = (uint32_t)(uintptr_t)ip;
    __asm__ __volatile__(
            ""hvc(5125)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3)
            :
            : "cc", "memory", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vcpu_switch_mode(okl4_kcap_t vcpu, okl4_bool_t to_64bit,
        okl4_bool_t set_ip, void *ip)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)vcpu;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)to_64bit;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)set_ip;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)(uintptr_t)ip;
    __asm__ __volatile__(
            "" hvc(5125) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3)
            :
            : "cc", "memory", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE void
_okl4_sys_vcpu_sync_sev(void)
{
    __asm__ __volatile__(
            ""hvc(5126)"\n\t"
            :
            :
            : "cc", "memory", "r0", "r1", "r2", "r3", "r4", "r5"
            );

}
#endif

#else

OKL4_FORCE_INLINE void
_okl4_sys_vcpu_sync_sev(void)
{
    __asm__ __volatile__(
            "" hvc(5126) "\n\t"
            :
            :
            : "cc", "memory", "x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );

}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE void
_okl4_sys_vcpu_sync_wfe(okl4_kcap_t holder)
{
    register uint32_t r0 asm("r0") = (uint32_t)holder;
    __asm__ __volatile__(
            ""hvc(5127)"\n\t"
            : "+r"(r0)
            :
            : "cc", "memory", "r1", "r2", "r3", "r4", "r5"
            );

}
#endif

#else

OKL4_FORCE_INLINE void
_okl4_sys_vcpu_sync_wfe(okl4_kcap_t holder)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)holder;
    __asm__ __volatile__(
            "" hvc(5127) "\n\t"
            : "+r"(x0)
            :
            : "cc", "memory", "x1", "x2", "x3", "x4", "x5", "x6", "x7"
            );

}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE struct _okl4_sys_vinterrupt_clear_and_raise_return
_okl4_sys_vinterrupt_clear_and_raise(okl4_interrupt_number_t irq,
        okl4_kcap_t virqline, okl4_virq_flags_t mask, okl4_virq_flags_t payload)
{
    typedef union {
        struct uint64 {
            uint32_t lo;
            uint32_t hi;
        } words;
        uint64_t val;
    } okl4_uint64_tmp;
    okl4_uint64_tmp payload_tmp;
    struct _okl4_sys_vinterrupt_clear_and_raise_return result;

    register uint32_t r0 asm("r0") = (uint32_t)irq;
    register uint32_t r1 asm("r1") = (uint32_t)virqline;
    register uint32_t r2 asm("r2") = (uint32_t)(mask        & 0xffffffff);
    register uint32_t r3 asm("r3") = (uint32_t)((mask >> 32) & 0xffffffff);
    register uint32_t r4 asm("r4") = (uint32_t)(payload        & 0xffffffff);
    register uint32_t r5 asm("r5") = (uint32_t)((payload >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5194)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4), "+r"(r5)
            :
            : "cc", "memory"
            );


    result.error = (okl4_error_t)(r0);
    payload_tmp.words.lo = r1;
    payload_tmp.words.hi = r2;
    result.payload = (okl4_virq_flags_t)(payload_tmp.val);
    return result;
}
#endif

#else

OKL4_FORCE_INLINE struct _okl4_sys_vinterrupt_clear_and_raise_return
_okl4_sys_vinterrupt_clear_and_raise(okl4_interrupt_number_t irq,
        okl4_kcap_t virqline, okl4_virq_flags_t mask, okl4_virq_flags_t payload)
{
    struct _okl4_sys_vinterrupt_clear_and_raise_return result;

    register okl4_register_t x0 asm("x0") = (okl4_register_t)irq;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)virqline;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)mask;
    register okl4_register_t x3 asm("x3") = (okl4_register_t)payload;
    __asm__ __volatile__(
            "" hvc(5194) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2), "+r"(x3)
            :
            : "cc", "memory", "x4", "x5", "x6", "x7"
            );


    result.error = (okl4_error_t)(x0);
    result.payload = (okl4_virq_flags_t)(x1);
    return result;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vinterrupt_modify(okl4_kcap_t virqline, okl4_virq_flags_t mask,
        okl4_virq_flags_t payload)
{
    register uint32_t r0 asm("r0") = (uint32_t)virqline;
    register uint32_t r1 asm("r1") = (uint32_t)(mask        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((mask >> 32) & 0xffffffff);
    register uint32_t r3 asm("r3") = (uint32_t)(payload        & 0xffffffff);
    register uint32_t r4 asm("r4") = (uint32_t)((payload >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5195)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4)
            :
            : "cc", "memory", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vinterrupt_modify(okl4_kcap_t virqline, okl4_virq_flags_t mask,
        okl4_virq_flags_t payload)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)virqline;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)mask;
    register okl4_register_t x2 asm("x2") = (okl4_register_t)payload;
    __asm__ __volatile__(
            "" hvc(5195) "\n\t"
            : "+r"(x0), "+r"(x1), "+r"(x2)
            :
            : "cc", "memory", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif



#if defined(__ARM_EABI__)

#if defined(__RVCT__) || defined(__RVCT_GNU__)
#elif defined(__ADS__)
#else
OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vinterrupt_raise(okl4_kcap_t virqline, okl4_virq_flags_t payload)
{
    register uint32_t r0 asm("r0") = (uint32_t)virqline;
    register uint32_t r1 asm("r1") = (uint32_t)(payload        & 0xffffffff);
    register uint32_t r2 asm("r2") = (uint32_t)((payload >> 32) & 0xffffffff);
    __asm__ __volatile__(
            ""hvc(5196)"\n\t"
            : "+r"(r0), "+r"(r1), "+r"(r2)
            :
            : "cc", "memory", "r3", "r4", "r5"
            );


    return (okl4_error_t)r0;
}
#endif

#else

OKL4_FORCE_INLINE okl4_error_t
_okl4_sys_vinterrupt_raise(okl4_kcap_t virqline, okl4_virq_flags_t payload)
{
    register okl4_register_t x0 asm("x0") = (okl4_register_t)virqline;
    register okl4_register_t x1 asm("x1") = (okl4_register_t)payload;
    __asm__ __volatile__(
            "" hvc(5196) "\n\t"
            : "+r"(x0), "+r"(x1)
            :
            : "cc", "memory", "x2", "x3", "x4", "x5", "x6", "x7"
            );


    return (okl4_error_t)x0;
}

#endif




#endif 




#define OKL4_SYSCALL_AXON_PROCESS_RECV 5184

#define OKL4_SYSCALL_AXON_SET_HALTED 5186

#define OKL4_SYSCALL_AXON_SET_RECV_AREA 5187

#define OKL4_SYSCALL_AXON_SET_RECV_QUEUE 5188

#define OKL4_SYSCALL_AXON_SET_RECV_SEGMENT 5189

#define OKL4_SYSCALL_AXON_SET_SEND_AREA 5190

#define OKL4_SYSCALL_AXON_SET_SEND_QUEUE 5191

#define OKL4_SYSCALL_AXON_SET_SEND_SEGMENT 5192

#define OKL4_SYSCALL_AXON_TRIGGER_SEND 5185

#define OKL4_SYSCALL_DEBUG_RESUME 5208

#define OKL4_SYSCALL_DEBUG_SUSPEND 5209

#define OKL4_SYSCALL_INTERRUPT_ACK 5128

#define OKL4_SYSCALL_INTERRUPT_ATTACH_PRIVATE 5134

#define OKL4_SYSCALL_INTERRUPT_ATTACH_SHARED 5135

#define OKL4_SYSCALL_INTERRUPT_DETACH 5136

#define OKL4_SYSCALL_INTERRUPT_DIST_ENABLE 5133

#define OKL4_SYSCALL_INTERRUPT_EOI 5129

#define OKL4_SYSCALL_INTERRUPT_GET_HIGHEST_PRIORITY_PENDING 5137

#define OKL4_SYSCALL_INTERRUPT_GET_PAYLOAD 5132

#define OKL4_SYSCALL_INTERRUPT_LIMITS 5138

#define OKL4_SYSCALL_INTERRUPT_MASK 5130

#define OKL4_SYSCALL_INTERRUPT_RAISE 5145

#define OKL4_SYSCALL_INTERRUPT_SET_BINARY_POINT 5139

#define OKL4_SYSCALL_INTERRUPT_SET_CONFIG 5140

#define OKL4_SYSCALL_INTERRUPT_SET_CONTROL 5141

#define OKL4_SYSCALL_INTERRUPT_SET_PRIORITY 5142

#define OKL4_SYSCALL_INTERRUPT_SET_PRIORITY_MASK 5143

#define OKL4_SYSCALL_INTERRUPT_SET_TARGETS 5144

#define OKL4_SYSCALL_INTERRUPT_UNMASK 5131

#define OKL4_SYSCALL_KDB_INTERACT 5120

#define OKL4_SYSCALL_KDB_SET_OBJECT_NAME 5121

#define OKL4_SYSCALL_KSP_PROCEDURE_CALL 5197

#define OKL4_SYSCALL_MMU_ATTACH_SEGMENT 5152

#define OKL4_SYSCALL_MMU_DETACH_SEGMENT 5153

#define OKL4_SYSCALL_MMU_FLUSH_RANGE 5154

#define OKL4_SYSCALL_MMU_FLUSH_RANGE_PN 5155

#define OKL4_SYSCALL_MMU_LOOKUP_PAGE 5156

#define OKL4_SYSCALL_MMU_LOOKUP_PN 5157

#define OKL4_SYSCALL_MMU_MAP_PAGE 5158

#define OKL4_SYSCALL_MMU_MAP_PN 5159

#define OKL4_SYSCALL_MMU_UNMAP_PAGE 5160

#define OKL4_SYSCALL_MMU_UNMAP_PN 5161

#define OKL4_SYSCALL_MMU_UPDATE_PAGE_ATTRS 5162

#define OKL4_SYSCALL_MMU_UPDATE_PAGE_PERMS 5163

#define OKL4_SYSCALL_MMU_UPDATE_PN_ATTRS 5164

#define OKL4_SYSCALL_MMU_UPDATE_PN_PERMS 5165

#define OKL4_SYSCALL_PERFORMANCE_NULL_SYSCALL 5198

#define OKL4_SYSCALL_PIPE_CONTROL 5146

#define OKL4_SYSCALL_PIPE_RECV 5147

#define OKL4_SYSCALL_PIPE_SEND 5148

#define OKL4_SYSCALL_PRIORITY_WAIVE 5151

#define OKL4_SYSCALL_REMOTE_GET_REGISTER 5200

#define OKL4_SYSCALL_REMOTE_GET_REGISTERS 5201

#define OKL4_SYSCALL_REMOTE_READ_MEMORY32 5202

#define OKL4_SYSCALL_REMOTE_SET_REGISTER 5203

#define OKL4_SYSCALL_REMOTE_SET_REGISTERS 5204

#define OKL4_SYSCALL_REMOTE_WRITE_MEMORY32 5205

#define OKL4_SYSCALL_SCHEDULE_METRICS_STATUS_SUSPENDED 5206

#define OKL4_SYSCALL_SCHEDULE_METRICS_WATCH_SUSPENDED 5207

#define OKL4_SYSCALL_SCHEDULE_PROFILE_CPU_DISABLE 5168

#define OKL4_SYSCALL_SCHEDULE_PROFILE_CPU_ENABLE 5169

#define OKL4_SYSCALL_SCHEDULE_PROFILE_CPU_GET_DATA 5170

#define OKL4_SYSCALL_SCHEDULE_PROFILE_VCPU_DISABLE 5171

#define OKL4_SYSCALL_SCHEDULE_PROFILE_VCPU_ENABLE 5172

#define OKL4_SYSCALL_SCHEDULE_PROFILE_VCPU_GET_DATA 5173

#define OKL4_SYSCALL_SCHEDULER_AFFINITY_GET 5182

#define OKL4_SYSCALL_SCHEDULER_AFFINITY_SET 5183

#define OKL4_SYSCALL_TIMER_CANCEL 5176

#define OKL4_SYSCALL_TIMER_GET_RESOLUTION 5177

#define OKL4_SYSCALL_TIMER_GET_TIME 5178

#define OKL4_SYSCALL_TIMER_QUERY 5179

#define OKL4_SYSCALL_TIMER_START 5180

#define OKL4_SYSCALL_TRACEBUFFER_SYNC 5199

#define OKL4_SYSCALL_VCPU_RESET 5122

#define OKL4_SYSCALL_VCPU_START 5123

#define OKL4_SYSCALL_VCPU_STOP 5124

#define OKL4_SYSCALL_VCPU_SWITCH_MODE 5125

#define OKL4_SYSCALL_VCPU_SYNC_SEV 5126

#define OKL4_SYSCALL_VCPU_SYNC_WFE 5127

#define OKL4_SYSCALL_VINTERRUPT_CLEAR_AND_RAISE 5194

#define OKL4_SYSCALL_VINTERRUPT_MODIFY 5195

#define OKL4_SYSCALL_VINTERRUPT_RAISE 5196


#undef hvc

#if defined(_definitions_for_linters)



















































































#endif
#endif 

