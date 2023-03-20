/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-navy-henry.letellier
** File description:
** hl_strdup.c
*/

#include <stdlib.h>
#include "my.h"

char *hl_strdup(char const *str)
{
    char *dest = NULL;
    int i = 0;
    if (str == NULL) {
        return NULL;
    }
    dest = malloc(sizeof(char) * my_strlen(str) + 1);
    if (dest == NULL) {
        return NULL;
    }
    for (; str[i] != '\0'; i++) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
    return dest;
}
