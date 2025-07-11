
#ifndef __ASM_HWCAP_H
#define __ASM_HWCAP_H

#include <uapi/asm/hwcap.h>

#define COMPAT_HWCAP_HALF	(1 << 1)
#define COMPAT_HWCAP_THUMB	(1 << 2)
#define COMPAT_HWCAP_FAST_MULT	(1 << 4)
#define COMPAT_HWCAP_VFP	(1 << 6)
#define COMPAT_HWCAP_EDSP	(1 << 7)
#define COMPAT_HWCAP_NEON	(1 << 12)
#define COMPAT_HWCAP_VFPv3	(1 << 13)
#define COMPAT_HWCAP_TLS	(1 << 15)
#define COMPAT_HWCAP_VFPv4	(1 << 16)
#define COMPAT_HWCAP_IDIVA	(1 << 17)
#define COMPAT_HWCAP_IDIVT	(1 << 18)
#define COMPAT_HWCAP_IDIV	(COMPAT_HWCAP_IDIVA|COMPAT_HWCAP_IDIVT)
#define COMPAT_HWCAP_LPAE	(1 << 20)
#define COMPAT_HWCAP_EVTSTRM	(1 << 21)

#define COMPAT_HWCAP2_AES	(1 << 0)
#define COMPAT_HWCAP2_PMULL	(1 << 1)
#define COMPAT_HWCAP2_SHA1	(1 << 2)
#define COMPAT_HWCAP2_SHA2	(1 << 3)
#define COMPAT_HWCAP2_CRC32	(1 << 4)

#ifndef __ASSEMBLY__

#define ELF_HWCAP		(elf_hwcap)

#ifdef CONFIG_COMPAT
#define COMPAT_ELF_HWCAP	(compat_elf_hwcap)
#define COMPAT_ELF_HWCAP2	(compat_elf_hwcap2)
extern unsigned int compat_elf_hwcap, compat_elf_hwcap2;
#endif

enum {
	CAP_HWCAP = 1,
#ifdef CONFIG_COMPAT
	CAP_COMPAT_HWCAP,
	CAP_COMPAT_HWCAP2,
#endif
};

extern unsigned long elf_hwcap;
#endif
#endif
