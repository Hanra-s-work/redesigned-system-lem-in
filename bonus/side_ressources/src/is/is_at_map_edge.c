/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_at_map_edge.c
*/

#include <stdbool.h>
#include <ncurses.h>
#include "hl_structs.h"

int is_at_map_edge(maps_t map, player_pos_t p_pos_t1, player_pos_t p_pos_t2)
{
    if (map.map_h <= p_pos_t1.y || map.map_h <= p_pos_t2.y) {
        mvprintw(28, 0, "(iame) in if 1");
        return true;
    }
    if (map.map_w <= p_pos_t1.x || map.map_w <= p_pos_t2.x) {
        mvprintw(28, 0, "(iame) in if 2");
        return true;
    }
    if (p_pos_t1.x < 0 || p_pos_t2.x < 0 || p_pos_t1.y < 0 || p_pos_t2.y < 0) {
        mvprintw(28, 0, "(iame) in if 3");
        return true;
    }
    return false;
}
