/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_reset.c
*/

#include <stdbool.h>
#include "hl_structs.h"

int is_reset(inputted_keys_t ikt)
{
    if (ikt.reset == true) {
        return true;
    }
    return false;
}
