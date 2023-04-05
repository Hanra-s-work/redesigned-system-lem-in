/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** jitter jitter
*/

#include "batch_colouriser.h"

char *bc_strcat(char *dest, char const *src)
{
    int len = bc_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
