/*
** EPITECH PROJECT, 2021
** Task02 - my_putstr.c
** File description:
** abc
*/

#include <unistd.h>
#include <stddef.h>
#include "batch_colouriser.h"

void bc_putstr(char const *str)
{
    if (str != NULL)
        write(1, str, bc_strlen(str));
}
