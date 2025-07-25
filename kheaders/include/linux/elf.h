/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_ELF_H
#define _LINUX_ELF_H

#include <asm/elf.h>
#include <uapi/linux/elf.h>

#ifndef elf_read_implies_exec
  
# define elf_read_implies_exec(ex, have_pt_gnu_stack)	0
#endif
#ifndef SET_PERSONALITY
#define SET_PERSONALITY(ex) \
	set_personality(PER_LINUX | (current->personality & (~PER_MASK)))
#endif

#ifndef SET_PERSONALITY2
#define SET_PERSONALITY2(ex, state) \
	SET_PERSONALITY(ex)
#endif

#if ELF_CLASS == ELFCLASS32

extern Elf32_Dyn _DYNAMIC [];
#define elfhdr		elf32_hdr
#define elf_phdr	elf32_phdr
#define elf_shdr	elf32_shdr
#define elf_note	elf32_note
#define elf_addr_t	Elf32_Off
#define Elf_Half	Elf32_Half
#define Elf_Word	Elf32_Word

#else

extern Elf64_Dyn _DYNAMIC [];
#define elfhdr		elf64_hdr
#define elf_phdr	elf64_phdr
#define elf_shdr	elf64_shdr
#define elf_note	elf64_note
#define elf_addr_t	Elf64_Off
#define Elf_Half	Elf64_Half
#define Elf_Word	Elf64_Word

#endif



static inline struct elf_shdr *elf_sheader(struct elfhdr *hdr)
{
	return (struct elf_shdr *)((size_t)hdr + (size_t)hdr->e_shoff);
}


static inline struct elf_shdr *elf_section(struct elfhdr *hdr, int idx)
{
	return &elf_sheader(hdr)[idx];
}


static inline struct elf_phdr *elf_pheader(struct elfhdr *hdr)
{
	return (struct elf_phdr *)((size_t)hdr + (size_t)hdr->e_phoff);
}


static inline struct elf_phdr *elf_program(struct elfhdr *hdr, int idx)
{
	return &elf_pheader(hdr)[idx];
}


static inline char *elf_str_table(struct elfhdr *hdr)
{
	if (hdr->e_shstrndx == SHN_UNDEF)
		return NULL;
	return (char *)hdr + elf_section(hdr, hdr->e_shstrndx)->sh_offset;
}


struct file;
struct coredump_params;

#ifndef ARCH_HAVE_EXTRA_ELF_NOTES
static inline int elf_coredump_extra_notes_size(void) { return 0; }
static inline int elf_coredump_extra_notes_write(struct coredump_params *cprm) { return 0; }
#else
extern int elf_coredump_extra_notes_size(void);
extern int elf_coredump_extra_notes_write(struct coredump_params *cprm);
#endif
#endif 
