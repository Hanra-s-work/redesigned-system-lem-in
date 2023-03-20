/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** is_empty.c
*/

#include <stdbool.h>
#include "my.h"

bool is_empty(char *usr_input)
{
    if (my_strlen(usr_input) == 0) {
        return true;
    }
    return false;
}
