





#ifndef __AUTO__MICROVISOR_TYPES_H__
#define __AUTO__MICROVISOR_TYPES_H__

#if !defined(ASSEMBLY)

#define OKL4_DEFAULT_PERMS OKL4_PAGE_PERMS_RWX
#define OKL4_DEFAULT_CACHE_ATTRIBUTES OKL4_PAGE_CACHE_DEFAULT

#if __SIZEOF_POINTER__ != 8
#define __ptr64(type, name) union { type name; uint64_t _x_##name; }
#define __ptr64_array(type, name) union { type val; uint64_t _x; } name
#else
#define __ptr64(type, name) type name
#define __ptr64_array(type, name) type name
#endif



typedef _Bool okl4_bool_t;











typedef uint64_t okl4_arm_mpidr_t;



OKL4_FORCE_INLINE uint64_t
okl4_arm_mpidr_getaff0(const okl4_arm_mpidr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_mpidr_setaff0(okl4_arm_mpidr_t *x, uint64_t _aff0);



OKL4_FORCE_INLINE uint64_t
okl4_arm_mpidr_getaff1(const okl4_arm_mpidr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_mpidr_setaff1(okl4_arm_mpidr_t *x, uint64_t _aff1);



OKL4_FORCE_INLINE uint64_t
okl4_arm_mpidr_getaff2(const okl4_arm_mpidr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_mpidr_setaff2(okl4_arm_mpidr_t *x, uint64_t _aff2);



OKL4_FORCE_INLINE uint64_t
okl4_arm_mpidr_getaff3(const okl4_arm_mpidr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_mpidr_setaff3(okl4_arm_mpidr_t *x, uint64_t _aff3);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_mpidr_getmt(const okl4_arm_mpidr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_mpidr_setmt(okl4_arm_mpidr_t *x, okl4_bool_t _mt);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_mpidr_getu(const okl4_arm_mpidr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_mpidr_setu(okl4_arm_mpidr_t *x, okl4_bool_t _u);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_mpidr_getmp(const okl4_arm_mpidr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_mpidr_init(okl4_arm_mpidr_t *x);


OKL4_FORCE_INLINE okl4_arm_mpidr_t
okl4_arm_mpidr_cast(uint64_t p, okl4_bool_t force);





#define OKL4_ARM_MPIDR_AFF0_MASK ((okl4_arm_mpidr_t)255U) 

#define OKL4_MASK_AFF0_ARM_MPIDR ((okl4_arm_mpidr_t)255U)

#define OKL4_SHIFT_AFF0_ARM_MPIDR (0)

#define OKL4_WIDTH_AFF0_ARM_MPIDR (8)

#define OKL4_ARM_MPIDR_AFF1_MASK ((okl4_arm_mpidr_t)255U << 8) 

#define OKL4_MASK_AFF1_ARM_MPIDR ((okl4_arm_mpidr_t)255U << 8)

#define OKL4_SHIFT_AFF1_ARM_MPIDR (8)

#define OKL4_WIDTH_AFF1_ARM_MPIDR (8)

#define OKL4_ARM_MPIDR_AFF2_MASK ((okl4_arm_mpidr_t)255U << 16) 

#define OKL4_MASK_AFF2_ARM_MPIDR ((okl4_arm_mpidr_t)255U << 16)

#define OKL4_SHIFT_AFF2_ARM_MPIDR (16)

#define OKL4_WIDTH_AFF2_ARM_MPIDR (8)

#define OKL4_ARM_MPIDR_MT_MASK ((okl4_arm_mpidr_t)1U << 24) 

#define OKL4_MASK_MT_ARM_MPIDR ((okl4_arm_mpidr_t)1U << 24)

#define OKL4_SHIFT_MT_ARM_MPIDR (24)

#define OKL4_WIDTH_MT_ARM_MPIDR (1)

#define OKL4_ARM_MPIDR_U_MASK ((okl4_arm_mpidr_t)1U << 30) 

#define OKL4_MASK_U_ARM_MPIDR ((okl4_arm_mpidr_t)1U << 30)

#define OKL4_SHIFT_U_ARM_MPIDR (30)

#define OKL4_WIDTH_U_ARM_MPIDR (1)

#define OKL4_ARM_MPIDR_MP_MASK ((okl4_arm_mpidr_t)1U << 31) 

#define OKL4_MASK_MP_ARM_MPIDR ((okl4_arm_mpidr_t)1U << 31)

#define OKL4_SHIFT_MP_ARM_MPIDR (31)

#define OKL4_WIDTH_MP_ARM_MPIDR (1)

#define OKL4_ARM_MPIDR_AFF3_MASK ((okl4_arm_mpidr_t)255U << 32) 

#define OKL4_MASK_AFF3_ARM_MPIDR ((okl4_arm_mpidr_t)255U << 32)

#define OKL4_SHIFT_AFF3_ARM_MPIDR (32)

#define OKL4_WIDTH_AFF3_ARM_MPIDR (8)





OKL4_FORCE_INLINE uint64_t
okl4_arm_mpidr_getaff0(const okl4_arm_mpidr_t *x)
{
    uint64_t field;
    union {
        
        struct {
            uint64_t field : 8;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint64_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_mpidr_setaff0(okl4_arm_mpidr_t *x, uint64_t _aff0)
{
    union {
        
        struct {
            uint64_t field : 8;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint64_t)_aff0;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint64_t
okl4_arm_mpidr_getaff1(const okl4_arm_mpidr_t *x)
{
    uint64_t field;
    union {
        
        struct {
            uint64_t _skip : 8;
            uint64_t field : 8;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint64_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_mpidr_setaff1(okl4_arm_mpidr_t *x, uint64_t _aff1)
{
    union {
        
        struct {
            uint64_t _skip : 8;
            uint64_t field : 8;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint64_t)_aff1;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint64_t
okl4_arm_mpidr_getaff2(const okl4_arm_mpidr_t *x)
{
    uint64_t field;
    union {
        
        struct {
            uint64_t _skip : 16;
            uint64_t field : 8;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint64_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_mpidr_setaff2(okl4_arm_mpidr_t *x, uint64_t _aff2)
{
    union {
        
        struct {
            uint64_t _skip : 16;
            uint64_t field : 8;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint64_t)_aff2;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_mpidr_getmt(const okl4_arm_mpidr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint64_t _skip : 24;
            _Bool field : 1;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_mpidr_setmt(okl4_arm_mpidr_t *x, okl4_bool_t _mt)
{
    union {
        
        struct {
            uint64_t _skip : 24;
            _Bool field : 1;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_mt;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_mpidr_getu(const okl4_arm_mpidr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint64_t _skip : 30;
            _Bool field : 1;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_mpidr_setu(okl4_arm_mpidr_t *x, okl4_bool_t _u)
{
    union {
        
        struct {
            uint64_t _skip : 30;
            _Bool field : 1;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_u;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_mpidr_getmp(const okl4_arm_mpidr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint64_t _skip : 31;
            _Bool field : 1;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}




OKL4_FORCE_INLINE uint64_t
okl4_arm_mpidr_getaff3(const okl4_arm_mpidr_t *x)
{
    uint64_t field;
    union {
        
        struct {
            uint64_t _skip : 32;
            uint64_t field : 8;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint64_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_mpidr_setaff3(okl4_arm_mpidr_t *x, uint64_t _aff3)
{
    union {
        
        struct {
            uint64_t _skip : 32;
            uint64_t field : 8;
        } bits;
        okl4_arm_mpidr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint64_t)_aff3;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_arm_mpidr_init(okl4_arm_mpidr_t *x)
{
    *x = (okl4_arm_mpidr_t)2147483648U;
}


OKL4_FORCE_INLINE okl4_arm_mpidr_t
okl4_arm_mpidr_cast(uint64_t p, okl4_bool_t force)
{
    okl4_arm_mpidr_t x = (okl4_arm_mpidr_t)p;
    if (force) {
        x &= ~(okl4_arm_mpidr_t)0x80000000U;
        x |= (okl4_arm_mpidr_t)0x80000000U; 
    }
    return x;
}





#define OKL4_AXON_NUM_RECEIVE_QUEUES ((uint32_t)(4U))


#define OKL4_AXON_NUM_SEND_QUEUES ((uint32_t)(4U))


#define _OKL4_POISON ((uint32_t)(3735928559U))


#define OKL4_TRACEBUFFER_INVALID_REF ((uint32_t)(0xffffffffU))




typedef uint32_t okl4_arm_psci_function_t;


#define OKL4_ARM_PSCI_FUNCTION_PSCI_VERSION ((okl4_arm_psci_function_t)0x0U)

#define OKL4_ARM_PSCI_FUNCTION_CPU_SUSPEND ((okl4_arm_psci_function_t)0x1U)

#define OKL4_ARM_PSCI_FUNCTION_CPU_OFF ((okl4_arm_psci_function_t)0x2U)

#define OKL4_ARM_PSCI_FUNCTION_CPU_ON ((okl4_arm_psci_function_t)0x3U)

#define OKL4_ARM_PSCI_FUNCTION_AFFINITY_INFO ((okl4_arm_psci_function_t)0x4U)

#define OKL4_ARM_PSCI_FUNCTION_MIGRATE ((okl4_arm_psci_function_t)0x5U)

#define OKL4_ARM_PSCI_FUNCTION_MIGRATE_INFO_TYPE ((okl4_arm_psci_function_t)0x6U)

#define OKL4_ARM_PSCI_FUNCTION_MIGRATE_INFO_UP_CPU ((okl4_arm_psci_function_t)0x7U)

#define OKL4_ARM_PSCI_FUNCTION_SYSTEM_OFF ((okl4_arm_psci_function_t)0x8U)

#define OKL4_ARM_PSCI_FUNCTION_SYSTEM_RESET ((okl4_arm_psci_function_t)0x9U)

#define OKL4_ARM_PSCI_FUNCTION_PSCI_FEATURES ((okl4_arm_psci_function_t)0xaU)

#define OKL4_ARM_PSCI_FUNCTION_CPU_FREEZE ((okl4_arm_psci_function_t)0xbU)

#define OKL4_ARM_PSCI_FUNCTION_CPU_DEFAULT_SUSPEND ((okl4_arm_psci_function_t)0xcU)

#define OKL4_ARM_PSCI_FUNCTION_NODE_HW_STATE ((okl4_arm_psci_function_t)0xdU)

#define OKL4_ARM_PSCI_FUNCTION_SYSTEM_SUSPEND ((okl4_arm_psci_function_t)0xeU)

#define OKL4_ARM_PSCI_FUNCTION_PSCI_SET_SUSPEND_MODE ((okl4_arm_psci_function_t)0xfU)

#define OKL4_ARM_PSCI_FUNCTION_PSCI_STAT_RESIDENCY ((okl4_arm_psci_function_t)0x10U)

#define OKL4_ARM_PSCI_FUNCTION_PSCI_STAT_COUNT ((okl4_arm_psci_function_t)0x11U)

#define OKL4_ARM_PSCI_FUNCTION_SYSTEM_RESET2 ((okl4_arm_psci_function_t)0x12U)

#define OKL4_ARM_PSCI_FUNCTION_MEM_PROTECT ((okl4_arm_psci_function_t)0x13U)

#define OKL4_ARM_PSCI_FUNCTION_MEM_PROTECT_CHECK_RANGE ((okl4_arm_psci_function_t)0x14U)


OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_psci_function_is_element_of(okl4_arm_psci_function_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_psci_function_is_element_of(okl4_arm_psci_function_t var)
{
    
    
    return ((var == OKL4_ARM_PSCI_FUNCTION_PSCI_VERSION) ||
            (var == OKL4_ARM_PSCI_FUNCTION_CPU_SUSPEND) ||
            (var == OKL4_ARM_PSCI_FUNCTION_CPU_OFF) ||
            (var == OKL4_ARM_PSCI_FUNCTION_CPU_ON) ||
            (var == OKL4_ARM_PSCI_FUNCTION_AFFINITY_INFO) ||
            (var == OKL4_ARM_PSCI_FUNCTION_MIGRATE) ||
            (var == OKL4_ARM_PSCI_FUNCTION_MIGRATE_INFO_TYPE) ||
            (var == OKL4_ARM_PSCI_FUNCTION_MIGRATE_INFO_UP_CPU) ||
            (var == OKL4_ARM_PSCI_FUNCTION_SYSTEM_OFF) ||
            (var == OKL4_ARM_PSCI_FUNCTION_SYSTEM_RESET) ||
            (var == OKL4_ARM_PSCI_FUNCTION_PSCI_FEATURES) ||
            (var == OKL4_ARM_PSCI_FUNCTION_CPU_FREEZE) ||
            (var == OKL4_ARM_PSCI_FUNCTION_CPU_DEFAULT_SUSPEND) ||
            (var == OKL4_ARM_PSCI_FUNCTION_NODE_HW_STATE) ||
            (var == OKL4_ARM_PSCI_FUNCTION_SYSTEM_SUSPEND) ||
            (var == OKL4_ARM_PSCI_FUNCTION_PSCI_SET_SUSPEND_MODE) ||
            (var == OKL4_ARM_PSCI_FUNCTION_PSCI_STAT_RESIDENCY) ||
            (var == OKL4_ARM_PSCI_FUNCTION_PSCI_STAT_COUNT) ||
            (var == OKL4_ARM_PSCI_FUNCTION_SYSTEM_RESET2) ||
            (var == OKL4_ARM_PSCI_FUNCTION_MEM_PROTECT) ||
            (var == OKL4_ARM_PSCI_FUNCTION_MEM_PROTECT_CHECK_RANGE));
}



typedef uint32_t okl4_arm_psci_result_t;


#define OKL4_ARM_PSCI_RESULT_SUCCESS ((okl4_arm_psci_result_t)0x0U)

#define OKL4_ARM_PSCI_RESULT_INVALID_ADDRESS ((okl4_arm_psci_result_t)0xfffffff7U)

#define OKL4_ARM_PSCI_RESULT_DISABLED ((okl4_arm_psci_result_t)0xfffffff8U)

#define OKL4_ARM_PSCI_RESULT_NOT_PRESENT ((okl4_arm_psci_result_t)0xfffffff9U)

#define OKL4_ARM_PSCI_RESULT_INTERNAL_FAILURE ((okl4_arm_psci_result_t)0xfffffffaU)

#define OKL4_ARM_PSCI_RESULT_ON_PENDING ((okl4_arm_psci_result_t)0xfffffffbU)

#define OKL4_ARM_PSCI_RESULT_ALREADY_ON ((okl4_arm_psci_result_t)0xfffffffcU)

#define OKL4_ARM_PSCI_RESULT_DENIED ((okl4_arm_psci_result_t)0xfffffffdU)

#define OKL4_ARM_PSCI_RESULT_INVALID_PARAMETERS ((okl4_arm_psci_result_t)0xfffffffeU)

#define OKL4_ARM_PSCI_RESULT_NOT_SUPPORTED ((okl4_arm_psci_result_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_psci_result_is_element_of(okl4_arm_psci_result_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_psci_result_is_element_of(okl4_arm_psci_result_t var)
{
    
    
    return ((var == OKL4_ARM_PSCI_RESULT_SUCCESS) ||
            (var == OKL4_ARM_PSCI_RESULT_NOT_SUPPORTED) ||
            (var == OKL4_ARM_PSCI_RESULT_INVALID_PARAMETERS) ||
            (var == OKL4_ARM_PSCI_RESULT_DENIED) ||
            (var == OKL4_ARM_PSCI_RESULT_ALREADY_ON) ||
            (var == OKL4_ARM_PSCI_RESULT_ON_PENDING) ||
            (var == OKL4_ARM_PSCI_RESULT_INTERNAL_FAILURE) ||
            (var == OKL4_ARM_PSCI_RESULT_NOT_PRESENT) ||
            (var == OKL4_ARM_PSCI_RESULT_DISABLED) ||
            (var == OKL4_ARM_PSCI_RESULT_INVALID_ADDRESS));
}





typedef uint32_t okl4_arm_sctlr_t;



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getmmuenable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setmmuenable(okl4_arm_sctlr_t *x, okl4_bool_t _mmu_enable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getalignmentcheckenable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setalignmentcheckenable(okl4_arm_sctlr_t *x, okl4_bool_t _alignment_check_enable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getdatacacheenable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setdatacacheenable(okl4_arm_sctlr_t *x, okl4_bool_t _data_cache_enable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getinstructioncacheenable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setinstructioncacheenable(okl4_arm_sctlr_t *x, okl4_bool_t _instruction_cache_enable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getcp15barrierenable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setcp15barrierenable(okl4_arm_sctlr_t *x, okl4_bool_t _cp15_barrier_enable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getitdisable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setitdisable(okl4_arm_sctlr_t *x, okl4_bool_t _it_disable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getsetenddisable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setsetenddisable(okl4_arm_sctlr_t *x, okl4_bool_t _setend_disable);



OKL4_FORCE_INLINE uint32_t
okl4_arm_sctlr_getreserved11(const okl4_arm_sctlr_t *x);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getnotrapwfi(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setnotrapwfi(okl4_arm_sctlr_t *x, okl4_bool_t _no_trap_wfi);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getnotrapwfe(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setnotrapwfe(okl4_arm_sctlr_t *x, okl4_bool_t _no_trap_wfe);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getwriteexecnever(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setwriteexecnever(okl4_arm_sctlr_t *x, okl4_bool_t _write_exec_never);



OKL4_FORCE_INLINE uint32_t
okl4_arm_sctlr_getreserved22(const okl4_arm_sctlr_t *x);



OKL4_FORCE_INLINE uint32_t
okl4_arm_sctlr_getspan(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setspan(okl4_arm_sctlr_t *x, uint32_t _span);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getel0endianness(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setel0endianness(okl4_arm_sctlr_t *x, okl4_bool_t _el0_endianness);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getexceptionendianness(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setexceptionendianness(okl4_arm_sctlr_t *x, okl4_bool_t _exception_endianness);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getvectorsbit(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setvectorsbit(okl4_arm_sctlr_t *x, okl4_bool_t _vectors_bit);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getuserwriteexecnever(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setuserwriteexecnever(okl4_arm_sctlr_t *x, okl4_bool_t _user_write_exec_never);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_gettexremapenable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_settexremapenable(okl4_arm_sctlr_t *x, okl4_bool_t _tex_remap_enable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getaccessflagenable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setaccessflagenable(okl4_arm_sctlr_t *x, okl4_bool_t _access_flag_enable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getthumbexceptionenable(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setthumbexceptionenable(okl4_arm_sctlr_t *x, okl4_bool_t _thumb_exception_enable);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getstackalign(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setstackalign(okl4_arm_sctlr_t *x, okl4_bool_t _stack_align);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getstackalignel0(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setstackalignel0(okl4_arm_sctlr_t *x, okl4_bool_t _stack_align_el0);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getusermaskaccess(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setusermaskaccess(okl4_arm_sctlr_t *x, okl4_bool_t _user_mask_access);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getdcachezero(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setdcachezero(okl4_arm_sctlr_t *x, okl4_bool_t _dcache_zero);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getusercachetype(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setusercachetype(okl4_arm_sctlr_t *x, okl4_bool_t _user_cache_type);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getoklhcrel2dc(const okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_setoklhcrel2dc(okl4_arm_sctlr_t *x, okl4_bool_t _okl_hcr_el2_dc);


OKL4_FORCE_INLINE void
okl4_arm_sctlr_init(okl4_arm_sctlr_t *x);


OKL4_FORCE_INLINE okl4_arm_sctlr_t
okl4_arm_sctlr_cast(uint32_t p, okl4_bool_t force);





#define OKL4_ARM_SCTLR_MMU_ENABLE_MASK ((okl4_arm_sctlr_t)1U) 

#define OKL4_MASK_MMU_ENABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U)

#define OKL4_SHIFT_MMU_ENABLE_ARM_SCTLR (0)

#define OKL4_WIDTH_MMU_ENABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_ALIGNMENT_CHECK_ENABLE_MASK ((okl4_arm_sctlr_t)1U << 1) 

#define OKL4_MASK_ALIGNMENT_CHECK_ENABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 1)

#define OKL4_SHIFT_ALIGNMENT_CHECK_ENABLE_ARM_SCTLR (1)

#define OKL4_WIDTH_ALIGNMENT_CHECK_ENABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_DATA_CACHE_ENABLE_MASK ((okl4_arm_sctlr_t)1U << 2) 

#define OKL4_MASK_DATA_CACHE_ENABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 2)

#define OKL4_SHIFT_DATA_CACHE_ENABLE_ARM_SCTLR (2)

#define OKL4_WIDTH_DATA_CACHE_ENABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_STACK_ALIGN_MASK ((okl4_arm_sctlr_t)1U << 3) 

#define OKL4_MASK_STACK_ALIGN_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 3)

#define OKL4_SHIFT_STACK_ALIGN_ARM_SCTLR (3)

#define OKL4_WIDTH_STACK_ALIGN_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_STACK_ALIGN_EL0_MASK ((okl4_arm_sctlr_t)1U << 4) 

#define OKL4_MASK_STACK_ALIGN_EL0_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 4)

#define OKL4_SHIFT_STACK_ALIGN_EL0_ARM_SCTLR (4)

#define OKL4_WIDTH_STACK_ALIGN_EL0_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_CP15_BARRIER_ENABLE_MASK ((okl4_arm_sctlr_t)1U << 5) 

#define OKL4_MASK_CP15_BARRIER_ENABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 5)

#define OKL4_SHIFT_CP15_BARRIER_ENABLE_ARM_SCTLR (5)

#define OKL4_WIDTH_CP15_BARRIER_ENABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_OKL_HCR_EL2_DC_MASK ((okl4_arm_sctlr_t)1U << 6) 

#define OKL4_MASK_OKL_HCR_EL2_DC_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 6)

#define OKL4_SHIFT_OKL_HCR_EL2_DC_ARM_SCTLR (6)

#define OKL4_WIDTH_OKL_HCR_EL2_DC_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_IT_DISABLE_MASK ((okl4_arm_sctlr_t)1U << 7) 

#define OKL4_MASK_IT_DISABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 7)

#define OKL4_SHIFT_IT_DISABLE_ARM_SCTLR (7)

#define OKL4_WIDTH_IT_DISABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_SETEND_DISABLE_MASK ((okl4_arm_sctlr_t)1U << 8) 

#define OKL4_MASK_SETEND_DISABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 8)

#define OKL4_SHIFT_SETEND_DISABLE_ARM_SCTLR (8)

#define OKL4_WIDTH_SETEND_DISABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_USER_MASK_ACCESS_MASK ((okl4_arm_sctlr_t)1U << 9) 

#define OKL4_MASK_USER_MASK_ACCESS_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 9)

#define OKL4_SHIFT_USER_MASK_ACCESS_ARM_SCTLR (9)

#define OKL4_WIDTH_USER_MASK_ACCESS_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_RESERVED11_MASK ((okl4_arm_sctlr_t)1U << 11) 

#define OKL4_MASK_RESERVED11_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 11)

#define OKL4_SHIFT_RESERVED11_ARM_SCTLR (11)

#define OKL4_WIDTH_RESERVED11_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_INSTRUCTION_CACHE_ENABLE_MASK ((okl4_arm_sctlr_t)1U << 12) 

#define OKL4_MASK_INSTRUCTION_CACHE_ENABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 12)

#define OKL4_SHIFT_INSTRUCTION_CACHE_ENABLE_ARM_SCTLR (12)

#define OKL4_WIDTH_INSTRUCTION_CACHE_ENABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_VECTORS_BIT_MASK ((okl4_arm_sctlr_t)1U << 13) 

#define OKL4_MASK_VECTORS_BIT_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 13)

#define OKL4_SHIFT_VECTORS_BIT_ARM_SCTLR (13)

#define OKL4_WIDTH_VECTORS_BIT_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_DCACHE_ZERO_MASK ((okl4_arm_sctlr_t)1U << 14) 

#define OKL4_MASK_DCACHE_ZERO_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 14)

#define OKL4_SHIFT_DCACHE_ZERO_ARM_SCTLR (14)

#define OKL4_WIDTH_DCACHE_ZERO_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_USER_CACHE_TYPE_MASK ((okl4_arm_sctlr_t)1U << 15) 

#define OKL4_MASK_USER_CACHE_TYPE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 15)

#define OKL4_SHIFT_USER_CACHE_TYPE_ARM_SCTLR (15)

#define OKL4_WIDTH_USER_CACHE_TYPE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_NO_TRAP_WFI_MASK ((okl4_arm_sctlr_t)1U << 16) 

#define OKL4_MASK_NO_TRAP_WFI_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 16)

#define OKL4_SHIFT_NO_TRAP_WFI_ARM_SCTLR (16)

#define OKL4_WIDTH_NO_TRAP_WFI_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_NO_TRAP_WFE_MASK ((okl4_arm_sctlr_t)1U << 18) 

#define OKL4_MASK_NO_TRAP_WFE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 18)

#define OKL4_SHIFT_NO_TRAP_WFE_ARM_SCTLR (18)

#define OKL4_WIDTH_NO_TRAP_WFE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_WRITE_EXEC_NEVER_MASK ((okl4_arm_sctlr_t)1U << 19) 

#define OKL4_MASK_WRITE_EXEC_NEVER_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 19)

#define OKL4_SHIFT_WRITE_EXEC_NEVER_ARM_SCTLR (19)

#define OKL4_WIDTH_WRITE_EXEC_NEVER_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_USER_WRITE_EXEC_NEVER_MASK ((okl4_arm_sctlr_t)1U << 20) 

#define OKL4_MASK_USER_WRITE_EXEC_NEVER_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 20)

#define OKL4_SHIFT_USER_WRITE_EXEC_NEVER_ARM_SCTLR (20)

#define OKL4_WIDTH_USER_WRITE_EXEC_NEVER_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_RESERVED22_MASK ((okl4_arm_sctlr_t)1U << 22) 

#define OKL4_MASK_RESERVED22_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 22)

#define OKL4_SHIFT_RESERVED22_ARM_SCTLR (22)

#define OKL4_WIDTH_RESERVED22_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_SPAN_MASK ((okl4_arm_sctlr_t)1U << 23) 

#define OKL4_MASK_SPAN_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 23)

#define OKL4_SHIFT_SPAN_ARM_SCTLR (23)

#define OKL4_WIDTH_SPAN_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_EL0_ENDIANNESS_MASK ((okl4_arm_sctlr_t)1U << 24) 

#define OKL4_MASK_EL0_ENDIANNESS_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 24)

#define OKL4_SHIFT_EL0_ENDIANNESS_ARM_SCTLR (24)

#define OKL4_WIDTH_EL0_ENDIANNESS_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_EXCEPTION_ENDIANNESS_MASK ((okl4_arm_sctlr_t)1U << 25) 

#define OKL4_MASK_EXCEPTION_ENDIANNESS_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 25)

#define OKL4_SHIFT_EXCEPTION_ENDIANNESS_ARM_SCTLR (25)

#define OKL4_WIDTH_EXCEPTION_ENDIANNESS_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_TEX_REMAP_ENABLE_MASK ((okl4_arm_sctlr_t)1U << 28) 

#define OKL4_MASK_TEX_REMAP_ENABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 28)

#define OKL4_SHIFT_TEX_REMAP_ENABLE_ARM_SCTLR (28)

#define OKL4_WIDTH_TEX_REMAP_ENABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_ACCESS_FLAG_ENABLE_MASK ((okl4_arm_sctlr_t)1U << 29) 

#define OKL4_MASK_ACCESS_FLAG_ENABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 29)

#define OKL4_SHIFT_ACCESS_FLAG_ENABLE_ARM_SCTLR (29)

#define OKL4_WIDTH_ACCESS_FLAG_ENABLE_ARM_SCTLR (1)

#define OKL4_ARM_SCTLR_THUMB_EXCEPTION_ENABLE_MASK ((okl4_arm_sctlr_t)1U << 30) 

#define OKL4_MASK_THUMB_EXCEPTION_ENABLE_ARM_SCTLR ((okl4_arm_sctlr_t)1U << 30)

#define OKL4_SHIFT_THUMB_EXCEPTION_ENABLE_ARM_SCTLR (30)

#define OKL4_WIDTH_THUMB_EXCEPTION_ENABLE_ARM_SCTLR (1)





OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getmmuenable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setmmuenable(okl4_arm_sctlr_t *x, okl4_bool_t _mmu_enable)
{
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_mmu_enable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getalignmentcheckenable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setalignmentcheckenable(okl4_arm_sctlr_t *x, okl4_bool_t _alignment_check_enable)
{
    union {
        
        struct {
            uint32_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_alignment_check_enable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getdatacacheenable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 2;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setdatacacheenable(okl4_arm_sctlr_t *x, okl4_bool_t _data_cache_enable)
{
    union {
        
        struct {
            uint32_t _skip : 2;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_data_cache_enable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getstackalign(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 3;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setstackalign(okl4_arm_sctlr_t *x, okl4_bool_t _stack_align)
{
    union {
        
        struct {
            uint32_t _skip : 3;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_stack_align;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getstackalignel0(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 4;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setstackalignel0(okl4_arm_sctlr_t *x, okl4_bool_t _stack_align_el0)
{
    union {
        
        struct {
            uint32_t _skip : 4;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_stack_align_el0;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getcp15barrierenable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 5;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setcp15barrierenable(okl4_arm_sctlr_t *x, okl4_bool_t _cp15_barrier_enable)
{
    union {
        
        struct {
            uint32_t _skip : 5;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_cp15_barrier_enable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getoklhcrel2dc(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 6;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setoklhcrel2dc(okl4_arm_sctlr_t *x, okl4_bool_t _okl_hcr_el2_dc)
{
    union {
        
        struct {
            uint32_t _skip : 6;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_okl_hcr_el2_dc;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getitdisable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 7;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setitdisable(okl4_arm_sctlr_t *x, okl4_bool_t _it_disable)
{
    union {
        
        struct {
            uint32_t _skip : 7;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_it_disable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getsetenddisable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 8;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setsetenddisable(okl4_arm_sctlr_t *x, okl4_bool_t _setend_disable)
{
    union {
        
        struct {
            uint32_t _skip : 8;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_setend_disable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getusermaskaccess(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 9;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setusermaskaccess(okl4_arm_sctlr_t *x, okl4_bool_t _user_mask_access)
{
    union {
        
        struct {
            uint32_t _skip : 9;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_user_mask_access;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
okl4_arm_sctlr_getreserved11(const okl4_arm_sctlr_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 11;
            uint32_t field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}




OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getinstructioncacheenable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 12;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setinstructioncacheenable(okl4_arm_sctlr_t *x, okl4_bool_t _instruction_cache_enable)
{
    union {
        
        struct {
            uint32_t _skip : 12;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_instruction_cache_enable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getvectorsbit(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 13;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setvectorsbit(okl4_arm_sctlr_t *x, okl4_bool_t _vectors_bit)
{
    union {
        
        struct {
            uint32_t _skip : 13;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_vectors_bit;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getdcachezero(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 14;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setdcachezero(okl4_arm_sctlr_t *x, okl4_bool_t _dcache_zero)
{
    union {
        
        struct {
            uint32_t _skip : 14;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_dcache_zero;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getusercachetype(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 15;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setusercachetype(okl4_arm_sctlr_t *x, okl4_bool_t _user_cache_type)
{
    union {
        
        struct {
            uint32_t _skip : 15;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_user_cache_type;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getnotrapwfi(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 16;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setnotrapwfi(okl4_arm_sctlr_t *x, okl4_bool_t _no_trap_wfi)
{
    union {
        
        struct {
            uint32_t _skip : 16;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_no_trap_wfi;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getnotrapwfe(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 18;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setnotrapwfe(okl4_arm_sctlr_t *x, okl4_bool_t _no_trap_wfe)
{
    union {
        
        struct {
            uint32_t _skip : 18;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_no_trap_wfe;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getwriteexecnever(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 19;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setwriteexecnever(okl4_arm_sctlr_t *x, okl4_bool_t _write_exec_never)
{
    union {
        
        struct {
            uint32_t _skip : 19;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_write_exec_never;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getuserwriteexecnever(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 20;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setuserwriteexecnever(okl4_arm_sctlr_t *x, okl4_bool_t _user_write_exec_never)
{
    union {
        
        struct {
            uint32_t _skip : 20;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_user_write_exec_never;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
okl4_arm_sctlr_getreserved22(const okl4_arm_sctlr_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 22;
            uint32_t field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}




OKL4_FORCE_INLINE uint32_t
okl4_arm_sctlr_getspan(const okl4_arm_sctlr_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 23;
            uint32_t field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setspan(okl4_arm_sctlr_t *x, uint32_t _span)
{
    union {
        
        struct {
            uint32_t _skip : 23;
            uint32_t field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_span;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getel0endianness(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 24;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setel0endianness(okl4_arm_sctlr_t *x, okl4_bool_t _el0_endianness)
{
    union {
        
        struct {
            uint32_t _skip : 24;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_el0_endianness;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getexceptionendianness(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 25;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setexceptionendianness(okl4_arm_sctlr_t *x, okl4_bool_t _exception_endianness)
{
    union {
        
        struct {
            uint32_t _skip : 25;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_exception_endianness;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_gettexremapenable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 28;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_settexremapenable(okl4_arm_sctlr_t *x, okl4_bool_t _tex_remap_enable)
{
    union {
        
        struct {
            uint32_t _skip : 28;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_tex_remap_enable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getaccessflagenable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 29;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setaccessflagenable(okl4_arm_sctlr_t *x, okl4_bool_t _access_flag_enable)
{
    union {
        
        struct {
            uint32_t _skip : 29;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_access_flag_enable;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_sctlr_getthumbexceptionenable(const okl4_arm_sctlr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 30;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_arm_sctlr_setthumbexceptionenable(okl4_arm_sctlr_t *x, okl4_bool_t _thumb_exception_enable)
{
    union {
        
        struct {
            uint32_t _skip : 30;
            _Bool field : 1;
        } bits;
        okl4_arm_sctlr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_thumb_exception_enable;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_arm_sctlr_init(okl4_arm_sctlr_t *x)
{
    *x = (okl4_arm_sctlr_t)12912928U;
}


OKL4_FORCE_INLINE okl4_arm_sctlr_t
okl4_arm_sctlr_cast(uint32_t p, okl4_bool_t force)
{
    okl4_arm_sctlr_t x = (okl4_arm_sctlr_t)p;
    if (force) {
        x &= ~(okl4_arm_sctlr_t)0x800U;
        x |= (okl4_arm_sctlr_t)0x800U; 
        x &= ~(okl4_arm_sctlr_t)0x400000U;
        x |= (okl4_arm_sctlr_t)0x400000U; 
    }
    return x;
}




typedef uint32_t okl4_arm_smccc_arch_function_t;


#define OKL4_ARM_SMCCC_ARCH_FUNCTION_SMCCC_VERSION ((okl4_arm_smccc_arch_function_t)0x0U)

#define OKL4_ARM_SMCCC_ARCH_FUNCTION_ARCH_FEATURES ((okl4_arm_smccc_arch_function_t)0x1U)

#define OKL4_ARM_SMCCC_ARCH_FUNCTION_ARCH_WORKAROUND_1 ((okl4_arm_smccc_arch_function_t)0x8000U)


OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_smccc_arch_function_is_element_of(okl4_arm_smccc_arch_function_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_smccc_arch_function_is_element_of(okl4_arm_smccc_arch_function_t var)
{
    
    
    return ((var == OKL4_ARM_SMCCC_ARCH_FUNCTION_SMCCC_VERSION) ||
            (var == OKL4_ARM_SMCCC_ARCH_FUNCTION_ARCH_FEATURES) ||
            (var == OKL4_ARM_SMCCC_ARCH_FUNCTION_ARCH_WORKAROUND_1));
}



typedef uint32_t okl4_arm_smccc_result_t;


#define OKL4_ARM_SMCCC_RESULT_SUCCESS ((okl4_arm_smccc_result_t)0x0U)

#define OKL4_ARM_SMCCC_RESULT_NOT_SUPPORTED ((okl4_arm_smccc_result_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_smccc_result_is_element_of(okl4_arm_smccc_result_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_arm_smccc_result_is_element_of(okl4_arm_smccc_result_t var)
{
    
    
    return ((var == OKL4_ARM_SMCCC_RESULT_SUCCESS) ||
            (var == OKL4_ARM_SMCCC_RESULT_NOT_SUPPORTED));
}




typedef uint64_t okl4_register_t;





typedef okl4_register_t okl4_atomic_raw_register_t;









typedef uint16_t okl4_atomic_raw_uint16_t;





typedef uint32_t okl4_atomic_raw_uint32_t;





typedef uint64_t okl4_atomic_raw_uint64_t;









typedef uint8_t okl4_atomic_raw_uint8_t;






struct okl4_atomic_register {
    volatile okl4_atomic_raw_register_t value;
};








typedef struct okl4_atomic_register okl4_atomic_register_t;






struct okl4_atomic_uint16 {
    volatile okl4_atomic_raw_uint16_t value;
};








typedef struct okl4_atomic_uint16 okl4_atomic_uint16_t;






struct okl4_atomic_uint32 {
    volatile okl4_atomic_raw_uint32_t value;
};








typedef struct okl4_atomic_uint32 okl4_atomic_uint32_t;






struct okl4_atomic_uint64 {
    volatile okl4_atomic_raw_uint64_t value;
};








typedef struct okl4_atomic_uint64 okl4_atomic_uint64_t;






struct okl4_atomic_uint8 {
    volatile okl4_atomic_raw_uint8_t value;
};








typedef struct okl4_atomic_uint8 okl4_atomic_uint8_t;






typedef uint32_t okl4_count_t;


#define OKL4_DEFAULT_PAGEBITS ((okl4_count_t)(12U))



#define OKL4_KMMU_LOOKUP_PAGE_SEGMENT_MASK ((okl4_count_t)(1023U))



#define OKL4_KMMU_MAX_SEGMENTS ((okl4_count_t)(256U))


#define OKL4_PROFILE_NO_PCPUS ((okl4_count_t)(0xffffffffU))





typedef okl4_count_t okl4_kcap_t;


#define OKL4_KCAP_INVALID ((okl4_kcap_t)(0xffffffffU))





typedef okl4_count_t okl4_interrupt_number_t;


#define OKL4_INTERRUPT_INVALID_IRQ ((okl4_interrupt_number_t)(1023U))


#define OKL4_INVALID_VIRQ ((okl4_interrupt_number_t)(1023U))




typedef okl4_interrupt_number_t okl4_irq_t;






struct okl4_axon_data {
    okl4_kcap_t kcap;
    okl4_kcap_t segment;
    okl4_irq_t virq;
};






typedef okl4_register_t okl4_psize_t;






typedef okl4_psize_t okl4_lsize_t;


#define OKL4_DEFAULT_PAGESIZE ((okl4_lsize_t)(4096U))





typedef okl4_lsize_t okl4_laddr_t;


#define OKL4_USER_AREA_END ((okl4_laddr_t)(17592186044416U))






typedef okl4_laddr_t okl4_axon_data_info_t;



OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_data_info_getpending(const okl4_axon_data_info_t *x);


OKL4_FORCE_INLINE void
okl4_axon_data_info_setpending(okl4_axon_data_info_t *x, okl4_bool_t _pending);



OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_data_info_getfailure(const okl4_axon_data_info_t *x);


OKL4_FORCE_INLINE void
okl4_axon_data_info_setfailure(okl4_axon_data_info_t *x, okl4_bool_t _failure);



OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_data_info_getusr(const okl4_axon_data_info_t *x);


OKL4_FORCE_INLINE void
okl4_axon_data_info_setusr(okl4_axon_data_info_t *x, okl4_bool_t _usr);



OKL4_FORCE_INLINE okl4_laddr_t
okl4_axon_data_info_getladdr(const okl4_axon_data_info_t *x);


OKL4_FORCE_INLINE void
okl4_axon_data_info_setladdr(okl4_axon_data_info_t *x, okl4_laddr_t _laddr);


OKL4_FORCE_INLINE void
okl4_axon_data_info_init(okl4_axon_data_info_t *x);


OKL4_FORCE_INLINE okl4_axon_data_info_t
okl4_axon_data_info_cast(uint64_t p, okl4_bool_t force);





#define OKL4_AXON_DATA_INFO_PENDING_MASK ((okl4_axon_data_info_t)1U) 

#define OKL4_MASK_PENDING_AXON_DATA_INFO ((okl4_axon_data_info_t)1U)

#define OKL4_SHIFT_PENDING_AXON_DATA_INFO (0)

#define OKL4_WIDTH_PENDING_AXON_DATA_INFO (1)

#define OKL4_AXON_DATA_INFO_FAILURE_MASK ((okl4_axon_data_info_t)1U << 1) 

#define OKL4_MASK_FAILURE_AXON_DATA_INFO ((okl4_axon_data_info_t)1U << 1)

#define OKL4_SHIFT_FAILURE_AXON_DATA_INFO (1)

#define OKL4_WIDTH_FAILURE_AXON_DATA_INFO (1)

#define OKL4_AXON_DATA_INFO_USR_MASK ((okl4_axon_data_info_t)1U << 2) 

#define OKL4_MASK_USR_AXON_DATA_INFO ((okl4_axon_data_info_t)1U << 2)

#define OKL4_SHIFT_USR_AXON_DATA_INFO (2)

#define OKL4_WIDTH_USR_AXON_DATA_INFO (1)

#define OKL4_AXON_DATA_INFO_LADDR_MASK ((okl4_axon_data_info_t)2305843009213693951U << 3) 

#define OKL4_MASK_LADDR_AXON_DATA_INFO ((okl4_axon_data_info_t)2305843009213693951U << 3)

#define OKL4_SHIFT_LADDR_AXON_DATA_INFO (3)

#define OKL4_PRESHIFT_LADDR_AXON_DATA_INFO (3)

#define OKL4_WIDTH_LADDR_AXON_DATA_INFO (61)





OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_data_info_getpending(const okl4_axon_data_info_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_axon_data_info_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_axon_data_info_setpending(okl4_axon_data_info_t *x, okl4_bool_t _pending)
{
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_axon_data_info_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_pending;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_data_info_getfailure(const okl4_axon_data_info_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint64_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_axon_data_info_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_axon_data_info_setfailure(okl4_axon_data_info_t *x, okl4_bool_t _failure)
{
    union {
        
        struct {
            uint64_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_axon_data_info_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_failure;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_data_info_getusr(const okl4_axon_data_info_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint64_t _skip : 2;
            _Bool field : 1;
        } bits;
        okl4_axon_data_info_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_axon_data_info_setusr(okl4_axon_data_info_t *x, okl4_bool_t _usr)
{
    union {
        
        struct {
            uint64_t _skip : 2;
            _Bool field : 1;
        } bits;
        okl4_axon_data_info_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_usr;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_laddr_t
okl4_axon_data_info_getladdr(const okl4_axon_data_info_t *x)
{
    okl4_laddr_t field;
    union {
        
        struct {
            uint64_t _skip : 3;
            uint64_t field : 61;
        } bits;
        okl4_axon_data_info_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_laddr_t)_conv.bits.field;
    return (okl4_laddr_t)(field << 3);
}




OKL4_FORCE_INLINE void
okl4_axon_data_info_setladdr(okl4_axon_data_info_t *x, okl4_laddr_t _laddr)
{
    okl4_laddr_t val = _laddr >> 3;
    union {
        
        struct {
            uint64_t _skip : 3;
            uint64_t field : 61;
        } bits;
        okl4_axon_data_info_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint64_t)val;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_axon_data_info_init(okl4_axon_data_info_t *x)
{
    *x = (okl4_axon_data_info_t)0U;
}


OKL4_FORCE_INLINE okl4_axon_data_info_t
okl4_axon_data_info_cast(uint64_t p, okl4_bool_t force)
{
    okl4_axon_data_info_t x = (okl4_axon_data_info_t)p;
    (void)force;
    return x;
}





struct okl4_axon_ep_data {
    struct okl4_axon_data rx;
    struct okl4_axon_data tx;
};









typedef char _okl4_padding_t;





struct okl4_axon_queue {
    uint32_t queue_offset;
    uint16_t entries;
    volatile uint16_t kptr;
    volatile uint16_t uptr;
    _okl4_padding_t __padding0_2; 
    _okl4_padding_t __padding1_3; 
};








typedef okl4_lsize_t okl4_ksize_t;





struct okl4_axon_queue_entry {
    okl4_axon_data_info_t info;
    okl4_ksize_t data_size;
    uint32_t recv_sequence;
    _okl4_padding_t __padding0_4; 
    _okl4_padding_t __padding1_5; 
    _okl4_padding_t __padding2_6; 
    _okl4_padding_t __padding3_7; 
};









typedef uint16_t okl4_axon_queue_size_t;



OKL4_FORCE_INLINE okl4_count_t
okl4_axon_queue_size_getallocorder(const okl4_axon_queue_size_t *x);


OKL4_FORCE_INLINE void
okl4_axon_queue_size_setallocorder(okl4_axon_queue_size_t *x, okl4_count_t _alloc_order);



OKL4_FORCE_INLINE okl4_count_t
okl4_axon_queue_size_getminorder(const okl4_axon_queue_size_t *x);


OKL4_FORCE_INLINE void
okl4_axon_queue_size_setminorder(okl4_axon_queue_size_t *x, okl4_count_t _min_order);


OKL4_FORCE_INLINE void
okl4_axon_queue_size_init(okl4_axon_queue_size_t *x);


OKL4_FORCE_INLINE okl4_axon_queue_size_t
okl4_axon_queue_size_cast(uint16_t p, okl4_bool_t force);





#define OKL4_AXON_QUEUE_SIZE_ALLOC_ORDER_MASK (okl4_axon_queue_size_t)(31U) 

#define OKL4_MASK_ALLOC_ORDER_AXON_QUEUE_SIZE (okl4_axon_queue_size_t)(31U)

#define OKL4_SHIFT_ALLOC_ORDER_AXON_QUEUE_SIZE (0)

#define OKL4_WIDTH_ALLOC_ORDER_AXON_QUEUE_SIZE (5)

#define OKL4_AXON_QUEUE_SIZE_MIN_ORDER_MASK (okl4_axon_queue_size_t)(31U << 8) 

#define OKL4_MASK_MIN_ORDER_AXON_QUEUE_SIZE (okl4_axon_queue_size_t)(31U << 8)

#define OKL4_SHIFT_MIN_ORDER_AXON_QUEUE_SIZE (8)

#define OKL4_WIDTH_MIN_ORDER_AXON_QUEUE_SIZE (5)





OKL4_FORCE_INLINE okl4_count_t
okl4_axon_queue_size_getallocorder(const okl4_axon_queue_size_t *x)
{
    okl4_count_t field;
    union {
        
        struct {
            uint32_t field : 5;
        } bits;
        okl4_axon_queue_size_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_count_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_axon_queue_size_setallocorder(okl4_axon_queue_size_t *x, okl4_count_t _alloc_order)
{
    union {
        
        struct {
            uint32_t field : 5;
        } bits;
        okl4_axon_queue_size_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_alloc_order;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_count_t
okl4_axon_queue_size_getminorder(const okl4_axon_queue_size_t *x)
{
    okl4_count_t field;
    union {
        
        struct {
            uint32_t _skip : 8;
            uint32_t field : 5;
        } bits;
        okl4_axon_queue_size_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_count_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_axon_queue_size_setminorder(okl4_axon_queue_size_t *x, okl4_count_t _min_order)
{
    union {
        
        struct {
            uint32_t _skip : 8;
            uint32_t field : 5;
        } bits;
        okl4_axon_queue_size_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_min_order;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_axon_queue_size_init(okl4_axon_queue_size_t *x)
{
    *x = (okl4_axon_queue_size_t)0U;
}


OKL4_FORCE_INLINE okl4_axon_queue_size_t
okl4_axon_queue_size_cast(uint16_t p, okl4_bool_t force)
{
    okl4_axon_queue_size_t x = (okl4_axon_queue_size_t)p;
    (void)force;
    return x;
}




struct okl4_axon_rx {
    struct okl4_axon_queue queues[4];
    okl4_axon_queue_size_t queue_sizes[4];
};







struct okl4_axon_tx {
    struct okl4_axon_queue queues[4];
};







typedef okl4_register_t okl4_virq_flags_t;







typedef okl4_virq_flags_t okl4_axon_virq_flags_t;



OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_virq_flags_getready(const okl4_axon_virq_flags_t *x);


OKL4_FORCE_INLINE void
okl4_axon_virq_flags_setready(okl4_axon_virq_flags_t *x, okl4_bool_t _ready);



OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_virq_flags_getfault(const okl4_axon_virq_flags_t *x);


OKL4_FORCE_INLINE void
okl4_axon_virq_flags_setfault(okl4_axon_virq_flags_t *x, okl4_bool_t _fault);


OKL4_FORCE_INLINE void
okl4_axon_virq_flags_init(okl4_axon_virq_flags_t *x);


OKL4_FORCE_INLINE okl4_axon_virq_flags_t
okl4_axon_virq_flags_cast(uint64_t p, okl4_bool_t force);





#define OKL4_AXON_VIRQ_FLAGS_READY_MASK ((okl4_axon_virq_flags_t)1U) 

#define OKL4_MASK_READY_AXON_VIRQ_FLAGS ((okl4_axon_virq_flags_t)1U)

#define OKL4_SHIFT_READY_AXON_VIRQ_FLAGS (0)

#define OKL4_WIDTH_READY_AXON_VIRQ_FLAGS (1)

#define OKL4_AXON_VIRQ_FLAGS_FAULT_MASK ((okl4_axon_virq_flags_t)1U << 1) 

#define OKL4_MASK_FAULT_AXON_VIRQ_FLAGS ((okl4_axon_virq_flags_t)1U << 1)

#define OKL4_SHIFT_FAULT_AXON_VIRQ_FLAGS (1)

#define OKL4_WIDTH_FAULT_AXON_VIRQ_FLAGS (1)





OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_virq_flags_getready(const okl4_axon_virq_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_axon_virq_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_axon_virq_flags_setready(okl4_axon_virq_flags_t *x, okl4_bool_t _ready)
{
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_axon_virq_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_ready;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_axon_virq_flags_getfault(const okl4_axon_virq_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint64_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_axon_virq_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_axon_virq_flags_setfault(okl4_axon_virq_flags_t *x, okl4_bool_t _fault)
{
    union {
        
        struct {
            uint64_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_axon_virq_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_fault;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_axon_virq_flags_init(okl4_axon_virq_flags_t *x)
{
    *x = (okl4_axon_virq_flags_t)0U;
}


OKL4_FORCE_INLINE okl4_axon_virq_flags_t
okl4_axon_virq_flags_cast(uint64_t p, okl4_bool_t force)
{
    okl4_axon_virq_flags_t x = (okl4_axon_virq_flags_t)p;
    (void)force;
    return x;
}





typedef okl4_count_t okl4_page_cache_t;


#define OKL4_PAGE_CACHE_WRITECOMBINE ((okl4_page_cache_t)0x0U)

#define OKL4_PAGE_CACHE_DEFAULT ((okl4_page_cache_t)0x1U)

#define OKL4_PAGE_CACHE_IPC_RX ((okl4_page_cache_t)0x1U)

#define OKL4_PAGE_CACHE_IPC_TX ((okl4_page_cache_t)0x1U)

#define OKL4_PAGE_CACHE_TRACEBUFFER ((okl4_page_cache_t)0x1U)

#define OKL4_PAGE_CACHE_WRITEBACK ((okl4_page_cache_t)0x1U)

#define OKL4_PAGE_CACHE_IWB_RWA_ONC ((okl4_page_cache_t)0x2U)

#define OKL4_PAGE_CACHE_WRITETHROUGH ((okl4_page_cache_t)0x3U)

#define OKL4_PAGE_CACHE_DEVICE_GRE ((okl4_page_cache_t)0x4U)

#define OKL4_PAGE_CACHE_DEVICE_NGRE ((okl4_page_cache_t)0x5U)

#define OKL4_PAGE_CACHE_DEVICE ((okl4_page_cache_t)0x6U)

#define OKL4_PAGE_CACHE_STRONG ((okl4_page_cache_t)0x7U)

#define OKL4_PAGE_CACHE_HW_DEVICE_NGNRNE ((okl4_page_cache_t)0x8000000U)

#define OKL4_PAGE_CACHE_HW_MASK ((okl4_page_cache_t)0x8000000U)

#define OKL4_PAGE_CACHE_HW_DEVICE_NGNRE ((okl4_page_cache_t)0x8000004U)

#define OKL4_PAGE_CACHE_HW_DEVICE_NGRE ((okl4_page_cache_t)0x8000008U)

#define OKL4_PAGE_CACHE_HW_DEVICE_GRE ((okl4_page_cache_t)0x800000cU)

#define OKL4_PAGE_CACHE_HW_TWT_WA_NSH ((okl4_page_cache_t)0x8000011U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_NSH ((okl4_page_cache_t)0x8000012U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_NSH ((okl4_page_cache_t)0x8000013U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_WA_NSH ((okl4_page_cache_t)0x8000014U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_NSH ((okl4_page_cache_t)0x8000015U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_NSH ((okl4_page_cache_t)0x8000016U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_NSH ((okl4_page_cache_t)0x8000017U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_WA_NSH ((okl4_page_cache_t)0x8000018U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_WA_NSH ((okl4_page_cache_t)0x8000019U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_WA_NSH ((okl4_page_cache_t)0x800001aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_NSH ((okl4_page_cache_t)0x800001bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_WA_NSH ((okl4_page_cache_t)0x800001cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_WA_NSH ((okl4_page_cache_t)0x800001dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_WA_NSH ((okl4_page_cache_t)0x800001eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_NSH ((okl4_page_cache_t)0x800001fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_NSH ((okl4_page_cache_t)0x8000021U)

#define OKL4_PAGE_CACHE_HW_TWT_RA_NSH ((okl4_page_cache_t)0x8000022U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_NSH ((okl4_page_cache_t)0x8000023U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_RA_NSH ((okl4_page_cache_t)0x8000024U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_NSH ((okl4_page_cache_t)0x8000025U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_NSH ((okl4_page_cache_t)0x8000026U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_NSH ((okl4_page_cache_t)0x8000027U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RA_NSH ((okl4_page_cache_t)0x8000028U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RA_NSH ((okl4_page_cache_t)0x8000029U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RA_NSH ((okl4_page_cache_t)0x800002aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_NSH ((okl4_page_cache_t)0x800002bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RA_NSH ((okl4_page_cache_t)0x800002cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RA_NSH ((okl4_page_cache_t)0x800002dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RA_NSH ((okl4_page_cache_t)0x800002eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_NSH ((okl4_page_cache_t)0x800002fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_NSH ((okl4_page_cache_t)0x8000031U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_NSH ((okl4_page_cache_t)0x8000032U)

#define OKL4_PAGE_CACHE_HW_TWT_RWA_NSH ((okl4_page_cache_t)0x8000033U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_RWA_NSH ((okl4_page_cache_t)0x8000034U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_NSH ((okl4_page_cache_t)0x8000035U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_NSH ((okl4_page_cache_t)0x8000036U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_NSH ((okl4_page_cache_t)0x8000037U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_NSH ((okl4_page_cache_t)0x8000038U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_NSH ((okl4_page_cache_t)0x8000039U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_NSH ((okl4_page_cache_t)0x800003aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_NSH ((okl4_page_cache_t)0x800003bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_NSH ((okl4_page_cache_t)0x800003cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_NSH ((okl4_page_cache_t)0x800003dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_NSH ((okl4_page_cache_t)0x800003eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_NSH ((okl4_page_cache_t)0x800003fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_ONC_NSH ((okl4_page_cache_t)0x8000041U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_ONC_NSH ((okl4_page_cache_t)0x8000042U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_ONC_NSH ((okl4_page_cache_t)0x8000043U)

#define OKL4_PAGE_CACHE_HW_NC_NSH ((okl4_page_cache_t)0x8000044U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_ONC_NSH ((okl4_page_cache_t)0x8000045U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_ONC_NSH ((okl4_page_cache_t)0x8000046U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_ONC_NSH ((okl4_page_cache_t)0x8000047U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_ONC_NSH ((okl4_page_cache_t)0x8000048U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_ONC_NSH ((okl4_page_cache_t)0x8000049U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_ONC_NSH ((okl4_page_cache_t)0x800004aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_ONC_NSH ((okl4_page_cache_t)0x800004bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_ONC_NSH ((okl4_page_cache_t)0x800004cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_ONC_NSH ((okl4_page_cache_t)0x800004dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_ONC_NSH ((okl4_page_cache_t)0x800004eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_ONC_NSH ((okl4_page_cache_t)0x800004fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_NSH ((okl4_page_cache_t)0x8000051U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_NSH ((okl4_page_cache_t)0x8000052U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_NSH ((okl4_page_cache_t)0x8000053U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_WA_NSH ((okl4_page_cache_t)0x8000054U)

#define OKL4_PAGE_CACHE_HW_TWB_WA_NSH ((okl4_page_cache_t)0x8000055U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_NSH ((okl4_page_cache_t)0x8000056U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_NSH ((okl4_page_cache_t)0x8000057U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_WA_NSH ((okl4_page_cache_t)0x8000058U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_WA_NSH ((okl4_page_cache_t)0x8000059U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_WA_NSH ((okl4_page_cache_t)0x800005aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_NSH ((okl4_page_cache_t)0x800005bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_WA_NSH ((okl4_page_cache_t)0x800005cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_WA_NSH ((okl4_page_cache_t)0x800005dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_WA_NSH ((okl4_page_cache_t)0x800005eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_NSH ((okl4_page_cache_t)0x800005fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_NSH ((okl4_page_cache_t)0x8000061U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_NSH ((okl4_page_cache_t)0x8000062U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_NSH ((okl4_page_cache_t)0x8000063U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_RA_NSH ((okl4_page_cache_t)0x8000064U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_NSH ((okl4_page_cache_t)0x8000065U)

#define OKL4_PAGE_CACHE_HW_TWB_RA_NSH ((okl4_page_cache_t)0x8000066U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_NSH ((okl4_page_cache_t)0x8000067U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RA_NSH ((okl4_page_cache_t)0x8000068U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RA_NSH ((okl4_page_cache_t)0x8000069U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RA_NSH ((okl4_page_cache_t)0x800006aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_NSH ((okl4_page_cache_t)0x800006bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RA_NSH ((okl4_page_cache_t)0x800006cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RA_NSH ((okl4_page_cache_t)0x800006dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RA_NSH ((okl4_page_cache_t)0x800006eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_NSH ((okl4_page_cache_t)0x800006fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_NSH ((okl4_page_cache_t)0x8000071U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_NSH ((okl4_page_cache_t)0x8000072U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_NSH ((okl4_page_cache_t)0x8000073U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_RWA_NSH ((okl4_page_cache_t)0x8000074U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_NSH ((okl4_page_cache_t)0x8000075U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_NSH ((okl4_page_cache_t)0x8000076U)

#define OKL4_PAGE_CACHE_HW_TWB_RWA_NSH ((okl4_page_cache_t)0x8000077U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_NSH ((okl4_page_cache_t)0x8000078U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_NSH ((okl4_page_cache_t)0x8000079U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_NSH ((okl4_page_cache_t)0x800007aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_NSH ((okl4_page_cache_t)0x800007bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_NSH ((okl4_page_cache_t)0x800007cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_NSH ((okl4_page_cache_t)0x800007dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_NSH ((okl4_page_cache_t)0x800007eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_NSH ((okl4_page_cache_t)0x800007fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_NA_NSH ((okl4_page_cache_t)0x8000081U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_NA_NSH ((okl4_page_cache_t)0x8000082U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_NSH ((okl4_page_cache_t)0x8000083U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_NA_NSH ((okl4_page_cache_t)0x8000084U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_NA_NSH ((okl4_page_cache_t)0x8000085U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_NA_NSH ((okl4_page_cache_t)0x8000086U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_NSH ((okl4_page_cache_t)0x8000087U)

#define OKL4_PAGE_CACHE_HW_WT_NA_NSH ((okl4_page_cache_t)0x8000088U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_NA_NSH ((okl4_page_cache_t)0x8000089U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_NA_NSH ((okl4_page_cache_t)0x800008aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_NA_NSH ((okl4_page_cache_t)0x800008bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_NA_NSH ((okl4_page_cache_t)0x800008cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_NA_NSH ((okl4_page_cache_t)0x800008dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_NA_NSH ((okl4_page_cache_t)0x800008eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_NA_NSH ((okl4_page_cache_t)0x800008fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_WA_NSH ((okl4_page_cache_t)0x8000091U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_WA_NSH ((okl4_page_cache_t)0x8000092U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_NSH ((okl4_page_cache_t)0x8000093U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_WA_NSH ((okl4_page_cache_t)0x8000094U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_WA_NSH ((okl4_page_cache_t)0x8000095U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_WA_NSH ((okl4_page_cache_t)0x8000096U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_NSH ((okl4_page_cache_t)0x8000097U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_WA_NSH ((okl4_page_cache_t)0x8000098U)

#define OKL4_PAGE_CACHE_HW_WT_WA_NSH ((okl4_page_cache_t)0x8000099U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_WA_NSH ((okl4_page_cache_t)0x800009aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_WA_NSH ((okl4_page_cache_t)0x800009bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_WA_NSH ((okl4_page_cache_t)0x800009cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_WA_NSH ((okl4_page_cache_t)0x800009dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_WA_NSH ((okl4_page_cache_t)0x800009eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_WA_NSH ((okl4_page_cache_t)0x800009fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RA_NSH ((okl4_page_cache_t)0x80000a1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RA_NSH ((okl4_page_cache_t)0x80000a2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_NSH ((okl4_page_cache_t)0x80000a3U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_RA_NSH ((okl4_page_cache_t)0x80000a4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RA_NSH ((okl4_page_cache_t)0x80000a5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RA_NSH ((okl4_page_cache_t)0x80000a6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_NSH ((okl4_page_cache_t)0x80000a7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RA_NSH ((okl4_page_cache_t)0x80000a8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RA_NSH ((okl4_page_cache_t)0x80000a9U)

#define OKL4_PAGE_CACHE_HW_WT_RA_NSH ((okl4_page_cache_t)0x80000aaU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_RA_NSH ((okl4_page_cache_t)0x80000abU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RA_NSH ((okl4_page_cache_t)0x80000acU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RA_NSH ((okl4_page_cache_t)0x80000adU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RA_NSH ((okl4_page_cache_t)0x80000aeU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RA_NSH ((okl4_page_cache_t)0x80000afU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b3U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000b9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000baU)

#define OKL4_PAGE_CACHE_HW_WT_RWA_NSH ((okl4_page_cache_t)0x80000bbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000bcU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000bdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000beU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_NSH ((okl4_page_cache_t)0x80000bfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_NA_NSH ((okl4_page_cache_t)0x80000c1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_NA_NSH ((okl4_page_cache_t)0x80000c2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_NSH ((okl4_page_cache_t)0x80000c3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_NA_NSH ((okl4_page_cache_t)0x80000c4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_NA_NSH ((okl4_page_cache_t)0x80000c5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_NA_NSH ((okl4_page_cache_t)0x80000c6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_NSH ((okl4_page_cache_t)0x80000c7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_NA_NSH ((okl4_page_cache_t)0x80000c8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_NA_NSH ((okl4_page_cache_t)0x80000c9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_NA_NSH ((okl4_page_cache_t)0x80000caU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_NA_NSH ((okl4_page_cache_t)0x80000cbU)

#define OKL4_PAGE_CACHE_HW_WB_NA_NSH ((okl4_page_cache_t)0x80000ccU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_NA_NSH ((okl4_page_cache_t)0x80000cdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_NA_NSH ((okl4_page_cache_t)0x80000ceU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_NA_NSH ((okl4_page_cache_t)0x80000cfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_WA_NSH ((okl4_page_cache_t)0x80000d1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_WA_NSH ((okl4_page_cache_t)0x80000d2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_NSH ((okl4_page_cache_t)0x80000d3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_WA_NSH ((okl4_page_cache_t)0x80000d4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_WA_NSH ((okl4_page_cache_t)0x80000d5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_WA_NSH ((okl4_page_cache_t)0x80000d6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_NSH ((okl4_page_cache_t)0x80000d7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_WA_NSH ((okl4_page_cache_t)0x80000d8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_WA_NSH ((okl4_page_cache_t)0x80000d9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_WA_NSH ((okl4_page_cache_t)0x80000daU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_WA_NSH ((okl4_page_cache_t)0x80000dbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_WA_NSH ((okl4_page_cache_t)0x80000dcU)

#define OKL4_PAGE_CACHE_HW_WB_WA_NSH ((okl4_page_cache_t)0x80000ddU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_WA_NSH ((okl4_page_cache_t)0x80000deU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_WA_NSH ((okl4_page_cache_t)0x80000dfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RA_NSH ((okl4_page_cache_t)0x80000e1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RA_NSH ((okl4_page_cache_t)0x80000e2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_NSH ((okl4_page_cache_t)0x80000e3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_RA_NSH ((okl4_page_cache_t)0x80000e4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RA_NSH ((okl4_page_cache_t)0x80000e5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RA_NSH ((okl4_page_cache_t)0x80000e6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_NSH ((okl4_page_cache_t)0x80000e7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RA_NSH ((okl4_page_cache_t)0x80000e8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RA_NSH ((okl4_page_cache_t)0x80000e9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RA_NSH ((okl4_page_cache_t)0x80000eaU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RA_NSH ((okl4_page_cache_t)0x80000ebU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RA_NSH ((okl4_page_cache_t)0x80000ecU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RA_NSH ((okl4_page_cache_t)0x80000edU)

#define OKL4_PAGE_CACHE_HW_WB_RA_NSH ((okl4_page_cache_t)0x80000eeU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_RA_NSH ((okl4_page_cache_t)0x80000efU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000f9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000faU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000fbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000fcU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000fdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_RWA_NSH ((okl4_page_cache_t)0x80000feU)

#define OKL4_PAGE_CACHE_HW_WB_RWA_NSH ((okl4_page_cache_t)0x80000ffU)

#define OKL4_PAGE_CACHE_HW_TWT_WA_OSH ((okl4_page_cache_t)0x8000211U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_OSH ((okl4_page_cache_t)0x8000212U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_OSH ((okl4_page_cache_t)0x8000213U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_WA_OSH ((okl4_page_cache_t)0x8000214U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_OSH ((okl4_page_cache_t)0x8000215U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_OSH ((okl4_page_cache_t)0x8000216U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_OSH ((okl4_page_cache_t)0x8000217U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_WA_OSH ((okl4_page_cache_t)0x8000218U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_WA_OSH ((okl4_page_cache_t)0x8000219U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_WA_OSH ((okl4_page_cache_t)0x800021aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_OSH ((okl4_page_cache_t)0x800021bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_WA_OSH ((okl4_page_cache_t)0x800021cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_WA_OSH ((okl4_page_cache_t)0x800021dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_WA_OSH ((okl4_page_cache_t)0x800021eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_OSH ((okl4_page_cache_t)0x800021fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_OSH ((okl4_page_cache_t)0x8000221U)

#define OKL4_PAGE_CACHE_HW_TWT_RA_OSH ((okl4_page_cache_t)0x8000222U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_OSH ((okl4_page_cache_t)0x8000223U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_RA_OSH ((okl4_page_cache_t)0x8000224U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_OSH ((okl4_page_cache_t)0x8000225U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_OSH ((okl4_page_cache_t)0x8000226U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_OSH ((okl4_page_cache_t)0x8000227U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RA_OSH ((okl4_page_cache_t)0x8000228U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RA_OSH ((okl4_page_cache_t)0x8000229U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RA_OSH ((okl4_page_cache_t)0x800022aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_OSH ((okl4_page_cache_t)0x800022bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RA_OSH ((okl4_page_cache_t)0x800022cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RA_OSH ((okl4_page_cache_t)0x800022dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RA_OSH ((okl4_page_cache_t)0x800022eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_OSH ((okl4_page_cache_t)0x800022fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_OSH ((okl4_page_cache_t)0x8000231U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_OSH ((okl4_page_cache_t)0x8000232U)

#define OKL4_PAGE_CACHE_HW_TWT_RWA_OSH ((okl4_page_cache_t)0x8000233U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_RWA_OSH ((okl4_page_cache_t)0x8000234U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_OSH ((okl4_page_cache_t)0x8000235U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_OSH ((okl4_page_cache_t)0x8000236U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_OSH ((okl4_page_cache_t)0x8000237U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_OSH ((okl4_page_cache_t)0x8000238U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_OSH ((okl4_page_cache_t)0x8000239U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_OSH ((okl4_page_cache_t)0x800023aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_OSH ((okl4_page_cache_t)0x800023bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_OSH ((okl4_page_cache_t)0x800023cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_OSH ((okl4_page_cache_t)0x800023dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_OSH ((okl4_page_cache_t)0x800023eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_OSH ((okl4_page_cache_t)0x800023fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_ONC_OSH ((okl4_page_cache_t)0x8000241U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_ONC_OSH ((okl4_page_cache_t)0x8000242U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_ONC_OSH ((okl4_page_cache_t)0x8000243U)

#define OKL4_PAGE_CACHE_HW_NC_OSH ((okl4_page_cache_t)0x8000244U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_ONC_OSH ((okl4_page_cache_t)0x8000245U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_ONC_OSH ((okl4_page_cache_t)0x8000246U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_ONC_OSH ((okl4_page_cache_t)0x8000247U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_ONC_OSH ((okl4_page_cache_t)0x8000248U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_ONC_OSH ((okl4_page_cache_t)0x8000249U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_ONC_OSH ((okl4_page_cache_t)0x800024aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_ONC_OSH ((okl4_page_cache_t)0x800024bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_ONC_OSH ((okl4_page_cache_t)0x800024cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_ONC_OSH ((okl4_page_cache_t)0x800024dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_ONC_OSH ((okl4_page_cache_t)0x800024eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_ONC_OSH ((okl4_page_cache_t)0x800024fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_OSH ((okl4_page_cache_t)0x8000251U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_OSH ((okl4_page_cache_t)0x8000252U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_OSH ((okl4_page_cache_t)0x8000253U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_WA_OSH ((okl4_page_cache_t)0x8000254U)

#define OKL4_PAGE_CACHE_HW_TWB_WA_OSH ((okl4_page_cache_t)0x8000255U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_OSH ((okl4_page_cache_t)0x8000256U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_OSH ((okl4_page_cache_t)0x8000257U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_WA_OSH ((okl4_page_cache_t)0x8000258U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_WA_OSH ((okl4_page_cache_t)0x8000259U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_WA_OSH ((okl4_page_cache_t)0x800025aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_OSH ((okl4_page_cache_t)0x800025bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_WA_OSH ((okl4_page_cache_t)0x800025cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_WA_OSH ((okl4_page_cache_t)0x800025dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_WA_OSH ((okl4_page_cache_t)0x800025eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_OSH ((okl4_page_cache_t)0x800025fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_OSH ((okl4_page_cache_t)0x8000261U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_OSH ((okl4_page_cache_t)0x8000262U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_OSH ((okl4_page_cache_t)0x8000263U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_RA_OSH ((okl4_page_cache_t)0x8000264U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_OSH ((okl4_page_cache_t)0x8000265U)

#define OKL4_PAGE_CACHE_HW_TWB_RA_OSH ((okl4_page_cache_t)0x8000266U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_OSH ((okl4_page_cache_t)0x8000267U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RA_OSH ((okl4_page_cache_t)0x8000268U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RA_OSH ((okl4_page_cache_t)0x8000269U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RA_OSH ((okl4_page_cache_t)0x800026aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_OSH ((okl4_page_cache_t)0x800026bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RA_OSH ((okl4_page_cache_t)0x800026cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RA_OSH ((okl4_page_cache_t)0x800026dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RA_OSH ((okl4_page_cache_t)0x800026eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_OSH ((okl4_page_cache_t)0x800026fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_OSH ((okl4_page_cache_t)0x8000271U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_OSH ((okl4_page_cache_t)0x8000272U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_OSH ((okl4_page_cache_t)0x8000273U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_RWA_OSH ((okl4_page_cache_t)0x8000274U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_OSH ((okl4_page_cache_t)0x8000275U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_OSH ((okl4_page_cache_t)0x8000276U)

#define OKL4_PAGE_CACHE_HW_TWB_RWA_OSH ((okl4_page_cache_t)0x8000277U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_OSH ((okl4_page_cache_t)0x8000278U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_OSH ((okl4_page_cache_t)0x8000279U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_OSH ((okl4_page_cache_t)0x800027aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_OSH ((okl4_page_cache_t)0x800027bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_OSH ((okl4_page_cache_t)0x800027cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_OSH ((okl4_page_cache_t)0x800027dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_OSH ((okl4_page_cache_t)0x800027eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_OSH ((okl4_page_cache_t)0x800027fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_NA_OSH ((okl4_page_cache_t)0x8000281U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_NA_OSH ((okl4_page_cache_t)0x8000282U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_OSH ((okl4_page_cache_t)0x8000283U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_NA_OSH ((okl4_page_cache_t)0x8000284U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_NA_OSH ((okl4_page_cache_t)0x8000285U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_NA_OSH ((okl4_page_cache_t)0x8000286U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_OSH ((okl4_page_cache_t)0x8000287U)

#define OKL4_PAGE_CACHE_HW_WT_NA_OSH ((okl4_page_cache_t)0x8000288U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_NA_OSH ((okl4_page_cache_t)0x8000289U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_NA_OSH ((okl4_page_cache_t)0x800028aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_NA_OSH ((okl4_page_cache_t)0x800028bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_NA_OSH ((okl4_page_cache_t)0x800028cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_NA_OSH ((okl4_page_cache_t)0x800028dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_NA_OSH ((okl4_page_cache_t)0x800028eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_NA_OSH ((okl4_page_cache_t)0x800028fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_WA_OSH ((okl4_page_cache_t)0x8000291U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_WA_OSH ((okl4_page_cache_t)0x8000292U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_OSH ((okl4_page_cache_t)0x8000293U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_WA_OSH ((okl4_page_cache_t)0x8000294U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_WA_OSH ((okl4_page_cache_t)0x8000295U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_WA_OSH ((okl4_page_cache_t)0x8000296U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_OSH ((okl4_page_cache_t)0x8000297U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_WA_OSH ((okl4_page_cache_t)0x8000298U)

#define OKL4_PAGE_CACHE_HW_WT_WA_OSH ((okl4_page_cache_t)0x8000299U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_WA_OSH ((okl4_page_cache_t)0x800029aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_WA_OSH ((okl4_page_cache_t)0x800029bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_WA_OSH ((okl4_page_cache_t)0x800029cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_WA_OSH ((okl4_page_cache_t)0x800029dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_WA_OSH ((okl4_page_cache_t)0x800029eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_WA_OSH ((okl4_page_cache_t)0x800029fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RA_OSH ((okl4_page_cache_t)0x80002a1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RA_OSH ((okl4_page_cache_t)0x80002a2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_OSH ((okl4_page_cache_t)0x80002a3U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_RA_OSH ((okl4_page_cache_t)0x80002a4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RA_OSH ((okl4_page_cache_t)0x80002a5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RA_OSH ((okl4_page_cache_t)0x80002a6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_OSH ((okl4_page_cache_t)0x80002a7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RA_OSH ((okl4_page_cache_t)0x80002a8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RA_OSH ((okl4_page_cache_t)0x80002a9U)

#define OKL4_PAGE_CACHE_HW_WT_RA_OSH ((okl4_page_cache_t)0x80002aaU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_RA_OSH ((okl4_page_cache_t)0x80002abU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RA_OSH ((okl4_page_cache_t)0x80002acU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RA_OSH ((okl4_page_cache_t)0x80002adU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RA_OSH ((okl4_page_cache_t)0x80002aeU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RA_OSH ((okl4_page_cache_t)0x80002afU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b3U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002b9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002baU)

#define OKL4_PAGE_CACHE_HW_WT_RWA_OSH ((okl4_page_cache_t)0x80002bbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002bcU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002bdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002beU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_OSH ((okl4_page_cache_t)0x80002bfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_NA_OSH ((okl4_page_cache_t)0x80002c1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_NA_OSH ((okl4_page_cache_t)0x80002c2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_OSH ((okl4_page_cache_t)0x80002c3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_NA_OSH ((okl4_page_cache_t)0x80002c4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_NA_OSH ((okl4_page_cache_t)0x80002c5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_NA_OSH ((okl4_page_cache_t)0x80002c6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_OSH ((okl4_page_cache_t)0x80002c7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_NA_OSH ((okl4_page_cache_t)0x80002c8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_NA_OSH ((okl4_page_cache_t)0x80002c9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_NA_OSH ((okl4_page_cache_t)0x80002caU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_NA_OSH ((okl4_page_cache_t)0x80002cbU)

#define OKL4_PAGE_CACHE_HW_WB_NA_OSH ((okl4_page_cache_t)0x80002ccU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_NA_OSH ((okl4_page_cache_t)0x80002cdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_NA_OSH ((okl4_page_cache_t)0x80002ceU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_NA_OSH ((okl4_page_cache_t)0x80002cfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_WA_OSH ((okl4_page_cache_t)0x80002d1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_WA_OSH ((okl4_page_cache_t)0x80002d2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_OSH ((okl4_page_cache_t)0x80002d3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_WA_OSH ((okl4_page_cache_t)0x80002d4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_WA_OSH ((okl4_page_cache_t)0x80002d5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_WA_OSH ((okl4_page_cache_t)0x80002d6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_OSH ((okl4_page_cache_t)0x80002d7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_WA_OSH ((okl4_page_cache_t)0x80002d8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_WA_OSH ((okl4_page_cache_t)0x80002d9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_WA_OSH ((okl4_page_cache_t)0x80002daU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_WA_OSH ((okl4_page_cache_t)0x80002dbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_WA_OSH ((okl4_page_cache_t)0x80002dcU)

#define OKL4_PAGE_CACHE_HW_WB_WA_OSH ((okl4_page_cache_t)0x80002ddU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_WA_OSH ((okl4_page_cache_t)0x80002deU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_WA_OSH ((okl4_page_cache_t)0x80002dfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RA_OSH ((okl4_page_cache_t)0x80002e1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RA_OSH ((okl4_page_cache_t)0x80002e2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_OSH ((okl4_page_cache_t)0x80002e3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_RA_OSH ((okl4_page_cache_t)0x80002e4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RA_OSH ((okl4_page_cache_t)0x80002e5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RA_OSH ((okl4_page_cache_t)0x80002e6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_OSH ((okl4_page_cache_t)0x80002e7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RA_OSH ((okl4_page_cache_t)0x80002e8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RA_OSH ((okl4_page_cache_t)0x80002e9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RA_OSH ((okl4_page_cache_t)0x80002eaU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RA_OSH ((okl4_page_cache_t)0x80002ebU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RA_OSH ((okl4_page_cache_t)0x80002ecU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RA_OSH ((okl4_page_cache_t)0x80002edU)

#define OKL4_PAGE_CACHE_HW_WB_RA_OSH ((okl4_page_cache_t)0x80002eeU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_RA_OSH ((okl4_page_cache_t)0x80002efU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002f9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002faU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002fbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002fcU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002fdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_RWA_OSH ((okl4_page_cache_t)0x80002feU)

#define OKL4_PAGE_CACHE_HW_WB_RWA_OSH ((okl4_page_cache_t)0x80002ffU)

#define OKL4_PAGE_CACHE_HW_TWT_WA_ISH ((okl4_page_cache_t)0x8000311U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_ISH ((okl4_page_cache_t)0x8000312U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_ISH ((okl4_page_cache_t)0x8000313U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_WA_ISH ((okl4_page_cache_t)0x8000314U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_ISH ((okl4_page_cache_t)0x8000315U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_ISH ((okl4_page_cache_t)0x8000316U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_ISH ((okl4_page_cache_t)0x8000317U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_WA_ISH ((okl4_page_cache_t)0x8000318U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_WA_ISH ((okl4_page_cache_t)0x8000319U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_WA_ISH ((okl4_page_cache_t)0x800031aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_ISH ((okl4_page_cache_t)0x800031bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_WA_ISH ((okl4_page_cache_t)0x800031cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_WA_ISH ((okl4_page_cache_t)0x800031dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_WA_ISH ((okl4_page_cache_t)0x800031eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_ISH ((okl4_page_cache_t)0x800031fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_ISH ((okl4_page_cache_t)0x8000321U)

#define OKL4_PAGE_CACHE_HW_TWT_RA_ISH ((okl4_page_cache_t)0x8000322U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_ISH ((okl4_page_cache_t)0x8000323U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_RA_ISH ((okl4_page_cache_t)0x8000324U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_ISH ((okl4_page_cache_t)0x8000325U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_ISH ((okl4_page_cache_t)0x8000326U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_ISH ((okl4_page_cache_t)0x8000327U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RA_ISH ((okl4_page_cache_t)0x8000328U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RA_ISH ((okl4_page_cache_t)0x8000329U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RA_ISH ((okl4_page_cache_t)0x800032aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_ISH ((okl4_page_cache_t)0x800032bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RA_ISH ((okl4_page_cache_t)0x800032cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RA_ISH ((okl4_page_cache_t)0x800032dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RA_ISH ((okl4_page_cache_t)0x800032eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_ISH ((okl4_page_cache_t)0x800032fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_ISH ((okl4_page_cache_t)0x8000331U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_ISH ((okl4_page_cache_t)0x8000332U)

#define OKL4_PAGE_CACHE_HW_TWT_RWA_ISH ((okl4_page_cache_t)0x8000333U)

#define OKL4_PAGE_CACHE_HW_INC_OTWT_RWA_ISH ((okl4_page_cache_t)0x8000334U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_ISH ((okl4_page_cache_t)0x8000335U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_ISH ((okl4_page_cache_t)0x8000336U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_ISH ((okl4_page_cache_t)0x8000337U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_ISH ((okl4_page_cache_t)0x8000338U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_ISH ((okl4_page_cache_t)0x8000339U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_ISH ((okl4_page_cache_t)0x800033aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_ISH ((okl4_page_cache_t)0x800033bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_ISH ((okl4_page_cache_t)0x800033cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_ISH ((okl4_page_cache_t)0x800033dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_ISH ((okl4_page_cache_t)0x800033eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_ISH ((okl4_page_cache_t)0x800033fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_ONC_ISH ((okl4_page_cache_t)0x8000341U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_ONC_ISH ((okl4_page_cache_t)0x8000342U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_ONC_ISH ((okl4_page_cache_t)0x8000343U)

#define OKL4_PAGE_CACHE_HW_NC_ISH ((okl4_page_cache_t)0x8000344U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_ONC_ISH ((okl4_page_cache_t)0x8000345U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_ONC_ISH ((okl4_page_cache_t)0x8000346U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_ONC_ISH ((okl4_page_cache_t)0x8000347U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_ONC_ISH ((okl4_page_cache_t)0x8000348U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_ONC_ISH ((okl4_page_cache_t)0x8000349U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_ONC_ISH ((okl4_page_cache_t)0x800034aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_ONC_ISH ((okl4_page_cache_t)0x800034bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_ONC_ISH ((okl4_page_cache_t)0x800034cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_ONC_ISH ((okl4_page_cache_t)0x800034dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_ONC_ISH ((okl4_page_cache_t)0x800034eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_ONC_ISH ((okl4_page_cache_t)0x800034fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_ISH ((okl4_page_cache_t)0x8000351U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_ISH ((okl4_page_cache_t)0x8000352U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_ISH ((okl4_page_cache_t)0x8000353U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_WA_ISH ((okl4_page_cache_t)0x8000354U)

#define OKL4_PAGE_CACHE_HW_TWB_WA_ISH ((okl4_page_cache_t)0x8000355U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_ISH ((okl4_page_cache_t)0x8000356U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_ISH ((okl4_page_cache_t)0x8000357U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_WA_ISH ((okl4_page_cache_t)0x8000358U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_WA_ISH ((okl4_page_cache_t)0x8000359U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_WA_ISH ((okl4_page_cache_t)0x800035aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_ISH ((okl4_page_cache_t)0x800035bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_WA_ISH ((okl4_page_cache_t)0x800035cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_WA_ISH ((okl4_page_cache_t)0x800035dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_WA_ISH ((okl4_page_cache_t)0x800035eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_ISH ((okl4_page_cache_t)0x800035fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_ISH ((okl4_page_cache_t)0x8000361U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_ISH ((okl4_page_cache_t)0x8000362U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_ISH ((okl4_page_cache_t)0x8000363U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_RA_ISH ((okl4_page_cache_t)0x8000364U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_ISH ((okl4_page_cache_t)0x8000365U)

#define OKL4_PAGE_CACHE_HW_TWB_RA_ISH ((okl4_page_cache_t)0x8000366U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_ISH ((okl4_page_cache_t)0x8000367U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RA_ISH ((okl4_page_cache_t)0x8000368U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RA_ISH ((okl4_page_cache_t)0x8000369U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RA_ISH ((okl4_page_cache_t)0x800036aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_ISH ((okl4_page_cache_t)0x800036bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RA_ISH ((okl4_page_cache_t)0x800036cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RA_ISH ((okl4_page_cache_t)0x800036dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RA_ISH ((okl4_page_cache_t)0x800036eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_ISH ((okl4_page_cache_t)0x800036fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_ISH ((okl4_page_cache_t)0x8000371U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_ISH ((okl4_page_cache_t)0x8000372U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_ISH ((okl4_page_cache_t)0x8000373U)

#define OKL4_PAGE_CACHE_HW_INC_OTWB_RWA_ISH ((okl4_page_cache_t)0x8000374U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_ISH ((okl4_page_cache_t)0x8000375U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_ISH ((okl4_page_cache_t)0x8000376U)

#define OKL4_PAGE_CACHE_HW_TWB_RWA_ISH ((okl4_page_cache_t)0x8000377U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_ISH ((okl4_page_cache_t)0x8000378U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_ISH ((okl4_page_cache_t)0x8000379U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_ISH ((okl4_page_cache_t)0x800037aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_ISH ((okl4_page_cache_t)0x800037bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_ISH ((okl4_page_cache_t)0x800037cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_ISH ((okl4_page_cache_t)0x800037dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_ISH ((okl4_page_cache_t)0x800037eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_ISH ((okl4_page_cache_t)0x800037fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_NA_ISH ((okl4_page_cache_t)0x8000381U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_NA_ISH ((okl4_page_cache_t)0x8000382U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_ISH ((okl4_page_cache_t)0x8000383U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_NA_ISH ((okl4_page_cache_t)0x8000384U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_NA_ISH ((okl4_page_cache_t)0x8000385U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_NA_ISH ((okl4_page_cache_t)0x8000386U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_ISH ((okl4_page_cache_t)0x8000387U)

#define OKL4_PAGE_CACHE_HW_WT_NA_ISH ((okl4_page_cache_t)0x8000388U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_NA_ISH ((okl4_page_cache_t)0x8000389U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_NA_ISH ((okl4_page_cache_t)0x800038aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_NA_ISH ((okl4_page_cache_t)0x800038bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_NA_ISH ((okl4_page_cache_t)0x800038cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_NA_ISH ((okl4_page_cache_t)0x800038dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_NA_ISH ((okl4_page_cache_t)0x800038eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_NA_ISH ((okl4_page_cache_t)0x800038fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_WA_ISH ((okl4_page_cache_t)0x8000391U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_WA_ISH ((okl4_page_cache_t)0x8000392U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_ISH ((okl4_page_cache_t)0x8000393U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_WA_ISH ((okl4_page_cache_t)0x8000394U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_WA_ISH ((okl4_page_cache_t)0x8000395U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_WA_ISH ((okl4_page_cache_t)0x8000396U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_ISH ((okl4_page_cache_t)0x8000397U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_WA_ISH ((okl4_page_cache_t)0x8000398U)

#define OKL4_PAGE_CACHE_HW_WT_WA_ISH ((okl4_page_cache_t)0x8000399U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_WA_ISH ((okl4_page_cache_t)0x800039aU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_WA_ISH ((okl4_page_cache_t)0x800039bU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_WA_ISH ((okl4_page_cache_t)0x800039cU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_WA_ISH ((okl4_page_cache_t)0x800039dU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_WA_ISH ((okl4_page_cache_t)0x800039eU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_WA_ISH ((okl4_page_cache_t)0x800039fU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RA_ISH ((okl4_page_cache_t)0x80003a1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RA_ISH ((okl4_page_cache_t)0x80003a2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_ISH ((okl4_page_cache_t)0x80003a3U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_RA_ISH ((okl4_page_cache_t)0x80003a4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RA_ISH ((okl4_page_cache_t)0x80003a5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RA_ISH ((okl4_page_cache_t)0x80003a6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_ISH ((okl4_page_cache_t)0x80003a7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RA_ISH ((okl4_page_cache_t)0x80003a8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RA_ISH ((okl4_page_cache_t)0x80003a9U)

#define OKL4_PAGE_CACHE_HW_WT_RA_ISH ((okl4_page_cache_t)0x80003aaU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_RA_ISH ((okl4_page_cache_t)0x80003abU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RA_ISH ((okl4_page_cache_t)0x80003acU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RA_ISH ((okl4_page_cache_t)0x80003adU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RA_ISH ((okl4_page_cache_t)0x80003aeU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RA_ISH ((okl4_page_cache_t)0x80003afU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b3U)

#define OKL4_PAGE_CACHE_HW_INC_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003b9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003baU)

#define OKL4_PAGE_CACHE_HW_WT_RWA_ISH ((okl4_page_cache_t)0x80003bbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003bcU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003bdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003beU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_ISH ((okl4_page_cache_t)0x80003bfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_NA_ISH ((okl4_page_cache_t)0x80003c1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_NA_ISH ((okl4_page_cache_t)0x80003c2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_ISH ((okl4_page_cache_t)0x80003c3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_NA_ISH ((okl4_page_cache_t)0x80003c4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_NA_ISH ((okl4_page_cache_t)0x80003c5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_NA_ISH ((okl4_page_cache_t)0x80003c6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_ISH ((okl4_page_cache_t)0x80003c7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_NA_ISH ((okl4_page_cache_t)0x80003c8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_NA_ISH ((okl4_page_cache_t)0x80003c9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_NA_ISH ((okl4_page_cache_t)0x80003caU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_NA_ISH ((okl4_page_cache_t)0x80003cbU)

#define OKL4_PAGE_CACHE_HW_WB_NA_ISH ((okl4_page_cache_t)0x80003ccU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_NA_ISH ((okl4_page_cache_t)0x80003cdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_NA_ISH ((okl4_page_cache_t)0x80003ceU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_NA_ISH ((okl4_page_cache_t)0x80003cfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_WA_ISH ((okl4_page_cache_t)0x80003d1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_WA_ISH ((okl4_page_cache_t)0x80003d2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_ISH ((okl4_page_cache_t)0x80003d3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_WA_ISH ((okl4_page_cache_t)0x80003d4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_WA_ISH ((okl4_page_cache_t)0x80003d5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_WA_ISH ((okl4_page_cache_t)0x80003d6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_ISH ((okl4_page_cache_t)0x80003d7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_WA_ISH ((okl4_page_cache_t)0x80003d8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_WA_ISH ((okl4_page_cache_t)0x80003d9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_WA_ISH ((okl4_page_cache_t)0x80003daU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_WA_ISH ((okl4_page_cache_t)0x80003dbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_WA_ISH ((okl4_page_cache_t)0x80003dcU)

#define OKL4_PAGE_CACHE_HW_WB_WA_ISH ((okl4_page_cache_t)0x80003ddU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_WA_ISH ((okl4_page_cache_t)0x80003deU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_WA_ISH ((okl4_page_cache_t)0x80003dfU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RA_ISH ((okl4_page_cache_t)0x80003e1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RA_ISH ((okl4_page_cache_t)0x80003e2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_ISH ((okl4_page_cache_t)0x80003e3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_RA_ISH ((okl4_page_cache_t)0x80003e4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RA_ISH ((okl4_page_cache_t)0x80003e5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RA_ISH ((okl4_page_cache_t)0x80003e6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_ISH ((okl4_page_cache_t)0x80003e7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RA_ISH ((okl4_page_cache_t)0x80003e8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RA_ISH ((okl4_page_cache_t)0x80003e9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RA_ISH ((okl4_page_cache_t)0x80003eaU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RA_ISH ((okl4_page_cache_t)0x80003ebU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RA_ISH ((okl4_page_cache_t)0x80003ecU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RA_ISH ((okl4_page_cache_t)0x80003edU)

#define OKL4_PAGE_CACHE_HW_WB_RA_ISH ((okl4_page_cache_t)0x80003eeU)

#define OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_RA_ISH ((okl4_page_cache_t)0x80003efU)

#define OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f1U)

#define OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f2U)

#define OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f3U)

#define OKL4_PAGE_CACHE_HW_INC_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f4U)

#define OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f5U)

#define OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f6U)

#define OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f7U)

#define OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f8U)

#define OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003f9U)

#define OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003faU)

#define OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003fbU)

#define OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003fcU)

#define OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003fdU)

#define OKL4_PAGE_CACHE_HW_IWB_RA_OWB_RWA_ISH ((okl4_page_cache_t)0x80003feU)

#define OKL4_PAGE_CACHE_HW_WB_RWA_ISH ((okl4_page_cache_t)0x80003ffU)


#define OKL4_PAGE_CACHE_MAX ((okl4_page_cache_t)0x80003ffU)


#define OKL4_PAGE_CACHE_INVALID ((okl4_page_cache_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_page_cache_is_element_of(okl4_page_cache_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_page_cache_is_element_of(okl4_page_cache_t var)
{
    
    
    return ((var == OKL4_PAGE_CACHE_WRITECOMBINE) ||
            (var == OKL4_PAGE_CACHE_DEFAULT) ||
            (var == OKL4_PAGE_CACHE_IPC_RX) ||
            (var == OKL4_PAGE_CACHE_IPC_TX) ||
            (var == OKL4_PAGE_CACHE_TRACEBUFFER) ||
            (var == OKL4_PAGE_CACHE_WRITEBACK) ||
            (var == OKL4_PAGE_CACHE_IWB_RWA_ONC) ||
            (var == OKL4_PAGE_CACHE_WRITETHROUGH) ||
            (var == OKL4_PAGE_CACHE_DEVICE_GRE) ||
            (var == OKL4_PAGE_CACHE_DEVICE_NGRE) ||
            (var == OKL4_PAGE_CACHE_DEVICE) ||
            (var == OKL4_PAGE_CACHE_STRONG) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_DEVICE_NGNRE) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_DEVICE_GRE) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_NC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_DEVICE_NGNRNE) ||
            (var == OKL4_PAGE_CACHE_HW_WB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_DEVICE_NGRE) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_NC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_WB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_TWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_NC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_ONC_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_TWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_INC_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_NA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OWT_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RWA_ONC_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_ONC_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_NA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_WA_OWB_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RA_OWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWT_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWT_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_WT_RWA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWB_WA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_RWA_OWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OTWT_RA_ISH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_NA_OTWT_WA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWB_WA_OTWB_WA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_WA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_IWT_RA_OWB_NA_OSH) ||
            (var == OKL4_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_NSH) ||
            (var == OKL4_PAGE_CACHE_HW_MASK));
}



typedef uint32_t okl4_cell_id_t;





typedef char okl4_char_t;










typedef const okl4_char_t *okl4_string_t;














struct okl4_range_item {
    okl4_laddr_t base;
    okl4_lsize_t size;
};






struct okl4_virtmem_item {
    struct okl4_range_item range;
};






struct okl4_cell_management_item {
    okl4_laddr_t entry;
    struct okl4_virtmem_item mapping_range;
    __ptr64(void *, data);
    __ptr64(okl4_string_t, image);
    okl4_kcap_t mmu;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64(okl4_string_t, name);
    okl4_kcap_t registers_cap;
    okl4_kcap_t reset_virq;
    okl4_count_t segment_index;
    _okl4_padding_t __padding4_4;
    _okl4_padding_t __padding5_5;
    _okl4_padding_t __padding6_6;
    _okl4_padding_t __padding7_7;
    __ptr64(struct okl4_cell_management_segments *, segments);
    __ptr64(struct okl4_cell_management_vcpus *, vcpus);
    okl4_bool_t boot_once;
    okl4_bool_t can_stop;
    okl4_bool_t deferred;
    okl4_bool_t detached;
    okl4_bool_t erase;
    _okl4_padding_t __padding8_5;
    _okl4_padding_t __padding9_6;
    _okl4_padding_t __padding10_7;
    okl4_laddr_t dtb_address;
};






struct okl4_cell_management {
    okl4_count_t num_items;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    struct okl4_cell_management_item items[]; 
};






typedef okl4_psize_t okl4_paddr_t;






struct okl4_segment_mapping {
    okl4_paddr_t phys_addr;
    okl4_psize_t size;
    okl4_laddr_t virt_addr;
    okl4_kcap_t cap;
    okl4_bool_t device;
    okl4_bool_t owned;
    _okl4_padding_t __padding0_6;
    _okl4_padding_t __padding1_7;
};






struct okl4_cell_management_segments {
    okl4_count_t free_segments;
    okl4_count_t num_segments;
    struct okl4_segment_mapping segment_mappings[]; 
};






struct okl4_cell_management_vcpus {
    okl4_count_t num_vcpus;
    okl4_kcap_t vcpu_caps[]; 
};






typedef uint32_t okl4_cpu_exec_mode;


#define OKL4_ARM_MODE ((okl4_cpu_exec_mode)(0U))


#define OKL4_DEFAULT_MODE ((okl4_cpu_exec_mode)(4U))


#define OKL4_JAZELLE_MODE ((okl4_cpu_exec_mode)(2U))


#define OKL4_THUMBEE_MODE ((okl4_cpu_exec_mode)(3U))


#define OKL4_THUMB_MODE ((okl4_cpu_exec_mode)(1U))




typedef okl4_count_t okl4_cpu_id_t;







typedef uint32_t okl4_cpu_mode_t;



OKL4_FORCE_INLINE okl4_cpu_exec_mode
okl4_cpu_mode_getexecmode(const okl4_cpu_mode_t *x);


OKL4_FORCE_INLINE void
okl4_cpu_mode_setexecmode(okl4_cpu_mode_t *x, okl4_cpu_exec_mode _exec_mode);



OKL4_FORCE_INLINE okl4_bool_t
okl4_cpu_mode_getendian(const okl4_cpu_mode_t *x);


OKL4_FORCE_INLINE void
okl4_cpu_mode_setendian(okl4_cpu_mode_t *x, okl4_bool_t _endian);


OKL4_FORCE_INLINE void
okl4_cpu_mode_init(okl4_cpu_mode_t *x);


OKL4_FORCE_INLINE okl4_cpu_mode_t
okl4_cpu_mode_cast(uint32_t p, okl4_bool_t force);





#define OKL4_CPU_MODE_EXEC_MODE_MASK ((okl4_cpu_mode_t)7U) 

#define OKL4_MASK_EXEC_MODE_CPU_MODE ((okl4_cpu_mode_t)7U)

#define OKL4_SHIFT_EXEC_MODE_CPU_MODE (0)

#define OKL4_WIDTH_EXEC_MODE_CPU_MODE (3)

#define OKL4_CPU_MODE_ENDIAN_MASK ((okl4_cpu_mode_t)1U << 7) 

#define OKL4_MASK_ENDIAN_CPU_MODE ((okl4_cpu_mode_t)1U << 7)

#define OKL4_SHIFT_ENDIAN_CPU_MODE (7)

#define OKL4_WIDTH_ENDIAN_CPU_MODE (1)





OKL4_FORCE_INLINE okl4_cpu_exec_mode
okl4_cpu_mode_getexecmode(const okl4_cpu_mode_t *x)
{
    okl4_cpu_exec_mode field;
    union {
        
        struct {
            uint32_t field : 3;
        } bits;
        okl4_cpu_mode_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_cpu_exec_mode)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_cpu_mode_setexecmode(okl4_cpu_mode_t *x, okl4_cpu_exec_mode _exec_mode)
{
    union {
        
        struct {
            uint32_t field : 3;
        } bits;
        okl4_cpu_mode_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_exec_mode;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_cpu_mode_getendian(const okl4_cpu_mode_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 7;
            _Bool field : 1;
        } bits;
        okl4_cpu_mode_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_cpu_mode_setendian(okl4_cpu_mode_t *x, okl4_bool_t _endian)
{
    union {
        
        struct {
            uint32_t _skip : 7;
            _Bool field : 1;
        } bits;
        okl4_cpu_mode_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_endian;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_cpu_mode_init(okl4_cpu_mode_t *x)
{
    *x = (okl4_cpu_mode_t)0U;
}


OKL4_FORCE_INLINE okl4_cpu_mode_t
okl4_cpu_mode_cast(uint32_t p, okl4_bool_t force)
{
    okl4_cpu_mode_t x = (okl4_cpu_mode_t)p;
    (void)force;
    return x;
}




struct _okl4_env_hdr {
    uint16_t magic;
    uint16_t count;
};







struct _okl4_env_item {
    __ptr64(okl4_string_t, name);
    __ptr64(void *, item);
};








struct _okl4_env {
    struct _okl4_env_hdr env_hdr;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    struct _okl4_env_item env_item[]; 
};






struct okl4_env_access_cell {
    __ptr64(okl4_string_t, name);
    okl4_count_t num_entries;
    okl4_count_t start_entry;
};






typedef uint32_t okl4_page_perms_t;


#define OKL4_PAGE_PERMS_NONE ((okl4_page_perms_t)0x0U)

#define OKL4_PAGE_PERMS_X ((okl4_page_perms_t)0x1U)

#define OKL4_PAGE_PERMS_W ((okl4_page_perms_t)0x2U)

#define OKL4_PAGE_PERMS_WX ((okl4_page_perms_t)0x3U)

#define OKL4_PAGE_PERMS_R ((okl4_page_perms_t)0x4U)

#define OKL4_PAGE_PERMS_RX ((okl4_page_perms_t)0x5U)

#define OKL4_PAGE_PERMS_RW ((okl4_page_perms_t)0x6U)

#define OKL4_PAGE_PERMS_RWX ((okl4_page_perms_t)0x7U)


#define OKL4_PAGE_PERMS_MAX ((okl4_page_perms_t)0x7U)


#define OKL4_PAGE_PERMS_INVALID ((okl4_page_perms_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_page_perms_is_element_of(okl4_page_perms_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_page_perms_is_element_of(okl4_page_perms_t var)
{
    
    
    return ((var == OKL4_PAGE_PERMS_NONE) ||
            (var == OKL4_PAGE_PERMS_X) ||
            (var == OKL4_PAGE_PERMS_W) ||
            (var == OKL4_PAGE_PERMS_WX) ||
            (var == OKL4_PAGE_PERMS_R) ||
            (var == OKL4_PAGE_PERMS_RX) ||
            (var == OKL4_PAGE_PERMS_RW) ||
            (var == OKL4_PAGE_PERMS_RWX));
}




struct okl4_env_access_entry {
    okl4_laddr_t virtual_address;
    okl4_psize_t offset;
    okl4_psize_t size;
    okl4_count_t num_segs;
    okl4_count_t segment_index;
    okl4_page_cache_t cache_attrs;
    okl4_page_perms_t permissions;
    __ptr64(okl4_string_t, object_name);
};






struct okl4_env_access_table {
    okl4_count_t num_cells;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64(struct okl4_env_access_cell *, cells);
    __ptr64(struct okl4_env_access_entry *, entries);
};






struct okl4_env_args {
    okl4_count_t argc;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64_array(okl4_string_t, argv)[]; 
};






struct okl4_env_interrupt_device_map {
    okl4_count_t num_entries;
    okl4_interrupt_number_t entries[]; 
};






struct okl4_interrupt {
    okl4_kcap_t kcap;
};






struct okl4_env_interrupt_handle {
    okl4_interrupt_number_t descriptor;
    struct okl4_interrupt interrupt;
};






struct okl4_env_interrupt_list {
    okl4_count_t num_entries;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64(okl4_interrupt_number_t *, descriptor);
    __ptr64(struct okl4_interrupt *, interrupt);
};






struct okl4_env_profile_cell {
    okl4_char_t name[32];
    okl4_count_t num_cores;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64(struct okl4_env_profile_cpu *, core);
};






struct okl4_env_profile_cpu {
    okl4_kcap_t cap;
};






struct okl4_env_profile_table {
    okl4_count_t num_cell_entries;
    okl4_count_t pcpu_cell_entry;
    __ptr64(struct okl4_env_profile_cell *, cells);
};






struct okl4_env_segment {
    okl4_paddr_t base;
    okl4_psize_t size;
    okl4_kcap_t cap_id;
    okl4_page_perms_t rwx;
};






struct okl4_env_segment_table {
    okl4_count_t num_segments;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    struct okl4_env_segment segments[]; 
};






typedef uint32_t okl4_error_t;



#define OKL4_ERROR_KSP_OK ((okl4_error_t)0x0U)


#define OKL4_ERROR_OK ((okl4_error_t)0x0U)


#define OKL4_ERROR_ALREADY_STARTED ((okl4_error_t)0x1U)


#define OKL4_ERROR_ALREADY_STOPPED ((okl4_error_t)0x2U)

#define OKL4_ERROR_AXON_AREA_TOO_BIG ((okl4_error_t)0x3U)

#define OKL4_ERROR_AXON_BAD_MESSAGE_SIZE ((okl4_error_t)0x4U)

#define OKL4_ERROR_AXON_INVALID_OFFSET ((okl4_error_t)0x5U)

#define OKL4_ERROR_AXON_QUEUE_NOT_MAPPED ((okl4_error_t)0x6U)

#define OKL4_ERROR_AXON_QUEUE_NOT_READY ((okl4_error_t)0x7U)

#define OKL4_ERROR_AXON_TRANSFER_LIMIT_EXCEEDED ((okl4_error_t)0x8U)


#define OKL4_ERROR_CANCELLED ((okl4_error_t)0x9U)


#define OKL4_ERROR_EXISTING_MAPPING ((okl4_error_t)0xaU)


#define OKL4_ERROR_INSUFFICIENT_SEGMENT_RIGHTS ((okl4_error_t)0xbU)


#define OKL4_ERROR_INTERRUPTED ((okl4_error_t)0xcU)


#define OKL4_ERROR_INTERRUPT_ALREADY_ATTACHED ((okl4_error_t)0xdU)


#define OKL4_ERROR_INTERRUPT_INVALID_IRQ ((okl4_error_t)0xeU)


#define OKL4_ERROR_INTERRUPT_NOT_ATTACHED ((okl4_error_t)0xfU)


#define OKL4_ERROR_INVALID_ARGUMENT ((okl4_error_t)0x10U)


#define OKL4_ERROR_INVALID_DESIGNATOR ((okl4_error_t)0x11U)


#define OKL4_ERROR_INVALID_SEGMENT_INDEX ((okl4_error_t)0x13U)


#define OKL4_ERROR_MEMORY_FAULT ((okl4_error_t)0x14U)


#define OKL4_ERROR_MISSING_MAPPING ((okl4_error_t)0x15U)


#define OKL4_ERROR_NON_EMPTY_MMU_CONTEXT ((okl4_error_t)0x16U)


#define OKL4_ERROR_NOT_IN_SEGMENT ((okl4_error_t)0x17U)


#define OKL4_ERROR_NO_RESOURCES ((okl4_error_t)0x19U)


#define OKL4_ERROR_PIPE_BAD_STATE ((okl4_error_t)0x1aU)


#define OKL4_ERROR_PIPE_EMPTY ((okl4_error_t)0x1bU)


#define OKL4_ERROR_PIPE_FULL ((okl4_error_t)0x1cU)


#define OKL4_ERROR_PIPE_NOT_READY ((okl4_error_t)0x1dU)


#define OKL4_ERROR_PIPE_RECV_OVERFLOW ((okl4_error_t)0x1eU)


#define OKL4_ERROR_SEGMENT_USED ((okl4_error_t)0x20U)

#define OKL4_ERROR_THREAD_ALREADY_WATCHING_SUSPENDED ((okl4_error_t)0x21U)


#define OKL4_ERROR_TIMER_ACTIVE ((okl4_error_t)0x22U)


#define OKL4_ERROR_TIMER_CANCELLED ((okl4_error_t)0x23U)


#define OKL4_ERROR_TRY_AGAIN ((okl4_error_t)0x24U)


#define OKL4_ERROR_WOULD_BLOCK ((okl4_error_t)0x25U)


#define OKL4_ERROR_ALLOC_EXHAUSTED ((okl4_error_t)0x26U)


#define OKL4_ERROR_INVALID_AFFINITY ((okl4_error_t)0x27U)


#define OKL4_ERROR_KSP_ERROR_0 ((okl4_error_t)0x10000010U)


#define OKL4_ERROR_KSP_ERROR_1 ((okl4_error_t)0x10000011U)


#define OKL4_ERROR_KSP_ERROR_2 ((okl4_error_t)0x10000012U)


#define OKL4_ERROR_KSP_ERROR_3 ((okl4_error_t)0x10000013U)


#define OKL4_ERROR_KSP_ERROR_4 ((okl4_error_t)0x10000014U)


#define OKL4_ERROR_KSP_ERROR_5 ((okl4_error_t)0x10000015U)


#define OKL4_ERROR_KSP_ERROR_6 ((okl4_error_t)0x10000016U)


#define OKL4_ERROR_KSP_ERROR_7 ((okl4_error_t)0x10000017U)


#define OKL4_ERROR_KSP_INVALID_ARG ((okl4_error_t)0x80000001U)


#define OKL4_ERROR_KSP_NOT_IMPLEMENTED ((okl4_error_t)0x80000002U)


#define OKL4_ERROR_KSP_INSUFFICIENT_RIGHTS ((okl4_error_t)0x80000003U)


#define OKL4_ERROR_KSP_INTERRUPT_REGISTERED ((okl4_error_t)0x80000004U)


#define OKL4_ERROR_NOT_IMPLEMENTED ((okl4_error_t)0xffffffffU)


#define OKL4_ERROR_MAX ((okl4_error_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_error_is_element_of(okl4_error_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_error_is_element_of(okl4_error_t var)
{
    
    
    return ((var == OKL4_ERROR_ALREADY_STARTED) ||
            (var == OKL4_ERROR_ALREADY_STOPPED) ||
            (var == OKL4_ERROR_AXON_AREA_TOO_BIG) ||
            (var == OKL4_ERROR_AXON_BAD_MESSAGE_SIZE) ||
            (var == OKL4_ERROR_AXON_INVALID_OFFSET) ||
            (var == OKL4_ERROR_AXON_QUEUE_NOT_MAPPED) ||
            (var == OKL4_ERROR_AXON_QUEUE_NOT_READY) ||
            (var == OKL4_ERROR_AXON_TRANSFER_LIMIT_EXCEEDED) ||
            (var == OKL4_ERROR_CANCELLED) ||
            (var == OKL4_ERROR_EXISTING_MAPPING) ||
            (var == OKL4_ERROR_INSUFFICIENT_SEGMENT_RIGHTS) ||
            (var == OKL4_ERROR_INTERRUPTED) ||
            (var == OKL4_ERROR_INTERRUPT_ALREADY_ATTACHED) ||
            (var == OKL4_ERROR_INTERRUPT_INVALID_IRQ) ||
            (var == OKL4_ERROR_INTERRUPT_NOT_ATTACHED) ||
            (var == OKL4_ERROR_INVALID_AFFINITY) ||
            (var == OKL4_ERROR_INVALID_ARGUMENT) ||
            (var == OKL4_ERROR_INVALID_DESIGNATOR) ||
            (var == OKL4_ERROR_INVALID_SEGMENT_INDEX) ||
            (var == OKL4_ERROR_KSP_ERROR_0) ||
            (var == OKL4_ERROR_KSP_ERROR_1) ||
            (var == OKL4_ERROR_KSP_ERROR_2) ||
            (var == OKL4_ERROR_KSP_ERROR_3) ||
            (var == OKL4_ERROR_KSP_ERROR_4) ||
            (var == OKL4_ERROR_KSP_ERROR_5) ||
            (var == OKL4_ERROR_KSP_ERROR_6) ||
            (var == OKL4_ERROR_KSP_ERROR_7) ||
            (var == OKL4_ERROR_KSP_INSUFFICIENT_RIGHTS) ||
            (var == OKL4_ERROR_KSP_INTERRUPT_REGISTERED) ||
            (var == OKL4_ERROR_KSP_INVALID_ARG) ||
            (var == OKL4_ERROR_KSP_NOT_IMPLEMENTED) ||
            (var == OKL4_ERROR_KSP_OK) ||
            (var == OKL4_ERROR_MEMORY_FAULT) ||
            (var == OKL4_ERROR_MISSING_MAPPING) ||
            (var == OKL4_ERROR_NON_EMPTY_MMU_CONTEXT) ||
            (var == OKL4_ERROR_NOT_IMPLEMENTED) ||
            (var == OKL4_ERROR_NOT_IN_SEGMENT) ||
            (var == OKL4_ERROR_NO_RESOURCES) ||
            (var == OKL4_ERROR_OK) ||
            (var == OKL4_ERROR_PIPE_BAD_STATE) ||
            (var == OKL4_ERROR_PIPE_EMPTY) ||
            (var == OKL4_ERROR_PIPE_FULL) ||
            (var == OKL4_ERROR_PIPE_NOT_READY) ||
            (var == OKL4_ERROR_PIPE_RECV_OVERFLOW) ||
            (var == OKL4_ERROR_SEGMENT_USED) ||
            (var == OKL4_ERROR_THREAD_ALREADY_WATCHING_SUSPENDED) ||
            (var == OKL4_ERROR_TIMER_ACTIVE) ||
            (var == OKL4_ERROR_TIMER_CANCELLED) ||
            (var == OKL4_ERROR_TRY_AGAIN) ||
            (var == OKL4_ERROR_WOULD_BLOCK) ||
            (var == OKL4_ERROR_ALLOC_EXHAUSTED));
}




struct okl4_firmware_segment {
    okl4_laddr_t copy_addr;
    okl4_laddr_t exec_addr;
    okl4_lsize_t filesz;
    okl4_lsize_t memsz_diff;
};






struct okl4_firmware_segments_info {
    okl4_count_t num_segments;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    struct okl4_firmware_segment segments[]; 
};







typedef uint32_t okl4_gicd_icfgr_t;



OKL4_FORCE_INLINE okl4_bool_t
okl4_gicd_icfgr_getedge(const okl4_gicd_icfgr_t *x);


OKL4_FORCE_INLINE void
okl4_gicd_icfgr_setedge(okl4_gicd_icfgr_t *x, okl4_bool_t _edge);


OKL4_FORCE_INLINE void
okl4_gicd_icfgr_init(okl4_gicd_icfgr_t *x);


OKL4_FORCE_INLINE okl4_gicd_icfgr_t
okl4_gicd_icfgr_cast(uint32_t p, okl4_bool_t force);





#define OKL4_GICD_ICFGR_EDGE_MASK ((okl4_gicd_icfgr_t)1U << 1) 

#define OKL4_MASK_EDGE_GICD_ICFGR ((okl4_gicd_icfgr_t)1U << 1)

#define OKL4_SHIFT_EDGE_GICD_ICFGR (1)

#define OKL4_WIDTH_EDGE_GICD_ICFGR (1)





OKL4_FORCE_INLINE okl4_bool_t
okl4_gicd_icfgr_getedge(const okl4_gicd_icfgr_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_gicd_icfgr_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_gicd_icfgr_setedge(okl4_gicd_icfgr_t *x, okl4_bool_t _edge)
{
    union {
        
        struct {
            uint32_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_gicd_icfgr_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_edge;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_gicd_icfgr_init(okl4_gicd_icfgr_t *x)
{
    *x = (okl4_gicd_icfgr_t)0U;
}


OKL4_FORCE_INLINE okl4_gicd_icfgr_t
okl4_gicd_icfgr_cast(uint32_t p, okl4_bool_t force)
{
    okl4_gicd_icfgr_t x = (okl4_gicd_icfgr_t)p;
    (void)force;
    return x;
}




typedef uint32_t okl4_sgi_target_t;


#define OKL4_SGI_TARGET_LISTED ((okl4_sgi_target_t)0x0U)

#define OKL4_SGI_TARGET_ALL_OTHERS ((okl4_sgi_target_t)0x1U)

#define OKL4_SGI_TARGET_SELF ((okl4_sgi_target_t)0x2U)


#define OKL4_SGI_TARGET_MAX ((okl4_sgi_target_t)0x2U)


#define OKL4_SGI_TARGET_INVALID ((okl4_sgi_target_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_sgi_target_is_element_of(okl4_sgi_target_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_sgi_target_is_element_of(okl4_sgi_target_t var)
{
    
    
    return ((var == OKL4_SGI_TARGET_LISTED) ||
            (var == OKL4_SGI_TARGET_ALL_OTHERS) ||
            (var == OKL4_SGI_TARGET_SELF));
}





typedef uint32_t okl4_gicd_sgir_t;



OKL4_FORCE_INLINE okl4_interrupt_number_t
okl4_gicd_sgir_getsgiintid(const okl4_gicd_sgir_t *x);


OKL4_FORCE_INLINE void
okl4_gicd_sgir_setsgiintid(okl4_gicd_sgir_t *x, okl4_interrupt_number_t _sgiintid);



OKL4_FORCE_INLINE okl4_bool_t
okl4_gicd_sgir_getnsatt(const okl4_gicd_sgir_t *x);


OKL4_FORCE_INLINE void
okl4_gicd_sgir_setnsatt(okl4_gicd_sgir_t *x, okl4_bool_t _nsatt);



OKL4_FORCE_INLINE uint8_t
okl4_gicd_sgir_getcputargetlist(const okl4_gicd_sgir_t *x);


OKL4_FORCE_INLINE void
okl4_gicd_sgir_setcputargetlist(okl4_gicd_sgir_t *x, uint8_t _cputargetlist);



OKL4_FORCE_INLINE okl4_sgi_target_t
okl4_gicd_sgir_gettargetlistfilter(const okl4_gicd_sgir_t *x);


OKL4_FORCE_INLINE void
okl4_gicd_sgir_settargetlistfilter(okl4_gicd_sgir_t *x, okl4_sgi_target_t _targetlistfilter);


OKL4_FORCE_INLINE void
okl4_gicd_sgir_init(okl4_gicd_sgir_t *x);


OKL4_FORCE_INLINE okl4_gicd_sgir_t
okl4_gicd_sgir_cast(uint32_t p, okl4_bool_t force);





#define OKL4_GICD_SGIR_SGIINTID_MASK ((okl4_gicd_sgir_t)15U) 

#define OKL4_MASK_SGIINTID_GICD_SGIR ((okl4_gicd_sgir_t)15U)

#define OKL4_SHIFT_SGIINTID_GICD_SGIR (0)

#define OKL4_WIDTH_SGIINTID_GICD_SGIR (4)

#define OKL4_GICD_SGIR_NSATT_MASK ((okl4_gicd_sgir_t)1U << 15) 

#define OKL4_MASK_NSATT_GICD_SGIR ((okl4_gicd_sgir_t)1U << 15)

#define OKL4_SHIFT_NSATT_GICD_SGIR (15)

#define OKL4_WIDTH_NSATT_GICD_SGIR (1)

#define OKL4_GICD_SGIR_CPUTARGETLIST_MASK ((okl4_gicd_sgir_t)255U << 16) 

#define OKL4_MASK_CPUTARGETLIST_GICD_SGIR ((okl4_gicd_sgir_t)255U << 16)

#define OKL4_SHIFT_CPUTARGETLIST_GICD_SGIR (16)

#define OKL4_WIDTH_CPUTARGETLIST_GICD_SGIR (8)

#define OKL4_GICD_SGIR_TARGETLISTFILTER_MASK ((okl4_gicd_sgir_t)3U << 24) 

#define OKL4_MASK_TARGETLISTFILTER_GICD_SGIR ((okl4_gicd_sgir_t)3U << 24)

#define OKL4_SHIFT_TARGETLISTFILTER_GICD_SGIR (24)

#define OKL4_WIDTH_TARGETLISTFILTER_GICD_SGIR (2)





OKL4_FORCE_INLINE okl4_interrupt_number_t
okl4_gicd_sgir_getsgiintid(const okl4_gicd_sgir_t *x)
{
    okl4_interrupt_number_t field;
    union {
        
        struct {
            uint32_t field : 4;
        } bits;
        okl4_gicd_sgir_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_interrupt_number_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_gicd_sgir_setsgiintid(okl4_gicd_sgir_t *x, okl4_interrupt_number_t _sgiintid)
{
    union {
        
        struct {
            uint32_t field : 4;
        } bits;
        okl4_gicd_sgir_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_sgiintid;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_gicd_sgir_getnsatt(const okl4_gicd_sgir_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 15;
            _Bool field : 1;
        } bits;
        okl4_gicd_sgir_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_gicd_sgir_setnsatt(okl4_gicd_sgir_t *x, okl4_bool_t _nsatt)
{
    union {
        
        struct {
            uint32_t _skip : 15;
            _Bool field : 1;
        } bits;
        okl4_gicd_sgir_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_nsatt;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint8_t
okl4_gicd_sgir_getcputargetlist(const okl4_gicd_sgir_t *x)
{
    uint8_t field;
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 8;
        } bits;
        okl4_gicd_sgir_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint8_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_gicd_sgir_setcputargetlist(okl4_gicd_sgir_t *x, uint8_t _cputargetlist)
{
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 8;
        } bits;
        okl4_gicd_sgir_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_cputargetlist;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_sgi_target_t
okl4_gicd_sgir_gettargetlistfilter(const okl4_gicd_sgir_t *x)
{
    okl4_sgi_target_t field;
    union {
        
        struct {
            uint32_t _skip : 24;
            uint32_t field : 2;
        } bits;
        okl4_gicd_sgir_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_sgi_target_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_gicd_sgir_settargetlistfilter(okl4_gicd_sgir_t *x, okl4_sgi_target_t _targetlistfilter)
{
    union {
        
        struct {
            uint32_t _skip : 24;
            uint32_t field : 2;
        } bits;
        okl4_gicd_sgir_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_targetlistfilter;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_gicd_sgir_init(okl4_gicd_sgir_t *x)
{
    *x = (okl4_gicd_sgir_t)32768U;
}


OKL4_FORCE_INLINE okl4_gicd_sgir_t
okl4_gicd_sgir_cast(uint32_t p, okl4_bool_t force)
{
    okl4_gicd_sgir_t x = (okl4_gicd_sgir_t)p;
    (void)force;
    return x;
}

























struct okl4_kmmu {
    okl4_kcap_t kcap;
};






typedef okl4_register_t okl4_ksp_arg_t;






struct okl4_ksp_user_agent {
    okl4_kcap_t kcap;
    okl4_interrupt_number_t virq;
};





typedef uint32_t okl4_ksp_vdevice_class_t;





typedef okl4_register_t okl4_laddr_pn_t;





typedef okl4_register_t okl4_laddr_tr_t;






struct okl4_pipe_data {
    okl4_kcap_t kcap;
    okl4_irq_t virq;
};






struct okl4_pipe_ep_data {
    struct okl4_pipe_data rx;
    struct okl4_pipe_data tx;
};





typedef uint32_t okl4_link_role_t;


#define OKL4_LINK_ROLE_SYMMETRIC ((okl4_link_role_t)0x0U)

#define OKL4_LINK_ROLE_SERVER ((okl4_link_role_t)0x1U)

#define OKL4_LINK_ROLE_CLIENT ((okl4_link_role_t)0x2U)


#define OKL4_LINK_ROLE_MAX ((okl4_link_role_t)0x2U)


#define OKL4_LINK_ROLE_INVALID ((okl4_link_role_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_link_role_is_element_of(okl4_link_role_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_link_role_is_element_of(okl4_link_role_t var)
{
    
    
    return ((var == OKL4_LINK_ROLE_SYMMETRIC) ||
            (var == OKL4_LINK_ROLE_SERVER) ||
            (var == OKL4_LINK_ROLE_CLIENT));
}



typedef uint32_t okl4_link_transport_type_t;


#define OKL4_LINK_TRANSPORT_TYPE_SHARED_BUFFER ((okl4_link_transport_type_t)0x0U)

#define OKL4_LINK_TRANSPORT_TYPE_AXONS ((okl4_link_transport_type_t)0x1U)

#define OKL4_LINK_TRANSPORT_TYPE_PIPES ((okl4_link_transport_type_t)0x2U)


#define OKL4_LINK_TRANSPORT_TYPE_MAX ((okl4_link_transport_type_t)0x2U)


#define OKL4_LINK_TRANSPORT_TYPE_INVALID ((okl4_link_transport_type_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_link_transport_type_is_element_of(okl4_link_transport_type_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_link_transport_type_is_element_of(okl4_link_transport_type_t var)
{
    
    
    return ((var == OKL4_LINK_TRANSPORT_TYPE_SHARED_BUFFER) ||
            (var == OKL4_LINK_TRANSPORT_TYPE_AXONS) ||
            (var == OKL4_LINK_TRANSPORT_TYPE_PIPES));
}




struct okl4_link {
    __ptr64(okl4_string_t, name);
    __ptr64(void *, opaque);
    __ptr64(okl4_string_t, partner_name);
    okl4_link_role_t role;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    union {
        struct {
            struct okl4_virtmem_item buffer;
            okl4_irq_t virq_in;
            okl4_kcap_t virq_out;
        } shared_buffer;

        struct {
            struct okl4_axon_ep_data axon_ep;
            okl4_ksize_t message_size;
            okl4_count_t queue_length;
            _okl4_padding_t __padding0_4; 
            _okl4_padding_t __padding1_5; 
            _okl4_padding_t __padding2_6; 
            _okl4_padding_t __padding3_7; 
        } axons;

        struct {
            okl4_ksize_t message_size;
            struct okl4_pipe_ep_data pipe_ep;
            okl4_count_t queue_length;
            _okl4_padding_t __padding0_4; 
            _okl4_padding_t __padding1_5; 
            _okl4_padding_t __padding2_6; 
            _okl4_padding_t __padding3_7; 
        } pipes;

    } transport;

    okl4_link_transport_type_t transport_type;
    _okl4_padding_t __padding4_4;
    _okl4_padding_t __padding5_5;
    _okl4_padding_t __padding6_6;
    _okl4_padding_t __padding7_7;
};






struct okl4_links {
    okl4_count_t num_links;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64_array(struct okl4_link *, links)[]; 
};





typedef okl4_register_t okl4_lsize_pn_t;





typedef okl4_register_t okl4_lsize_tr_t;






struct okl4_machine_info {
    okl4_ksize_t l1_cache_line_size;
    okl4_ksize_t l2_cache_line_size;
    okl4_count_t num_cpus;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
};






struct okl4_merged_physpool {
    okl4_paddr_t phys_addr;
    okl4_count_t num_segments;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    struct okl4_virtmem_item segments[]; 
};





typedef uint32_t okl4_microseconds_t;






struct okl4_microvisor_timer {
    okl4_kcap_t kcap;
    okl4_irq_t virq;
};







typedef uint32_t okl4_mmu_lookup_index_t;



OKL4_FORCE_INLINE okl4_error_t
okl4_mmu_lookup_index_geterror(const okl4_mmu_lookup_index_t *x);


OKL4_FORCE_INLINE void
okl4_mmu_lookup_index_seterror(okl4_mmu_lookup_index_t *x, okl4_error_t _error);



OKL4_FORCE_INLINE okl4_count_t
okl4_mmu_lookup_index_getindex(const okl4_mmu_lookup_index_t *x);


OKL4_FORCE_INLINE void
okl4_mmu_lookup_index_setindex(okl4_mmu_lookup_index_t *x, okl4_count_t _index);


OKL4_FORCE_INLINE void
okl4_mmu_lookup_index_init(okl4_mmu_lookup_index_t *x);


OKL4_FORCE_INLINE okl4_mmu_lookup_index_t
okl4_mmu_lookup_index_cast(uint32_t p, okl4_bool_t force);





#define OKL4_MMU_LOOKUP_INDEX_ERROR_MASK ((okl4_mmu_lookup_index_t)65535U) 

#define OKL4_MASK_ERROR_MMU_LOOKUP_INDEX ((okl4_mmu_lookup_index_t)65535U)

#define OKL4_SHIFT_ERROR_MMU_LOOKUP_INDEX (0)

#define OKL4_WIDTH_ERROR_MMU_LOOKUP_INDEX (16)

#define OKL4_MMU_LOOKUP_INDEX_INDEX_MASK ((okl4_mmu_lookup_index_t)65535U << 16) 

#define OKL4_MASK_INDEX_MMU_LOOKUP_INDEX ((okl4_mmu_lookup_index_t)65535U << 16)

#define OKL4_SHIFT_INDEX_MMU_LOOKUP_INDEX (16)

#define OKL4_WIDTH_INDEX_MMU_LOOKUP_INDEX (16)





OKL4_FORCE_INLINE okl4_error_t
okl4_mmu_lookup_index_geterror(const okl4_mmu_lookup_index_t *x)
{
    okl4_error_t field;
    union {
        
        struct {
            uint32_t field : 16;
        } bits;
        okl4_mmu_lookup_index_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_error_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_mmu_lookup_index_seterror(okl4_mmu_lookup_index_t *x, okl4_error_t _error)
{
    union {
        
        struct {
            uint32_t field : 16;
        } bits;
        okl4_mmu_lookup_index_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_error;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_count_t
okl4_mmu_lookup_index_getindex(const okl4_mmu_lookup_index_t *x)
{
    okl4_count_t field;
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 16;
        } bits;
        okl4_mmu_lookup_index_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_count_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_mmu_lookup_index_setindex(okl4_mmu_lookup_index_t *x, okl4_count_t _index)
{
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 16;
        } bits;
        okl4_mmu_lookup_index_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_index;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_mmu_lookup_index_init(okl4_mmu_lookup_index_t *x)
{
    *x = (okl4_mmu_lookup_index_t)0U;
}


OKL4_FORCE_INLINE okl4_mmu_lookup_index_t
okl4_mmu_lookup_index_cast(uint32_t p, okl4_bool_t force)
{
    okl4_mmu_lookup_index_t x = (okl4_mmu_lookup_index_t)p;
    (void)force;
    return x;
}






typedef okl4_register_t okl4_mmu_lookup_size_t;



OKL4_FORCE_INLINE okl4_count_t
okl4_mmu_lookup_size_getsegindex(const okl4_mmu_lookup_size_t *x);


OKL4_FORCE_INLINE void
okl4_mmu_lookup_size_setsegindex(okl4_mmu_lookup_size_t *x, okl4_count_t _seg_index);



OKL4_FORCE_INLINE okl4_register_t
okl4_mmu_lookup_size_getsize10(const okl4_mmu_lookup_size_t *x);


OKL4_FORCE_INLINE void
okl4_mmu_lookup_size_setsize10(okl4_mmu_lookup_size_t *x, okl4_register_t _size_10);


OKL4_FORCE_INLINE void
okl4_mmu_lookup_size_init(okl4_mmu_lookup_size_t *x);


OKL4_FORCE_INLINE okl4_mmu_lookup_size_t
okl4_mmu_lookup_size_cast(uint64_t p, okl4_bool_t force);





#define OKL4_MMU_LOOKUP_SIZE_SEG_INDEX_MASK ((okl4_mmu_lookup_size_t)1023U) 

#define OKL4_MASK_SEG_INDEX_MMU_LOOKUP_SIZE ((okl4_mmu_lookup_size_t)1023U)

#define OKL4_SHIFT_SEG_INDEX_MMU_LOOKUP_SIZE (0)

#define OKL4_WIDTH_SEG_INDEX_MMU_LOOKUP_SIZE (10)

#define OKL4_MMU_LOOKUP_SIZE_SIZE_10_MASK ((okl4_mmu_lookup_size_t)18014398509481983U << 10) 

#define OKL4_MASK_SIZE_10_MMU_LOOKUP_SIZE ((okl4_mmu_lookup_size_t)18014398509481983U << 10)

#define OKL4_SHIFT_SIZE_10_MMU_LOOKUP_SIZE (10)

#define OKL4_WIDTH_SIZE_10_MMU_LOOKUP_SIZE (54)





OKL4_FORCE_INLINE okl4_count_t
okl4_mmu_lookup_size_getsegindex(const okl4_mmu_lookup_size_t *x)
{
    okl4_count_t field;
    union {
        
        struct {
            uint64_t field : 10;
        } bits;
        okl4_mmu_lookup_size_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_count_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_mmu_lookup_size_setsegindex(okl4_mmu_lookup_size_t *x, okl4_count_t _seg_index)
{
    union {
        
        struct {
            uint64_t field : 10;
        } bits;
        okl4_mmu_lookup_size_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint64_t)_seg_index;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_register_t
okl4_mmu_lookup_size_getsize10(const okl4_mmu_lookup_size_t *x)
{
    okl4_register_t field;
    union {
        
        struct {
            uint64_t _skip : 10;
            uint64_t field : 54;
        } bits;
        okl4_mmu_lookup_size_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_register_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_mmu_lookup_size_setsize10(okl4_mmu_lookup_size_t *x, okl4_register_t _size_10)
{
    union {
        
        struct {
            uint64_t _skip : 10;
            uint64_t field : 54;
        } bits;
        okl4_mmu_lookup_size_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint64_t)_size_10;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_mmu_lookup_size_init(okl4_mmu_lookup_size_t *x)
{
    *x = (okl4_mmu_lookup_size_t)0U;
}


OKL4_FORCE_INLINE okl4_mmu_lookup_size_t
okl4_mmu_lookup_size_cast(uint64_t p, okl4_bool_t force)
{
    okl4_mmu_lookup_size_t x = (okl4_mmu_lookup_size_t)p;
    (void)force;
    return x;
}




typedef uint64_t okl4_nanoseconds_t;



#define OKL4_TIMER_MAX_PERIOD_NS ((okl4_nanoseconds_t)(36028797018963968U))



#define OKL4_TIMER_MIN_PERIOD_NS ((okl4_nanoseconds_t)(1000000U))






typedef uint32_t _okl4_page_attribute_t;



OKL4_FORCE_INLINE okl4_page_perms_t
_okl4_page_attribute_getrwx(const _okl4_page_attribute_t *x);


OKL4_FORCE_INLINE void
_okl4_page_attribute_setrwx(_okl4_page_attribute_t *x, okl4_page_perms_t _rwx);



OKL4_FORCE_INLINE okl4_page_cache_t
_okl4_page_attribute_getattrib(const _okl4_page_attribute_t *x);


OKL4_FORCE_INLINE void
_okl4_page_attribute_setattrib(_okl4_page_attribute_t *x, okl4_page_cache_t _attrib);


OKL4_FORCE_INLINE void
_okl4_page_attribute_init(_okl4_page_attribute_t *x);


OKL4_FORCE_INLINE _okl4_page_attribute_t
_okl4_page_attribute_cast(uint32_t p, okl4_bool_t force);





#define _OKL4_PAGE_ATTRIBUTE_RWX_MASK ((_okl4_page_attribute_t)7U) 

#define _OKL4_MASK_RWX_PAGE_ATTRIBUTE ((_okl4_page_attribute_t)7U)

#define _OKL4_SHIFT_RWX_PAGE_ATTRIBUTE (0)

#define _OKL4_WIDTH_RWX_PAGE_ATTRIBUTE (3)

#define _OKL4_PAGE_ATTRIBUTE_ATTRIB_MASK ((_okl4_page_attribute_t)268435455U << 4) 

#define _OKL4_MASK_ATTRIB_PAGE_ATTRIBUTE ((_okl4_page_attribute_t)268435455U << 4)

#define _OKL4_SHIFT_ATTRIB_PAGE_ATTRIBUTE (4)

#define _OKL4_WIDTH_ATTRIB_PAGE_ATTRIBUTE (28)





OKL4_FORCE_INLINE okl4_page_perms_t
_okl4_page_attribute_getrwx(const _okl4_page_attribute_t *x)
{
    okl4_page_perms_t field;
    union {
        
        struct {
            uint32_t field : 3;
        } bits;
        _okl4_page_attribute_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_page_perms_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_page_attribute_setrwx(_okl4_page_attribute_t *x, okl4_page_perms_t _rwx)
{
    union {
        
        struct {
            uint32_t field : 3;
        } bits;
        _okl4_page_attribute_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_rwx;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_page_cache_t
_okl4_page_attribute_getattrib(const _okl4_page_attribute_t *x)
{
    okl4_page_cache_t field;
    union {
        
        struct {
            uint32_t _skip : 4;
            uint32_t field : 28;
        } bits;
        _okl4_page_attribute_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_page_cache_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_page_attribute_setattrib(_okl4_page_attribute_t *x, okl4_page_cache_t _attrib)
{
    union {
        
        struct {
            uint32_t _skip : 4;
            uint32_t field : 28;
        } bits;
        _okl4_page_attribute_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_attrib;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
_okl4_page_attribute_init(_okl4_page_attribute_t *x)
{
    *x = (_okl4_page_attribute_t)0U;
}


OKL4_FORCE_INLINE _okl4_page_attribute_t
_okl4_page_attribute_cast(uint32_t p, okl4_bool_t force)
{
    _okl4_page_attribute_t x = (_okl4_page_attribute_t)p;
    (void)force;
    return x;
}






typedef uint8_t okl4_pipe_control_t;



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_control_getdoop(const okl4_pipe_control_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_control_setdoop(okl4_pipe_control_t *x, okl4_bool_t _do_op);



OKL4_FORCE_INLINE uint8_t
okl4_pipe_control_getoperation(const okl4_pipe_control_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_control_setoperation(okl4_pipe_control_t *x, uint8_t _operation);


OKL4_FORCE_INLINE void
okl4_pipe_control_init(okl4_pipe_control_t *x);


OKL4_FORCE_INLINE okl4_pipe_control_t
okl4_pipe_control_cast(uint8_t p, okl4_bool_t force);




#define OKL4_PIPE_CONTROL_OP_CLR_HALTED ((okl4_pipe_control_t)(4U))

#define OKL4_PIPE_CONTROL_OP_RESET ((okl4_pipe_control_t)(0U))

#define OKL4_PIPE_CONTROL_OP_SET_HALTED ((okl4_pipe_control_t)(3U))

#define OKL4_PIPE_CONTROL_OP_SET_RX_READY ((okl4_pipe_control_t)(2U))

#define OKL4_PIPE_CONTROL_OP_SET_TX_READY ((okl4_pipe_control_t)(1U))


#define OKL4_PIPE_CONTROL_DO_OP_MASK (okl4_pipe_control_t)(1U) 

#define OKL4_MASK_DO_OP_PIPE_CONTROL (okl4_pipe_control_t)(1U)

#define OKL4_SHIFT_DO_OP_PIPE_CONTROL (0)

#define OKL4_WIDTH_DO_OP_PIPE_CONTROL (1)

#define OKL4_PIPE_CONTROL_OPERATION_MASK (okl4_pipe_control_t)(7U << 1) 

#define OKL4_MASK_OPERATION_PIPE_CONTROL (okl4_pipe_control_t)(7U << 1)

#define OKL4_SHIFT_OPERATION_PIPE_CONTROL (1)

#define OKL4_WIDTH_OPERATION_PIPE_CONTROL (3)





OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_control_getdoop(const okl4_pipe_control_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_pipe_control_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_control_setdoop(okl4_pipe_control_t *x, okl4_bool_t _do_op)
{
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_pipe_control_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_do_op;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint8_t
okl4_pipe_control_getoperation(const okl4_pipe_control_t *x)
{
    uint8_t field;
    union {
        
        struct {
            uint32_t _skip : 1;
            uint32_t field : 3;
        } bits;
        okl4_pipe_control_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint8_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_control_setoperation(okl4_pipe_control_t *x, uint8_t _operation)
{
    union {
        
        struct {
            uint32_t _skip : 1;
            uint32_t field : 3;
        } bits;
        okl4_pipe_control_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_operation;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_pipe_control_init(okl4_pipe_control_t *x)
{
    *x = (okl4_pipe_control_t)0U;
}


OKL4_FORCE_INLINE okl4_pipe_control_t
okl4_pipe_control_cast(uint8_t p, okl4_bool_t force)
{
    okl4_pipe_control_t x = (okl4_pipe_control_t)p;
    (void)force;
    return x;
}






typedef uint8_t okl4_pipe_state_t;



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getreset(const okl4_pipe_state_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_state_setreset(okl4_pipe_state_t *x, okl4_bool_t _reset);



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_gethalted(const okl4_pipe_state_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_state_sethalted(okl4_pipe_state_t *x, okl4_bool_t _halted);



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getrxready(const okl4_pipe_state_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_state_setrxready(okl4_pipe_state_t *x, okl4_bool_t _rx_ready);



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_gettxready(const okl4_pipe_state_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_state_settxready(okl4_pipe_state_t *x, okl4_bool_t _tx_ready);



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getrxavailable(const okl4_pipe_state_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_state_setrxavailable(okl4_pipe_state_t *x, okl4_bool_t _rx_available);



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_gettxavailable(const okl4_pipe_state_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_state_settxavailable(okl4_pipe_state_t *x, okl4_bool_t _tx_available);



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getwaiting(const okl4_pipe_state_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_state_setwaiting(okl4_pipe_state_t *x, okl4_bool_t _waiting);



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getoverquota(const okl4_pipe_state_t *x);


OKL4_FORCE_INLINE void
okl4_pipe_state_setoverquota(okl4_pipe_state_t *x, okl4_bool_t _overquota);


OKL4_FORCE_INLINE void
okl4_pipe_state_init(okl4_pipe_state_t *x);


OKL4_FORCE_INLINE okl4_pipe_state_t
okl4_pipe_state_cast(uint8_t p, okl4_bool_t force);





#define OKL4_PIPE_STATE_RESET_MASK (okl4_pipe_state_t)(1U) 

#define OKL4_MASK_RESET_PIPE_STATE (okl4_pipe_state_t)(1U)

#define OKL4_SHIFT_RESET_PIPE_STATE (0)

#define OKL4_WIDTH_RESET_PIPE_STATE (1)

#define OKL4_PIPE_STATE_HALTED_MASK (okl4_pipe_state_t)(1U << 1) 

#define OKL4_MASK_HALTED_PIPE_STATE (okl4_pipe_state_t)(1U << 1)

#define OKL4_SHIFT_HALTED_PIPE_STATE (1)

#define OKL4_WIDTH_HALTED_PIPE_STATE (1)

#define OKL4_PIPE_STATE_RX_READY_MASK (okl4_pipe_state_t)(1U << 2) 

#define OKL4_MASK_RX_READY_PIPE_STATE (okl4_pipe_state_t)(1U << 2)

#define OKL4_SHIFT_RX_READY_PIPE_STATE (2)

#define OKL4_WIDTH_RX_READY_PIPE_STATE (1)

#define OKL4_PIPE_STATE_TX_READY_MASK (okl4_pipe_state_t)(1U << 3) 

#define OKL4_MASK_TX_READY_PIPE_STATE (okl4_pipe_state_t)(1U << 3)

#define OKL4_SHIFT_TX_READY_PIPE_STATE (3)

#define OKL4_WIDTH_TX_READY_PIPE_STATE (1)

#define OKL4_PIPE_STATE_RX_AVAILABLE_MASK (okl4_pipe_state_t)(1U << 4) 

#define OKL4_MASK_RX_AVAILABLE_PIPE_STATE (okl4_pipe_state_t)(1U << 4)

#define OKL4_SHIFT_RX_AVAILABLE_PIPE_STATE (4)

#define OKL4_WIDTH_RX_AVAILABLE_PIPE_STATE (1)

#define OKL4_PIPE_STATE_TX_AVAILABLE_MASK (okl4_pipe_state_t)(1U << 5) 

#define OKL4_MASK_TX_AVAILABLE_PIPE_STATE (okl4_pipe_state_t)(1U << 5)

#define OKL4_SHIFT_TX_AVAILABLE_PIPE_STATE (5)

#define OKL4_WIDTH_TX_AVAILABLE_PIPE_STATE (1)

#define OKL4_PIPE_STATE_WAITING_MASK (okl4_pipe_state_t)(1U << 6) 

#define OKL4_MASK_WAITING_PIPE_STATE (okl4_pipe_state_t)(1U << 6)

#define OKL4_SHIFT_WAITING_PIPE_STATE (6)

#define OKL4_WIDTH_WAITING_PIPE_STATE (1)

#define OKL4_PIPE_STATE_OVERQUOTA_MASK (okl4_pipe_state_t)(1U << 7) 

#define OKL4_MASK_OVERQUOTA_PIPE_STATE (okl4_pipe_state_t)(1U << 7)

#define OKL4_SHIFT_OVERQUOTA_PIPE_STATE (7)

#define OKL4_WIDTH_OVERQUOTA_PIPE_STATE (1)





OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getreset(const okl4_pipe_state_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_state_setreset(okl4_pipe_state_t *x, okl4_bool_t _reset)
{
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_reset;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_gethalted(const okl4_pipe_state_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_state_sethalted(okl4_pipe_state_t *x, okl4_bool_t _halted)
{
    union {
        
        struct {
            uint32_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_halted;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getrxready(const okl4_pipe_state_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 2;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_state_setrxready(okl4_pipe_state_t *x, okl4_bool_t _rx_ready)
{
    union {
        
        struct {
            uint32_t _skip : 2;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_rx_ready;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_gettxready(const okl4_pipe_state_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 3;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_state_settxready(okl4_pipe_state_t *x, okl4_bool_t _tx_ready)
{
    union {
        
        struct {
            uint32_t _skip : 3;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_tx_ready;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getrxavailable(const okl4_pipe_state_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 4;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_state_setrxavailable(okl4_pipe_state_t *x, okl4_bool_t _rx_available)
{
    union {
        
        struct {
            uint32_t _skip : 4;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_rx_available;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_gettxavailable(const okl4_pipe_state_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 5;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_state_settxavailable(okl4_pipe_state_t *x, okl4_bool_t _tx_available)
{
    union {
        
        struct {
            uint32_t _skip : 5;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_tx_available;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getwaiting(const okl4_pipe_state_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 6;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_state_setwaiting(okl4_pipe_state_t *x, okl4_bool_t _waiting)
{
    union {
        
        struct {
            uint32_t _skip : 6;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_waiting;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_pipe_state_getoverquota(const okl4_pipe_state_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 7;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_pipe_state_setoverquota(okl4_pipe_state_t *x, okl4_bool_t _overquota)
{
    union {
        
        struct {
            uint32_t _skip : 7;
            _Bool field : 1;
        } bits;
        okl4_pipe_state_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_overquota;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_pipe_state_init(okl4_pipe_state_t *x)
{
    *x = (okl4_pipe_state_t)1U;
}


OKL4_FORCE_INLINE okl4_pipe_state_t
okl4_pipe_state_cast(uint8_t p, okl4_bool_t force)
{
    okl4_pipe_state_t x = (okl4_pipe_state_t)p;
    (void)force;
    return x;
}




typedef uint32_t okl4_power_state_t;


#define OKL4_POWER_STATE_IDLE ((okl4_power_state_t)(2147483648U))


#define OKL4_POWER_STATE_PLATFORM_LAST ((okl4_power_state_t)(2147483647U))


#define OKL4_POWER_STATE_POWEROFF ((okl4_power_state_t)(2147483650U))


#define OKL4_POWER_STATE_RETENTION ((okl4_power_state_t)(2147483649U))





typedef int8_t okl4_priority_t;





typedef okl4_register_t okl4_psize_pn_t;





typedef okl4_register_t okl4_psize_tr_t;






typedef uint32_t okl4_register_set_t;


#define OKL4_REGISTER_SET_CPU_REGS ((okl4_register_set_t)0x0U)

#define OKL4_REGISTER_SET_VFP_REGS ((okl4_register_set_t)0x1U)

#define OKL4_REGISTER_SET_VFP_CTRL_REGS ((okl4_register_set_t)0x2U)

#define OKL4_REGISTER_SET_VFP64_REGS ((okl4_register_set_t)0x3U)

#define OKL4_REGISTER_SET_VFP128_REGS ((okl4_register_set_t)0x4U)


#define OKL4_REGISTER_SET_MAX ((okl4_register_set_t)0x4U)


#define OKL4_REGISTER_SET_INVALID ((okl4_register_set_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_register_set_is_element_of(okl4_register_set_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_register_set_is_element_of(okl4_register_set_t var)
{
    
    
    return ((var == OKL4_REGISTER_SET_CPU_REGS) ||
            (var == OKL4_REGISTER_SET_VFP_REGS) ||
            (var == OKL4_REGISTER_SET_VFP_CTRL_REGS) ||
            (var == OKL4_REGISTER_SET_VFP64_REGS) ||
            (var == OKL4_REGISTER_SET_VFP128_REGS));
}



typedef okl4_psize_t okl4_vsize_t;







typedef uint32_t okl4_register_and_set_t;



OKL4_FORCE_INLINE okl4_vsize_t
okl4_register_and_set_getoffset(const okl4_register_and_set_t *x);


OKL4_FORCE_INLINE void
okl4_register_and_set_setoffset(okl4_register_and_set_t *x, okl4_vsize_t _offset);



OKL4_FORCE_INLINE okl4_register_set_t
okl4_register_and_set_getset(const okl4_register_and_set_t *x);


OKL4_FORCE_INLINE void
okl4_register_and_set_setset(okl4_register_and_set_t *x, okl4_register_set_t _set);


OKL4_FORCE_INLINE void
okl4_register_and_set_init(okl4_register_and_set_t *x);


OKL4_FORCE_INLINE okl4_register_and_set_t
okl4_register_and_set_cast(uint32_t p, okl4_bool_t force);





#define OKL4_REGISTER_AND_SET_OFFSET_MASK ((okl4_register_and_set_t)65535U) 

#define OKL4_MASK_OFFSET_REGISTER_AND_SET ((okl4_register_and_set_t)65535U)

#define OKL4_SHIFT_OFFSET_REGISTER_AND_SET (0)

#define OKL4_WIDTH_OFFSET_REGISTER_AND_SET (16)

#define OKL4_REGISTER_AND_SET_SET_MASK ((okl4_register_and_set_t)65535U << 16) 

#define OKL4_MASK_SET_REGISTER_AND_SET ((okl4_register_and_set_t)65535U << 16)

#define OKL4_SHIFT_SET_REGISTER_AND_SET (16)

#define OKL4_WIDTH_SET_REGISTER_AND_SET (16)





OKL4_FORCE_INLINE okl4_vsize_t
okl4_register_and_set_getoffset(const okl4_register_and_set_t *x)
{
    okl4_vsize_t field;
    union {
        
        struct {
            uint32_t field : 16;
        } bits;
        okl4_register_and_set_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_vsize_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_register_and_set_setoffset(okl4_register_and_set_t *x, okl4_vsize_t _offset)
{
    union {
        
        struct {
            uint32_t field : 16;
        } bits;
        okl4_register_and_set_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_offset;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_register_set_t
okl4_register_and_set_getset(const okl4_register_and_set_t *x)
{
    okl4_register_set_t field;
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 16;
        } bits;
        okl4_register_and_set_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_register_set_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_register_and_set_setset(okl4_register_and_set_t *x, okl4_register_set_t _set)
{
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 16;
        } bits;
        okl4_register_and_set_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_set;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_register_and_set_init(okl4_register_and_set_t *x)
{
    *x = (okl4_register_and_set_t)0U;
}


OKL4_FORCE_INLINE okl4_register_and_set_t
okl4_register_and_set_cast(uint32_t p, okl4_bool_t force)
{
    okl4_register_and_set_t x = (okl4_register_and_set_t)p;
    (void)force;
    return x;
}




struct okl4_cpu_registers {
    okl4_register_t x[31];
    okl4_register_t sp_el0;
    okl4_register_t ip;
    uint32_t cpsr;
    _okl4_padding_t __padding0_4; 
    _okl4_padding_t __padding1_5; 
    _okl4_padding_t __padding2_6; 
    _okl4_padding_t __padding3_7; 
    okl4_register_t sp_EL1;
    okl4_register_t elr_EL1;
    uint32_t spsr_EL1;
    uint32_t spsr_abt;
    uint32_t spsr_und;
    uint32_t spsr_irq;
    uint32_t spsr_fiq;
    uint32_t csselr_EL1;
    okl4_arm_sctlr_t sctlr_EL1;
    uint32_t cpacr_EL1;
    uint64_t ttbr0_EL1;
    uint64_t ttbr1_EL1;
    uint64_t tcr_EL1;
    uint32_t dacr32_EL2;
    uint32_t ifsr32_EL2;
    uint32_t esr_EL1;
    _okl4_padding_t __padding4_4; 
    _okl4_padding_t __padding5_5; 
    _okl4_padding_t __padding6_6; 
    _okl4_padding_t __padding7_7; 
    uint64_t far_EL1;
    uint64_t par_EL1;
    uint64_t mair_EL1;
    uint64_t vbar_EL1;
    uint32_t contextidr_EL1;
    _okl4_padding_t __padding8_4; 
    _okl4_padding_t __padding9_5; 
    _okl4_padding_t __padding10_6; 
    _okl4_padding_t __padding11_7; 
    uint64_t tpidr_EL1;
    uint64_t tpidrro_EL0;
    uint64_t tpidr_EL0;
    uint32_t pmcr_EL0;
    _okl4_padding_t __padding12_4; 
    _okl4_padding_t __padding13_5; 
    _okl4_padding_t __padding14_6; 
    _okl4_padding_t __padding15_7; 
    uint64_t pmccntr_EL0;
    uint32_t fpexc32_EL2;
    uint32_t cntkctl_EL1;
};








typedef struct okl4_cpu_registers okl4_cpu_registers_t;






typedef uint32_t okl4_rights_t;





typedef uint64_t okl4_soc_time_t;






struct okl4_schedule_profile_data {
    okl4_soc_time_t timestamp;
    okl4_soc_time_t cpu_time;
    okl4_count_t context_switches;
    okl4_count_t cpu_migrations;
    okl4_count_t cpu_hwirqs;
    okl4_count_t cpu_virqs;
};







typedef okl4_virq_flags_t okl4_scheduler_virq_flags_t;



OKL4_FORCE_INLINE okl4_bool_t
okl4_scheduler_virq_flags_getpowersuspended(const okl4_scheduler_virq_flags_t *x);


OKL4_FORCE_INLINE void
okl4_scheduler_virq_flags_setpowersuspended(okl4_scheduler_virq_flags_t *x, okl4_bool_t _power_suspended);


OKL4_FORCE_INLINE void
okl4_scheduler_virq_flags_init(okl4_scheduler_virq_flags_t *x);


OKL4_FORCE_INLINE okl4_scheduler_virq_flags_t
okl4_scheduler_virq_flags_cast(uint64_t p, okl4_bool_t force);





#define OKL4_SCHEDULER_VIRQ_FLAGS_POWER_SUSPENDED_MASK ((okl4_scheduler_virq_flags_t)1U) 

#define OKL4_MASK_POWER_SUSPENDED_SCHEDULER_VIRQ_FLAGS ((okl4_scheduler_virq_flags_t)1U)

#define OKL4_SHIFT_POWER_SUSPENDED_SCHEDULER_VIRQ_FLAGS (0)

#define OKL4_WIDTH_POWER_SUSPENDED_SCHEDULER_VIRQ_FLAGS (1)





OKL4_FORCE_INLINE okl4_bool_t
okl4_scheduler_virq_flags_getpowersuspended(const okl4_scheduler_virq_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_scheduler_virq_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_scheduler_virq_flags_setpowersuspended(okl4_scheduler_virq_flags_t *x, okl4_bool_t _power_suspended)
{
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_scheduler_virq_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_power_suspended;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_scheduler_virq_flags_init(okl4_scheduler_virq_flags_t *x)
{
    *x = (okl4_scheduler_virq_flags_t)0U;
}


OKL4_FORCE_INLINE okl4_scheduler_virq_flags_t
okl4_scheduler_virq_flags_cast(uint64_t p, okl4_bool_t force)
{
    okl4_scheduler_virq_flags_t x = (okl4_scheduler_virq_flags_t)p;
    (void)force;
    return x;
}





typedef int32_t okl4_scount_t;







typedef uint32_t okl4_sdk_version_t;



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getformatflag(const okl4_sdk_version_t *x);


OKL4_FORCE_INLINE void
okl4_sdk_version_setformatflag(okl4_sdk_version_t *x, uint32_t _format_flag);



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getdevflag(const okl4_sdk_version_t *x);


OKL4_FORCE_INLINE void
okl4_sdk_version_setdevflag(okl4_sdk_version_t *x, uint32_t _dev_flag);



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getres0flag(const okl4_sdk_version_t *x);


OKL4_FORCE_INLINE void
okl4_sdk_version_setres0flag(okl4_sdk_version_t *x, uint32_t _res0_flag);



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getmajor(const okl4_sdk_version_t *x);


OKL4_FORCE_INLINE void
okl4_sdk_version_setmajor(okl4_sdk_version_t *x, uint32_t _major);



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getminor(const okl4_sdk_version_t *x);


OKL4_FORCE_INLINE void
okl4_sdk_version_setminor(okl4_sdk_version_t *x, uint32_t _minor);



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getrelease(const okl4_sdk_version_t *x);


OKL4_FORCE_INLINE void
okl4_sdk_version_setrelease(okl4_sdk_version_t *x, uint32_t _release);



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getmaintenance(const okl4_sdk_version_t *x);


OKL4_FORCE_INLINE void
okl4_sdk_version_setmaintenance(okl4_sdk_version_t *x, uint32_t _maintenance);


OKL4_FORCE_INLINE void
okl4_sdk_version_init(okl4_sdk_version_t *x);


OKL4_FORCE_INLINE okl4_sdk_version_t
okl4_sdk_version_cast(uint32_t p, okl4_bool_t force);





#define OKL4_SDK_VERSION_MAINTENANCE_MASK ((okl4_sdk_version_t)63U) 


#define OKL4_MASK_MAINTENANCE_SDK_VERSION ((okl4_sdk_version_t)63U)

#define OKL4_SHIFT_MAINTENANCE_SDK_VERSION (0)

#define OKL4_WIDTH_MAINTENANCE_SDK_VERSION (6)

#define OKL4_SDK_VERSION_RELEASE_MASK ((okl4_sdk_version_t)255U << 8) 


#define OKL4_MASK_RELEASE_SDK_VERSION ((okl4_sdk_version_t)255U << 8)

#define OKL4_SHIFT_RELEASE_SDK_VERSION (8)

#define OKL4_WIDTH_RELEASE_SDK_VERSION (8)

#define OKL4_SDK_VERSION_MINOR_MASK ((okl4_sdk_version_t)63U << 16) 


#define OKL4_MASK_MINOR_SDK_VERSION ((okl4_sdk_version_t)63U << 16)

#define OKL4_SHIFT_MINOR_SDK_VERSION (16)

#define OKL4_WIDTH_MINOR_SDK_VERSION (6)

#define OKL4_SDK_VERSION_MAJOR_MASK ((okl4_sdk_version_t)15U << 24) 


#define OKL4_MASK_MAJOR_SDK_VERSION ((okl4_sdk_version_t)15U << 24)

#define OKL4_SHIFT_MAJOR_SDK_VERSION (24)

#define OKL4_WIDTH_MAJOR_SDK_VERSION (4)

#define OKL4_SDK_VERSION_RES0_FLAG_MASK ((okl4_sdk_version_t)1U << 28) 


#define OKL4_MASK_RES0_FLAG_SDK_VERSION ((okl4_sdk_version_t)1U << 28)

#define OKL4_SHIFT_RES0_FLAG_SDK_VERSION (28)

#define OKL4_WIDTH_RES0_FLAG_SDK_VERSION (1)

#define OKL4_SDK_VERSION_DEV_FLAG_MASK ((okl4_sdk_version_t)1U << 30) 


#define OKL4_MASK_DEV_FLAG_SDK_VERSION ((okl4_sdk_version_t)1U << 30)

#define OKL4_SHIFT_DEV_FLAG_SDK_VERSION (30)

#define OKL4_WIDTH_DEV_FLAG_SDK_VERSION (1)

#define OKL4_SDK_VERSION_FORMAT_FLAG_MASK ((okl4_sdk_version_t)1U << 31) 


#define OKL4_MASK_FORMAT_FLAG_SDK_VERSION ((okl4_sdk_version_t)1U << 31)

#define OKL4_SHIFT_FORMAT_FLAG_SDK_VERSION (31)

#define OKL4_WIDTH_FORMAT_FLAG_SDK_VERSION (1)





OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getmaintenance(const okl4_sdk_version_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t field : 6;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_sdk_version_setmaintenance(okl4_sdk_version_t *x, uint32_t _maintenance)
{
    union {
        
        struct {
            uint32_t field : 6;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_maintenance;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getrelease(const okl4_sdk_version_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 8;
            uint32_t field : 8;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_sdk_version_setrelease(okl4_sdk_version_t *x, uint32_t _release)
{
    union {
        
        struct {
            uint32_t _skip : 8;
            uint32_t field : 8;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_release;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getminor(const okl4_sdk_version_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 6;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_sdk_version_setminor(okl4_sdk_version_t *x, uint32_t _minor)
{
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 6;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_minor;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getmajor(const okl4_sdk_version_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 24;
            uint32_t field : 4;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_sdk_version_setmajor(okl4_sdk_version_t *x, uint32_t _major)
{
    union {
        
        struct {
            uint32_t _skip : 24;
            uint32_t field : 4;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_major;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getres0flag(const okl4_sdk_version_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 28;
            uint32_t field : 1;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_sdk_version_setres0flag(okl4_sdk_version_t *x, uint32_t _res0_flag)
{
    union {
        
        struct {
            uint32_t _skip : 28;
            uint32_t field : 1;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_res0_flag;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getdevflag(const okl4_sdk_version_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 30;
            uint32_t field : 1;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_sdk_version_setdevflag(okl4_sdk_version_t *x, uint32_t _dev_flag)
{
    union {
        
        struct {
            uint32_t _skip : 30;
            uint32_t field : 1;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_dev_flag;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
okl4_sdk_version_getformatflag(const okl4_sdk_version_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 31;
            uint32_t field : 1;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_sdk_version_setformatflag(okl4_sdk_version_t *x, uint32_t _format_flag)
{
    union {
        
        struct {
            uint32_t _skip : 31;
            uint32_t field : 1;
        } bits;
        okl4_sdk_version_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_format_flag;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_sdk_version_init(okl4_sdk_version_t *x)
{
    *x = (okl4_sdk_version_t)0U;
}


OKL4_FORCE_INLINE okl4_sdk_version_t
okl4_sdk_version_cast(uint32_t p, okl4_bool_t force)
{
    okl4_sdk_version_t x = (okl4_sdk_version_t)p;
    (void)force;
    return x;
}





struct okl4_shared_buffer {
    okl4_paddr_t physical_base;
    struct okl4_virtmem_item virtmem_item;
    okl4_kcap_t cap;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
};






struct okl4_shared_buffers_array {
    __ptr64(struct okl4_shared_buffer *, buffers);
    okl4_count_t num_buffers;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
};





typedef okl4_kcap_t okl4_signal_t;










typedef int64_t okl4_sregister_t;





typedef uint64_t okl4_ticks_t;







typedef uint32_t okl4_timer_flags_t;



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getactive(const okl4_timer_flags_t *x);


OKL4_FORCE_INLINE void
okl4_timer_flags_setactive(okl4_timer_flags_t *x, okl4_bool_t _active);



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getperiodic(const okl4_timer_flags_t *x);


OKL4_FORCE_INLINE void
okl4_timer_flags_setperiodic(okl4_timer_flags_t *x, okl4_bool_t _periodic);



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getabsolute(const okl4_timer_flags_t *x);


OKL4_FORCE_INLINE void
okl4_timer_flags_setabsolute(okl4_timer_flags_t *x, okl4_bool_t _absolute);



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getunits(const okl4_timer_flags_t *x);


OKL4_FORCE_INLINE void
okl4_timer_flags_setunits(okl4_timer_flags_t *x, okl4_bool_t _units);



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getalign(const okl4_timer_flags_t *x);


OKL4_FORCE_INLINE void
okl4_timer_flags_setalign(okl4_timer_flags_t *x, okl4_bool_t _align);



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getwatchdog(const okl4_timer_flags_t *x);


OKL4_FORCE_INLINE void
okl4_timer_flags_setwatchdog(okl4_timer_flags_t *x, okl4_bool_t _watchdog);



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getreload(const okl4_timer_flags_t *x);


OKL4_FORCE_INLINE void
okl4_timer_flags_setreload(okl4_timer_flags_t *x, okl4_bool_t _reload);



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_gettimeslice(const okl4_timer_flags_t *x);


OKL4_FORCE_INLINE void
okl4_timer_flags_settimeslice(okl4_timer_flags_t *x, okl4_bool_t _timeslice);


OKL4_FORCE_INLINE void
okl4_timer_flags_init(okl4_timer_flags_t *x);


OKL4_FORCE_INLINE okl4_timer_flags_t
okl4_timer_flags_cast(uint32_t p, okl4_bool_t force);





#define OKL4_TIMER_FLAGS_ACTIVE_MASK ((okl4_timer_flags_t)1U) 


#define OKL4_MASK_ACTIVE_TIMER_FLAGS ((okl4_timer_flags_t)1U)

#define OKL4_SHIFT_ACTIVE_TIMER_FLAGS (0)

#define OKL4_WIDTH_ACTIVE_TIMER_FLAGS (1)

#define OKL4_TIMER_FLAGS_PERIODIC_MASK ((okl4_timer_flags_t)1U << 1) 


#define OKL4_MASK_PERIODIC_TIMER_FLAGS ((okl4_timer_flags_t)1U << 1)

#define OKL4_SHIFT_PERIODIC_TIMER_FLAGS (1)

#define OKL4_WIDTH_PERIODIC_TIMER_FLAGS (1)

#define OKL4_TIMER_FLAGS_ABSOLUTE_MASK ((okl4_timer_flags_t)1U << 2) 


#define OKL4_MASK_ABSOLUTE_TIMER_FLAGS ((okl4_timer_flags_t)1U << 2)

#define OKL4_SHIFT_ABSOLUTE_TIMER_FLAGS (2)

#define OKL4_WIDTH_ABSOLUTE_TIMER_FLAGS (1)

#define OKL4_TIMER_FLAGS_UNITS_MASK ((okl4_timer_flags_t)1U << 3) 


#define OKL4_MASK_UNITS_TIMER_FLAGS ((okl4_timer_flags_t)1U << 3)

#define OKL4_SHIFT_UNITS_TIMER_FLAGS (3)

#define OKL4_WIDTH_UNITS_TIMER_FLAGS (1)

#define OKL4_TIMER_FLAGS_ALIGN_MASK ((okl4_timer_flags_t)1U << 4) 


#define OKL4_MASK_ALIGN_TIMER_FLAGS ((okl4_timer_flags_t)1U << 4)

#define OKL4_SHIFT_ALIGN_TIMER_FLAGS (4)

#define OKL4_WIDTH_ALIGN_TIMER_FLAGS (1)

#define OKL4_TIMER_FLAGS_WATCHDOG_MASK ((okl4_timer_flags_t)1U << 5) 


#define OKL4_MASK_WATCHDOG_TIMER_FLAGS ((okl4_timer_flags_t)1U << 5)

#define OKL4_SHIFT_WATCHDOG_TIMER_FLAGS (5)

#define OKL4_WIDTH_WATCHDOG_TIMER_FLAGS (1)

#define OKL4_TIMER_FLAGS_RELOAD_MASK ((okl4_timer_flags_t)1U << 30) 

#define OKL4_MASK_RELOAD_TIMER_FLAGS ((okl4_timer_flags_t)1U << 30)

#define OKL4_SHIFT_RELOAD_TIMER_FLAGS (30)

#define OKL4_WIDTH_RELOAD_TIMER_FLAGS (1)

#define OKL4_TIMER_FLAGS_TIMESLICE_MASK ((okl4_timer_flags_t)1U << 31) 

#define OKL4_MASK_TIMESLICE_TIMER_FLAGS ((okl4_timer_flags_t)1U << 31)

#define OKL4_SHIFT_TIMESLICE_TIMER_FLAGS (31)

#define OKL4_WIDTH_TIMESLICE_TIMER_FLAGS (1)





OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getactive(const okl4_timer_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_timer_flags_setactive(okl4_timer_flags_t *x, okl4_bool_t _active)
{
    union {
        
        struct {
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_active;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getperiodic(const okl4_timer_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_timer_flags_setperiodic(okl4_timer_flags_t *x, okl4_bool_t _periodic)
{
    union {
        
        struct {
            uint32_t _skip : 1;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_periodic;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getabsolute(const okl4_timer_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 2;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_timer_flags_setabsolute(okl4_timer_flags_t *x, okl4_bool_t _absolute)
{
    union {
        
        struct {
            uint32_t _skip : 2;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_absolute;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getunits(const okl4_timer_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 3;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_timer_flags_setunits(okl4_timer_flags_t *x, okl4_bool_t _units)
{
    union {
        
        struct {
            uint32_t _skip : 3;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_units;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getalign(const okl4_timer_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 4;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_timer_flags_setalign(okl4_timer_flags_t *x, okl4_bool_t _align)
{
    union {
        
        struct {
            uint32_t _skip : 4;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_align;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getwatchdog(const okl4_timer_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 5;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_timer_flags_setwatchdog(okl4_timer_flags_t *x, okl4_bool_t _watchdog)
{
    union {
        
        struct {
            uint32_t _skip : 5;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_watchdog;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_getreload(const okl4_timer_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 30;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_timer_flags_setreload(okl4_timer_flags_t *x, okl4_bool_t _reload)
{
    union {
        
        struct {
            uint32_t _skip : 30;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_reload;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
okl4_timer_flags_gettimeslice(const okl4_timer_flags_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 31;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
okl4_timer_flags_settimeslice(okl4_timer_flags_t *x, okl4_bool_t _timeslice)
{
    union {
        
        struct {
            uint32_t _skip : 31;
            _Bool field : 1;
        } bits;
        okl4_timer_flags_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_timeslice;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
okl4_timer_flags_init(okl4_timer_flags_t *x)
{
    *x = (okl4_timer_flags_t)0U;
}


OKL4_FORCE_INLINE okl4_timer_flags_t
okl4_timer_flags_cast(uint32_t p, okl4_bool_t force)
{
    okl4_timer_flags_t x = (okl4_timer_flags_t)p;
    (void)force;
    return x;
}




struct _okl4_tracebuffer_buffer_header {
    okl4_soc_time_t timestamp;
    okl4_count_t wrap;
    _okl4_padding_t __padding0_4; 
    _okl4_padding_t __padding1_5; 
    _okl4_padding_t __padding2_6; 
    _okl4_padding_t __padding3_7; 
    okl4_ksize_t size;
    okl4_ksize_t head;
    okl4_ksize_t offset;
};








struct okl4_tracebuffer_env {
    struct okl4_virtmem_item virt;
    okl4_interrupt_number_t virq;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
};





struct _okl4_tracebuffer_header {
    uint32_t magic;
    uint32_t version;
    uint32_t id;
    okl4_count_t num_buffers;
    okl4_ksize_t buffer_size;
    okl4_atomic_uint32_t log_mask;
    okl4_atomic_uint32_t active_buffer;
    okl4_atomic_uint32_t grabbed_buffer;
    okl4_atomic_uint32_t empty_buffers;
    struct _okl4_tracebuffer_buffer_header buffers[]; 
};







typedef uint32_t okl4_tracepoint_class_t;


#define OKL4_TRACEPOINT_CLASS_THREAD_STATE ((okl4_tracepoint_class_t)0x0U)

#define OKL4_TRACEPOINT_CLASS_SYSCALLS ((okl4_tracepoint_class_t)0x1U)

#define OKL4_TRACEPOINT_CLASS_PRIMARY ((okl4_tracepoint_class_t)0x2U)

#define OKL4_TRACEPOINT_CLASS_SECONDARY ((okl4_tracepoint_class_t)0x3U)

#define OKL4_TRACEPOINT_CLASS_TERTIARY ((okl4_tracepoint_class_t)0x4U)


#define OKL4_TRACEPOINT_CLASS_MAX ((okl4_tracepoint_class_t)0x4U)


#define OKL4_TRACEPOINT_CLASS_INVALID ((okl4_tracepoint_class_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_tracepoint_class_is_element_of(okl4_tracepoint_class_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_tracepoint_class_is_element_of(okl4_tracepoint_class_t var)
{
    
    
    return ((var == OKL4_TRACEPOINT_CLASS_THREAD_STATE) ||
            (var == OKL4_TRACEPOINT_CLASS_SYSCALLS) ||
            (var == OKL4_TRACEPOINT_CLASS_PRIMARY) ||
            (var == OKL4_TRACEPOINT_CLASS_SECONDARY) ||
            (var == OKL4_TRACEPOINT_CLASS_TERTIARY));
}





typedef uint32_t _okl4_tracepoint_desc_t;



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_desc_getid(const _okl4_tracepoint_desc_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setid(_okl4_tracepoint_desc_t *x, uint32_t _id);



OKL4_FORCE_INLINE okl4_bool_t
_okl4_tracepoint_desc_getuser(const _okl4_tracepoint_desc_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setuser(_okl4_tracepoint_desc_t *x, okl4_bool_t _user);



OKL4_FORCE_INLINE okl4_bool_t
_okl4_tracepoint_desc_getbin(const _okl4_tracepoint_desc_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setbin(_okl4_tracepoint_desc_t *x, okl4_bool_t _bin);



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_desc_getreclen(const _okl4_tracepoint_desc_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setreclen(_okl4_tracepoint_desc_t *x, uint32_t _reclen);



OKL4_FORCE_INLINE okl4_count_t
_okl4_tracepoint_desc_getcpuid(const _okl4_tracepoint_desc_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setcpuid(_okl4_tracepoint_desc_t *x, okl4_count_t _cpuid);



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_desc_getthreadid(const _okl4_tracepoint_desc_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setthreadid(_okl4_tracepoint_desc_t *x, uint32_t _threadid);



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_desc_getr1(const _okl4_tracepoint_desc_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setr1(_okl4_tracepoint_desc_t *x, uint32_t __r1);


OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_init(_okl4_tracepoint_desc_t *x);


OKL4_FORCE_INLINE _okl4_tracepoint_desc_t
_okl4_tracepoint_desc_cast(uint32_t p, okl4_bool_t force);





#define _OKL4_TRACEPOINT_DESC_ID_MASK ((_okl4_tracepoint_desc_t)255U) 

#define _OKL4_MASK_ID_TRACEPOINT_DESC ((_okl4_tracepoint_desc_t)255U)

#define _OKL4_SHIFT_ID_TRACEPOINT_DESC (0)

#define _OKL4_WIDTH_ID_TRACEPOINT_DESC (8)

#define _OKL4_TRACEPOINT_DESC_USER_MASK ((_okl4_tracepoint_desc_t)1U << 8) 

#define _OKL4_MASK_USER_TRACEPOINT_DESC ((_okl4_tracepoint_desc_t)1U << 8)

#define _OKL4_SHIFT_USER_TRACEPOINT_DESC (8)

#define _OKL4_WIDTH_USER_TRACEPOINT_DESC (1)

#define _OKL4_TRACEPOINT_DESC_BIN_MASK ((_okl4_tracepoint_desc_t)1U << 9) 

#define _OKL4_MASK_BIN_TRACEPOINT_DESC ((_okl4_tracepoint_desc_t)1U << 9)

#define _OKL4_SHIFT_BIN_TRACEPOINT_DESC (9)

#define _OKL4_WIDTH_BIN_TRACEPOINT_DESC (1)

#define _OKL4_TRACEPOINT_DESC_RECLEN_MASK ((_okl4_tracepoint_desc_t)63U << 10) 

#define _OKL4_MASK_RECLEN_TRACEPOINT_DESC ((_okl4_tracepoint_desc_t)63U << 10)

#define _OKL4_SHIFT_RECLEN_TRACEPOINT_DESC (10)

#define _OKL4_WIDTH_RECLEN_TRACEPOINT_DESC (6)

#define _OKL4_TRACEPOINT_DESC_CPUID_MASK ((_okl4_tracepoint_desc_t)63U << 16) 

#define _OKL4_MASK_CPUID_TRACEPOINT_DESC ((_okl4_tracepoint_desc_t)63U << 16)

#define _OKL4_SHIFT_CPUID_TRACEPOINT_DESC (16)

#define _OKL4_WIDTH_CPUID_TRACEPOINT_DESC (6)

#define _OKL4_TRACEPOINT_DESC_THREADID_MASK ((_okl4_tracepoint_desc_t)63U << 22) 

#define _OKL4_MASK_THREADID_TRACEPOINT_DESC ((_okl4_tracepoint_desc_t)63U << 22)

#define _OKL4_SHIFT_THREADID_TRACEPOINT_DESC (22)

#define _OKL4_WIDTH_THREADID_TRACEPOINT_DESC (6)

#define _OKL4_TRACEPOINT_DESC__R1_MASK ((_okl4_tracepoint_desc_t)15U << 28) 

#define _OKL4_MASK__R1_TRACEPOINT_DESC ((_okl4_tracepoint_desc_t)15U << 28)

#define _OKL4_SHIFT__R1_TRACEPOINT_DESC (28)

#define _OKL4_WIDTH__R1_TRACEPOINT_DESC (4)





OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_desc_getid(const _okl4_tracepoint_desc_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t field : 8;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setid(_okl4_tracepoint_desc_t *x, uint32_t _id)
{
    union {
        
        struct {
            uint32_t field : 8;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_id;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
_okl4_tracepoint_desc_getuser(const _okl4_tracepoint_desc_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 8;
            _Bool field : 1;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setuser(_okl4_tracepoint_desc_t *x, okl4_bool_t _user)
{
    union {
        
        struct {
            uint32_t _skip : 8;
            _Bool field : 1;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_user;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_bool_t
_okl4_tracepoint_desc_getbin(const _okl4_tracepoint_desc_t *x)
{
    okl4_bool_t field;
    union {
        
        struct {
            uint32_t _skip : 9;
            _Bool field : 1;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_bool_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setbin(_okl4_tracepoint_desc_t *x, okl4_bool_t _bin)
{
    union {
        
        struct {
            uint32_t _skip : 9;
            _Bool field : 1;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (_Bool)_bin;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_desc_getreclen(const _okl4_tracepoint_desc_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 10;
            uint32_t field : 6;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setreclen(_okl4_tracepoint_desc_t *x, uint32_t _reclen)
{
    union {
        
        struct {
            uint32_t _skip : 10;
            uint32_t field : 6;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_reclen;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE okl4_count_t
_okl4_tracepoint_desc_getcpuid(const _okl4_tracepoint_desc_t *x)
{
    okl4_count_t field;
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 6;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    field = (okl4_count_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setcpuid(_okl4_tracepoint_desc_t *x, okl4_count_t _cpuid)
{
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 6;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_cpuid;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_desc_getthreadid(const _okl4_tracepoint_desc_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 22;
            uint32_t field : 6;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setthreadid(_okl4_tracepoint_desc_t *x, uint32_t _threadid)
{
    union {
        
        struct {
            uint32_t _skip : 22;
            uint32_t field : 6;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_threadid;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_desc_getr1(const _okl4_tracepoint_desc_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 28;
            uint32_t field : 4;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_setr1(_okl4_tracepoint_desc_t *x, uint32_t __r1)
{
    union {
        
        struct {
            uint32_t _skip : 28;
            uint32_t field : 4;
        } bits;
        _okl4_tracepoint_desc_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)__r1;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
_okl4_tracepoint_desc_init(_okl4_tracepoint_desc_t *x)
{
    *x = (_okl4_tracepoint_desc_t)0U;
}


OKL4_FORCE_INLINE _okl4_tracepoint_desc_t
_okl4_tracepoint_desc_cast(uint32_t p, okl4_bool_t force)
{
    _okl4_tracepoint_desc_t x = (_okl4_tracepoint_desc_t)p;
    (void)force;
    return x;
}






typedef uint32_t _okl4_tracepoint_masks_t;



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_masks_getclass(const _okl4_tracepoint_masks_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_masks_setclass(_okl4_tracepoint_masks_t *x, uint32_t _class);



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_masks_getsubsystem(const _okl4_tracepoint_masks_t *x);


OKL4_FORCE_INLINE void
_okl4_tracepoint_masks_setsubsystem(_okl4_tracepoint_masks_t *x, uint32_t _subsystem);


OKL4_FORCE_INLINE void
_okl4_tracepoint_masks_init(_okl4_tracepoint_masks_t *x);


OKL4_FORCE_INLINE _okl4_tracepoint_masks_t
_okl4_tracepoint_masks_cast(uint32_t p, okl4_bool_t force);





#define _OKL4_TRACEPOINT_MASKS_CLASS_MASK ((_okl4_tracepoint_masks_t)65535U) 

#define _OKL4_MASK_CLASS_TRACEPOINT_MASKS ((_okl4_tracepoint_masks_t)65535U)

#define _OKL4_SHIFT_CLASS_TRACEPOINT_MASKS (0)

#define _OKL4_WIDTH_CLASS_TRACEPOINT_MASKS (16)

#define _OKL4_TRACEPOINT_MASKS_SUBSYSTEM_MASK ((_okl4_tracepoint_masks_t)65535U << 16) 

#define _OKL4_MASK_SUBSYSTEM_TRACEPOINT_MASKS ((_okl4_tracepoint_masks_t)65535U << 16)

#define _OKL4_SHIFT_SUBSYSTEM_TRACEPOINT_MASKS (16)

#define _OKL4_WIDTH_SUBSYSTEM_TRACEPOINT_MASKS (16)





OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_masks_getclass(const _okl4_tracepoint_masks_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t field : 16;
        } bits;
        _okl4_tracepoint_masks_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_masks_setclass(_okl4_tracepoint_masks_t *x, uint32_t _class)
{
    union {
        
        struct {
            uint32_t field : 16;
        } bits;
        _okl4_tracepoint_masks_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_class;
    *x = _conv.raw;
}



OKL4_FORCE_INLINE uint32_t
_okl4_tracepoint_masks_getsubsystem(const _okl4_tracepoint_masks_t *x)
{
    uint32_t field;
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 16;
        } bits;
        _okl4_tracepoint_masks_t raw;
    } _conv;

    _conv.raw = *x;
    field = (uint32_t)_conv.bits.field;
    return field;
}





OKL4_FORCE_INLINE void
_okl4_tracepoint_masks_setsubsystem(_okl4_tracepoint_masks_t *x, uint32_t _subsystem)
{
    union {
        
        struct {
            uint32_t _skip : 16;
            uint32_t field : 16;
        } bits;
        _okl4_tracepoint_masks_t raw;
    } _conv;

    _conv.raw = *x;
    _conv.bits.field = (uint32_t)_subsystem;
    *x = _conv.raw;
}

OKL4_FORCE_INLINE void
_okl4_tracepoint_masks_init(_okl4_tracepoint_masks_t *x)
{
    *x = (_okl4_tracepoint_masks_t)0U;
}


OKL4_FORCE_INLINE _okl4_tracepoint_masks_t
_okl4_tracepoint_masks_cast(uint32_t p, okl4_bool_t force)
{
    _okl4_tracepoint_masks_t x = (_okl4_tracepoint_masks_t)p;
    (void)force;
    return x;
}




struct okl4_tracepoint_entry_base {
    uint32_t time_offset;
    _okl4_tracepoint_masks_t masks;
    _okl4_tracepoint_desc_t description;
};







typedef uint32_t okl4_tracepoint_evt_t;


#define OKL4_TRACEPOINT_EVT_SCH_SCHEDULER_FLAG_SET_RUNNABLE ((okl4_tracepoint_evt_t)0x0U)

#define OKL4_TRACEPOINT_EVT_SCH_SCHEDULER_FLAG_CLEAR_RUNNABLE ((okl4_tracepoint_evt_t)0x1U)

#define OKL4_TRACEPOINT_EVT_SCH_CONTEXT_SWITCH ((okl4_tracepoint_evt_t)0x2U)

#define OKL4_TRACEPOINT_EVT_KDB_SET_OBJECT_NAME ((okl4_tracepoint_evt_t)0x3U)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_PROCESS_RECV ((okl4_tracepoint_evt_t)0x4U)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_SET_HALTED ((okl4_tracepoint_evt_t)0x5U)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_SET_RECV_AREA ((okl4_tracepoint_evt_t)0x6U)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_SET_RECV_QUEUE ((okl4_tracepoint_evt_t)0x7U)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_SET_RECV_SEGMENT ((okl4_tracepoint_evt_t)0x8U)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_SET_SEND_AREA ((okl4_tracepoint_evt_t)0x9U)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_SET_SEND_QUEUE ((okl4_tracepoint_evt_t)0xaU)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_SET_SEND_SEGMENT ((okl4_tracepoint_evt_t)0xbU)

#define OKL4_TRACEPOINT_EVT_SWI_AXON_TRIGGER_SEND ((okl4_tracepoint_evt_t)0xcU)

#define OKL4_TRACEPOINT_EVT_SWI_DEBUG_RESUME ((okl4_tracepoint_evt_t)0xdU)

#define OKL4_TRACEPOINT_EVT_SWI_DEBUG_SUSPEND ((okl4_tracepoint_evt_t)0xeU)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_ACK ((okl4_tracepoint_evt_t)0xfU)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_ATTACH_PRIVATE ((okl4_tracepoint_evt_t)0x10U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_ATTACH_SHARED ((okl4_tracepoint_evt_t)0x11U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_DETACH ((okl4_tracepoint_evt_t)0x12U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_DIST_ENABLE ((okl4_tracepoint_evt_t)0x13U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_EOI ((okl4_tracepoint_evt_t)0x14U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_GET_HIGHEST_PRIORITY_PENDING ((okl4_tracepoint_evt_t)0x15U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_GET_PAYLOAD ((okl4_tracepoint_evt_t)0x16U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_LIMITS ((okl4_tracepoint_evt_t)0x17U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_MASK ((okl4_tracepoint_evt_t)0x18U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_RAISE ((okl4_tracepoint_evt_t)0x19U)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_BINARY_POINT ((okl4_tracepoint_evt_t)0x1aU)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_CONFIG ((okl4_tracepoint_evt_t)0x1bU)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_CONTROL ((okl4_tracepoint_evt_t)0x1cU)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_PRIORITY ((okl4_tracepoint_evt_t)0x1dU)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_PRIORITY_MASK ((okl4_tracepoint_evt_t)0x1eU)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_TARGETS ((okl4_tracepoint_evt_t)0x1fU)

#define OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_UNMASK ((okl4_tracepoint_evt_t)0x20U)

#define OKL4_TRACEPOINT_EVT_SWI_KDB_INTERACT ((okl4_tracepoint_evt_t)0x21U)

#define OKL4_TRACEPOINT_EVT_SWI_KDB_SET_OBJECT_NAME ((okl4_tracepoint_evt_t)0x22U)

#define OKL4_TRACEPOINT_EVT_SWI_KSP_PROCEDURE_CALL ((okl4_tracepoint_evt_t)0x23U)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_ATTACH_SEGMENT ((okl4_tracepoint_evt_t)0x24U)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_DETACH_SEGMENT ((okl4_tracepoint_evt_t)0x25U)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_FLUSH_RANGE ((okl4_tracepoint_evt_t)0x26U)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_FLUSH_RANGE_PN ((okl4_tracepoint_evt_t)0x27U)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_LOOKUP_PAGE ((okl4_tracepoint_evt_t)0x28U)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_LOOKUP_PN ((okl4_tracepoint_evt_t)0x29U)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_MAP_PAGE ((okl4_tracepoint_evt_t)0x2aU)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_MAP_PN ((okl4_tracepoint_evt_t)0x2bU)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_UNMAP_PAGE ((okl4_tracepoint_evt_t)0x2cU)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_UNMAP_PN ((okl4_tracepoint_evt_t)0x2dU)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_UPDATE_PAGE_ATTRS ((okl4_tracepoint_evt_t)0x2eU)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_UPDATE_PAGE_PERMS ((okl4_tracepoint_evt_t)0x2fU)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_UPDATE_PN_ATTRS ((okl4_tracepoint_evt_t)0x30U)

#define OKL4_TRACEPOINT_EVT_SWI_MMU_UPDATE_PN_PERMS ((okl4_tracepoint_evt_t)0x31U)

#define OKL4_TRACEPOINT_EVT_SWI_PERFORMANCE_NULL_SYSCALL ((okl4_tracepoint_evt_t)0x32U)

#define OKL4_TRACEPOINT_EVT_SWI_PIPE_CONTROL ((okl4_tracepoint_evt_t)0x33U)

#define OKL4_TRACEPOINT_EVT_SWI_PIPE_RECV ((okl4_tracepoint_evt_t)0x34U)

#define OKL4_TRACEPOINT_EVT_SWI_PIPE_SEND ((okl4_tracepoint_evt_t)0x35U)

#define OKL4_TRACEPOINT_EVT_SWI_PRIORITY_WAIVE ((okl4_tracepoint_evt_t)0x36U)

#define OKL4_TRACEPOINT_EVT_SWI_REMOTE_GET_REGISTER ((okl4_tracepoint_evt_t)0x37U)

#define OKL4_TRACEPOINT_EVT_SWI_REMOTE_GET_REGISTERS ((okl4_tracepoint_evt_t)0x38U)

#define OKL4_TRACEPOINT_EVT_SWI_REMOTE_READ_MEMORY32 ((okl4_tracepoint_evt_t)0x39U)

#define OKL4_TRACEPOINT_EVT_SWI_REMOTE_SET_REGISTER ((okl4_tracepoint_evt_t)0x3aU)

#define OKL4_TRACEPOINT_EVT_SWI_REMOTE_SET_REGISTERS ((okl4_tracepoint_evt_t)0x3bU)

#define OKL4_TRACEPOINT_EVT_SWI_REMOTE_WRITE_MEMORY32 ((okl4_tracepoint_evt_t)0x3cU)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_METRICS_STATUS_SUSPENDED ((okl4_tracepoint_evt_t)0x3dU)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_METRICS_WATCH_SUSPENDED ((okl4_tracepoint_evt_t)0x3eU)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_DISABLE ((okl4_tracepoint_evt_t)0x3fU)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_ENABLE ((okl4_tracepoint_evt_t)0x40U)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_GET_DATA ((okl4_tracepoint_evt_t)0x41U)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_DISABLE ((okl4_tracepoint_evt_t)0x42U)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_ENABLE ((okl4_tracepoint_evt_t)0x43U)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_GET_DATA ((okl4_tracepoint_evt_t)0x44U)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULER_AFFINITY_GET ((okl4_tracepoint_evt_t)0x45U)

#define OKL4_TRACEPOINT_EVT_SWI_SCHEDULER_AFFINITY_SET ((okl4_tracepoint_evt_t)0x46U)

#define OKL4_TRACEPOINT_EVT_SWI_TIMER_CANCEL ((okl4_tracepoint_evt_t)0x47U)

#define OKL4_TRACEPOINT_EVT_SWI_TIMER_GET_RESOLUTION ((okl4_tracepoint_evt_t)0x48U)

#define OKL4_TRACEPOINT_EVT_SWI_TIMER_GET_TIME ((okl4_tracepoint_evt_t)0x49U)

#define OKL4_TRACEPOINT_EVT_SWI_TIMER_QUERY ((okl4_tracepoint_evt_t)0x4aU)

#define OKL4_TRACEPOINT_EVT_SWI_TIMER_START ((okl4_tracepoint_evt_t)0x4bU)

#define OKL4_TRACEPOINT_EVT_SWI_TRACEBUFFER_SYNC ((okl4_tracepoint_evt_t)0x4cU)

#define OKL4_TRACEPOINT_EVT_SWI_VCPU_RESET ((okl4_tracepoint_evt_t)0x4dU)

#define OKL4_TRACEPOINT_EVT_SWI_VCPU_START ((okl4_tracepoint_evt_t)0x4eU)

#define OKL4_TRACEPOINT_EVT_SWI_VCPU_STOP ((okl4_tracepoint_evt_t)0x4fU)

#define OKL4_TRACEPOINT_EVT_SWI_VCPU_SWITCH_MODE ((okl4_tracepoint_evt_t)0x50U)

#define OKL4_TRACEPOINT_EVT_SWI_VCPU_SYNC_SEV ((okl4_tracepoint_evt_t)0x51U)

#define OKL4_TRACEPOINT_EVT_SWI_VCPU_SYNC_WFE ((okl4_tracepoint_evt_t)0x52U)

#define OKL4_TRACEPOINT_EVT_SWI_VINTERRUPT_CLEAR_AND_RAISE ((okl4_tracepoint_evt_t)0x53U)

#define OKL4_TRACEPOINT_EVT_SWI_VINTERRUPT_MODIFY ((okl4_tracepoint_evt_t)0x54U)

#define OKL4_TRACEPOINT_EVT_SWI_VINTERRUPT_RAISE ((okl4_tracepoint_evt_t)0x55U)


#define OKL4_TRACEPOINT_EVT_MAX ((okl4_tracepoint_evt_t)0x55U)


#define OKL4_TRACEPOINT_EVT_INVALID ((okl4_tracepoint_evt_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_tracepoint_evt_is_element_of(okl4_tracepoint_evt_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_tracepoint_evt_is_element_of(okl4_tracepoint_evt_t var)
{
    
    
    return ((var == OKL4_TRACEPOINT_EVT_SCH_SCHEDULER_FLAG_SET_RUNNABLE) ||
            (var == OKL4_TRACEPOINT_EVT_SCH_SCHEDULER_FLAG_CLEAR_RUNNABLE) ||
            (var == OKL4_TRACEPOINT_EVT_SCH_CONTEXT_SWITCH) ||
            (var == OKL4_TRACEPOINT_EVT_KDB_SET_OBJECT_NAME) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_PROCESS_RECV) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_SET_HALTED) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_SET_RECV_AREA) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_SET_RECV_QUEUE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_SET_RECV_SEGMENT) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_SET_SEND_AREA) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_SET_SEND_QUEUE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_SET_SEND_SEGMENT) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_AXON_TRIGGER_SEND) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_DEBUG_RESUME) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_DEBUG_SUSPEND) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_ACK) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_ATTACH_PRIVATE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_ATTACH_SHARED) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_DETACH) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_DIST_ENABLE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_EOI) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_GET_HIGHEST_PRIORITY_PENDING) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_GET_PAYLOAD) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_LIMITS) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_MASK) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_RAISE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_BINARY_POINT) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_CONFIG) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_CONTROL) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_PRIORITY) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_PRIORITY_MASK) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_SET_TARGETS) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_INTERRUPT_UNMASK) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_KDB_INTERACT) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_KDB_SET_OBJECT_NAME) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_KSP_PROCEDURE_CALL) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_ATTACH_SEGMENT) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_DETACH_SEGMENT) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_FLUSH_RANGE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_FLUSH_RANGE_PN) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_LOOKUP_PAGE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_LOOKUP_PN) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_MAP_PAGE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_MAP_PN) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_UNMAP_PAGE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_UNMAP_PN) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_UPDATE_PAGE_ATTRS) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_UPDATE_PAGE_PERMS) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_UPDATE_PN_ATTRS) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_MMU_UPDATE_PN_PERMS) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_PERFORMANCE_NULL_SYSCALL) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_PIPE_CONTROL) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_PIPE_RECV) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_PIPE_SEND) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_PRIORITY_WAIVE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_REMOTE_GET_REGISTER) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_REMOTE_GET_REGISTERS) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_REMOTE_READ_MEMORY32) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_REMOTE_SET_REGISTER) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_REMOTE_SET_REGISTERS) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_REMOTE_WRITE_MEMORY32) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_METRICS_STATUS_SUSPENDED) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_METRICS_WATCH_SUSPENDED) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_DISABLE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_ENABLE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_GET_DATA) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_DISABLE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_ENABLE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_GET_DATA) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULER_AFFINITY_GET) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_SCHEDULER_AFFINITY_SET) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_TIMER_CANCEL) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_TIMER_GET_RESOLUTION) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_TIMER_GET_TIME) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_TIMER_QUERY) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_TIMER_START) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_TRACEBUFFER_SYNC) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VCPU_RESET) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VCPU_START) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VCPU_STOP) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VCPU_SWITCH_MODE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VCPU_SYNC_SEV) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VCPU_SYNC_WFE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VINTERRUPT_CLEAR_AND_RAISE) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VINTERRUPT_MODIFY) ||
            (var == OKL4_TRACEPOINT_EVT_SWI_VINTERRUPT_RAISE));
}



typedef uint32_t okl4_tracepoint_level_t;


#define OKL4_TRACEPOINT_LEVEL_DEBUG ((okl4_tracepoint_level_t)0x0U)

#define OKL4_TRACEPOINT_LEVEL_INFO ((okl4_tracepoint_level_t)0x1U)

#define OKL4_TRACEPOINT_LEVEL_WARN ((okl4_tracepoint_level_t)0x2U)

#define OKL4_TRACEPOINT_LEVEL_CRITICAL ((okl4_tracepoint_level_t)0x3U)


#define OKL4_TRACEPOINT_LEVEL_MAX ((okl4_tracepoint_level_t)0x3U)


#define OKL4_TRACEPOINT_LEVEL_INVALID ((okl4_tracepoint_level_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_tracepoint_level_is_element_of(okl4_tracepoint_level_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_tracepoint_level_is_element_of(okl4_tracepoint_level_t var)
{
    
    
    return ((var == OKL4_TRACEPOINT_LEVEL_DEBUG) ||
            (var == OKL4_TRACEPOINT_LEVEL_INFO) ||
            (var == OKL4_TRACEPOINT_LEVEL_WARN) ||
            (var == OKL4_TRACEPOINT_LEVEL_CRITICAL));
}



typedef uint32_t okl4_tracepoint_mask_t;





typedef uint32_t okl4_tracepoint_subsystem_t;


#define OKL4_TRACEPOINT_SUBSYSTEM_SCHEDULER ((okl4_tracepoint_subsystem_t)0x0U)

#define OKL4_TRACEPOINT_SUBSYSTEM_TRACE ((okl4_tracepoint_subsystem_t)0x1U)

#define OKL4_TRACEPOINT_SUBSYSTEM_CORE ((okl4_tracepoint_subsystem_t)0x2U)


#define OKL4_TRACEPOINT_SUBSYSTEM_MAX ((okl4_tracepoint_subsystem_t)0x2U)


#define OKL4_TRACEPOINT_SUBSYSTEM_INVALID ((okl4_tracepoint_subsystem_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_tracepoint_subsystem_is_element_of(okl4_tracepoint_subsystem_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_tracepoint_subsystem_is_element_of(okl4_tracepoint_subsystem_t var)
{
    
    
    return ((var == OKL4_TRACEPOINT_SUBSYSTEM_SCHEDULER) ||
            (var == OKL4_TRACEPOINT_SUBSYSTEM_TRACE) ||
            (var == OKL4_TRACEPOINT_SUBSYSTEM_CORE));
}



struct okl4_tracepoint_unpacked_entry {
    struct okl4_tracepoint_entry_base entry;
    uint32_t data[]; 
};




















struct okl4_vclient_info {
    struct okl4_axon_ep_data axon_ep;
    __ptr64(void *, opaque);
};






struct okl4_vcpu_entry {
    okl4_kcap_t vcpu;
    okl4_kcap_t ipi;
    okl4_interrupt_number_t irq;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    okl4_register_t stack_pointer;
};





typedef okl4_arm_mpidr_t okl4_vcpu_id_t;






struct okl4_vcpu_table {
    okl4_count_t num_vcpus;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64(struct okl4_vcpu_entry *, vcpu);
};






struct okl4_vfp_ctrl_registers {
    uint32_t fpsr;
    uint32_t fpcr;
};








typedef struct okl4_vfp_ctrl_registers okl4_vfp_ctrl_registers_t;






typedef uint32_t okl4_vfp_ops_t;



#define OKL4_VFP_OPS_MAX ((okl4_vfp_ops_t)0x0U)


#define OKL4_VFP_OPS_INVALID ((okl4_vfp_ops_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_vfp_ops_is_element_of(okl4_vfp_ops_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_vfp_ops_is_element_of(okl4_vfp_ops_t var)
{
    
    
    return ((okl4_bool_t)0);
}



struct okl4_vfp_register {
    ALIGNED(16) uint8_t __bytes[16];
};







typedef struct okl4_vfp_register okl4_vfp_register_t;






struct okl4_vfp_registers {
    okl4_vfp_register_t v0;
    okl4_vfp_register_t v1;
    okl4_vfp_register_t v2;
    okl4_vfp_register_t v3;
    okl4_vfp_register_t v4;
    okl4_vfp_register_t v5;
    okl4_vfp_register_t v6;
    okl4_vfp_register_t v7;
    okl4_vfp_register_t v8;
    okl4_vfp_register_t v9;
    okl4_vfp_register_t v10;
    okl4_vfp_register_t v11;
    okl4_vfp_register_t v12;
    okl4_vfp_register_t v13;
    okl4_vfp_register_t v14;
    okl4_vfp_register_t v15;
    okl4_vfp_register_t v16;
    okl4_vfp_register_t v17;
    okl4_vfp_register_t v18;
    okl4_vfp_register_t v19;
    okl4_vfp_register_t v20;
    okl4_vfp_register_t v21;
    okl4_vfp_register_t v22;
    okl4_vfp_register_t v23;
    okl4_vfp_register_t v24;
    okl4_vfp_register_t v25;
    okl4_vfp_register_t v26;
    okl4_vfp_register_t v27;
    okl4_vfp_register_t v28;
    okl4_vfp_register_t v29;
    okl4_vfp_register_t v30;
    okl4_vfp_register_t v31;
    struct okl4_vfp_ctrl_registers control;
    _okl4_padding_t __padding0_8; 
    _okl4_padding_t __padding1_9; 
    _okl4_padding_t __padding2_10; 
    _okl4_padding_t __padding3_11; 
    _okl4_padding_t __padding4_12; 
    _okl4_padding_t __padding5_13; 
    _okl4_padding_t __padding6_14; 
    _okl4_padding_t __padding7_15; 
};








typedef struct okl4_vfp_registers okl4_vfp_registers_t;






struct okl4_virtmem_pool {
    struct okl4_virtmem_item pool;
};






struct okl4_virtual_interrupt_lines {
    okl4_count_t num_lines;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64(okl4_kcap_t *, lines);
};






struct okl4_vserver_info {
    struct {
        __ptr64(struct okl4_axon_ep_data *, data);
        okl4_count_t max_messages;
        _okl4_padding_t __padding0_4; 
        _okl4_padding_t __padding1_5; 
        _okl4_padding_t __padding2_6; 
        _okl4_padding_t __padding3_7; 
        okl4_ksize_t message_size;
    } channels;

    okl4_count_t num_clients;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
};






struct okl4_vservices_service_descriptor {
    __ptr64(okl4_string_t, name);
    __ptr64(okl4_string_t, protocol);
    __ptr64(void *, RESERVED);
};





typedef uint32_t okl4_vservices_transport_type_t;


#define OKL4_VSERVICES_TRANSPORT_TYPE_AXON ((okl4_vservices_transport_type_t)0x0U)

#define OKL4_VSERVICES_TRANSPORT_TYPE_SHARED_BUFFER ((okl4_vservices_transport_type_t)0x1U)


#define OKL4_VSERVICES_TRANSPORT_TYPE_MAX ((okl4_vservices_transport_type_t)0x1U)


#define OKL4_VSERVICES_TRANSPORT_TYPE_INVALID ((okl4_vservices_transport_type_t)0xffffffffU)


OKL4_FORCE_INLINE okl4_bool_t
okl4_vservices_transport_type_is_element_of(okl4_vservices_transport_type_t var);



OKL4_FORCE_INLINE okl4_bool_t
okl4_vservices_transport_type_is_element_of(okl4_vservices_transport_type_t var)
{
    
    
    return ((var == OKL4_VSERVICES_TRANSPORT_TYPE_AXON) ||
            (var == OKL4_VSERVICES_TRANSPORT_TYPE_SHARED_BUFFER));
}




struct okl4_vservices_transport_microvisor {
    okl4_bool_t is_server;
    _okl4_padding_t __padding0_1;
    _okl4_padding_t __padding1_2;
    _okl4_padding_t __padding2_3;
    okl4_vservices_transport_type_t type;
    union {
        struct {
            struct okl4_axon_ep_data ep;
            okl4_ksize_t message_size;
            okl4_count_t queue_length;
            _okl4_padding_t __padding0_4; 
            _okl4_padding_t __padding1_5; 
            _okl4_padding_t __padding2_6; 
            _okl4_padding_t __padding3_7; 
        } axon;

        struct {
            okl4_ksize_t message_size;
            okl4_count_t queue_length;
            _okl4_padding_t __padding0_4; 
            _okl4_padding_t __padding1_5; 
            _okl4_padding_t __padding2_6; 
            _okl4_padding_t __padding3_7; 
            struct okl4_virtmem_item rx;
            okl4_count_t rx_batch_size;
            okl4_count_t rx_notify_bits;
            struct okl4_virtmem_item tx;
            okl4_count_t tx_batch_size;
            okl4_count_t tx_notify_bits;
        } shared_buffer;

    } u;

    struct okl4_virtual_interrupt_lines virqs_in;
    struct okl4_virtual_interrupt_lines virqs_out;
    okl4_count_t num_services;
    _okl4_padding_t __padding3_4;
    _okl4_padding_t __padding4_5;
    _okl4_padding_t __padding5_6;
    _okl4_padding_t __padding6_7;
    __ptr64(struct okl4_vservices_service_descriptor *, services);
};






struct okl4_vservices_transports {
    okl4_count_t num_transports;
    _okl4_padding_t __padding0_4;
    _okl4_padding_t __padding1_5;
    _okl4_padding_t __padding2_6;
    _okl4_padding_t __padding3_7;
    __ptr64(struct okl4_vservices_transport_microvisor *, transports);
};





typedef struct okl4_axon_data okl4_axon_data_t;
typedef struct okl4_axon_ep_data okl4_axon_ep_data_t;
typedef struct okl4_range_item okl4_range_item_t;
typedef struct okl4_virtmem_item okl4_virtmem_item_t;
typedef struct okl4_cell_management_item okl4_cell_management_item_t;
typedef struct okl4_cell_management okl4_cell_management_t;
typedef struct okl4_segment_mapping okl4_segment_mapping_t;
typedef struct okl4_cell_management_segments okl4_cell_management_segments_t;
typedef struct okl4_cell_management_vcpus okl4_cell_management_vcpus_t;
typedef struct _okl4_env okl4_env_t;
typedef struct okl4_env_access_cell okl4_env_access_cell_t;
typedef struct okl4_env_access_entry okl4_env_access_entry_t;
typedef struct okl4_env_access_table okl4_env_access_table_t;
typedef struct okl4_env_args okl4_env_args_t;
typedef struct okl4_env_interrupt_device_map okl4_env_interrupt_device_map_t;
typedef struct okl4_interrupt okl4_interrupt_t;
typedef struct okl4_env_interrupt_handle okl4_env_interrupt_handle_t;
typedef struct okl4_env_interrupt_list okl4_env_interrupt_list_t;
typedef struct okl4_env_profile_cell okl4_env_profile_cell_t;
typedef struct okl4_env_profile_cpu okl4_env_profile_cpu_t;
typedef struct okl4_env_profile_table okl4_env_profile_table_t;
typedef struct okl4_env_segment okl4_env_segment_t;
typedef struct okl4_env_segment_table okl4_env_segment_table_t;
typedef struct okl4_firmware_segment okl4_firmware_segment_t;
typedef struct okl4_firmware_segments_info okl4_firmware_segments_info_t;
typedef void (*okl4_irq_callback_t)(okl4_interrupt_number_t irq, void *opaque);
typedef struct okl4_kmmu okl4_kmmu_t;
typedef struct okl4_ksp_user_agent okl4_ksp_user_agent_t;
typedef struct okl4_pipe_data okl4_pipe_data_t;
typedef struct okl4_pipe_ep_data okl4_pipe_ep_data_t;
typedef struct okl4_link okl4_link_t;
typedef struct okl4_links okl4_links_t;
typedef struct okl4_machine_info okl4_machine_info_t;
typedef struct okl4_merged_physpool okl4_merged_physpool_t;
typedef struct okl4_microvisor_timer okl4_microvisor_timer_t;
typedef struct okl4_schedule_profile_data okl4_schedule_profile_data_t;
typedef struct okl4_shared_buffer okl4_shared_buffer_t;
typedef struct okl4_shared_buffers_array okl4_shared_buffers_array_t;
typedef struct okl4_tracebuffer_env okl4_tracebuffer_env_t;
typedef struct okl4_vclient_info okl4_vclient_info_t;
typedef struct okl4_vcpu_entry okl4_vcpu_entry_t;
typedef struct okl4_vcpu_table okl4_vcpu_table_t;
typedef struct okl4_virtmem_pool okl4_virtmem_pool_t;
typedef struct okl4_virtual_interrupt_lines okl4_virtual_interrupt_lines_t;
typedef struct okl4_vserver_info okl4_vserver_info_t;
typedef struct okl4_vservices_service_descriptor okl4_vservices_service_descriptor_t;
typedef struct okl4_vservices_transport_microvisor okl4_vservices_transport_microvisor_t;
typedef struct okl4_vservices_transports okl4_vservices_transports_t;



struct _okl4_sys_axon_process_recv_return {
    okl4_error_t error;
    okl4_bool_t send_empty;
};

struct _okl4_sys_axon_set_halted_return {
    okl4_error_t error;
};

struct _okl4_sys_axon_set_recv_area_return {
    okl4_error_t error;
};

struct _okl4_sys_axon_set_recv_queue_return {
    okl4_error_t error;
};

struct _okl4_sys_axon_set_recv_segment_return {
    okl4_error_t error;
};

struct _okl4_sys_axon_set_send_area_return {
    okl4_error_t error;
};

struct _okl4_sys_axon_set_send_queue_return {
    okl4_error_t error;
};

struct _okl4_sys_axon_set_send_segment_return {
    okl4_error_t error;
};

struct _okl4_sys_axon_trigger_send_return {
    okl4_error_t error;
};

struct _okl4_sys_debug_resume_return {
    okl4_error_t error;
};

struct _okl4_sys_debug_suspend_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_ack_return {
    okl4_interrupt_number_t irq;
    uint8_t source;
};

struct _okl4_sys_interrupt_attach_private_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_attach_shared_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_detach_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_dist_enable_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_eoi_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_get_highest_priority_pending_return {
    okl4_interrupt_number_t irq;
    uint8_t source;
};

struct _okl4_sys_interrupt_get_payload_return {
    okl4_error_t error;
    okl4_virq_flags_t payload;
};

struct _okl4_sys_interrupt_limits_return {
    okl4_count_t cpunumber;
    okl4_count_t itnumber;
};

struct _okl4_sys_interrupt_mask_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_raise_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_set_binary_point_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_set_config_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_set_control_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_set_priority_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_set_priority_mask_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_set_targets_return {
    okl4_error_t error;
};

struct _okl4_sys_interrupt_unmask_return {
    okl4_error_t error;
};

struct _okl4_sys_kdb_set_object_name_return {
    okl4_error_t error;
};

struct _okl4_sys_ksp_procedure_call_return {
    okl4_error_t error;
    okl4_ksp_arg_t ret0;
    okl4_ksp_arg_t ret1;
    okl4_ksp_arg_t ret2;
};

struct _okl4_sys_mmu_attach_segment_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_detach_segment_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_flush_range_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_flush_range_pn_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_lookup_page_return {
    okl4_error_t error;
    okl4_psize_tr_t offset;
    okl4_mmu_lookup_size_t size;
    _okl4_page_attribute_t page_attr;
};

struct _okl4_sys_mmu_lookup_pn_return {
    okl4_mmu_lookup_index_t segment_index;
    okl4_psize_pn_t offset_pn;
    okl4_lsize_pn_t count_pn;
    _okl4_page_attribute_t page_attr;
};

struct _okl4_sys_mmu_map_page_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_map_pn_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_unmap_page_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_unmap_pn_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_update_page_attrs_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_update_page_perms_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_update_pn_attrs_return {
    okl4_error_t error;
};

struct _okl4_sys_mmu_update_pn_perms_return {
    okl4_error_t error;
};

struct _okl4_sys_performance_null_syscall_return {
    okl4_error_t error;
};

struct _okl4_sys_pipe_control_return {
    okl4_error_t error;
};

struct _okl4_sys_pipe_recv_return {
    okl4_error_t error;
    okl4_ksize_t size;
};

struct _okl4_sys_pipe_send_return {
    okl4_error_t error;
};

struct _okl4_sys_priority_waive_return {
    okl4_error_t error;
};

struct _okl4_sys_remote_get_register_return {
    uint32_t reg_w0;
    uint32_t reg_w1;
    uint32_t reg_w2;
    uint32_t reg_w3;
    okl4_error_t error;
};

struct _okl4_sys_remote_get_registers_return {
    okl4_error_t error;
};

struct _okl4_sys_remote_read_memory32_return {
    uint32_t data;
    okl4_error_t error;
};

struct _okl4_sys_remote_set_register_return {
    okl4_error_t error;
};

struct _okl4_sys_remote_set_registers_return {
    okl4_error_t error;
};

struct _okl4_sys_remote_write_memory32_return {
    okl4_error_t error;
};

struct _okl4_sys_schedule_metrics_status_suspended_return {
    okl4_error_t error;
    uint32_t power_suspend_version;
    uint32_t power_suspend_running_count;
};

struct _okl4_sys_schedule_metrics_watch_suspended_return {
    okl4_error_t error;
};

struct _okl4_sys_schedule_profile_cpu_disable_return {
    okl4_error_t error;
};

struct _okl4_sys_schedule_profile_cpu_enable_return {
    okl4_error_t error;
    uint64_t timestamp;
};

struct _okl4_sys_schedule_profile_cpu_get_data_return {
    okl4_error_t error;
};

struct _okl4_sys_schedule_profile_vcpu_disable_return {
    okl4_error_t error;
};

struct _okl4_sys_schedule_profile_vcpu_enable_return {
    okl4_error_t error;
    uint64_t timestamp;
};

struct _okl4_sys_schedule_profile_vcpu_get_data_return {
    okl4_error_t error;
};

struct _okl4_sys_scheduler_affinity_get_return {
    okl4_error_t error;
    okl4_cpu_id_t cpu_index;
};

struct _okl4_sys_scheduler_affinity_set_return {
    okl4_error_t error;
};

struct _okl4_sys_timer_cancel_return {
    uint64_t remaining;
    okl4_timer_flags_t old_flags;
    okl4_error_t error;
};

struct _okl4_sys_timer_get_resolution_return {
    uint64_t tick_freq;
    uint32_t a;
    uint32_t b;
    okl4_error_t error;
};

struct _okl4_sys_timer_get_time_return {
    uint64_t time;
    okl4_error_t error;
};

struct _okl4_sys_timer_query_return {
    uint64_t remaining;
    okl4_timer_flags_t active_flags;
    okl4_error_t error;
};

struct _okl4_sys_timer_start_return {
    okl4_error_t error;
};

struct _okl4_sys_vcpu_reset_return {
    okl4_error_t error;
};

struct _okl4_sys_vcpu_start_return {
    okl4_error_t error;
};

struct _okl4_sys_vcpu_stop_return {
    okl4_error_t error;
};

struct _okl4_sys_vcpu_switch_mode_return {
    okl4_error_t error;
};

struct _okl4_sys_vinterrupt_clear_and_raise_return {
    okl4_error_t error;
    okl4_virq_flags_t payload;
};

struct _okl4_sys_vinterrupt_modify_return {
    okl4_error_t error;
};

struct _okl4_sys_vinterrupt_raise_return {
    okl4_error_t error;
};





#if !defined(GLOBAL_STATIC_ASSERT)
#if defined(__cplusplus)

#define GLOBAL_STATIC_ASSERT(expr, msg)
#else
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#define GLOBAL_STATIC_ASSERT(expr, msg) \
        _Static_assert(expr, #msg);
#else
#define GLOBAL_STATIC_ASSERT(expr, msg)
#endif
#endif
#endif


GLOBAL_STATIC_ASSERT(sizeof(okl4_arm_mpidr_t) == 8U,
        __autogen_confused_about_sizeof_arm_mpidr)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_arm_mpidr_t) == 8U,
        __autogen_confused_about_alignof_arm_mpidr)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_arm_psci_function_t) == 4U,
        __autogen_confused_about_sizeof_arm_psci_function)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_arm_psci_function_t) == 4U,
        __autogen_confused_about_alignof_arm_psci_function)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_arm_psci_result_t) == 4U,
        __autogen_confused_about_sizeof_arm_psci_result)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_arm_psci_result_t) == 4U,
        __autogen_confused_about_alignof_arm_psci_result)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_arm_sctlr_t) == 4U,
        __autogen_confused_about_sizeof_arm_sctlr)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_arm_sctlr_t) == 4U,
        __autogen_confused_about_alignof_arm_sctlr)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_arm_smccc_arch_function_t) == 4U,
        __autogen_confused_about_sizeof_arm_smccc_arch_function)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_arm_smccc_arch_function_t) == 4U,
        __autogen_confused_about_alignof_arm_smccc_arch_function)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_arm_smccc_result_t) == 4U,
        __autogen_confused_about_sizeof_arm_smccc_result)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_arm_smccc_result_t) == 4U,
        __autogen_confused_about_alignof_arm_smccc_result)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_atomic_register) == 8U,
        __autogen_confused_about_sizeof_atomic_register)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_atomic_register) == 8U,
        __autogen_confused_about_alignof_atomic_register)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_atomic_register_t) == 8U,
        __autogen_confused_about_sizeof_atomic_register_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_atomic_register_t) == 8U,
        __autogen_confused_about_alignof_atomic_register_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_atomic_uint16) == 2U,
        __autogen_confused_about_sizeof_atomic_uint16)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_atomic_uint16) == 2U,
        __autogen_confused_about_alignof_atomic_uint16)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_atomic_uint16_t) == 2U,
        __autogen_confused_about_sizeof_atomic_uint16_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_atomic_uint16_t) == 2U,
        __autogen_confused_about_alignof_atomic_uint16_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_atomic_uint32) == 4U,
        __autogen_confused_about_sizeof_atomic_uint32)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_atomic_uint32) == 4U,
        __autogen_confused_about_alignof_atomic_uint32)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_atomic_uint32_t) == 4U,
        __autogen_confused_about_sizeof_atomic_uint32_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_atomic_uint32_t) == 4U,
        __autogen_confused_about_alignof_atomic_uint32_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_atomic_uint64) == 8U,
        __autogen_confused_about_sizeof_atomic_uint64)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_atomic_uint64) == 8U,
        __autogen_confused_about_alignof_atomic_uint64)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_atomic_uint64_t) == 8U,
        __autogen_confused_about_sizeof_atomic_uint64_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_atomic_uint64_t) == 8U,
        __autogen_confused_about_alignof_atomic_uint64_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_atomic_uint8) == 1U,
        __autogen_confused_about_sizeof_atomic_uint8)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_atomic_uint8) == 1U,
        __autogen_confused_about_alignof_atomic_uint8)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_atomic_uint8_t) == 1U,
        __autogen_confused_about_sizeof_atomic_uint8_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_atomic_uint8_t) == 1U,
        __autogen_confused_about_alignof_atomic_uint8_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_axon_data) == 12U,
        __autogen_confused_about_sizeof_axon_data)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_axon_data) == 4U,
        __autogen_confused_about_alignof_axon_data)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_axon_data_info_t) == 8U,
        __autogen_confused_about_sizeof_axon_data_info)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_axon_data_info_t) == 8U,
        __autogen_confused_about_alignof_axon_data_info)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_axon_ep_data) == 24U,
        __autogen_confused_about_sizeof_axon_ep_data)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_axon_ep_data) == 4U,
        __autogen_confused_about_alignof_axon_ep_data)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_axon_queue) == 12U,
        __autogen_confused_about_sizeof_axon_queue)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_axon_queue) == 4U,
        __autogen_confused_about_alignof_axon_queue)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_axon_queue_entry) == 24U,
        __autogen_confused_about_sizeof_axon_queue_entry)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_axon_queue_entry) == 8U,
        __autogen_confused_about_alignof_axon_queue_entry)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_axon_queue_size_t) == 2U,
        __autogen_confused_about_sizeof_axon_queue_size)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_axon_queue_size_t) == 2U,
        __autogen_confused_about_alignof_axon_queue_size)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_axon_rx) == 56U,
        __autogen_confused_about_sizeof_axon_rx)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_axon_rx) == 4U,
        __autogen_confused_about_alignof_axon_rx)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_axon_tx) == 48U,
        __autogen_confused_about_sizeof_axon_tx)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_axon_tx) == 4U,
        __autogen_confused_about_alignof_axon_tx)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_axon_virq_flags_t) == 8U,
        __autogen_confused_about_sizeof_axon_virq_flags)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_axon_virq_flags_t) == 8U,
        __autogen_confused_about_alignof_axon_virq_flags)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_page_cache_t) == 4U,
        __autogen_confused_about_sizeof_cache_attr)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_page_cache_t) == 4U,
        __autogen_confused_about_alignof_cache_attr)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_range_item) == 16U,
        __autogen_confused_about_sizeof_range_item)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_range_item) == 8U,
        __autogen_confused_about_alignof_range_item)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_virtmem_item) == 16U,
        __autogen_confused_about_sizeof_virtmem_item)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_virtmem_item) == 8U,
        __autogen_confused_about_alignof_virtmem_item)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_cell_management_item) == 104U,
        __autogen_confused_about_sizeof_cell_management_item)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_cell_management_item) == 8U,
        __autogen_confused_about_alignof_cell_management_item)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_cell_management) == 8U,
        __autogen_confused_about_sizeof_cell_management)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_cell_management) == 8U,
        __autogen_confused_about_alignof_cell_management)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_segment_mapping) == 32U,
        __autogen_confused_about_sizeof_segment_mapping)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_segment_mapping) == 8U,
        __autogen_confused_about_alignof_segment_mapping)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_cell_management_segments) == 8U,
        __autogen_confused_about_sizeof_cell_management_segments)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_cell_management_segments) == 8U,
        __autogen_confused_about_alignof_cell_management_segments)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_cell_management_vcpus) == 4U,
        __autogen_confused_about_sizeof_cell_management_vcpus)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_cell_management_vcpus) == 4U,
        __autogen_confused_about_alignof_cell_management_vcpus)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_cpu_mode_t) == 4U,
        __autogen_confused_about_sizeof_cpu_mode)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_cpu_mode_t) == 4U,
        __autogen_confused_about_alignof_cpu_mode)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct _okl4_env_hdr) == 4U,
        __autogen_confused_about_sizeof_env_hdr)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct _okl4_env_hdr) == 2U,
        __autogen_confused_about_alignof_env_hdr)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct _okl4_env_item) == 16U,
        __autogen_confused_about_sizeof_env_item)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct _okl4_env_item) == 8U,
        __autogen_confused_about_alignof_env_item)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct _okl4_env) == 8U,
        __autogen_confused_about_sizeof_env)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct _okl4_env) == 8U,
        __autogen_confused_about_alignof_env)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_access_cell) == 16U,
        __autogen_confused_about_sizeof_env_access_cell)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_access_cell) == 8U,
        __autogen_confused_about_alignof_env_access_cell)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_page_perms_t) == 4U,
        __autogen_confused_about_sizeof_page_perms)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_page_perms_t) == 4U,
        __autogen_confused_about_alignof_page_perms)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_access_entry) == 48U,
        __autogen_confused_about_sizeof_env_access_entry)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_access_entry) == 8U,
        __autogen_confused_about_alignof_env_access_entry)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_access_table) == 24U,
        __autogen_confused_about_sizeof_env_access_table)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_access_table) == 8U,
        __autogen_confused_about_alignof_env_access_table)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_args) == 8U,
        __autogen_confused_about_sizeof_env_args)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_args) == 8U,
        __autogen_confused_about_alignof_env_args)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_interrupt_device_map) == 4U,
        __autogen_confused_about_sizeof_env_interrupt_device_map)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_interrupt_device_map) == 4U,
        __autogen_confused_about_alignof_env_interrupt_device_map)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_interrupt) == 4U,
        __autogen_confused_about_sizeof_okl4_interrupt)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_interrupt) == 4U,
        __autogen_confused_about_alignof_okl4_interrupt)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_interrupt_handle) == 8U,
        __autogen_confused_about_sizeof_env_interrupt_handle)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_interrupt_handle) == 4U,
        __autogen_confused_about_alignof_env_interrupt_handle)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_interrupt_list) == 24U,
        __autogen_confused_about_sizeof_env_interrupt_list)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_interrupt_list) == 8U,
        __autogen_confused_about_alignof_env_interrupt_list)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_profile_cell) == 48U,
        __autogen_confused_about_sizeof_env_profile_cell)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_profile_cell) == 8U,
        __autogen_confused_about_alignof_env_profile_cell)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_profile_cpu) == 4U,
        __autogen_confused_about_sizeof_env_profile_cpu)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_profile_cpu) == 4U,
        __autogen_confused_about_alignof_env_profile_cpu)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_profile_table) == 16U,
        __autogen_confused_about_sizeof_env_profile_table)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_profile_table) == 8U,
        __autogen_confused_about_alignof_env_profile_table)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_segment) == 24U,
        __autogen_confused_about_sizeof_env_segment)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_segment) == 8U,
        __autogen_confused_about_alignof_env_segment)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_env_segment_table) == 8U,
        __autogen_confused_about_sizeof_env_segment_table)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_env_segment_table) == 8U,
        __autogen_confused_about_alignof_env_segment_table)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_error_t) == 4U,
        __autogen_confused_about_sizeof_error_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_error_t) == 4U,
        __autogen_confused_about_alignof_error_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_firmware_segment) == 32U,
        __autogen_confused_about_sizeof_firmware_segment)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_firmware_segment) == 8U,
        __autogen_confused_about_alignof_firmware_segment)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_firmware_segments_info) == 8U,
        __autogen_confused_about_sizeof_firmware_segments_info)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_firmware_segments_info) == 8U,
        __autogen_confused_about_alignof_firmware_segments_info)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_gicd_icfgr_t) == 4U,
        __autogen_confused_about_sizeof_gicd_icfgr)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_gicd_icfgr_t) == 4U,
        __autogen_confused_about_alignof_gicd_icfgr)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_sgi_target_t) == 4U,
        __autogen_confused_about_sizeof_sgi_target)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_sgi_target_t) == 4U,
        __autogen_confused_about_alignof_sgi_target)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_gicd_sgir_t) == 4U,
        __autogen_confused_about_sizeof_gicd_sgir)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_gicd_sgir_t) == 4U,
        __autogen_confused_about_alignof_gicd_sgir)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_kmmu) == 4U,
        __autogen_confused_about_sizeof_kmmu)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_kmmu) == 4U,
        __autogen_confused_about_alignof_kmmu)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_ksp_user_agent) == 8U,
        __autogen_confused_about_sizeof_ksp_user_agent)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_ksp_user_agent) == 4U,
        __autogen_confused_about_alignof_ksp_user_agent)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_pipe_data) == 8U,
        __autogen_confused_about_sizeof_pipe_data)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_pipe_data) == 4U,
        __autogen_confused_about_alignof_pipe_data)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_pipe_ep_data) == 16U,
        __autogen_confused_about_sizeof_pipe_ep_data)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_pipe_ep_data) == 4U,
        __autogen_confused_about_alignof_pipe_ep_data)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_link_role_t) == 4U,
        __autogen_confused_about_sizeof_link_role)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_link_role_t) == 4U,
        __autogen_confused_about_alignof_link_role)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_link_transport_type_t) == 4U,
        __autogen_confused_about_sizeof_link_transport_type)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_link_transport_type_t) == 4U,
        __autogen_confused_about_alignof_link_transport_type)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_link) == 80U,
        __autogen_confused_about_sizeof_link)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_link) == 8U,
        __autogen_confused_about_alignof_link)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_links) == 8U,
        __autogen_confused_about_sizeof_links)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_links) == 8U,
        __autogen_confused_about_alignof_links)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_machine_info) == 24U,
        __autogen_confused_about_sizeof_machine_info)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_machine_info) == 8U,
        __autogen_confused_about_alignof_machine_info)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_merged_physpool) == 16U,
        __autogen_confused_about_sizeof_merged_physpool)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_merged_physpool) == 8U,
        __autogen_confused_about_alignof_merged_physpool)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_microvisor_timer) == 8U,
        __autogen_confused_about_sizeof_microvisor_timer)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_microvisor_timer) == 4U,
        __autogen_confused_about_alignof_microvisor_timer)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_mmu_lookup_index_t) == 4U,
        __autogen_confused_about_sizeof_mmu_lookup_index)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_mmu_lookup_index_t) == 4U,
        __autogen_confused_about_alignof_mmu_lookup_index)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_mmu_lookup_size_t) == 8U,
        __autogen_confused_about_sizeof_mmu_lookup_size)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_mmu_lookup_size_t) == 8U,
        __autogen_confused_about_alignof_mmu_lookup_size)
#endif
GLOBAL_STATIC_ASSERT(sizeof(_okl4_page_attribute_t) == 4U,
        __autogen_confused_about_sizeof_page_attribute)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(_okl4_page_attribute_t) == 4U,
        __autogen_confused_about_alignof_page_attribute)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_pipe_control_t) == 1U,
        __autogen_confused_about_sizeof_pipe_control)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_pipe_control_t) == 1U,
        __autogen_confused_about_alignof_pipe_control)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_pipe_state_t) == 1U,
        __autogen_confused_about_sizeof_pipe_state)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_pipe_state_t) == 1U,
        __autogen_confused_about_alignof_pipe_state)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_register_set_t) == 4U,
        __autogen_confused_about_sizeof_register_set)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_register_set_t) == 4U,
        __autogen_confused_about_alignof_register_set)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_register_and_set_t) == 4U,
        __autogen_confused_about_sizeof_register_and_set)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_register_and_set_t) == 4U,
        __autogen_confused_about_alignof_register_and_set)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_cpu_registers) == 448U,
        __autogen_confused_about_sizeof_registers)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_cpu_registers) == 8U,
        __autogen_confused_about_alignof_registers)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_cpu_registers_t) == 448U,
        __autogen_confused_about_sizeof_registers_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_cpu_registers_t) == 8U,
        __autogen_confused_about_alignof_registers_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_schedule_profile_data) == 32U,
        __autogen_confused_about_sizeof_schedule_profile_data)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_schedule_profile_data) == 8U,
        __autogen_confused_about_alignof_schedule_profile_data)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_scheduler_virq_flags_t) == 8U,
        __autogen_confused_about_sizeof_scheduler_virq_flags)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_scheduler_virq_flags_t) == 8U,
        __autogen_confused_about_alignof_scheduler_virq_flags)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_sdk_version_t) == 4U,
        __autogen_confused_about_sizeof_sdk_version)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_sdk_version_t) == 4U,
        __autogen_confused_about_alignof_sdk_version)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_shared_buffer) == 32U,
        __autogen_confused_about_sizeof_shared_buffer)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_shared_buffer) == 8U,
        __autogen_confused_about_alignof_shared_buffer)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_shared_buffers_array) == 16U,
        __autogen_confused_about_sizeof_shared_buffers_array)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_shared_buffers_array) == 8U,
        __autogen_confused_about_alignof_shared_buffers_array)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_timer_flags_t) == 4U,
        __autogen_confused_about_sizeof_timer_flags)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_timer_flags_t) == 4U,
        __autogen_confused_about_alignof_timer_flags)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct _okl4_tracebuffer_buffer_header) == 40U,
        __autogen_confused_about_sizeof_tracebuffer_buffer_header)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct _okl4_tracebuffer_buffer_header) == 8U,
        __autogen_confused_about_alignof_tracebuffer_buffer_header)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_tracebuffer_env) == 24U,
        __autogen_confused_about_sizeof_tracebuffer_env)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_tracebuffer_env) == 8U,
        __autogen_confused_about_alignof_tracebuffer_env)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct _okl4_tracebuffer_header) == 40U,
        __autogen_confused_about_sizeof_tracebuffer_header)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct _okl4_tracebuffer_header) == 8U,
        __autogen_confused_about_alignof_tracebuffer_header)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_tracepoint_class_t) == 4U,
        __autogen_confused_about_sizeof_tracepoint_class)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_tracepoint_class_t) == 4U,
        __autogen_confused_about_alignof_tracepoint_class)
#endif
GLOBAL_STATIC_ASSERT(sizeof(_okl4_tracepoint_desc_t) == 4U,
        __autogen_confused_about_sizeof_tracepoint_desc)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(_okl4_tracepoint_desc_t) == 4U,
        __autogen_confused_about_alignof_tracepoint_desc)
#endif
GLOBAL_STATIC_ASSERT(sizeof(_okl4_tracepoint_masks_t) == 4U,
        __autogen_confused_about_sizeof_tracepoint_masks)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(_okl4_tracepoint_masks_t) == 4U,
        __autogen_confused_about_alignof_tracepoint_masks)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_tracepoint_entry_base) == 12U,
        __autogen_confused_about_sizeof_tracepoint_entry_base)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_tracepoint_entry_base) == 4U,
        __autogen_confused_about_alignof_tracepoint_entry_base)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_tracepoint_evt_t) == 4U,
        __autogen_confused_about_sizeof_tracepoint_evt)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_tracepoint_evt_t) == 4U,
        __autogen_confused_about_alignof_tracepoint_evt)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_tracepoint_level_t) == 4U,
        __autogen_confused_about_sizeof_tracepoint_level)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_tracepoint_level_t) == 4U,
        __autogen_confused_about_alignof_tracepoint_level)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_tracepoint_subsystem_t) == 4U,
        __autogen_confused_about_sizeof_tracepoint_subsystem)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_tracepoint_subsystem_t) == 4U,
        __autogen_confused_about_alignof_tracepoint_subsystem)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_tracepoint_unpacked_entry) == 12U,
        __autogen_confused_about_sizeof_tracepoint_unpacked_entry)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_tracepoint_unpacked_entry) == 4U,
        __autogen_confused_about_alignof_tracepoint_unpacked_entry)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vclient_info) == 32U,
        __autogen_confused_about_sizeof_vclient_info)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vclient_info) == 8U,
        __autogen_confused_about_alignof_vclient_info)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vcpu_entry) == 24U,
        __autogen_confused_about_sizeof_vcpu_entry)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vcpu_entry) == 8U,
        __autogen_confused_about_alignof_vcpu_entry)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vcpu_table) == 16U,
        __autogen_confused_about_sizeof_vcpu_table)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vcpu_table) == 8U,
        __autogen_confused_about_alignof_vcpu_table)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vfp_ctrl_registers) == 8U,
        __autogen_confused_about_sizeof_vfp_ctrl_registers)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vfp_ctrl_registers) == 4U,
        __autogen_confused_about_alignof_vfp_ctrl_registers)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_vfp_ctrl_registers_t) == 8U,
        __autogen_confused_about_sizeof_vfp_ctrl_registers_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_vfp_ctrl_registers_t) == 4U,
        __autogen_confused_about_alignof_vfp_ctrl_registers_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_vfp_ops_t) == 4U,
        __autogen_confused_about_sizeof_vfp_ops)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_vfp_ops_t) == 4U,
        __autogen_confused_about_alignof_vfp_ops)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vfp_register) == 16U,
        __autogen_confused_about_sizeof_vfp_register)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vfp_register) == 16U,
        __autogen_confused_about_alignof_vfp_register)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_vfp_register_t) == 16U,
        __autogen_confused_about_sizeof_vfp_register_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_vfp_register_t) == 16U,
        __autogen_confused_about_alignof_vfp_register_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vfp_registers) == 528U,
        __autogen_confused_about_sizeof_vfp_registers)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vfp_registers) == 16U,
        __autogen_confused_about_alignof_vfp_registers)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_vfp_registers_t) == 528U,
        __autogen_confused_about_sizeof_vfp_registers_t)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_vfp_registers_t) == 16U,
        __autogen_confused_about_alignof_vfp_registers_t)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_virtmem_pool) == 16U,
        __autogen_confused_about_sizeof_virtmem_pool)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_virtmem_pool) == 8U,
        __autogen_confused_about_alignof_virtmem_pool)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_virtual_interrupt_lines) == 16U,
        __autogen_confused_about_sizeof_virtual_interrupt_lines)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_virtual_interrupt_lines) == 8U,
        __autogen_confused_about_alignof_virtual_interrupt_lines)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vserver_info) == 32U,
        __autogen_confused_about_sizeof_vserver_info)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vserver_info) == 8U,
        __autogen_confused_about_alignof_vserver_info)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vservices_service_descriptor) == 24U,
        __autogen_confused_about_sizeof_vservices_service_descriptor)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vservices_service_descriptor) == 8U,
        __autogen_confused_about_alignof_vservices_service_descriptor)
#endif
GLOBAL_STATIC_ASSERT(sizeof(okl4_vservices_transport_type_t) == 4U,
        __autogen_confused_about_sizeof_vservices_transport_type)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(okl4_vservices_transport_type_t) == 4U,
        __autogen_confused_about_alignof_vservices_transport_type)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vservices_transport_microvisor) == 120U,
        __autogen_confused_about_sizeof_vservices_transport_microvisor)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vservices_transport_microvisor) == 8U,
        __autogen_confused_about_alignof_vservices_transport_microvisor)
#endif
GLOBAL_STATIC_ASSERT(sizeof(struct okl4_vservices_transports) == 16U,
        __autogen_confused_about_sizeof_vservices_transports)
#if !defined(LINTER)
GLOBAL_STATIC_ASSERT(_Alignof(struct okl4_vservices_transports) == 8U,
        __autogen_confused_about_alignof_vservices_transports)
#endif

#else





#define OKL4_ASM_MASK_AFF0_ARM_MPIDR (255)

#define OKL4_ASM_SHIFT_AFF0_ARM_MPIDR (0)

#define OKL4_ASM_WIDTH_AFF0_ARM_MPIDR (8)

#define OKL4_ASM_MASK_AFF1_ARM_MPIDR (255 << 8)

#define OKL4_ASM_SHIFT_AFF1_ARM_MPIDR (8)

#define OKL4_ASM_WIDTH_AFF1_ARM_MPIDR (8)

#define OKL4_ASM_MASK_AFF2_ARM_MPIDR (255 << 16)

#define OKL4_ASM_SHIFT_AFF2_ARM_MPIDR (16)

#define OKL4_ASM_WIDTH_AFF2_ARM_MPIDR (8)

#define OKL4_ASM_MASK_MT_ARM_MPIDR (1 << 24)

#define OKL4_ASM_SHIFT_MT_ARM_MPIDR (24)

#define OKL4_ASM_WIDTH_MT_ARM_MPIDR (1)

#define OKL4_ASM_MASK_U_ARM_MPIDR (1 << 30)

#define OKL4_ASM_SHIFT_U_ARM_MPIDR (30)

#define OKL4_ASM_WIDTH_U_ARM_MPIDR (1)

#define OKL4_ASM_MASK_MP_ARM_MPIDR (1 << 31)

#define OKL4_ASM_SHIFT_MP_ARM_MPIDR (31)

#define OKL4_ASM_WIDTH_MP_ARM_MPIDR (1)

#define OKL4_ASM_MASK_AFF3_ARM_MPIDR (255 << 32)

#define OKL4_ASM_SHIFT_AFF3_ARM_MPIDR (32)

#define OKL4_ASM_WIDTH_AFF3_ARM_MPIDR (8)




#define OKL4_AXON_NUM_RECEIVE_QUEUES (4)


#define OKL4_AXON_NUM_SEND_QUEUES (4)


#define _OKL4_POISON (3735928559)


#define OKL4_TRACEBUFFER_INVALID_REF (-1)



#define OKL4_ASM_ARM_PSCI_FUNCTION_PSCI_VERSION (0x0)

#define OKL4_ASM_ARM_PSCI_FUNCTION_CPU_SUSPEND (0x1)

#define OKL4_ASM_ARM_PSCI_FUNCTION_CPU_OFF (0x2)

#define OKL4_ASM_ARM_PSCI_FUNCTION_CPU_ON (0x3)

#define OKL4_ASM_ARM_PSCI_FUNCTION_AFFINITY_INFO (0x4)

#define OKL4_ASM_ARM_PSCI_FUNCTION_MIGRATE (0x5)

#define OKL4_ASM_ARM_PSCI_FUNCTION_MIGRATE_INFO_TYPE (0x6)

#define OKL4_ASM_ARM_PSCI_FUNCTION_MIGRATE_INFO_UP_CPU (0x7)

#define OKL4_ASM_ARM_PSCI_FUNCTION_SYSTEM_OFF (0x8)

#define OKL4_ASM_ARM_PSCI_FUNCTION_SYSTEM_RESET (0x9)

#define OKL4_ASM_ARM_PSCI_FUNCTION_PSCI_FEATURES (0xa)

#define OKL4_ASM_ARM_PSCI_FUNCTION_CPU_FREEZE (0xb)

#define OKL4_ASM_ARM_PSCI_FUNCTION_CPU_DEFAULT_SUSPEND (0xc)

#define OKL4_ASM_ARM_PSCI_FUNCTION_NODE_HW_STATE (0xd)

#define OKL4_ASM_ARM_PSCI_FUNCTION_SYSTEM_SUSPEND (0xe)

#define OKL4_ASM_ARM_PSCI_FUNCTION_PSCI_SET_SUSPEND_MODE (0xf)

#define OKL4_ASM_ARM_PSCI_FUNCTION_PSCI_STAT_RESIDENCY (0x10)

#define OKL4_ASM_ARM_PSCI_FUNCTION_PSCI_STAT_COUNT (0x11)

#define OKL4_ASM_ARM_PSCI_FUNCTION_SYSTEM_RESET2 (0x12)

#define OKL4_ASM_ARM_PSCI_FUNCTION_MEM_PROTECT (0x13)

#define OKL4_ASM_ARM_PSCI_FUNCTION_MEM_PROTECT_CHECK_RANGE (0x14)



#define OKL4_ASM_ARM_PSCI_RESULT_SUCCESS (0x0)

#define OKL4_ASM_ARM_PSCI_RESULT_INVALID_ADDRESS (0xfffffff7)

#define OKL4_ASM_ARM_PSCI_RESULT_DISABLED (0xfffffff8)

#define OKL4_ASM_ARM_PSCI_RESULT_NOT_PRESENT (0xfffffff9)

#define OKL4_ASM_ARM_PSCI_RESULT_INTERNAL_FAILURE (0xfffffffa)

#define OKL4_ASM_ARM_PSCI_RESULT_ON_PENDING (0xfffffffb)

#define OKL4_ASM_ARM_PSCI_RESULT_ALREADY_ON (0xfffffffc)

#define OKL4_ASM_ARM_PSCI_RESULT_DENIED (0xfffffffd)

#define OKL4_ASM_ARM_PSCI_RESULT_INVALID_PARAMETERS (0xfffffffe)

#define OKL4_ASM_ARM_PSCI_RESULT_NOT_SUPPORTED (0xffffffff)





#define OKL4_ASM_MASK_MMU_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_SHIFT_MMU_ENABLE_ARM_SCTLR (0)

#define OKL4_ASM_WIDTH_MMU_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_ALIGNMENT_CHECK_ENABLE_ARM_SCTLR (1 << 1)

#define OKL4_ASM_SHIFT_ALIGNMENT_CHECK_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_WIDTH_ALIGNMENT_CHECK_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_DATA_CACHE_ENABLE_ARM_SCTLR (1 << 2)

#define OKL4_ASM_SHIFT_DATA_CACHE_ENABLE_ARM_SCTLR (2)

#define OKL4_ASM_WIDTH_DATA_CACHE_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_STACK_ALIGN_ARM_SCTLR (1 << 3)

#define OKL4_ASM_SHIFT_STACK_ALIGN_ARM_SCTLR (3)

#define OKL4_ASM_WIDTH_STACK_ALIGN_ARM_SCTLR (1)

#define OKL4_ASM_MASK_STACK_ALIGN_EL0_ARM_SCTLR (1 << 4)

#define OKL4_ASM_SHIFT_STACK_ALIGN_EL0_ARM_SCTLR (4)

#define OKL4_ASM_WIDTH_STACK_ALIGN_EL0_ARM_SCTLR (1)

#define OKL4_ASM_MASK_CP15_BARRIER_ENABLE_ARM_SCTLR (1 << 5)

#define OKL4_ASM_SHIFT_CP15_BARRIER_ENABLE_ARM_SCTLR (5)

#define OKL4_ASM_WIDTH_CP15_BARRIER_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_OKL_HCR_EL2_DC_ARM_SCTLR (1 << 6)

#define OKL4_ASM_SHIFT_OKL_HCR_EL2_DC_ARM_SCTLR (6)

#define OKL4_ASM_WIDTH_OKL_HCR_EL2_DC_ARM_SCTLR (1)

#define OKL4_ASM_MASK_IT_DISABLE_ARM_SCTLR (1 << 7)

#define OKL4_ASM_SHIFT_IT_DISABLE_ARM_SCTLR (7)

#define OKL4_ASM_WIDTH_IT_DISABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_SETEND_DISABLE_ARM_SCTLR (1 << 8)

#define OKL4_ASM_SHIFT_SETEND_DISABLE_ARM_SCTLR (8)

#define OKL4_ASM_WIDTH_SETEND_DISABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_USER_MASK_ACCESS_ARM_SCTLR (1 << 9)

#define OKL4_ASM_SHIFT_USER_MASK_ACCESS_ARM_SCTLR (9)

#define OKL4_ASM_WIDTH_USER_MASK_ACCESS_ARM_SCTLR (1)

#define OKL4_ASM_MASK_RESERVED11_ARM_SCTLR (1 << 11)

#define OKL4_ASM_SHIFT_RESERVED11_ARM_SCTLR (11)

#define OKL4_ASM_WIDTH_RESERVED11_ARM_SCTLR (1)

#define OKL4_ASM_MASK_INSTRUCTION_CACHE_ENABLE_ARM_SCTLR (1 << 12)

#define OKL4_ASM_SHIFT_INSTRUCTION_CACHE_ENABLE_ARM_SCTLR (12)

#define OKL4_ASM_WIDTH_INSTRUCTION_CACHE_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_VECTORS_BIT_ARM_SCTLR (1 << 13)

#define OKL4_ASM_SHIFT_VECTORS_BIT_ARM_SCTLR (13)

#define OKL4_ASM_WIDTH_VECTORS_BIT_ARM_SCTLR (1)

#define OKL4_ASM_MASK_DCACHE_ZERO_ARM_SCTLR (1 << 14)

#define OKL4_ASM_SHIFT_DCACHE_ZERO_ARM_SCTLR (14)

#define OKL4_ASM_WIDTH_DCACHE_ZERO_ARM_SCTLR (1)

#define OKL4_ASM_MASK_USER_CACHE_TYPE_ARM_SCTLR (1 << 15)

#define OKL4_ASM_SHIFT_USER_CACHE_TYPE_ARM_SCTLR (15)

#define OKL4_ASM_WIDTH_USER_CACHE_TYPE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_NO_TRAP_WFI_ARM_SCTLR (1 << 16)

#define OKL4_ASM_SHIFT_NO_TRAP_WFI_ARM_SCTLR (16)

#define OKL4_ASM_WIDTH_NO_TRAP_WFI_ARM_SCTLR (1)

#define OKL4_ASM_MASK_NO_TRAP_WFE_ARM_SCTLR (1 << 18)

#define OKL4_ASM_SHIFT_NO_TRAP_WFE_ARM_SCTLR (18)

#define OKL4_ASM_WIDTH_NO_TRAP_WFE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_WRITE_EXEC_NEVER_ARM_SCTLR (1 << 19)

#define OKL4_ASM_SHIFT_WRITE_EXEC_NEVER_ARM_SCTLR (19)

#define OKL4_ASM_WIDTH_WRITE_EXEC_NEVER_ARM_SCTLR (1)

#define OKL4_ASM_MASK_USER_WRITE_EXEC_NEVER_ARM_SCTLR (1 << 20)

#define OKL4_ASM_SHIFT_USER_WRITE_EXEC_NEVER_ARM_SCTLR (20)

#define OKL4_ASM_WIDTH_USER_WRITE_EXEC_NEVER_ARM_SCTLR (1)

#define OKL4_ASM_MASK_RESERVED22_ARM_SCTLR (1 << 22)

#define OKL4_ASM_SHIFT_RESERVED22_ARM_SCTLR (22)

#define OKL4_ASM_WIDTH_RESERVED22_ARM_SCTLR (1)

#define OKL4_ASM_MASK_SPAN_ARM_SCTLR (1 << 23)

#define OKL4_ASM_SHIFT_SPAN_ARM_SCTLR (23)

#define OKL4_ASM_WIDTH_SPAN_ARM_SCTLR (1)

#define OKL4_ASM_MASK_EL0_ENDIANNESS_ARM_SCTLR (1 << 24)

#define OKL4_ASM_SHIFT_EL0_ENDIANNESS_ARM_SCTLR (24)

#define OKL4_ASM_WIDTH_EL0_ENDIANNESS_ARM_SCTLR (1)

#define OKL4_ASM_MASK_EXCEPTION_ENDIANNESS_ARM_SCTLR (1 << 25)

#define OKL4_ASM_SHIFT_EXCEPTION_ENDIANNESS_ARM_SCTLR (25)

#define OKL4_ASM_WIDTH_EXCEPTION_ENDIANNESS_ARM_SCTLR (1)

#define OKL4_ASM_MASK_TEX_REMAP_ENABLE_ARM_SCTLR (1 << 28)

#define OKL4_ASM_SHIFT_TEX_REMAP_ENABLE_ARM_SCTLR (28)

#define OKL4_ASM_WIDTH_TEX_REMAP_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_ACCESS_FLAG_ENABLE_ARM_SCTLR (1 << 29)

#define OKL4_ASM_SHIFT_ACCESS_FLAG_ENABLE_ARM_SCTLR (29)

#define OKL4_ASM_WIDTH_ACCESS_FLAG_ENABLE_ARM_SCTLR (1)

#define OKL4_ASM_MASK_THUMB_EXCEPTION_ENABLE_ARM_SCTLR (1 << 30)

#define OKL4_ASM_SHIFT_THUMB_EXCEPTION_ENABLE_ARM_SCTLR (30)

#define OKL4_ASM_WIDTH_THUMB_EXCEPTION_ENABLE_ARM_SCTLR (1)




#define OKL4_ASM_ARM_SMCCC_ARCH_FUNCTION_SMCCC_VERSION (0x0)

#define OKL4_ASM_ARM_SMCCC_ARCH_FUNCTION_ARCH_FEATURES (0x1)

#define OKL4_ASM_ARM_SMCCC_ARCH_FUNCTION_ARCH_WORKAROUND_1 (0x8000)



#define OKL4_ASM_ARM_SMCCC_RESULT_SUCCESS (0x0)

#define OKL4_ASM_ARM_SMCCC_RESULT_NOT_SUPPORTED (0xffffffff)



#define OKL4_DEFAULT_PAGEBITS (12)



#define OKL4_KMMU_LOOKUP_PAGE_SEGMENT_MASK (1023)



#define OKL4_KMMU_MAX_SEGMENTS (256)


#define OKL4_PROFILE_NO_PCPUS (-1)



#define OKL4_KCAP_INVALID (-1)



#define OKL4_INTERRUPT_INVALID_IRQ (1023)


#define OKL4_INVALID_VIRQ (1023)



#define OKL4_DEFAULT_PAGESIZE (4096)



#define OKL4_USER_AREA_END (17592186044416)





#define OKL4_ASM_MASK_PENDING_AXON_DATA_INFO (1)

#define OKL4_ASM_SHIFT_PENDING_AXON_DATA_INFO (0)

#define OKL4_ASM_WIDTH_PENDING_AXON_DATA_INFO (1)

#define OKL4_ASM_MASK_FAILURE_AXON_DATA_INFO (1 << 1)

#define OKL4_ASM_SHIFT_FAILURE_AXON_DATA_INFO (1)

#define OKL4_ASM_WIDTH_FAILURE_AXON_DATA_INFO (1)

#define OKL4_ASM_MASK_USR_AXON_DATA_INFO (1 << 2)

#define OKL4_ASM_SHIFT_USR_AXON_DATA_INFO (2)

#define OKL4_ASM_WIDTH_USR_AXON_DATA_INFO (1)

#define OKL4_ASM_MASK_LADDR_AXON_DATA_INFO (2305843009213693951 << 3)

#define OKL4_ASM_SHIFT_LADDR_AXON_DATA_INFO (3)

#define OKL4_ASM_PRESHIFT_LADDR_AXON_DATA_INFO (3)

#define OKL4_ASM_WIDTH_LADDR_AXON_DATA_INFO (61)






#define OKL4_ASM_MASK_ALLOC_ORDER_AXON_QUEUE_SIZE (31)

#define OKL4_ASM_SHIFT_ALLOC_ORDER_AXON_QUEUE_SIZE (0)

#define OKL4_ASM_WIDTH_ALLOC_ORDER_AXON_QUEUE_SIZE (5)

#define OKL4_ASM_MASK_MIN_ORDER_AXON_QUEUE_SIZE (31 << 8)

#define OKL4_ASM_SHIFT_MIN_ORDER_AXON_QUEUE_SIZE (8)

#define OKL4_ASM_WIDTH_MIN_ORDER_AXON_QUEUE_SIZE (5)






#define OKL4_ASM_MASK_READY_AXON_VIRQ_FLAGS (1)

#define OKL4_ASM_SHIFT_READY_AXON_VIRQ_FLAGS (0)

#define OKL4_ASM_WIDTH_READY_AXON_VIRQ_FLAGS (1)

#define OKL4_ASM_MASK_FAULT_AXON_VIRQ_FLAGS (1 << 1)

#define OKL4_ASM_SHIFT_FAULT_AXON_VIRQ_FLAGS (1)

#define OKL4_ASM_WIDTH_FAULT_AXON_VIRQ_FLAGS (1)




#define OKL4_ASM_PAGE_CACHE_WRITECOMBINE (0x0)

#define OKL4_ASM_PAGE_CACHE_DEFAULT (0x1)

#define OKL4_ASM_PAGE_CACHE_IPC_RX (0x1)

#define OKL4_ASM_PAGE_CACHE_IPC_TX (0x1)

#define OKL4_ASM_PAGE_CACHE_TRACEBUFFER (0x1)

#define OKL4_ASM_PAGE_CACHE_WRITEBACK (0x1)

#define OKL4_ASM_PAGE_CACHE_IWB_RWA_ONC (0x2)

#define OKL4_ASM_PAGE_CACHE_WRITETHROUGH (0x3)

#define OKL4_ASM_PAGE_CACHE_DEVICE_GRE (0x4)

#define OKL4_ASM_PAGE_CACHE_DEVICE_NGRE (0x5)

#define OKL4_ASM_PAGE_CACHE_DEVICE (0x6)

#define OKL4_ASM_PAGE_CACHE_STRONG (0x7)

#define OKL4_ASM_PAGE_CACHE_HW_DEVICE_NGNRNE (0x8000000)

#define OKL4_ASM_PAGE_CACHE_HW_MASK (0x8000000)

#define OKL4_ASM_PAGE_CACHE_HW_DEVICE_NGNRE (0x8000004)

#define OKL4_ASM_PAGE_CACHE_HW_DEVICE_NGRE (0x8000008)

#define OKL4_ASM_PAGE_CACHE_HW_DEVICE_GRE (0x800000c)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_WA_NSH (0x8000011)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_NSH (0x8000012)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_NSH (0x8000013)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_WA_NSH (0x8000014)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_NSH (0x8000015)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_NSH (0x8000016)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_NSH (0x8000017)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_WA_NSH (0x8000018)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_WA_NSH (0x8000019)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_WA_NSH (0x800001a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_NSH (0x800001b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_WA_NSH (0x800001c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_WA_NSH (0x800001d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_WA_NSH (0x800001e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_NSH (0x800001f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_NSH (0x8000021)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_RA_NSH (0x8000022)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_NSH (0x8000023)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_RA_NSH (0x8000024)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_NSH (0x8000025)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_NSH (0x8000026)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_NSH (0x8000027)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_RA_NSH (0x8000028)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_RA_NSH (0x8000029)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_RA_NSH (0x800002a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_NSH (0x800002b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_RA_NSH (0x800002c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_RA_NSH (0x800002d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_RA_NSH (0x800002e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_NSH (0x800002f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_NSH (0x8000031)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_NSH (0x8000032)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_RWA_NSH (0x8000033)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_RWA_NSH (0x8000034)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_NSH (0x8000035)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_NSH (0x8000036)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_NSH (0x8000037)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_NSH (0x8000038)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_NSH (0x8000039)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_NSH (0x800003a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_NSH (0x800003b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_NSH (0x800003c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_NSH (0x800003d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_NSH (0x800003e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_NSH (0x800003f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_ONC_NSH (0x8000041)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_ONC_NSH (0x8000042)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_ONC_NSH (0x8000043)

#define OKL4_ASM_PAGE_CACHE_HW_NC_NSH (0x8000044)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_ONC_NSH (0x8000045)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_ONC_NSH (0x8000046)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_ONC_NSH (0x8000047)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_ONC_NSH (0x8000048)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_ONC_NSH (0x8000049)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_ONC_NSH (0x800004a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_ONC_NSH (0x800004b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_ONC_NSH (0x800004c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_ONC_NSH (0x800004d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_ONC_NSH (0x800004e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_ONC_NSH (0x800004f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_NSH (0x8000051)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_NSH (0x8000052)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_NSH (0x8000053)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_WA_NSH (0x8000054)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_WA_NSH (0x8000055)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_NSH (0x8000056)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_NSH (0x8000057)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_WA_NSH (0x8000058)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_WA_NSH (0x8000059)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_WA_NSH (0x800005a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_NSH (0x800005b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_WA_NSH (0x800005c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_WA_NSH (0x800005d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_WA_NSH (0x800005e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_NSH (0x800005f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_NSH (0x8000061)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_NSH (0x8000062)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_NSH (0x8000063)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_RA_NSH (0x8000064)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_NSH (0x8000065)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_RA_NSH (0x8000066)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_NSH (0x8000067)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_RA_NSH (0x8000068)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_RA_NSH (0x8000069)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_RA_NSH (0x800006a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_NSH (0x800006b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_RA_NSH (0x800006c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_RA_NSH (0x800006d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_RA_NSH (0x800006e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_NSH (0x800006f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_NSH (0x8000071)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_NSH (0x8000072)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_NSH (0x8000073)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_RWA_NSH (0x8000074)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_NSH (0x8000075)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_NSH (0x8000076)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_RWA_NSH (0x8000077)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_NSH (0x8000078)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_NSH (0x8000079)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_NSH (0x800007a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_NSH (0x800007b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_NSH (0x800007c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_NSH (0x800007d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_NSH (0x800007e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_NSH (0x800007f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_NA_NSH (0x8000081)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_NA_NSH (0x8000082)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_NSH (0x8000083)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_NA_NSH (0x8000084)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_NA_NSH (0x8000085)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_NA_NSH (0x8000086)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_NSH (0x8000087)

#define OKL4_ASM_PAGE_CACHE_HW_WT_NA_NSH (0x8000088)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_NA_NSH (0x8000089)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_NA_NSH (0x800008a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_NA_NSH (0x800008b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_NA_NSH (0x800008c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_NA_NSH (0x800008d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_NA_NSH (0x800008e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_NA_NSH (0x800008f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_WA_NSH (0x8000091)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_WA_NSH (0x8000092)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_NSH (0x8000093)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_WA_NSH (0x8000094)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_WA_NSH (0x8000095)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_WA_NSH (0x8000096)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_NSH (0x8000097)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_WA_NSH (0x8000098)

#define OKL4_ASM_PAGE_CACHE_HW_WT_WA_NSH (0x8000099)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_WA_NSH (0x800009a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_WA_NSH (0x800009b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_WA_NSH (0x800009c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_WA_NSH (0x800009d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_WA_NSH (0x800009e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_WA_NSH (0x800009f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_RA_NSH (0x80000a1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_RA_NSH (0x80000a2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_NSH (0x80000a3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_RA_NSH (0x80000a4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_RA_NSH (0x80000a5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_RA_NSH (0x80000a6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_NSH (0x80000a7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_RA_NSH (0x80000a8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_RA_NSH (0x80000a9)

#define OKL4_ASM_PAGE_CACHE_HW_WT_RA_NSH (0x80000aa)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_RA_NSH (0x80000ab)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_RA_NSH (0x80000ac)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_RA_NSH (0x80000ad)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_RA_NSH (0x80000ae)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_RA_NSH (0x80000af)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_NSH (0x80000b1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_NSH (0x80000b2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_NSH (0x80000b3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_RWA_NSH (0x80000b4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_NSH (0x80000b5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_NSH (0x80000b6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_NSH (0x80000b7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_RWA_NSH (0x80000b8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_RWA_NSH (0x80000b9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_RWA_NSH (0x80000ba)

#define OKL4_ASM_PAGE_CACHE_HW_WT_RWA_NSH (0x80000bb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_RWA_NSH (0x80000bc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_RWA_NSH (0x80000bd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_RWA_NSH (0x80000be)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_NSH (0x80000bf)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_NA_NSH (0x80000c1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_NA_NSH (0x80000c2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_NSH (0x80000c3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_NA_NSH (0x80000c4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_NA_NSH (0x80000c5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_NA_NSH (0x80000c6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_NSH (0x80000c7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_NA_NSH (0x80000c8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_NA_NSH (0x80000c9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_NA_NSH (0x80000ca)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_NA_NSH (0x80000cb)

#define OKL4_ASM_PAGE_CACHE_HW_WB_NA_NSH (0x80000cc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_NA_NSH (0x80000cd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_NA_NSH (0x80000ce)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_NA_NSH (0x80000cf)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_WA_NSH (0x80000d1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_WA_NSH (0x80000d2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_NSH (0x80000d3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_WA_NSH (0x80000d4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_WA_NSH (0x80000d5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_WA_NSH (0x80000d6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_NSH (0x80000d7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_WA_NSH (0x80000d8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_WA_NSH (0x80000d9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_WA_NSH (0x80000da)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_WA_NSH (0x80000db)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_WA_NSH (0x80000dc)

#define OKL4_ASM_PAGE_CACHE_HW_WB_WA_NSH (0x80000dd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_WA_NSH (0x80000de)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_WA_NSH (0x80000df)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_RA_NSH (0x80000e1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_RA_NSH (0x80000e2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_NSH (0x80000e3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_RA_NSH (0x80000e4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_RA_NSH (0x80000e5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_RA_NSH (0x80000e6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_NSH (0x80000e7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_RA_NSH (0x80000e8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_RA_NSH (0x80000e9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_RA_NSH (0x80000ea)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_RA_NSH (0x80000eb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_RA_NSH (0x80000ec)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_RA_NSH (0x80000ed)

#define OKL4_ASM_PAGE_CACHE_HW_WB_RA_NSH (0x80000ee)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_RA_NSH (0x80000ef)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_NSH (0x80000f1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_NSH (0x80000f2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_NSH (0x80000f3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_RWA_NSH (0x80000f4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_NSH (0x80000f5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_NSH (0x80000f6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_NSH (0x80000f7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_RWA_NSH (0x80000f8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_RWA_NSH (0x80000f9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_RWA_NSH (0x80000fa)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_NSH (0x80000fb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_RWA_NSH (0x80000fc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_RWA_NSH (0x80000fd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_RWA_NSH (0x80000fe)

#define OKL4_ASM_PAGE_CACHE_HW_WB_RWA_NSH (0x80000ff)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_WA_OSH (0x8000211)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_OSH (0x8000212)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_OSH (0x8000213)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_WA_OSH (0x8000214)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_OSH (0x8000215)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_OSH (0x8000216)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_OSH (0x8000217)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_WA_OSH (0x8000218)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_WA_OSH (0x8000219)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_WA_OSH (0x800021a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_OSH (0x800021b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_WA_OSH (0x800021c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_WA_OSH (0x800021d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_WA_OSH (0x800021e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_OSH (0x800021f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_OSH (0x8000221)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_RA_OSH (0x8000222)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_OSH (0x8000223)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_RA_OSH (0x8000224)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_OSH (0x8000225)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_OSH (0x8000226)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_OSH (0x8000227)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_RA_OSH (0x8000228)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_RA_OSH (0x8000229)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_RA_OSH (0x800022a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_OSH (0x800022b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_RA_OSH (0x800022c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_RA_OSH (0x800022d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_RA_OSH (0x800022e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_OSH (0x800022f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_OSH (0x8000231)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_OSH (0x8000232)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_RWA_OSH (0x8000233)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_RWA_OSH (0x8000234)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_OSH (0x8000235)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_OSH (0x8000236)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_OSH (0x8000237)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_OSH (0x8000238)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_OSH (0x8000239)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_OSH (0x800023a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_OSH (0x800023b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_OSH (0x800023c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_OSH (0x800023d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_OSH (0x800023e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_OSH (0x800023f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_ONC_OSH (0x8000241)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_ONC_OSH (0x8000242)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_ONC_OSH (0x8000243)

#define OKL4_ASM_PAGE_CACHE_HW_NC_OSH (0x8000244)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_ONC_OSH (0x8000245)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_ONC_OSH (0x8000246)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_ONC_OSH (0x8000247)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_ONC_OSH (0x8000248)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_ONC_OSH (0x8000249)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_ONC_OSH (0x800024a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_ONC_OSH (0x800024b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_ONC_OSH (0x800024c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_ONC_OSH (0x800024d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_ONC_OSH (0x800024e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_ONC_OSH (0x800024f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_OSH (0x8000251)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_OSH (0x8000252)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_OSH (0x8000253)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_WA_OSH (0x8000254)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_WA_OSH (0x8000255)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_OSH (0x8000256)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_OSH (0x8000257)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_WA_OSH (0x8000258)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_WA_OSH (0x8000259)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_WA_OSH (0x800025a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_OSH (0x800025b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_WA_OSH (0x800025c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_WA_OSH (0x800025d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_WA_OSH (0x800025e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_OSH (0x800025f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_OSH (0x8000261)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_OSH (0x8000262)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_OSH (0x8000263)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_RA_OSH (0x8000264)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_OSH (0x8000265)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_RA_OSH (0x8000266)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_OSH (0x8000267)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_RA_OSH (0x8000268)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_RA_OSH (0x8000269)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_RA_OSH (0x800026a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_OSH (0x800026b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_RA_OSH (0x800026c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_RA_OSH (0x800026d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_RA_OSH (0x800026e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_OSH (0x800026f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_OSH (0x8000271)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_OSH (0x8000272)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_OSH (0x8000273)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_RWA_OSH (0x8000274)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_OSH (0x8000275)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_OSH (0x8000276)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_RWA_OSH (0x8000277)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_OSH (0x8000278)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_OSH (0x8000279)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_OSH (0x800027a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_OSH (0x800027b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_OSH (0x800027c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_OSH (0x800027d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_OSH (0x800027e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_OSH (0x800027f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_NA_OSH (0x8000281)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_NA_OSH (0x8000282)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_OSH (0x8000283)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_NA_OSH (0x8000284)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_NA_OSH (0x8000285)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_NA_OSH (0x8000286)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_OSH (0x8000287)

#define OKL4_ASM_PAGE_CACHE_HW_WT_NA_OSH (0x8000288)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_NA_OSH (0x8000289)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_NA_OSH (0x800028a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_NA_OSH (0x800028b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_NA_OSH (0x800028c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_NA_OSH (0x800028d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_NA_OSH (0x800028e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_NA_OSH (0x800028f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_WA_OSH (0x8000291)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_WA_OSH (0x8000292)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_OSH (0x8000293)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_WA_OSH (0x8000294)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_WA_OSH (0x8000295)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_WA_OSH (0x8000296)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_OSH (0x8000297)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_WA_OSH (0x8000298)

#define OKL4_ASM_PAGE_CACHE_HW_WT_WA_OSH (0x8000299)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_WA_OSH (0x800029a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_WA_OSH (0x800029b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_WA_OSH (0x800029c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_WA_OSH (0x800029d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_WA_OSH (0x800029e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_WA_OSH (0x800029f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_RA_OSH (0x80002a1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_RA_OSH (0x80002a2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_OSH (0x80002a3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_RA_OSH (0x80002a4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_RA_OSH (0x80002a5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_RA_OSH (0x80002a6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_OSH (0x80002a7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_RA_OSH (0x80002a8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_RA_OSH (0x80002a9)

#define OKL4_ASM_PAGE_CACHE_HW_WT_RA_OSH (0x80002aa)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_RA_OSH (0x80002ab)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_RA_OSH (0x80002ac)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_RA_OSH (0x80002ad)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_RA_OSH (0x80002ae)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_RA_OSH (0x80002af)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_OSH (0x80002b1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_OSH (0x80002b2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_OSH (0x80002b3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_RWA_OSH (0x80002b4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_OSH (0x80002b5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_OSH (0x80002b6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_OSH (0x80002b7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_RWA_OSH (0x80002b8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_RWA_OSH (0x80002b9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_RWA_OSH (0x80002ba)

#define OKL4_ASM_PAGE_CACHE_HW_WT_RWA_OSH (0x80002bb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_RWA_OSH (0x80002bc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_RWA_OSH (0x80002bd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_RWA_OSH (0x80002be)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_OSH (0x80002bf)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_NA_OSH (0x80002c1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_NA_OSH (0x80002c2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_OSH (0x80002c3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_NA_OSH (0x80002c4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_NA_OSH (0x80002c5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_NA_OSH (0x80002c6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_OSH (0x80002c7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_NA_OSH (0x80002c8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_NA_OSH (0x80002c9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_NA_OSH (0x80002ca)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_NA_OSH (0x80002cb)

#define OKL4_ASM_PAGE_CACHE_HW_WB_NA_OSH (0x80002cc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_NA_OSH (0x80002cd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_NA_OSH (0x80002ce)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_NA_OSH (0x80002cf)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_WA_OSH (0x80002d1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_WA_OSH (0x80002d2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_OSH (0x80002d3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_WA_OSH (0x80002d4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_WA_OSH (0x80002d5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_WA_OSH (0x80002d6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_OSH (0x80002d7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_WA_OSH (0x80002d8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_WA_OSH (0x80002d9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_WA_OSH (0x80002da)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_WA_OSH (0x80002db)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_WA_OSH (0x80002dc)

#define OKL4_ASM_PAGE_CACHE_HW_WB_WA_OSH (0x80002dd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_WA_OSH (0x80002de)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_WA_OSH (0x80002df)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_RA_OSH (0x80002e1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_RA_OSH (0x80002e2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_OSH (0x80002e3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_RA_OSH (0x80002e4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_RA_OSH (0x80002e5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_RA_OSH (0x80002e6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_OSH (0x80002e7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_RA_OSH (0x80002e8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_RA_OSH (0x80002e9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_RA_OSH (0x80002ea)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_RA_OSH (0x80002eb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_RA_OSH (0x80002ec)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_RA_OSH (0x80002ed)

#define OKL4_ASM_PAGE_CACHE_HW_WB_RA_OSH (0x80002ee)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_RA_OSH (0x80002ef)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_OSH (0x80002f1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_OSH (0x80002f2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_OSH (0x80002f3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_RWA_OSH (0x80002f4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_OSH (0x80002f5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_OSH (0x80002f6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_OSH (0x80002f7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_RWA_OSH (0x80002f8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_RWA_OSH (0x80002f9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_RWA_OSH (0x80002fa)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_OSH (0x80002fb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_RWA_OSH (0x80002fc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_RWA_OSH (0x80002fd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_RWA_OSH (0x80002fe)

#define OKL4_ASM_PAGE_CACHE_HW_WB_RWA_OSH (0x80002ff)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_WA_ISH (0x8000311)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWT_WA_ISH (0x8000312)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWT_WA_ISH (0x8000313)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_WA_ISH (0x8000314)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_WA_ISH (0x8000315)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_WA_ISH (0x8000316)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_WA_ISH (0x8000317)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_WA_ISH (0x8000318)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_WA_ISH (0x8000319)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_WA_ISH (0x800031a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_WA_ISH (0x800031b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_WA_ISH (0x800031c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_WA_ISH (0x800031d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_WA_ISH (0x800031e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_WA_ISH (0x800031f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWT_RA_ISH (0x8000321)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_RA_ISH (0x8000322)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWT_RA_ISH (0x8000323)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_RA_ISH (0x8000324)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_RA_ISH (0x8000325)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_RA_ISH (0x8000326)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_RA_ISH (0x8000327)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_RA_ISH (0x8000328)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_RA_ISH (0x8000329)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_RA_ISH (0x800032a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_RA_ISH (0x800032b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_RA_ISH (0x800032c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_RA_ISH (0x800032d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_RA_ISH (0x800032e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_RA_ISH (0x800032f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWT_RWA_ISH (0x8000331)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWT_RWA_ISH (0x8000332)

#define OKL4_ASM_PAGE_CACHE_HW_TWT_RWA_ISH (0x8000333)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWT_RWA_ISH (0x8000334)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWT_RWA_ISH (0x8000335)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWT_RWA_ISH (0x8000336)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWT_RWA_ISH (0x8000337)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWT_RWA_ISH (0x8000338)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWT_RWA_ISH (0x8000339)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWT_RWA_ISH (0x800033a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWT_RWA_ISH (0x800033b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWT_RWA_ISH (0x800033c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWT_RWA_ISH (0x800033d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWT_RWA_ISH (0x800033e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWT_RWA_ISH (0x800033f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_ONC_ISH (0x8000341)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_ONC_ISH (0x8000342)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_ONC_ISH (0x8000343)

#define OKL4_ASM_PAGE_CACHE_HW_NC_ISH (0x8000344)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_ONC_ISH (0x8000345)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_ONC_ISH (0x8000346)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_ONC_ISH (0x8000347)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_ONC_ISH (0x8000348)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_ONC_ISH (0x8000349)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_ONC_ISH (0x800034a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_ONC_ISH (0x800034b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_ONC_ISH (0x800034c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_ONC_ISH (0x800034d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_ONC_ISH (0x800034e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_ONC_ISH (0x800034f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_WA_ISH (0x8000351)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_WA_ISH (0x8000352)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_WA_ISH (0x8000353)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_WA_ISH (0x8000354)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_WA_ISH (0x8000355)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWB_WA_ISH (0x8000356)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWB_WA_ISH (0x8000357)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_WA_ISH (0x8000358)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_WA_ISH (0x8000359)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_WA_ISH (0x800035a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_WA_ISH (0x800035b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_WA_ISH (0x800035c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_WA_ISH (0x800035d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_WA_ISH (0x800035e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_WA_ISH (0x800035f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_RA_ISH (0x8000361)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_RA_ISH (0x8000362)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_RA_ISH (0x8000363)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_RA_ISH (0x8000364)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWB_RA_ISH (0x8000365)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_RA_ISH (0x8000366)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OTWB_RA_ISH (0x8000367)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_RA_ISH (0x8000368)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_RA_ISH (0x8000369)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_RA_ISH (0x800036a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_RA_ISH (0x800036b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_RA_ISH (0x800036c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_RA_ISH (0x800036d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_RA_ISH (0x800036e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_RA_ISH (0x800036f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OTWB_RWA_ISH (0x8000371)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OTWB_RWA_ISH (0x8000372)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OTWB_RWA_ISH (0x8000373)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OTWB_RWA_ISH (0x8000374)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OTWB_RWA_ISH (0x8000375)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OTWB_RWA_ISH (0x8000376)

#define OKL4_ASM_PAGE_CACHE_HW_TWB_RWA_ISH (0x8000377)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OTWB_RWA_ISH (0x8000378)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OTWB_RWA_ISH (0x8000379)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OTWB_RWA_ISH (0x800037a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OTWB_RWA_ISH (0x800037b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OTWB_RWA_ISH (0x800037c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OTWB_RWA_ISH (0x800037d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OTWB_RWA_ISH (0x800037e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OTWB_RWA_ISH (0x800037f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_NA_ISH (0x8000381)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_NA_ISH (0x8000382)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_NA_ISH (0x8000383)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_NA_ISH (0x8000384)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_NA_ISH (0x8000385)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_NA_ISH (0x8000386)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_NA_ISH (0x8000387)

#define OKL4_ASM_PAGE_CACHE_HW_WT_NA_ISH (0x8000388)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_NA_ISH (0x8000389)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_NA_ISH (0x800038a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_NA_ISH (0x800038b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_NA_ISH (0x800038c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_NA_ISH (0x800038d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_NA_ISH (0x800038e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_NA_ISH (0x800038f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_WA_ISH (0x8000391)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_WA_ISH (0x8000392)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_WA_ISH (0x8000393)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_WA_ISH (0x8000394)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_WA_ISH (0x8000395)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_WA_ISH (0x8000396)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_WA_ISH (0x8000397)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_WA_ISH (0x8000398)

#define OKL4_ASM_PAGE_CACHE_HW_WT_WA_ISH (0x8000399)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_WA_ISH (0x800039a)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_WA_ISH (0x800039b)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_WA_ISH (0x800039c)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_WA_ISH (0x800039d)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_WA_ISH (0x800039e)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_WA_ISH (0x800039f)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_RA_ISH (0x80003a1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_RA_ISH (0x80003a2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_RA_ISH (0x80003a3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_RA_ISH (0x80003a4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_RA_ISH (0x80003a5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_RA_ISH (0x80003a6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_RA_ISH (0x80003a7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_RA_ISH (0x80003a8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_RA_ISH (0x80003a9)

#define OKL4_ASM_PAGE_CACHE_HW_WT_RA_ISH (0x80003aa)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWT_RA_ISH (0x80003ab)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_RA_ISH (0x80003ac)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_RA_ISH (0x80003ad)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_RA_ISH (0x80003ae)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_RA_ISH (0x80003af)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWT_RWA_ISH (0x80003b1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWT_RWA_ISH (0x80003b2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWT_RWA_ISH (0x80003b3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWT_RWA_ISH (0x80003b4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWT_RWA_ISH (0x80003b5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWT_RWA_ISH (0x80003b6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWT_RWA_ISH (0x80003b7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWT_RWA_ISH (0x80003b8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWT_RWA_ISH (0x80003b9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWT_RWA_ISH (0x80003ba)

#define OKL4_ASM_PAGE_CACHE_HW_WT_RWA_ISH (0x80003bb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWT_RWA_ISH (0x80003bc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWT_RWA_ISH (0x80003bd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWT_RWA_ISH (0x80003be)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWT_RWA_ISH (0x80003bf)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_NA_ISH (0x80003c1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_NA_ISH (0x80003c2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_NA_ISH (0x80003c3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_NA_ISH (0x80003c4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_NA_ISH (0x80003c5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_NA_ISH (0x80003c6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_NA_ISH (0x80003c7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_NA_ISH (0x80003c8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_NA_ISH (0x80003c9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_NA_ISH (0x80003ca)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_NA_ISH (0x80003cb)

#define OKL4_ASM_PAGE_CACHE_HW_WB_NA_ISH (0x80003cc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_NA_ISH (0x80003cd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_NA_ISH (0x80003ce)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_NA_ISH (0x80003cf)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_WA_ISH (0x80003d1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_WA_ISH (0x80003d2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_WA_ISH (0x80003d3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_WA_ISH (0x80003d4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_WA_ISH (0x80003d5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_WA_ISH (0x80003d6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_WA_ISH (0x80003d7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_WA_ISH (0x80003d8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_WA_ISH (0x80003d9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_WA_ISH (0x80003da)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_WA_ISH (0x80003db)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_WA_ISH (0x80003dc)

#define OKL4_ASM_PAGE_CACHE_HW_WB_WA_ISH (0x80003dd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_WA_ISH (0x80003de)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_WA_ISH (0x80003df)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_RA_ISH (0x80003e1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_RA_ISH (0x80003e2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_RA_ISH (0x80003e3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_RA_ISH (0x80003e4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_RA_ISH (0x80003e5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_RA_ISH (0x80003e6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_RA_ISH (0x80003e7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_RA_ISH (0x80003e8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_RA_ISH (0x80003e9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_RA_ISH (0x80003ea)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_RA_ISH (0x80003eb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_RA_ISH (0x80003ec)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_RA_ISH (0x80003ed)

#define OKL4_ASM_PAGE_CACHE_HW_WB_RA_ISH (0x80003ee)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RWA_OWB_RA_ISH (0x80003ef)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_WA_OWB_RWA_ISH (0x80003f1)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RA_OWB_RWA_ISH (0x80003f2)

#define OKL4_ASM_PAGE_CACHE_HW_ITWT_RWA_OWB_RWA_ISH (0x80003f3)

#define OKL4_ASM_PAGE_CACHE_HW_INC_OWB_RWA_ISH (0x80003f4)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_WA_OWB_RWA_ISH (0x80003f5)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RA_OWB_RWA_ISH (0x80003f6)

#define OKL4_ASM_PAGE_CACHE_HW_ITWB_RWA_OWB_RWA_ISH (0x80003f7)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_NA_OWB_RWA_ISH (0x80003f8)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_WA_OWB_RWA_ISH (0x80003f9)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RA_OWB_RWA_ISH (0x80003fa)

#define OKL4_ASM_PAGE_CACHE_HW_IWT_RWA_OWB_RWA_ISH (0x80003fb)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_NA_OWB_RWA_ISH (0x80003fc)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_WA_OWB_RWA_ISH (0x80003fd)

#define OKL4_ASM_PAGE_CACHE_HW_IWB_RA_OWB_RWA_ISH (0x80003fe)

#define OKL4_ASM_PAGE_CACHE_HW_WB_RWA_ISH (0x80003ff)


#define OKL4_ASM_PAGE_CACHE_MAX (0x80003ff)


#define OKL4_ASM_PAGE_CACHE_INVALID (0xffffffff)



#define OKL4_ARM_MODE (0)


#define OKL4_DEFAULT_MODE (4)


#define OKL4_JAZELLE_MODE (2)


#define OKL4_THUMBEE_MODE (3)


#define OKL4_THUMB_MODE (1)





#define OKL4_ASM_MASK_EXEC_MODE_CPU_MODE (7)

#define OKL4_ASM_SHIFT_EXEC_MODE_CPU_MODE (0)

#define OKL4_ASM_WIDTH_EXEC_MODE_CPU_MODE (3)

#define OKL4_ASM_MASK_ENDIAN_CPU_MODE (1 << 7)

#define OKL4_ASM_SHIFT_ENDIAN_CPU_MODE (7)

#define OKL4_ASM_WIDTH_ENDIAN_CPU_MODE (1)




#define OKL4_ASM_PAGE_PERMS_NONE (0x0)

#define OKL4_ASM_PAGE_PERMS_X (0x1)

#define OKL4_ASM_PAGE_PERMS_W (0x2)

#define OKL4_ASM_PAGE_PERMS_WX (0x3)

#define OKL4_ASM_PAGE_PERMS_R (0x4)

#define OKL4_ASM_PAGE_PERMS_RX (0x5)

#define OKL4_ASM_PAGE_PERMS_RW (0x6)

#define OKL4_ASM_PAGE_PERMS_RWX (0x7)


#define OKL4_ASM_PAGE_PERMS_MAX (0x7)


#define OKL4_ASM_PAGE_PERMS_INVALID (0xffffffff)




#define OKL4_ASM_ERROR_KSP_OK (0x0)


#define OKL4_ASM_ERROR_OK (0x0)


#define OKL4_ASM_ERROR_ALREADY_STARTED (0x1)


#define OKL4_ASM_ERROR_ALREADY_STOPPED (0x2)

#define OKL4_ASM_ERROR_AXON_AREA_TOO_BIG (0x3)

#define OKL4_ASM_ERROR_AXON_BAD_MESSAGE_SIZE (0x4)

#define OKL4_ASM_ERROR_AXON_INVALID_OFFSET (0x5)

#define OKL4_ASM_ERROR_AXON_QUEUE_NOT_MAPPED (0x6)

#define OKL4_ASM_ERROR_AXON_QUEUE_NOT_READY (0x7)

#define OKL4_ASM_ERROR_AXON_TRANSFER_LIMIT_EXCEEDED (0x8)


#define OKL4_ASM_ERROR_CANCELLED (0x9)


#define OKL4_ASM_ERROR_EXISTING_MAPPING (0xa)


#define OKL4_ASM_ERROR_INSUFFICIENT_SEGMENT_RIGHTS (0xb)


#define OKL4_ASM_ERROR_INTERRUPTED (0xc)


#define OKL4_ASM_ERROR_INTERRUPT_ALREADY_ATTACHED (0xd)


#define OKL4_ASM_ERROR_INTERRUPT_INVALID_IRQ (0xe)


#define OKL4_ASM_ERROR_INTERRUPT_NOT_ATTACHED (0xf)


#define OKL4_ASM_ERROR_INVALID_ARGUMENT (0x10)


#define OKL4_ASM_ERROR_INVALID_DESIGNATOR (0x11)


#define OKL4_ASM_ERROR_INVALID_SEGMENT_INDEX (0x13)


#define OKL4_ASM_ERROR_MEMORY_FAULT (0x14)


#define OKL4_ASM_ERROR_MISSING_MAPPING (0x15)


#define OKL4_ASM_ERROR_NON_EMPTY_MMU_CONTEXT (0x16)


#define OKL4_ASM_ERROR_NOT_IN_SEGMENT (0x17)


#define OKL4_ASM_ERROR_NO_RESOURCES (0x19)


#define OKL4_ASM_ERROR_PIPE_BAD_STATE (0x1a)


#define OKL4_ASM_ERROR_PIPE_EMPTY (0x1b)


#define OKL4_ASM_ERROR_PIPE_FULL (0x1c)


#define OKL4_ASM_ERROR_PIPE_NOT_READY (0x1d)


#define OKL4_ASM_ERROR_PIPE_RECV_OVERFLOW (0x1e)


#define OKL4_ASM_ERROR_SEGMENT_USED (0x20)

#define OKL4_ASM_ERROR_THREAD_ALREADY_WATCHING_SUSPENDED (0x21)


#define OKL4_ASM_ERROR_TIMER_ACTIVE (0x22)


#define OKL4_ASM_ERROR_TIMER_CANCELLED (0x23)


#define OKL4_ASM_ERROR_TRY_AGAIN (0x24)


#define OKL4_ASM_ERROR_WOULD_BLOCK (0x25)


#define OKL4_ASM_ERROR_ALLOC_EXHAUSTED (0x26)


#define OKL4_ASM_ERROR_INVALID_AFFINITY (0x27)


#define OKL4_ASM_ERROR_KSP_ERROR_0 (0x10000010)


#define OKL4_ASM_ERROR_KSP_ERROR_1 (0x10000011)


#define OKL4_ASM_ERROR_KSP_ERROR_2 (0x10000012)


#define OKL4_ASM_ERROR_KSP_ERROR_3 (0x10000013)


#define OKL4_ASM_ERROR_KSP_ERROR_4 (0x10000014)


#define OKL4_ASM_ERROR_KSP_ERROR_5 (0x10000015)


#define OKL4_ASM_ERROR_KSP_ERROR_6 (0x10000016)


#define OKL4_ASM_ERROR_KSP_ERROR_7 (0x10000017)


#define OKL4_ASM_ERROR_KSP_INVALID_ARG (0x80000001)


#define OKL4_ASM_ERROR_KSP_NOT_IMPLEMENTED (0x80000002)


#define OKL4_ASM_ERROR_KSP_INSUFFICIENT_RIGHTS (0x80000003)


#define OKL4_ASM_ERROR_KSP_INTERRUPT_REGISTERED (0x80000004)


#define OKL4_ASM_ERROR_NOT_IMPLEMENTED (0xffffffff)


#define OKL4_ASM_ERROR_MAX (0xffffffff)





#define OKL4_ASM_MASK_EDGE_GICD_ICFGR (1 << 1)

#define OKL4_ASM_SHIFT_EDGE_GICD_ICFGR (1)

#define OKL4_ASM_WIDTH_EDGE_GICD_ICFGR (1)




#define OKL4_ASM_SGI_TARGET_LISTED (0x0)

#define OKL4_ASM_SGI_TARGET_ALL_OTHERS (0x1)

#define OKL4_ASM_SGI_TARGET_SELF (0x2)


#define OKL4_ASM_SGI_TARGET_MAX (0x2)


#define OKL4_ASM_SGI_TARGET_INVALID (0xffffffff)





#define OKL4_ASM_MASK_SGIINTID_GICD_SGIR (15)

#define OKL4_ASM_SHIFT_SGIINTID_GICD_SGIR (0)

#define OKL4_ASM_WIDTH_SGIINTID_GICD_SGIR (4)

#define OKL4_ASM_MASK_NSATT_GICD_SGIR (1 << 15)

#define OKL4_ASM_SHIFT_NSATT_GICD_SGIR (15)

#define OKL4_ASM_WIDTH_NSATT_GICD_SGIR (1)

#define OKL4_ASM_MASK_CPUTARGETLIST_GICD_SGIR (255 << 16)

#define OKL4_ASM_SHIFT_CPUTARGETLIST_GICD_SGIR (16)

#define OKL4_ASM_WIDTH_CPUTARGETLIST_GICD_SGIR (8)

#define OKL4_ASM_MASK_TARGETLISTFILTER_GICD_SGIR (3 << 24)

#define OKL4_ASM_SHIFT_TARGETLISTFILTER_GICD_SGIR (24)

#define OKL4_ASM_WIDTH_TARGETLISTFILTER_GICD_SGIR (2)




#define OKL4_ASM_LINK_ROLE_SYMMETRIC (0x0)

#define OKL4_ASM_LINK_ROLE_SERVER (0x1)

#define OKL4_ASM_LINK_ROLE_CLIENT (0x2)


#define OKL4_ASM_LINK_ROLE_MAX (0x2)


#define OKL4_ASM_LINK_ROLE_INVALID (0xffffffff)



#define OKL4_ASM_LINK_TRANSPORT_TYPE_SHARED_BUFFER (0x0)

#define OKL4_ASM_LINK_TRANSPORT_TYPE_AXONS (0x1)

#define OKL4_ASM_LINK_TRANSPORT_TYPE_PIPES (0x2)


#define OKL4_ASM_LINK_TRANSPORT_TYPE_MAX (0x2)


#define OKL4_ASM_LINK_TRANSPORT_TYPE_INVALID (0xffffffff)





#define OKL4_ASM_MASK_ERROR_MMU_LOOKUP_INDEX (65535)

#define OKL4_ASM_SHIFT_ERROR_MMU_LOOKUP_INDEX (0)

#define OKL4_ASM_WIDTH_ERROR_MMU_LOOKUP_INDEX (16)

#define OKL4_ASM_MASK_INDEX_MMU_LOOKUP_INDEX (65535 << 16)

#define OKL4_ASM_SHIFT_INDEX_MMU_LOOKUP_INDEX (16)

#define OKL4_ASM_WIDTH_INDEX_MMU_LOOKUP_INDEX (16)






#define OKL4_ASM_MASK_SEG_INDEX_MMU_LOOKUP_SIZE (1023)

#define OKL4_ASM_SHIFT_SEG_INDEX_MMU_LOOKUP_SIZE (0)

#define OKL4_ASM_WIDTH_SEG_INDEX_MMU_LOOKUP_SIZE (10)

#define OKL4_ASM_MASK_SIZE_10_MMU_LOOKUP_SIZE (18014398509481983 << 10)

#define OKL4_ASM_SHIFT_SIZE_10_MMU_LOOKUP_SIZE (10)

#define OKL4_ASM_WIDTH_SIZE_10_MMU_LOOKUP_SIZE (54)





#define OKL4_TIMER_MAX_PERIOD_NS (36028797018963968)



#define OKL4_TIMER_MIN_PERIOD_NS (1000000)





#define _OKL4_ASM_MASK_RWX_PAGE_ATTRIBUTE (7)

#define _OKL4_ASM_SHIFT_RWX_PAGE_ATTRIBUTE (0)

#define _OKL4_ASM_WIDTH_RWX_PAGE_ATTRIBUTE (3)

#define _OKL4_ASM_MASK_ATTRIB_PAGE_ATTRIBUTE (268435455 << 4)

#define _OKL4_ASM_SHIFT_ATTRIB_PAGE_ATTRIBUTE (4)

#define _OKL4_ASM_WIDTH_ATTRIB_PAGE_ATTRIBUTE (28)





#define OKL4_PIPE_CONTROL_OP_CLR_HALTED (4)

#define OKL4_PIPE_CONTROL_OP_RESET (0)

#define OKL4_PIPE_CONTROL_OP_SET_HALTED (3)

#define OKL4_PIPE_CONTROL_OP_SET_RX_READY (2)

#define OKL4_PIPE_CONTROL_OP_SET_TX_READY (1)


#define OKL4_ASM_MASK_DO_OP_PIPE_CONTROL (1)

#define OKL4_ASM_SHIFT_DO_OP_PIPE_CONTROL (0)

#define OKL4_ASM_WIDTH_DO_OP_PIPE_CONTROL (1)

#define OKL4_ASM_MASK_OPERATION_PIPE_CONTROL (7 << 1)

#define OKL4_ASM_SHIFT_OPERATION_PIPE_CONTROL (1)

#define OKL4_ASM_WIDTH_OPERATION_PIPE_CONTROL (3)






#define OKL4_ASM_MASK_RESET_PIPE_STATE (1)

#define OKL4_ASM_SHIFT_RESET_PIPE_STATE (0)

#define OKL4_ASM_WIDTH_RESET_PIPE_STATE (1)

#define OKL4_ASM_MASK_HALTED_PIPE_STATE (1 << 1)

#define OKL4_ASM_SHIFT_HALTED_PIPE_STATE (1)

#define OKL4_ASM_WIDTH_HALTED_PIPE_STATE (1)

#define OKL4_ASM_MASK_RX_READY_PIPE_STATE (1 << 2)

#define OKL4_ASM_SHIFT_RX_READY_PIPE_STATE (2)

#define OKL4_ASM_WIDTH_RX_READY_PIPE_STATE (1)

#define OKL4_ASM_MASK_TX_READY_PIPE_STATE (1 << 3)

#define OKL4_ASM_SHIFT_TX_READY_PIPE_STATE (3)

#define OKL4_ASM_WIDTH_TX_READY_PIPE_STATE (1)

#define OKL4_ASM_MASK_RX_AVAILABLE_PIPE_STATE (1 << 4)

#define OKL4_ASM_SHIFT_RX_AVAILABLE_PIPE_STATE (4)

#define OKL4_ASM_WIDTH_RX_AVAILABLE_PIPE_STATE (1)

#define OKL4_ASM_MASK_TX_AVAILABLE_PIPE_STATE (1 << 5)

#define OKL4_ASM_SHIFT_TX_AVAILABLE_PIPE_STATE (5)

#define OKL4_ASM_WIDTH_TX_AVAILABLE_PIPE_STATE (1)

#define OKL4_ASM_MASK_WAITING_PIPE_STATE (1 << 6)

#define OKL4_ASM_SHIFT_WAITING_PIPE_STATE (6)

#define OKL4_ASM_WIDTH_WAITING_PIPE_STATE (1)

#define OKL4_ASM_MASK_OVERQUOTA_PIPE_STATE (1 << 7)

#define OKL4_ASM_SHIFT_OVERQUOTA_PIPE_STATE (7)

#define OKL4_ASM_WIDTH_OVERQUOTA_PIPE_STATE (1)




#define OKL4_POWER_STATE_IDLE (2147483648)


#define OKL4_POWER_STATE_PLATFORM_LAST (2147483647)


#define OKL4_POWER_STATE_POWEROFF (2147483650)


#define OKL4_POWER_STATE_RETENTION (2147483649)



#define OKL4_ASM_REGISTER_SET_CPU_REGS (0x0)

#define OKL4_ASM_REGISTER_SET_VFP_REGS (0x1)

#define OKL4_ASM_REGISTER_SET_VFP_CTRL_REGS (0x2)

#define OKL4_ASM_REGISTER_SET_VFP64_REGS (0x3)

#define OKL4_ASM_REGISTER_SET_VFP128_REGS (0x4)


#define OKL4_ASM_REGISTER_SET_MAX (0x4)


#define OKL4_ASM_REGISTER_SET_INVALID (0xffffffff)





#define OKL4_ASM_MASK_OFFSET_REGISTER_AND_SET (65535)

#define OKL4_ASM_SHIFT_OFFSET_REGISTER_AND_SET (0)

#define OKL4_ASM_WIDTH_OFFSET_REGISTER_AND_SET (16)

#define OKL4_ASM_MASK_SET_REGISTER_AND_SET (65535 << 16)

#define OKL4_ASM_SHIFT_SET_REGISTER_AND_SET (16)

#define OKL4_ASM_WIDTH_SET_REGISTER_AND_SET (16)






#define OKL4_ASM_MASK_POWER_SUSPENDED_SCHEDULER_VIRQ_FLAGS (1)

#define OKL4_ASM_SHIFT_POWER_SUSPENDED_SCHEDULER_VIRQ_FLAGS (0)

#define OKL4_ASM_WIDTH_POWER_SUSPENDED_SCHEDULER_VIRQ_FLAGS (1)






#define OKL4_ASM_MASK_MAINTENANCE_SDK_VERSION (63)

#define OKL4_ASM_SHIFT_MAINTENANCE_SDK_VERSION (0)

#define OKL4_ASM_WIDTH_MAINTENANCE_SDK_VERSION (6)

#define OKL4_ASM_MASK_RELEASE_SDK_VERSION (255 << 8)

#define OKL4_ASM_SHIFT_RELEASE_SDK_VERSION (8)

#define OKL4_ASM_WIDTH_RELEASE_SDK_VERSION (8)

#define OKL4_ASM_MASK_MINOR_SDK_VERSION (63 << 16)

#define OKL4_ASM_SHIFT_MINOR_SDK_VERSION (16)

#define OKL4_ASM_WIDTH_MINOR_SDK_VERSION (6)

#define OKL4_ASM_MASK_MAJOR_SDK_VERSION (15 << 24)

#define OKL4_ASM_SHIFT_MAJOR_SDK_VERSION (24)

#define OKL4_ASM_WIDTH_MAJOR_SDK_VERSION (4)

#define OKL4_ASM_MASK_RES0_FLAG_SDK_VERSION (1 << 28)

#define OKL4_ASM_SHIFT_RES0_FLAG_SDK_VERSION (28)

#define OKL4_ASM_WIDTH_RES0_FLAG_SDK_VERSION (1)

#define OKL4_ASM_MASK_DEV_FLAG_SDK_VERSION (1 << 30)

#define OKL4_ASM_SHIFT_DEV_FLAG_SDK_VERSION (30)

#define OKL4_ASM_WIDTH_DEV_FLAG_SDK_VERSION (1)

#define OKL4_ASM_MASK_FORMAT_FLAG_SDK_VERSION (1 << 31)

#define OKL4_ASM_SHIFT_FORMAT_FLAG_SDK_VERSION (31)

#define OKL4_ASM_WIDTH_FORMAT_FLAG_SDK_VERSION (1)






#define OKL4_ASM_MASK_ACTIVE_TIMER_FLAGS (1)

#define OKL4_ASM_SHIFT_ACTIVE_TIMER_FLAGS (0)

#define OKL4_ASM_WIDTH_ACTIVE_TIMER_FLAGS (1)

#define OKL4_ASM_MASK_PERIODIC_TIMER_FLAGS (1 << 1)

#define OKL4_ASM_SHIFT_PERIODIC_TIMER_FLAGS (1)

#define OKL4_ASM_WIDTH_PERIODIC_TIMER_FLAGS (1)

#define OKL4_ASM_MASK_ABSOLUTE_TIMER_FLAGS (1 << 2)

#define OKL4_ASM_SHIFT_ABSOLUTE_TIMER_FLAGS (2)

#define OKL4_ASM_WIDTH_ABSOLUTE_TIMER_FLAGS (1)

#define OKL4_ASM_MASK_UNITS_TIMER_FLAGS (1 << 3)

#define OKL4_ASM_SHIFT_UNITS_TIMER_FLAGS (3)

#define OKL4_ASM_WIDTH_UNITS_TIMER_FLAGS (1)

#define OKL4_ASM_MASK_ALIGN_TIMER_FLAGS (1 << 4)

#define OKL4_ASM_SHIFT_ALIGN_TIMER_FLAGS (4)

#define OKL4_ASM_WIDTH_ALIGN_TIMER_FLAGS (1)

#define OKL4_ASM_MASK_WATCHDOG_TIMER_FLAGS (1 << 5)

#define OKL4_ASM_SHIFT_WATCHDOG_TIMER_FLAGS (5)

#define OKL4_ASM_WIDTH_WATCHDOG_TIMER_FLAGS (1)

#define OKL4_ASM_MASK_RELOAD_TIMER_FLAGS (1 << 30)

#define OKL4_ASM_SHIFT_RELOAD_TIMER_FLAGS (30)

#define OKL4_ASM_WIDTH_RELOAD_TIMER_FLAGS (1)

#define OKL4_ASM_MASK_TIMESLICE_TIMER_FLAGS (1 << 31)

#define OKL4_ASM_SHIFT_TIMESLICE_TIMER_FLAGS (31)

#define OKL4_ASM_WIDTH_TIMESLICE_TIMER_FLAGS (1)




#define OKL4_ASM_TRACEPOINT_CLASS_THREAD_STATE (0x0)

#define OKL4_ASM_TRACEPOINT_CLASS_SYSCALLS (0x1)

#define OKL4_ASM_TRACEPOINT_CLASS_PRIMARY (0x2)

#define OKL4_ASM_TRACEPOINT_CLASS_SECONDARY (0x3)

#define OKL4_ASM_TRACEPOINT_CLASS_TERTIARY (0x4)


#define OKL4_ASM_TRACEPOINT_CLASS_MAX (0x4)


#define OKL4_ASM_TRACEPOINT_CLASS_INVALID (0xffffffff)





#define _OKL4_ASM_MASK_ID_TRACEPOINT_DESC (255)

#define _OKL4_ASM_SHIFT_ID_TRACEPOINT_DESC (0)

#define _OKL4_ASM_WIDTH_ID_TRACEPOINT_DESC (8)

#define _OKL4_ASM_MASK_USER_TRACEPOINT_DESC (1 << 8)

#define _OKL4_ASM_SHIFT_USER_TRACEPOINT_DESC (8)

#define _OKL4_ASM_WIDTH_USER_TRACEPOINT_DESC (1)

#define _OKL4_ASM_MASK_BIN_TRACEPOINT_DESC (1 << 9)

#define _OKL4_ASM_SHIFT_BIN_TRACEPOINT_DESC (9)

#define _OKL4_ASM_WIDTH_BIN_TRACEPOINT_DESC (1)

#define _OKL4_ASM_MASK_RECLEN_TRACEPOINT_DESC (63 << 10)

#define _OKL4_ASM_SHIFT_RECLEN_TRACEPOINT_DESC (10)

#define _OKL4_ASM_WIDTH_RECLEN_TRACEPOINT_DESC (6)

#define _OKL4_ASM_MASK_CPUID_TRACEPOINT_DESC (63 << 16)

#define _OKL4_ASM_SHIFT_CPUID_TRACEPOINT_DESC (16)

#define _OKL4_ASM_WIDTH_CPUID_TRACEPOINT_DESC (6)

#define _OKL4_ASM_MASK_THREADID_TRACEPOINT_DESC (63 << 22)

#define _OKL4_ASM_SHIFT_THREADID_TRACEPOINT_DESC (22)

#define _OKL4_ASM_WIDTH_THREADID_TRACEPOINT_DESC (6)

#define _OKL4_ASM_MASK__R1_TRACEPOINT_DESC (15 << 28)

#define _OKL4_ASM_SHIFT__R1_TRACEPOINT_DESC (28)

#define _OKL4_ASM_WIDTH__R1_TRACEPOINT_DESC (4)






#define _OKL4_ASM_MASK_CLASS_TRACEPOINT_MASKS (65535)

#define _OKL4_ASM_SHIFT_CLASS_TRACEPOINT_MASKS (0)

#define _OKL4_ASM_WIDTH_CLASS_TRACEPOINT_MASKS (16)

#define _OKL4_ASM_MASK_SUBSYSTEM_TRACEPOINT_MASKS (65535 << 16)

#define _OKL4_ASM_SHIFT_SUBSYSTEM_TRACEPOINT_MASKS (16)

#define _OKL4_ASM_WIDTH_SUBSYSTEM_TRACEPOINT_MASKS (16)




#define OKL4_ASM_TRACEPOINT_EVT_SCH_SCHEDULER_FLAG_SET_RUNNABLE (0x0)

#define OKL4_ASM_TRACEPOINT_EVT_SCH_SCHEDULER_FLAG_CLEAR_RUNNABLE (0x1)

#define OKL4_ASM_TRACEPOINT_EVT_SCH_CONTEXT_SWITCH (0x2)

#define OKL4_ASM_TRACEPOINT_EVT_KDB_SET_OBJECT_NAME (0x3)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_PROCESS_RECV (0x4)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_SET_HALTED (0x5)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_SET_RECV_AREA (0x6)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_SET_RECV_QUEUE (0x7)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_SET_RECV_SEGMENT (0x8)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_SET_SEND_AREA (0x9)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_SET_SEND_QUEUE (0xa)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_SET_SEND_SEGMENT (0xb)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_AXON_TRIGGER_SEND (0xc)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_DEBUG_RESUME (0xd)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_DEBUG_SUSPEND (0xe)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_ACK (0xf)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_ATTACH_PRIVATE (0x10)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_ATTACH_SHARED (0x11)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_DETACH (0x12)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_DIST_ENABLE (0x13)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_EOI (0x14)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_GET_HIGHEST_PRIORITY_PENDING (0x15)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_GET_PAYLOAD (0x16)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_LIMITS (0x17)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_MASK (0x18)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_RAISE (0x19)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_SET_BINARY_POINT (0x1a)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_SET_CONFIG (0x1b)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_SET_CONTROL (0x1c)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_SET_PRIORITY (0x1d)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_SET_PRIORITY_MASK (0x1e)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_SET_TARGETS (0x1f)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_INTERRUPT_UNMASK (0x20)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_KDB_INTERACT (0x21)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_KDB_SET_OBJECT_NAME (0x22)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_KSP_PROCEDURE_CALL (0x23)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_ATTACH_SEGMENT (0x24)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_DETACH_SEGMENT (0x25)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_FLUSH_RANGE (0x26)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_FLUSH_RANGE_PN (0x27)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_LOOKUP_PAGE (0x28)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_LOOKUP_PN (0x29)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_MAP_PAGE (0x2a)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_MAP_PN (0x2b)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_UNMAP_PAGE (0x2c)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_UNMAP_PN (0x2d)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_UPDATE_PAGE_ATTRS (0x2e)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_UPDATE_PAGE_PERMS (0x2f)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_UPDATE_PN_ATTRS (0x30)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_MMU_UPDATE_PN_PERMS (0x31)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_PERFORMANCE_NULL_SYSCALL (0x32)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_PIPE_CONTROL (0x33)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_PIPE_RECV (0x34)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_PIPE_SEND (0x35)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_PRIORITY_WAIVE (0x36)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_REMOTE_GET_REGISTER (0x37)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_REMOTE_GET_REGISTERS (0x38)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_REMOTE_READ_MEMORY32 (0x39)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_REMOTE_SET_REGISTER (0x3a)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_REMOTE_SET_REGISTERS (0x3b)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_REMOTE_WRITE_MEMORY32 (0x3c)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULE_METRICS_STATUS_SUSPENDED (0x3d)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULE_METRICS_WATCH_SUSPENDED (0x3e)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_DISABLE (0x3f)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_ENABLE (0x40)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_CPU_GET_DATA (0x41)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_DISABLE (0x42)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_ENABLE (0x43)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULE_PROFILE_VCPU_GET_DATA (0x44)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULER_AFFINITY_GET (0x45)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_SCHEDULER_AFFINITY_SET (0x46)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_TIMER_CANCEL (0x47)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_TIMER_GET_RESOLUTION (0x48)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_TIMER_GET_TIME (0x49)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_TIMER_QUERY (0x4a)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_TIMER_START (0x4b)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_TRACEBUFFER_SYNC (0x4c)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VCPU_RESET (0x4d)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VCPU_START (0x4e)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VCPU_STOP (0x4f)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VCPU_SWITCH_MODE (0x50)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VCPU_SYNC_SEV (0x51)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VCPU_SYNC_WFE (0x52)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VINTERRUPT_CLEAR_AND_RAISE (0x53)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VINTERRUPT_MODIFY (0x54)

#define OKL4_ASM_TRACEPOINT_EVT_SWI_VINTERRUPT_RAISE (0x55)


#define OKL4_ASM_TRACEPOINT_EVT_MAX (0x55)


#define OKL4_ASM_TRACEPOINT_EVT_INVALID (0xffffffff)



#define OKL4_ASM_TRACEPOINT_LEVEL_DEBUG (0x0)

#define OKL4_ASM_TRACEPOINT_LEVEL_INFO (0x1)

#define OKL4_ASM_TRACEPOINT_LEVEL_WARN (0x2)

#define OKL4_ASM_TRACEPOINT_LEVEL_CRITICAL (0x3)


#define OKL4_ASM_TRACEPOINT_LEVEL_MAX (0x3)


#define OKL4_ASM_TRACEPOINT_LEVEL_INVALID (0xffffffff)



#define OKL4_ASM_TRACEPOINT_SUBSYSTEM_SCHEDULER (0x0)

#define OKL4_ASM_TRACEPOINT_SUBSYSTEM_TRACE (0x1)

#define OKL4_ASM_TRACEPOINT_SUBSYSTEM_CORE (0x2)


#define OKL4_ASM_TRACEPOINT_SUBSYSTEM_MAX (0x2)


#define OKL4_ASM_TRACEPOINT_SUBSYSTEM_INVALID (0xffffffff)




#define OKL4_ASM_VFP_OPS_MAX (0x0)


#define OKL4_ASM_VFP_OPS_INVALID (0xffffffff)



#define OKL4_ASM_VSERVICES_TRANSPORT_TYPE_AXON (0x0)

#define OKL4_ASM_VSERVICES_TRANSPORT_TYPE_SHARED_BUFFER (0x1)


#define OKL4_ASM_VSERVICES_TRANSPORT_TYPE_MAX (0x1)


#define OKL4_ASM_VSERVICES_TRANSPORT_TYPE_INVALID (0xffffffff)


#endif 

#endif 


