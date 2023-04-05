/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** jitter jitter
*/

int bc_strlen(char const *chr)
{
    int i = 0;
    int counter = 0;
    for (; chr[i] != '\0'; i++) {
        counter++;
    }
    return counter;
}
