/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** li_free.c
*/

#include <stdlib.h>

void li_free(void *data)
{
    if (data != NULL) {
        free(data);
    }
}
