/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_free.c
*/

#include <stdlib.h>

void hl_free(void *data)
{
    if (data != NULL) {
        free(data);
    }
}
