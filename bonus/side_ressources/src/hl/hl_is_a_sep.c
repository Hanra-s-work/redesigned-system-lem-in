/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** hl_is_a_sep.c
*/

#include <stdbool.h>

int hl_is_a_sep(char chr, char *sep)
{
    int i = 0;
    for (; sep[i] != '\0'; i++) {
        if (sep[i] == chr) {
            return true;
        }
    }
    return false;
}
