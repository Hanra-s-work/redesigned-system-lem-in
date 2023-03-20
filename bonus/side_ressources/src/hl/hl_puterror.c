/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_puterror.c
*/

#include <unistd.h>

#include "my.h"

void hl_puterror(char const *str)
{
    write(2, str, my_strlen(str));
}
