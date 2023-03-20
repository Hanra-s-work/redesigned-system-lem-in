/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_copy_from.c
*/

char *hl_copy_from(char *src, char *dest, int i)
{
    int j = 0;
    for (; src[i] != '\0'; i++, j++) {
        dest[j] = src[i];
    }
    dest[j] = '\0';
    return dest;
}
