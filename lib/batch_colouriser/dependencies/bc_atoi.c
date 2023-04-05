/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** hl_atoi.c
*/

#include <stdbool.h>
#include "batch_colouriser.h"

static bool bc_char_is_numeric(char chr)
{
    if (chr >= '0' && chr <= '9') {
        return true;
    }
    return false;
}

int bc_atoi(char *nb)
{
    int i = bc_strlen(nb);
    int res = 0;
    int pos = 1;

    for (; i >= 0; i--) {
        if (bc_char_is_numeric(nb[i]) == true) {
            res += (nb[i] - '0') * pos;
            pos *= 10;
        }
    }
    if (nb[0] == '-') {
        res *= (-1);
    }
    return res;
}
