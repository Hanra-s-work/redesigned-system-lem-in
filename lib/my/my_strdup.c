/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** my_strdup.c
*/

#include <stdlib.h>

#include "my.h"

char *my_strdup(char const *str)
{
    int size = my_strlen(str);
    char *dest = malloc(sizeof(char) * (size + 1));
    dest = my_strcpy(dest, str);
    dest[size] = '\0';
    return dest;
}
