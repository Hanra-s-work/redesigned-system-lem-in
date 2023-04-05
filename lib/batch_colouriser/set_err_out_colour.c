/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** set_err_out_colour.c
*/

#include <stddef.h>
#include <stdbool.h>

#include "batch_colouriser.h"

int set_err_out_colour(bcol_t *colours, char *batch_colour_code, char *cont)
{
    int i = 0;
    if (colours == NULL) {
        bc_puterror(cont);
        return bc_colours_not_initialised;
    }
    if (batch_colour_code == NULL || bc_strlen(batch_colour_code) < 2) {
        bc_puterror(cont);
        return bc_colour_code_is_empty;
    }
    for (; colours[i].at_end != true; i++) {
        if (bc_strcmp(colours[i].batch_code, batch_colour_code) == 0) {
            bc_puterror(colours[i].colour_code);
            bc_puterror(cont);
            return bc_err;
        }
    }
    bc_putstr(cont);
    return bc_not_found;
}
