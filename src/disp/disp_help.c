/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp_help.c
*/

#include "my.h"
#include "batch_colouriser.h"
#include "li_colour_constants.h"

void disp_help(bcol_t *bc, char const *bin_name)
{
    set_colour(bc, HELP_COL, "USAGE:\n\t");
    my_putstr(bin_name);
    my_putstr(" < <path_to_anthill_to_solve>\n");
    my_putstr("BASICS:");
    my_putstr("\tLem-in is a program that aims to help all the ants get from");
    my_putstr(" one room (##start) to the destination room (##end).\n");
    set_colour(bc, RESET_COL, "");
}
