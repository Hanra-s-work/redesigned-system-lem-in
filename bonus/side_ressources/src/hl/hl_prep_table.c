/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier
** File description:
** hl_prep_table.c
*/

#include <stddef.h>

void **hl_prep_table(void **table, void *value, int height)
{
    int y = 0;
    if (table != NULL) {
        for (; y < height; y++) {
            table[y] = value;
        }
    }
    return table;
}
