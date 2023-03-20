/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-navy-henry.letellier
** File description:
** hl_show_int_table.c
*/

#include <stddef.h>

#include "my.h"
#include "hl_constants.h"

void hl_show_int_table(int **tab)
{
    int y = 0;
    int x = 0;

    for (; tab[y] != NULL; y++) {
        for (x = 0; tab[y][x] != end_of_int_line; x++) {
            my_put_nbr(tab[y][x]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}
