/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_copy_line.c
*/

#include <stddef.h>

void *hl_copy_line(void *dest, void *src, size_t n)
{
    size_t i = 0;
    char *dest_ptr = (char *)dest;
    char *src_ptr = (char *)src;
    if (dest == NULL || src == NULL) {
        return NULL;
    }
    for (; i < n; i++) {
        *(dest_ptr + i) = *(src_ptr + i);
    }
    return dest;
}
