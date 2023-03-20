/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** is_in_str.c
*/

#include <stdbool.h>

static bool is_needle_present(char *needle, char *haystack, int i)
{
    int combo = 0;
    int j = i;
    for (; needle[combo] != '\0' && haystack[j] != '\0'; combo++, j++) {
        if (needle[combo] != haystack[j]) {
            return false;
        }
    }
    return true;
}

bool is_in_str(char *needle, char *haystack)
{
    int i = 0;

    for (;haystack[i] != '\0'; i++) {
        if (is_needle_present(needle, haystack, i) == true) {
            return true;
        }
    }
    return false;
}
