/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_quit.c
*/

#include <stdbool.h>
#include "hl_structs.h"

int is_quit(inputted_keys_t ikt)
{
    if (ikt.quit == true) {
        return true;
    }
    return false;
}
