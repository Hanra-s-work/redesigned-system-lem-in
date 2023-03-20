/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** is_unsetenv.c
*/

#include <stdbool.h>

#include "my.h"

bool is_unsetenv(char **usr_input)
{
    if (my_strcmp(usr_input[0], "unsetenv") == 0) {
        return true;
    }
    if (my_strcmp(usr_input[0], "unsetenv\n") == 0) {
        return true;
    }
    return false;
}
