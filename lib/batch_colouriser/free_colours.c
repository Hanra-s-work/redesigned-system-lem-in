/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** free_colours.c
*/

#include <stdlib.h>
#include <stdbool.h>

#include "batch_colouriser.h"

int free_colours(batch_colours_t *colours)
{
    int i = 0;
    if (colours == NULL) {
        return bc_colours_not_initialised;
    }
    for (; colours[i].at_end != true; i++) {
        if (colours[i].batch_code != NULL) {
            free(colours[i].batch_code);
        }
        if (colours[i].colour_code != NULL) {
            free(colours[i].colour_code);
        }
    }
    free(colours);
    return bc_success;
}
