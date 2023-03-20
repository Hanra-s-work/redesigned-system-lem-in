/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_player_dead.c
*/

#include <stddef.h>
#include <stdbool.h>
#include "my.h"
#include "src/is.h"
#include "hl_structs.h"

static bool is_dead(char **map, int x, int y)
{
    if (map[y - 1][x] == '#' || map[y + 1][x] == '#') {
        if (map[y][x - 1] == '#' || map[y][x + 1] == '#') {
            return true;
        }
    }
    return false;
}

static bool check_box(maps_t map, int x, int y)
{
    if (is_a_box(map.game_map[y][x]) == true &&
        !is_a_storage_location(map.bkp_map[y][x])) {
        return is_dead(map.game_map, x, y);
    }
    return false;
}

static bool check_line(maps_t map, int y)
{
    int x = 0;
    bool has_been_true = false;
    for (; map.game_map[y][x] != '\0'; x++) {
        has_been_true = check_box(map, x, y);
        if (has_been_true == true) {
            return has_been_true;
        }
    }
    return has_been_true;
}

int is_player_dead(maps_t map)
{
    int y = 0;
    bool has_been_true = false;

    for (; map.game_map[y] != NULL; y++) {
        has_been_true = check_line(map, y);
        if (has_been_true == true) {
            return true;
        }
    }
    return false;
}
