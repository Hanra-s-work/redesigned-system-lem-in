/*
** EPITECH PROJECT, 2023
** count_char
** File description:
** cpe
*/

#include "li_constants.h"

int count_char(char *str, char sep)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep)
            count++;
    }
    return count;
}
