/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_dup_map.c
*/

#include <stdlib.h>
#include "my.h"

static int get_height(char **map)
{
    int y = 0;
    for (; map[y] != NULL; y++);
    return y;
}

char **hl_dup_map(char **map)
{
    int y = 0;
    int height = get_height(map);
    char **dest = malloc(sizeof(char *) * (height + 1));

    for (; y < height; y++) {
        dest[y] = my_strdup(map[y]);
    }
    dest[y] = NULL;
    return dest;
}
