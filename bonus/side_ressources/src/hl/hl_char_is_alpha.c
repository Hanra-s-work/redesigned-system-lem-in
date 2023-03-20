/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** hl_char_is_alpha.c
*/

#include <stdbool.h>

int hl_char_is_alpha(char const chr)
{
    if ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z')) {
        return true;
    }
    return false;
}
