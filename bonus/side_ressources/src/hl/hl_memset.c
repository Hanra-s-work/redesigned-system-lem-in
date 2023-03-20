/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier
** File description:
** hl_memset.c
*/

void *hl_memset(void *tab, int value, int size)
{
    char *i = (char *)tab;
    for (;size > 0;size--) {
        *i = value;
        i++;
    }
    return tab;
}
