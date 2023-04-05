/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** cpool
*/

#include <unistd.h>

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 84;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 84;
        i++;
    }
    return 0;
}
