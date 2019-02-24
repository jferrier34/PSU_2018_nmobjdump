/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** Obj
*/

#include "../include/my.h"

void do_all(char *path)
{
    void *my_map = try_open_mmap(path);
    Elf32_Ehdr *elf = (Elf32_Ehdr*)my_map;
    choose_by_sort(path, my_map, elf);
}

void *try_open_mmap(char *path)
{
    int is_ok = 0;
    struct stat value;
    void *map_me;

    is_ok = open(path, O_RDONLY, 0);
    if (is_ok == -1)
        exit (84);
    fstat(is_ok, &value);
    map_me = mmap(NULL, value.st_size, PROT_READ, MAP_PRIVATE, is_ok, 0);
    if (map_me == MAP_FAILED)
        exit(84);
    return (map_me);
}

void choose_by_sort(char *path, void *my_map, Elf32_Ehdr *elf)
{
    if (elf->e_ident[EI_CLASS] == ELFCLASS32) {
        do_for_32(my_map, path);
    }
    if (elf->e_ident[EI_CLASS] == ELFCLASS64) {
        do_for_64(my_map, path);
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        exit(84);
    do_all(av[2]);
}
