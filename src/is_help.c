/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** is_help.c
*/

#include <stdbool.h>
#include "my.h"
#include "batch_colouriser.h"


bool is_help(char *arg)
{
    if (my_strcmp(arg, "-h") == 0 || my_strcmp(arg, "--help") == 0) {
        return true;
    }
    if (my_strcmp(arg, "--h") == 0 || my_strcmp(arg, "-help") == 0) {
        return true;
    }
    if (my_strcmp(arg, "/?") == 0 || my_strcmp(arg, "/h") == 0) {
        return true;
    }
    if (my_strcmp(arg, "/help") == 0 || my_strcmp(arg, "-?") == 0) {
        return true;
    }
    return false;
}
