/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** is_exit.c
*/

#include <stdbool.h>

#include "my.h"

static int skip_blanks(char *input)
{
    int i = 0;
    for (; (input[i] == '\t' || input[i] == ' ') && input[i] != '\0'; i++);
    return i;
}

bool is_exit(char *usr_input, int size_read)
{
    int i = 0;
    if (size_read == (-1)) {
        my_putchar('\n');
        return true;
    }
    i = skip_blanks(usr_input);
    if (my_strcmp((usr_input + i), "exit\n") == 0) {
        return true;
    }
    return false;
}
