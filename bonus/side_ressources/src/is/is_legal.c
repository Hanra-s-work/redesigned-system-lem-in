/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_legal.c
*/

#include <stdbool.h>

int is_legal(char c)
{
    if (c == '\n' || c == '\0') {
        return false;
    }
    return true;
}
