/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_a_box.c
*/

#include <stdbool.h>
#include "constants.h"

int is_a_box(char chr)
{
    if (chr == box_sp) {
        return true;
    }
    return false;
}
