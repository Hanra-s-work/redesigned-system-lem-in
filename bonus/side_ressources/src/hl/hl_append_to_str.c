/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier (Workspace)
** File description:
** hl_append_to_str.c
*/

#include <stdlib.h>

#include "my.h"
#include "src/hl.h"

char *hl_append_to_str(char *dest, char *str, char sep)
{
    int size = my_strlen(dest) + my_strlen(str) + 1;
    char *res = malloc(sizeof(char) * (size + 1));
    char tmp[2];

    if (res == NULL || dest == NULL || str == NULL) {
        return NULL;
    }

    res = (char *)hl_memset((void *)res, '\0', size);
    tmp[0] = sep;
    tmp[1] = '\0';
    my_strcpy(res, dest);
    my_strcat(res, tmp);
    my_strcat(res, str);
    return res;
}
