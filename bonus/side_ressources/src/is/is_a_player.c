/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_a_player.c
*/

#include <stdbool.h>
#include "constants.h"

int is_a_player(char chr)
{
    if (chr == player_sp) {
        return true;
    }
    return false;
}
