/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_dup_tab.c
*/

#include <stdlib.h>
#include "my.h"

static int get_tab_height(void **tab, void *eot)
{
    int height = 0;
    for (; tab[height] != eot; height++);
    return height;

}

static int data_length(void *data, int eol)
{
    int length = 0;
    int *tmp_data = (int *)data;
    for (; tmp_data[length] != eol; length++);
    return length;
}

static void *data_dup(void *src, int eol, int type_size)
{
    int length = data_length(src, eol);
    int i = 0;
    long long int *dest = malloc(type_size * (length + 1));
    long long int *tmp_src = (long long int *)src;

    for (; i < length; i++) {
        dest[i] = tmp_src[i];
    }
    dest[i] = eol;
    return (void *)dest;
}

void **hl_dup_tab(void **tab, void *eot, int eol, int type_size)
{
    int y = 0;
    int height = get_tab_height(tab, eot);
    void **dest = malloc((type_size * 8) * (height + 1));

    for (; y < height; y++) {
        dest[y] = data_dup(tab[y], eol, type_size);
    }
    dest[y] = eot;
    return dest;
}
