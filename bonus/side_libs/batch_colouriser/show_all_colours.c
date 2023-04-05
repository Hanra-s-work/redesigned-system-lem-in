/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** show_all_colours.c
*/

#include <stddef.h>
#include <unistd.h>
#include "batch_colouriser.h"

void show_all_colours(void)
{
    batch_colours_t *bc = init_colours();
    int i = 0;

    if (bc != NULL) {
        for (; bc[i].at_end != true; i++) {
            bc_putstr(bc[i].colour_code);
            write(1, "'", 1);
            bc_putstr(bc[i].batch_code);
            set_colour(bc, "rr", "'\n");
        }
    }
    bc_putstr("(c) Writtent by Henry Letellier\n");
    free_colours(bc);
}
