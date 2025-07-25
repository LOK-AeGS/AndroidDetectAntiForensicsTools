

#ifndef LOAD_OFFSET
#define LOAD_OFFSET 0
#endif


#define ALIGN_FUNCTION()  . = ALIGN(8)


#if defined(CONFIG_LD_DEAD_CODE_DATA_ELIMINATION) || defined(CONFIG_LTO_CLANG)
#define TEXT_MAIN .text .text.[0-9a-zA-Z_]*
#define TEXT_CFI_MAIN .text.[0-9a-zA-Z_]*.cfi
#define DATA_MAIN .data .data.[0-9a-zA-Z_]* .data..LPBX*
#define SDATA_MAIN .sdata .sdata.[0-9a-zA-Z_]*
#define RODATA_MAIN .rodata .rodata.[0-9a-zA-Z_]*
#define BSS_MAIN .bss .bss.[0-9a-zA-Z_]*
#define SBSS_MAIN .sbss .sbss.[0-9a-zA-Z_]*
#else
#define TEXT_MAIN .text
#define TEXT_CFI_MAIN .text.cfi
#define DATA_MAIN .data
#define SDATA_MAIN .sdata
#define RODATA_MAIN .rodata
#define BSS_MAIN .bss
#define SBSS_MAIN .sbss
#endif


#define STRUCT_ALIGNMENT 32
#define STRUCT_ALIGN() . = ALIGN(STRUCT_ALIGNMENT)


#ifdef CONFIG_HOTPLUG_CPU
#define CPU_KEEP(sec)    *(.cpu##sec)
#define CPU_DISCARD(sec)
#else
#define CPU_KEEP(sec)
#define CPU_DISCARD(sec) *(.cpu##sec)
#endif

#if defined(CONFIG_MEMORY_HOTPLUG)
#define MEM_KEEP(sec)    *(.mem##sec)
#define MEM_DISCARD(sec)
#else
#define MEM_KEEP(sec)
#define MEM_DISCARD(sec) *(.mem##sec)
#endif

#ifdef CONFIG_FTRACE_MCOUNT_RECORD
#define MCOUNT_REC()	. = ALIGN(8);				\
			__start_mcount_loc = .;			\
			KEEP(*(__mcount_loc))			\
			__stop_mcount_loc = .;
#else
#define MCOUNT_REC()
#endif

#ifdef CONFIG_TRACE_BRANCH_PROFILING
#define LIKELY_PROFILE()	__start_annotated_branch_profile = .;	\
				KEEP(*(_ftrace_annotated_branch))	\
				__stop_annotated_branch_profile = .;
#else
#define LIKELY_PROFILE()
#endif

#ifdef CONFIG_PROFILE_ALL_BRANCHES
#define BRANCH_PROFILE()	__start_branch_profile = .;		\
				KEEP(*(_ftrace_branch))			\
				__stop_branch_profile = .;
#else
#define BRANCH_PROFILE()
#endif

#ifdef CONFIG_KPROBES
#define KPROBE_BLACKLIST()	. = ALIGN(8);				      \
				__start_kprobe_blacklist = .;		      \
				KEEP(*(_kprobe_blacklist))		      \
				__stop_kprobe_blacklist = .;
#else
#define KPROBE_BLACKLIST()
#endif

#ifdef CONFIG_FUNCTION_ERROR_INJECTION
#define ERROR_INJECT_WHITELIST()	STRUCT_ALIGN();			      \
			__start_error_injection_whitelist = .;		      \
			KEEP(*(_error_injection_whitelist))		      \
			__stop_error_injection_whitelist = .;
#else
#define ERROR_INJECT_WHITELIST()
#endif

#ifdef CONFIG_EVENT_TRACING
#define FTRACE_EVENTS()	. = ALIGN(8);					\
			__start_ftrace_events = .;			\
			KEEP(*(_ftrace_events))				\
			__stop_ftrace_events = .;			\
			__start_ftrace_eval_maps = .;			\
			KEEP(*(_ftrace_eval_map))			\
			__stop_ftrace_eval_maps = .;
#else
#define FTRACE_EVENTS()
#endif

#ifdef CONFIG_TRACING
#define TRACE_PRINTKS()	 __start___trace_bprintk_fmt = .;      \
			 KEEP(*(__trace_printk_fmt))  \
			 __stop___trace_bprintk_fmt = .;
#define TRACEPOINT_STR() __start___tracepoint_str = .;	\
			 KEEP(*(__tracepoint_str))  \
			 __stop___tracepoint_str = .;
#else
#define TRACE_PRINTKS()
#define TRACEPOINT_STR()
#endif

#ifdef CONFIG_FTRACE_SYSCALLS
#define TRACE_SYSCALLS() . = ALIGN(8);					\
			 __start_syscalls_metadata = .;			\
			 KEEP(*(__syscalls_metadata))			\
			 __stop_syscalls_metadata = .;
#else
#define TRACE_SYSCALLS()
#endif

#ifdef CONFIG_BPF_EVENTS
#define BPF_RAW_TP() STRUCT_ALIGN();					\
			 __start__bpf_raw_tp = .;			\
			 KEEP(*(__bpf_raw_tp_map))			\
			 __stop__bpf_raw_tp = .;
#else
#define BPF_RAW_TP()
#endif

#ifdef CONFIG_SERIAL_EARLYCON
#define EARLYCON_TABLE() . = ALIGN(8);				\
			 __earlycon_table = .;			\
			 KEEP(*(__earlycon_table))		\
			 __earlycon_table_end = .;
#else
#define EARLYCON_TABLE()
#endif

#define ___OF_TABLE(cfg, name)	_OF_TABLE_##cfg(name)
#define __OF_TABLE(cfg, name)	___OF_TABLE(cfg, name)
#define OF_TABLE(cfg, name)	__OF_TABLE(IS_ENABLED(cfg), name)
#define _OF_TABLE_0(name)
#define _OF_TABLE_1(name)						\
	. = ALIGN(8);							\
	__##name##_of_table = .;					\
	KEEP(*(__##name##_of_table))					\
	KEEP(*(__##name##_of_table_end))

#define TIMER_OF_TABLES()	OF_TABLE(CONFIG_TIMER_OF, timer)
#define IRQCHIP_OF_MATCH_TABLE() OF_TABLE(CONFIG_IRQCHIP, irqchip)
#define CLK_OF_TABLES()		OF_TABLE(CONFIG_COMMON_CLK, clk)
#define RESERVEDMEM_OF_TABLES()	OF_TABLE(CONFIG_OF_RESERVED_MEM, reservedmem)
#define CPU_METHOD_OF_TABLES()	OF_TABLE(CONFIG_SMP, cpu_method)
#define CPUIDLE_METHOD_OF_TABLES() OF_TABLE(CONFIG_CPU_IDLE, cpuidle_method)

#ifdef CONFIG_ACPI
#define ACPI_PROBE_TABLE(name)						\
	. = ALIGN(8);							\
	__##name##_acpi_probe_table = .;				\
	KEEP(*(__##name##_acpi_probe_table))				\
	__##name##_acpi_probe_table_end = .;
#else
#define ACPI_PROBE_TABLE(name)
#endif

#define KERNEL_DTB()							\
	STRUCT_ALIGN();							\
	__dtb_start = .;						\
	KEEP(*(.dtb.init.rodata))					\
	__dtb_end = .;


#define DATA_DATA							\
	*(.xiptext)							\
	*(DATA_MAIN)							\
	*(.ref.data)							\
	*(.data..shared_aligned) 			\
	MEM_KEEP(init.data*)						\
	MEM_KEEP(exit.data*)						\
	*(.data.unlikely)						\
	__start_once = .;						\
	*(.data.once)							\
	__end_once = .;							\
	STRUCT_ALIGN();							\
	*(__tracepoints)						\
					\
	. = ALIGN(8);                                                   \
	__start___jump_table = .;					\
	KEEP(*(__jump_table))                                           \
	__stop___jump_table = .;					\
	. = ALIGN(8);							\
	__start___verbose = .;						\
	KEEP(*(__verbose))                                              \
	__stop___verbose = .;						\
	LIKELY_PROFILE()		       				\
	BRANCH_PROFILE()						\
	TRACE_PRINTKS()							\
	BPF_RAW_TP()							\
	TRACEPOINT_STR()


#define NOSAVE_DATA							\
	. = ALIGN(PAGE_SIZE);						\
	__nosave_begin = .;						\
	*(.data..nosave)						\
	. = ALIGN(PAGE_SIZE);						\
	__nosave_end = .;

#define PAGE_ALIGNED_DATA(page_align)					\
	. = ALIGN(page_align);						\
	*(.data..page_aligned)						\
	. = ALIGN(page_align);

#define READ_MOSTLY_DATA(align)						\
	. = ALIGN(align);						\
	*(.data..read_mostly)						\
	. = ALIGN(align);

#define CACHELINE_ALIGNED_DATA(align)					\
	. = ALIGN(align);						\
	*(.data..cacheline_aligned)

#define INIT_TASK_DATA(align)						\
	. = ALIGN(align);						\
	__start_init_task = .;						\
	init_thread_union = .;						\
	init_stack = .;							\
	KEEP(*(.data..init_task))					\
	KEEP(*(.data..init_thread_info))				\
	. = __start_init_task + THREAD_SIZE;				\
	__end_init_task = .;


#ifndef RO_AFTER_INIT_DATA
#define RO_AFTER_INIT_DATA						\
	. = ALIGN(8);							\
	__start_ro_after_init = .;					\
	*(.data..ro_after_init)						\
	__end_ro_after_init = .;
#endif


#ifdef CONFIG_RKP
#define PG_IDMAP							\
	. = ALIGN(PAGE_SIZE);						\
	idmap_pg_dir = .;						\
	. += IDMAP_DIR_SIZE;

#define PG_SWAP								\
	. = ALIGN(PAGE_SIZE);						\
	swapper_pg_dir = .;						\
	. += SWAPPER_DIR_SIZE;						\
	swapper_pg_end = .;

#ifdef CONFIG_ARM64_SW_TTBR0_PAN
#define PG_RESERVED							\
	. = ALIGN(PAGE_SIZE);						\
	reserved_ttbr0 = .;						\
	. += RESERVED_TTBR0_SIZE;
#else
#define PG_RESERVED
#endif

#ifdef CONFIG_UNMAP_KERNEL_AT_EL0
#define PG_TRAMP							\
	. = ALIGN(PAGE_SIZE);						\
	tramp_pg_dir = .;						\
	. += PAGE_SIZE;
#else
#define PG_TRAMP
#endif

#define RKP_RO_DATA							\
	PG_IDMAP							\
	PG_SWAP								\
	PG_RESERVED							\
	PG_TRAMP
#else

#define RKP_RO_DATA
#endif

#ifdef CONFIG_UH
#define UH_RO_SECTION						\
	. = ALIGN(4096);						\
	.uh_bss       : AT(ADDR(.uh_bss) - LOAD_OFFSET) {	\
		*(.uh_bss.page_aligned)				\
		*(.uh_bss)						\
	} = 0								\
									\
	.uh_ro          : AT(ADDR(.uh_ro) - LOAD_OFFSET) {	\
		*(.rkp_ro)						\
		*(.kdp_ro)						\
		RKP_RO_DATA			\
	}
#else
#define UH_RO_SECTION
#endif


#define RO_DATA_SECTION(align)						\
	. = ALIGN((align));						\
	.rodata           : AT(ADDR(.rodata) - LOAD_OFFSET) {		\
		__start_rodata = .;					\
		*(.rodata) *(.rodata.*)					\
		RO_AFTER_INIT_DATA		\
		KEEP(*(__vermagic))		\
		. = ALIGN(8);						\
		__start___tracepoints_ptrs = .;				\
		KEEP(*(__tracepoints_ptrs))  \
		__stop___tracepoints_ptrs = .;				\
		*(__tracepoints_strings)	\
	}								\
									\
	.rodata1          : AT(ADDR(.rodata1) - LOAD_OFFSET) {		\
		*(.rodata1)						\
	}								\
									\
								\
	UH_RO_SECTION						\
									\
							\
	.pci_fixup        : AT(ADDR(.pci_fixup) - LOAD_OFFSET) {	\
		__start_pci_fixups_early = .;				\
		KEEP(*(.pci_fixup_early))				\
		__end_pci_fixups_early = .;				\
		__start_pci_fixups_header = .;				\
		KEEP(*(.pci_fixup_header))				\
		__end_pci_fixups_header = .;				\
		__start_pci_fixups_final = .;				\
		KEEP(*(.pci_fixup_final))				\
		__end_pci_fixups_final = .;				\
		__start_pci_fixups_enable = .;				\
		KEEP(*(.pci_fixup_enable))				\
		__end_pci_fixups_enable = .;				\
		__start_pci_fixups_resume = .;				\
		KEEP(*(.pci_fixup_resume))				\
		__end_pci_fixups_resume = .;				\
		__start_pci_fixups_resume_early = .;			\
		KEEP(*(.pci_fixup_resume_early))			\
		__end_pci_fixups_resume_early = .;			\
		__start_pci_fixups_suspend = .;				\
		KEEP(*(.pci_fixup_suspend))				\
		__end_pci_fixups_suspend = .;				\
		__start_pci_fixups_suspend_late = .;			\
		KEEP(*(.pci_fixup_suspend_late))			\
		__end_pci_fixups_suspend_late = .;			\
	}								\
									\
						\
	.builtin_fw        : AT(ADDR(.builtin_fw) - LOAD_OFFSET) {	\
		__start_builtin_fw = .;					\
		KEEP(*(.builtin_fw))					\
		__end_builtin_fw = .;					\
	}								\
									\
	TRACEDATA							\
									\
				\
	__ksymtab         : AT(ADDR(__ksymtab) - LOAD_OFFSET) {		\
		__start___ksymtab = .;					\
		KEEP(*(SORT(___ksymtab+*)))				\
		__stop___ksymtab = .;					\
	}								\
									\
				\
	__ksymtab_gpl     : AT(ADDR(__ksymtab_gpl) - LOAD_OFFSET) {	\
		__start___ksymtab_gpl = .;				\
		KEEP(*(SORT(___ksymtab_gpl+*)))				\
		__stop___ksymtab_gpl = .;				\
	}								\
									\
			\
	__ksymtab_unused  : AT(ADDR(__ksymtab_unused) - LOAD_OFFSET) {	\
		__start___ksymtab_unused = .;				\
		KEEP(*(SORT(___ksymtab_unused+*)))			\
		__stop___ksymtab_unused = .;				\
	}								\
									\
			\
	__ksymtab_unused_gpl : AT(ADDR(__ksymtab_unused_gpl) - LOAD_OFFSET) { \
		__start___ksymtab_unused_gpl = .;			\
		KEEP(*(SORT(___ksymtab_unused_gpl+*)))			\
		__stop___ksymtab_unused_gpl = .;			\
	}								\
									\
			\
	__ksymtab_gpl_future : AT(ADDR(__ksymtab_gpl_future) - LOAD_OFFSET) { \
		__start___ksymtab_gpl_future = .;			\
		KEEP(*(SORT(___ksymtab_gpl_future+*)))			\
		__stop___ksymtab_gpl_future = .;			\
	}								\
									\
				\
	__kcrctab         : AT(ADDR(__kcrctab) - LOAD_OFFSET) {		\
		__start___kcrctab = .;					\
		KEEP(*(SORT(___kcrctab+*)))				\
		__stop___kcrctab = .;					\
	}								\
									\
				\
	__kcrctab_gpl     : AT(ADDR(__kcrctab_gpl) - LOAD_OFFSET) {	\
		__start___kcrctab_gpl = .;				\
		KEEP(*(SORT(___kcrctab_gpl+*)))				\
		__stop___kcrctab_gpl = .;				\
	}								\
									\
			\
	__kcrctab_unused  : AT(ADDR(__kcrctab_unused) - LOAD_OFFSET) {	\
		__start___kcrctab_unused = .;				\
		KEEP(*(SORT(___kcrctab_unused+*)))			\
		__stop___kcrctab_unused = .;				\
	}								\
									\
			\
	__kcrctab_unused_gpl : AT(ADDR(__kcrctab_unused_gpl) - LOAD_OFFSET) { \
		__start___kcrctab_unused_gpl = .;			\
		KEEP(*(SORT(___kcrctab_unused_gpl+*)))			\
		__stop___kcrctab_unused_gpl = .;			\
	}								\
									\
			\
	__kcrctab_gpl_future : AT(ADDR(__kcrctab_gpl_future) - LOAD_OFFSET) { \
		__start___kcrctab_gpl_future = .;			\
		KEEP(*(SORT(___kcrctab_gpl_future+*)))			\
		__stop___kcrctab_gpl_future = .;			\
	}								\
									\
					\
        __ksymtab_strings : AT(ADDR(__ksymtab_strings) - LOAD_OFFSET) {	\
		*(__ksymtab_strings)					\
	}								\
									\
							\
	__init_rodata : AT(ADDR(__init_rodata) - LOAD_OFFSET) {		\
		*(.ref.rodata)						\
		MEM_KEEP(init.rodata)					\
		MEM_KEEP(exit.rodata)					\
	}								\
									\
					\
	__param : AT(ADDR(__param) - LOAD_OFFSET) {			\
		__start___param = .;					\
		KEEP(*(__param))					\
		__stop___param = .;					\
	}								\
									\
						\
	__modver : AT(ADDR(__modver) - LOAD_OFFSET) {			\
		__start___modver = .;					\
		KEEP(*(__modver))					\
		__stop___modver = .;					\
		. = ALIGN((align));					\
		__end_rodata = .;					\
	}								\
	. = ALIGN((align));


#define RODATA          RO_DATA_SECTION(4096)
#define RO_DATA(align)  RO_DATA_SECTION(align)

#define SECURITY_INIT							\
	.security_initcall.init : AT(ADDR(.security_initcall.init) - LOAD_OFFSET) { \
		__security_initcall_start = .;				\
		KEEP(*(.security_initcall.init))			\
		__security_initcall_end = .;				\
	}


#define TEXT_TEXT							\
		ALIGN_FUNCTION();					\
		*(.text.hot TEXT_MAIN .text.fixup .text.unlikely)	\
		*(TEXT_CFI_MAIN) 					\
		*(.text..refcount)					\
		*(.text..ftrace)					\
		*(.ref.text)						\
	MEM_KEEP(init.text*)						\
	MEM_KEEP(exit.text*)						\



#define SCHED_TEXT							\
		ALIGN_FUNCTION();					\
		__sched_text_start = .;					\
		*(.sched.text)						\
		__sched_text_end = .;


#define LOCK_TEXT							\
		ALIGN_FUNCTION();					\
		__lock_text_start = .;					\
		*(.spinlock.text)					\
		__lock_text_end = .;

#define CPUIDLE_TEXT							\
		ALIGN_FUNCTION();					\
		__cpuidle_text_start = .;				\
		*(.cpuidle.text)					\
		__cpuidle_text_end = .;

#define KPROBES_TEXT							\
		ALIGN_FUNCTION();					\
		__kprobes_text_start = .;				\
		*(.kprobes.text)					\
		__kprobes_text_end = .;

#define ENTRY_TEXT							\
		ALIGN_FUNCTION();					\
		__entry_text_start = .;					\
		*(.entry.text)						\
		__entry_text_end = .;

#define IRQENTRY_TEXT							\
		ALIGN_FUNCTION();					\
		__irqentry_text_start = .;				\
		*(.irqentry.text)					\
		__irqentry_text_end = .;

#define SOFTIRQENTRY_TEXT						\
		ALIGN_FUNCTION();					\
		__softirqentry_text_start = .;				\
		*(.softirqentry.text)					\
		__softirqentry_text_end = .;


#define HEAD_TEXT  KEEP(*(.head.text))

#define HEAD_TEXT_SECTION							\
	.head.text : AT(ADDR(.head.text) - LOAD_OFFSET) {		\
		HEAD_TEXT						\
	}


#define EXCEPTION_TABLE(align)						\
	. = ALIGN(align);						\
	__ex_table : AT(ADDR(__ex_table) - LOAD_OFFSET) {		\
		__start___ex_table = .;					\
		KEEP(*(__ex_table))					\
		__stop___ex_table = .;					\
	}


#define INIT_TASK_DATA_SECTION(align)					\
	. = ALIGN(align);						\
	.data..init_task :  AT(ADDR(.data..init_task) - LOAD_OFFSET) {	\
		INIT_TASK_DATA(align)					\
	}

#ifdef CONFIG_CONSTRUCTORS
#define KERNEL_CTORS()	. = ALIGN(8);			   \
			__ctors_start = .;		   \
			KEEP(*(.ctors))			   \
			KEEP(*(SORT(.init_array.*)))	   \
			KEEP(*(.init_array))		   \
			__ctors_end = .;
#else
#define KERNEL_CTORS()
#endif


#define INIT_DATA							\
	KEEP(*(SORT(___kentry+*)))					\
	*(.init.data init.data.*)					\
	MEM_DISCARD(init.data*)						\
	KERNEL_CTORS()							\
	MCOUNT_REC()							\
	*(.init.rodata .init.rodata.*)					\
	FTRACE_EVENTS()							\
	TRACE_SYSCALLS()						\
	KPROBE_BLACKLIST()						\
	ERROR_INJECT_WHITELIST()					\
	MEM_DISCARD(init.rodata)					\
	CLK_OF_TABLES()							\
	RESERVEDMEM_OF_TABLES()						\
	TIMER_OF_TABLES()						\
	CPU_METHOD_OF_TABLES()						\
	CPUIDLE_METHOD_OF_TABLES()					\
	KERNEL_DTB()							\
	IRQCHIP_OF_MATCH_TABLE()					\
	ACPI_PROBE_TABLE(irqchip)					\
	ACPI_PROBE_TABLE(timer)						\
	EARLYCON_TABLE()

#define INIT_TEXT							\
	*(.init.text .init.text.*)					\
	*(.text.startup)						\
	MEM_DISCARD(init.text*)

#define EXIT_DATA							\
	*(.exit.data .exit.data.*)					\
	*(.fini_array .fini_array.*)					\
	*(.dtors .dtors.*)						\
	MEM_DISCARD(exit.data*)						\
	MEM_DISCARD(exit.rodata*)

#define EXIT_TEXT							\
	*(.exit.text)							\
	*(.text.exit)							\
	MEM_DISCARD(exit.text)

#define EXIT_CALL							\
	*(.exitcall.exit)


#define SBSS(sbss_align)						\
	. = ALIGN(sbss_align);						\
	.sbss : AT(ADDR(.sbss) - LOAD_OFFSET) {				\
		*(.dynsbss)						\
		*(SBSS_MAIN)						\
		*(.scommon)						\
	}


#ifndef BSS_FIRST_SECTIONS
#define BSS_FIRST_SECTIONS
#endif

#define BSS(bss_align)							\
	. = ALIGN(bss_align);						\
	.bss : AT(ADDR(.bss) - LOAD_OFFSET) {				\
		BSS_FIRST_SECTIONS					\
		. = ALIGN(PAGE_SIZE);					\
		*(.bss..page_aligned)					\
		. = ALIGN(PAGE_SIZE);					\
		*(.dynbss)						\
		*(BSS_MAIN)						\
		*(COMMON)						\
	}


#define DWARF_DEBUG							\
								\
		.debug          0 : { *(.debug) }			\
		.line           0 : { *(.line) }			\
						\
		.debug_srcinfo  0 : { *(.debug_srcinfo) }		\
		.debug_sfnames  0 : { *(.debug_sfnames) }		\
						\
		.debug_aranges  0 : { *(.debug_aranges) }		\
		.debug_pubnames 0 : { *(.debug_pubnames) }		\
								\
		.debug_info     0 : { *(.debug_info			\
				.gnu.linkonce.wi.*) }			\
		.debug_abbrev   0 : { *(.debug_abbrev) }		\
		.debug_line     0 : { *(.debug_line) }			\
		.debug_frame    0 : { *(.debug_frame) }			\
		.debug_str      0 : { *(.debug_str) }			\
		.debug_loc      0 : { *(.debug_loc) }			\
		.debug_macinfo  0 : { *(.debug_macinfo) }		\
		.debug_pubtypes 0 : { *(.debug_pubtypes) }		\
								\
		.debug_ranges	0 : { *(.debug_ranges) }		\
					\
		.debug_weaknames 0 : { *(.debug_weaknames) }		\
		.debug_funcnames 0 : { *(.debug_funcnames) }		\
		.debug_typenames 0 : { *(.debug_typenames) }		\
		.debug_varnames  0 : { *(.debug_varnames) }		\
						\
		.debug_gnu_pubnames 0 : { *(.debug_gnu_pubnames) }	\
		.debug_gnu_pubtypes 0 : { *(.debug_gnu_pubtypes) }	\
								\
		.debug_types	0 : { *(.debug_types) }			\
								\
		.debug_macro	0 : { *(.debug_macro) }			\
		.debug_addr	0 : { *(.debug_addr) }

		
#define STABS_DEBUG							\
		.stab 0 : { *(.stab) }					\
		.stabstr 0 : { *(.stabstr) }				\
		.stab.excl 0 : { *(.stab.excl) }			\
		.stab.exclstr 0 : { *(.stab.exclstr) }			\
		.stab.index 0 : { *(.stab.index) }			\
		.stab.indexstr 0 : { *(.stab.indexstr) }		\
		.comment 0 : { *(.comment) }

#ifdef CONFIG_GENERIC_BUG
#define BUG_TABLE							\
	. = ALIGN(8);							\
	__bug_table : AT(ADDR(__bug_table) - LOAD_OFFSET) {		\
		__start___bug_table = .;				\
		KEEP(*(__bug_table))					\
		__stop___bug_table = .;					\
	}
#else
#define BUG_TABLE
#endif

#ifdef CONFIG_UNWINDER_ORC
#define ORC_UNWIND_TABLE						\
	. = ALIGN(4);							\
	.orc_unwind_ip : AT(ADDR(.orc_unwind_ip) - LOAD_OFFSET) {	\
		__start_orc_unwind_ip = .;				\
		KEEP(*(.orc_unwind_ip))					\
		__stop_orc_unwind_ip = .;				\
	}								\
	. = ALIGN(2);							\
	.orc_unwind : AT(ADDR(.orc_unwind) - LOAD_OFFSET) {		\
		__start_orc_unwind = .;					\
		KEEP(*(.orc_unwind))					\
		__stop_orc_unwind = .;					\
	}								\
	. = ALIGN(4);							\
	.orc_lookup : AT(ADDR(.orc_lookup) - LOAD_OFFSET) {		\
		orc_lookup = .;						\
		. += (((SIZEOF(.text) + LOOKUP_BLOCK_SIZE - 1) /	\
			LOOKUP_BLOCK_SIZE) + 1) * 4;			\
		orc_lookup_end = .;					\
	}
#else
#define ORC_UNWIND_TABLE
#endif

#ifdef CONFIG_PM_TRACE
#define TRACEDATA							\
	. = ALIGN(4);							\
	.tracedata : AT(ADDR(.tracedata) - LOAD_OFFSET) {		\
		__tracedata_start = .;					\
		KEEP(*(.tracedata))					\
		__tracedata_end = .;					\
	}
#else
#define TRACEDATA
#endif

#define NOTES								\
	.notes : AT(ADDR(.notes) - LOAD_OFFSET) {			\
		__start_notes = .;					\
		KEEP(*(.note.*))					\
		__stop_notes = .;					\
	}

#define INIT_SETUP(initsetup_align)					\
		. = ALIGN(initsetup_align);				\
		__setup_start = .;					\
		KEEP(*(.init.setup))					\
		__setup_end = .;

#define INIT_CALLS_LEVEL(level)						\
		__initcall##level##_start = .;				\
		KEEP(*(.initcall##level##.init))			\
		KEEP(*(.initcall##level##s.init))			\

#define INIT_CALLS							\
		__initcall_start = .;					\
		KEEP(*(.initcallearly.init))				\
		INIT_CALLS_LEVEL(0)					\
		INIT_CALLS_LEVEL(1)					\
		INIT_CALLS_LEVEL(2)					\
		INIT_CALLS_LEVEL(3)					\
		INIT_CALLS_LEVEL(4)					\
		INIT_CALLS_LEVEL(5)					\
		INIT_CALLS_LEVEL(rootfs)				\
		INIT_CALLS_LEVEL(6)					\
		INIT_CALLS_LEVEL(7)					\
		__initcall_end = .;

#define CON_INITCALL							\
		__con_initcall_start = .;				\
		KEEP(*(.con_initcall.init))				\
		__con_initcall_end = .;

#define SECURITY_INITCALL						\
		__security_initcall_start = .;				\
		KEEP(*(.security_initcall.init))			\
		__security_initcall_end = .;

#ifdef CONFIG_BLK_DEV_INITRD
#define INIT_RAM_FS							\
	. = ALIGN(4);							\
	__initramfs_start = .;						\
	KEEP(*(.init.ramfs))						\
	. = ALIGN(8);							\
	KEEP(*(.init.ramfs.info))
#else
#define INIT_RAM_FS
#endif


#ifdef CONFIG_AMD_MEM_ENCRYPT
#define PERCPU_DECRYPTED_SECTION					\
	. = ALIGN(PAGE_SIZE);						\
	*(.data..percpu..decrypted)					\
	. = ALIGN(PAGE_SIZE);
#else
#define PERCPU_DECRYPTED_SECTION
#endif



#define DISCARDS							\
	/DISCARD/ : {							\
	EXIT_TEXT							\
	EXIT_DATA							\
	EXIT_CALL							\
	*(.discard)							\
	*(.discard.*)							\
	}


#define PERCPU_INPUT(cacheline)						\
	__per_cpu_start = .;						\
	*(.data..percpu..first)						\
	. = ALIGN(PAGE_SIZE);						\
	*(.data..percpu..page_aligned)					\
	. = ALIGN(cacheline);						\
	*(.data..percpu..read_mostly)					\
	. = ALIGN(cacheline);						\
	*(.data..percpu)						\
	*(.data..percpu..shared_aligned)				\
	PERCPU_DECRYPTED_SECTION					\
	__per_cpu_end = .;


#define PERCPU_VADDR(cacheline, vaddr, phdr)				\
	__per_cpu_load = .;						\
	.data..percpu vaddr : AT(__per_cpu_load - LOAD_OFFSET) {	\
		PERCPU_INPUT(cacheline)					\
	} phdr								\
	. = __per_cpu_load + SIZEOF(.data..percpu);


#define PERCPU_SECTION(cacheline)					\
	. = ALIGN(PAGE_SIZE);						\
	.data..percpu	: AT(ADDR(.data..percpu) - LOAD_OFFSET) {	\
		__per_cpu_load = .;					\
		PERCPU_INPUT(cacheline)					\
	}






#define RW_DATA_SECTION(cacheline, pagealigned, inittask)		\
	. = ALIGN(PAGE_SIZE);						\
	.data : AT(ADDR(.data) - LOAD_OFFSET) {				\
		INIT_TASK_DATA(inittask)				\
		NOSAVE_DATA						\
		PAGE_ALIGNED_DATA(pagealigned)				\
		CACHELINE_ALIGNED_DATA(cacheline)			\
		READ_MOSTLY_DATA(cacheline)				\
		DATA_DATA						\
		CONSTRUCTORS						\
	}								\
	BUG_TABLE							\

#define INIT_TEXT_SECTION(inittext_align)				\
	. = ALIGN(inittext_align);					\
	.init.text : AT(ADDR(.init.text) - LOAD_OFFSET) {		\
		_sinittext = .;						\
		INIT_TEXT						\
		_einittext = .;						\
	}

#define INIT_DATA_SECTION(initsetup_align)				\
	.init.data : AT(ADDR(.init.data) - LOAD_OFFSET) {		\
		INIT_DATA						\
		INIT_SETUP(initsetup_align)				\
		INIT_CALLS						\
		CON_INITCALL						\
		SECURITY_INITCALL					\
		INIT_RAM_FS						\
	}

#define BSS_SECTION(sbss_align, bss_align, stop_align)			\
	. = ALIGN(sbss_align);						\
	__bss_start = .;						\
	SBSS(sbss_align)						\
	BSS(bss_align)							\
	. = ALIGN(stop_align);						\
	__bss_stop = .;
