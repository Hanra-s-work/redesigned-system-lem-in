/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_a_death_block.c
*/

#include <stdbool.h>
#include "hl_structs.h"
#include "src/is.h"

int is_a_death_block(char chr)
{
    if (is_a_wall(chr) == true) {
        return true;
    }
    if (is_a_box(chr) == true) {
        return true;
    }
    if (is_a_player(chr) == false) {
        if (is_a_storage_location(chr) == false && is_empty(chr) == false) {
            return true;
        }
    }
    return false;
}
