/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

char *my_strdup(char const *str);
char *my_strdup(char const *src);
char **my_str_to_word_array(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strncat(char *dest, char const *src, int nb);

void my_putchar(char c);
void my_show_word_array(char *const *tab);

#endif
