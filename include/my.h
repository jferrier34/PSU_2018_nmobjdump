/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** my.h
*/

#ifndef MY_H_
	#define MY_H_

    # include <stdarg.h>
    # include <stdio.h>
    # include <stdlib.h>
    # include <elf.h>
    # include <unistd.h>
    # include <sys/types.h>
    # include <sys/stat.h>
    # include <fcntl.h>
    # include <string.h>
    # include <sys/mman.h>
    # include <ctype.h>

    void do_all(char *path);
    void *try_open_mmap(char *path);
    void choose_by_sort(char *path, void *my_map, Elf32_Ehdr *elf);
    char *choose_flags_two(Elf32_Ehdr *elf);
    void do_for_64(void *tmp, char *path);
    void print_32(char *str, Elf32_Shdr *shdr, int i);
    void my_print_for_32(void *tmp, char *path, Elf32_Ehdr *elf, char *tmp2);
    void do_for_32(void *tmp, char *path);

#endif /* !MY_H_ */


