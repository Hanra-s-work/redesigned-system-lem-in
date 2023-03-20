/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_a_wall.c
*/

#include <stdbool.h>
#include "constants.h"

int is_a_wall(char chr)
{
    if (chr == wall_sp) {
        return true;
    }
    return false;
}
