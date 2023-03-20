/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_a_storage_location.c
*/

#include <stdbool.h>
#include "constants.h"

int is_a_storage_location(char chr)
{
    if (chr == hole_sp) {
        return true;
    }
    return false;
}
