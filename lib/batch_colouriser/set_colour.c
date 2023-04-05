/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** set_colour.c
*/

#include <stddef.h>
#include <stdbool.h>

#include "batch_colouriser.h"

int set_colour(batch_colours_t *colours, char *batch_colour_code, char *cont)
{
    int i = 0;
    if (colours == NULL) {
        bc_putstr(cont);
        return bc_colours_not_initialised;
    }
    if (batch_colour_code == NULL || bc_strlen(batch_colour_code) < 2) {
        bc_putstr(cont);
        return bc_colour_code_is_empty;
    }
    for (; colours[i].at_end != true; i++) {
        if (bc_strcmp(colours[i].batch_code, batch_colour_code) == 0) {
            bc_putstr(colours[i].colour_code);
            bc_putstr(cont);
            return bc_success;
        }
    }
    bc_putstr(cont);
    return bc_not_found;
}
