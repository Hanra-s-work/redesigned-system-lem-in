/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_coliding.c
*/

#include <stdbool.h>
#include "src/is.h"
#include "hl_structs.h"

int is_coliding(char **map, player_pos_t p_pos, inputted_keys_t ikt)
{
    player_pos_t offset = get_offset(ikt);
    player_pos_t new_pos = get_new_pos(p_pos, offset, 1);
    player_pos_t new_pos_t2 = get_new_pos(p_pos, offset, 2);
    if (p_pos.y == 1 && ikt.up == true)
        return true;
    if (is_a_wall(map[new_pos.y][new_pos.x]) == true)
        return true;
    if (is_a_box(map[new_pos.y][new_pos.x]) == true) {
        if (p_pos.y == 2 && ikt.up == true) {
            return true;
        }
        if (is_a_box(map[new_pos_t2.y][new_pos_t2.x]) == true) {
            return true;
        }
        if (is_a_wall(map[new_pos_t2.y][new_pos_t2.x]) == true) {
            return true;
        }
        return false;
    }
    return false;
}
