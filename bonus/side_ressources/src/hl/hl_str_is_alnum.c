/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_str_is_alnum.c
*/

#include <stdbool.h>

int hl_str_is_alnum(char *str)
{
    int i = 0;
    char c;
    int is_alpha = true;
    int is_num = true;
    for (; str[i] != '\0'; i++) {
        c = str[i];
        is_alpha = false;
        is_num = false;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            is_alpha = true;
        }
        if (c >= '0' && c <= '9') {
            is_num = true;
        }
        if (is_alpha != true && is_num != true) {
            return false;
        }
    }
    return true;
}
