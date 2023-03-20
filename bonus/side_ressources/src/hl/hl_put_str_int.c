/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-navy-henry.letellier
** File description:
** hl_put_str_int.c
*/

#include "my.h"

void hl_put_str_int(char *str, int nb, char *end)
{
    my_putstr(str);
    my_put_nbr(nb);
    my_putstr(end);
}
