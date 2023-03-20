/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_tab_to_str.c
*/

#include <stdlib.h>

#include "my.h"
#include "src/hl.h"

char *hl_tab_to_str(char **tab, char *sep)
{
    int y = 0;
    int tot_size = 0;
    char *dest = NULL;

    for (; tab[y] != NULL; y++) {
        tot_size += my_strlen(tab[y]);
        tot_size++;
    }
    dest = malloc(sizeof(char) * (tot_size + 1));
    if (dest == NULL) {
        return dest;
    }
    dest = hl_memset((void *)dest, '\0', tot_size);
    for (y = 0; tab[y] != NULL; y++) {
        dest = my_strcat(dest, tab[y]);
        dest = my_strcat(dest, sep);
    }
    return dest;
}
