/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_equal.c
*/

#include <stdbool.h>

int is_equal(int nb_boxes, int nb_holes)
{
    if (nb_boxes == nb_holes) {
        return true;
    }
    return false;
}
