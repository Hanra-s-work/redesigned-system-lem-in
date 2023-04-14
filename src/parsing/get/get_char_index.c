/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** get_char_index.c
*/

int get_char_index(char const *str, char const sep)
{
    int i = 0;

    for (; str[i] != '\0' && str[i] != sep; i++);
    return i;
}
