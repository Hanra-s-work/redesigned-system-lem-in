/*
** EPITECH PROJECT, 2021
** Task02 - my_putstr.c
** File description:
** abc
*/

#include <unistd.h>
#include <stddef.h>
#include "batch_colouriser.h"

int bc_puterror(char const *str)
{
    if (str != NULL)
        write(2, str, bc_strlen(str));
    return bc_err;
}
