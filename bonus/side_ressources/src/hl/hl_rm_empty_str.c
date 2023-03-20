/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_rm_empty_str.c
*/

#include <stdlib.h>
#include "my.h"
#include "src/hl.h"

static int get_real_height(char **tab)
{
    int y = 0;
    int tracker = 0;
    if (tab == NULL) {
        return tracker;
    }
    for (; tab[y] != NULL; y++) {
        if (tab[y][0] != '\0') {
            tracker++;
        }
    }
    return tracker;
}

char **hl_rm_empty_str(char **tab)
{
    int y = 0;
    int track = 0;
    int real_size = get_real_height(tab);
    char **res = malloc(sizeof(char *) * (real_size + 1));
    if (tab == NULL || res == NULL) {
        return NULL;
    }
    res = (char **)hl_prep_table((void **)res, '\0', real_size);
    for (; tab[y] != NULL; y++) {
        if (tab[y][0] != '\0') {
            res[track] = hl_strdup(tab[y]);
            track += 1;
        }
    }
    res[y] = NULL;
    return res;
}
