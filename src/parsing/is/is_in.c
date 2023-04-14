/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** is_in.c
*/

#include <stdbool.h>

bool is_in(char const *str, char sep)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            return true;
        }
    }
    return false;
}
