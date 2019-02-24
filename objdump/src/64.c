/*
** EPITECH PROJECT, 2019
** 64
** File description:
** 64
*/
#include "../../include/my.h"

char *choose_flags(Elf64_Ehdr *elf)
{
    char *value;
        if (elf->e_type == ET_REL)
		value = "flags 0x000000011:\nHAS_RELOC, HAS_SYMS";
	if (elf->e_type == ET_EXEC)
		value = "flags 0x000000112:\nEXEC_P, HAS_SYMS, D_PAGED";
	if (elf->e_type == ET_DYN)
		value = "flags 0x000000150:\nHAS_SYMS, DYNAMIC, D_PAGED";
	if (elf->e_type == ET_CORE)
		value = "Core\n";
    return (value);
}

char *choose_flags_two(Elf32_Ehdr *elf)
{
    char *value;
        if (elf->e_type == ET_REL)
		value = "flags 0x000000011:\nHAS_RELOC, HAS_SYMS";
	if (elf->e_type == ET_EXEC)
		value = "flags 0x000000112:\nEXEC_P, HAS_SYMS, D_PAGED";
	if (elf->e_type == ET_DYN)
		value = "flags 0x000000150:\nHAS_SYMS, DYNAMIC, D_PAGED";
	if (elf->e_type == ET_CORE)
		value = "Core\n";
    return (value);
}

void do_for_64(void *tmp, char *path)
{
    Elf64_Ehdr *elf = (Elf64_Ehdr*)tmp;
    char *flags = choose_flags(elf);
    printf("\n%s:     file format elf64-x86-64\n", path);
    printf("architecture: %s ", "i386:x86-64,");
    printf("%s\n", flags);
    printf("start address 0x0000000000%lx\n\n", elf->e_entry);
}

void do_for_32(void *tmp, char *path)
{
    Elf32_Ehdr *elf = (Elf32_Ehdr*)tmp;
    char *flags = choose_flags_two(elf);
    printf("\n%s:     file format elf32-x86-32\n", path);
    printf("architecture: %s ", "i386:x86-32,");
    printf("%s\n", flags);
    printf("start address 0x0000000000%lx\n\n", elf->e_entry);
}
