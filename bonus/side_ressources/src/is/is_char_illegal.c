/*
** EPITECH PROJECT, 2022
** sokoban (Workspace)
** File description:
** is_char_illegal.c
*/

#include <stdbool.h>

int is_char_illegal(char chr, char *authed_str)
{
    int i = 0;
    int has_been_legal = false;
    for (; authed_str[i] != '\0'; i++) {
        if (chr == authed_str[i]) {
            has_been_legal = true;
        }
    }
    if (has_been_legal == true) {
        return false;
    } else {
        return true;
    }
}
