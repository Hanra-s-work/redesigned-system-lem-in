/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** hl_dup_char.c
*/

#include <stdlib.h>

char *hl_dup_char(char chr)
{
    char *tmp_data = malloc(sizeof(char) + 1);
    tmp_data[0] = chr;
    tmp_data[1] = '\0';
    return tmp_data;
}
