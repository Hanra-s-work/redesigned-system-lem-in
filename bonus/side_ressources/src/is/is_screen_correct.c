/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_screen_correct.c
*/

#include <stdbool.h>

int is_screen_correct(int screen_w, int screen_h, int map_w, int map_h)
{
    if (screen_h >= map_h && screen_w >= map_w) {
        return true;
    }
    return false;
}
