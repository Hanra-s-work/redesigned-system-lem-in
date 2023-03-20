/*
** EPITECH PROJECT, 2022
** BSQ (Workspace)
** File description:
** hl_str_to_int_array.c
*/

#include <stdlib.h>
#include "my.h"
#include "src.h"
#include "src/hl.h"
#include "li_constants.h"

int whois(char chr)
{
    if ((int)chr == empty) {
        return 1;
    }
    if ((int)chr == wall) {
        return 0;
    }
    if ((int)chr == new_line || (int)chr == end_of_line) {
        return (-1);
    }
    return (int)chr;
}

static int get_tab_height(char *str, char seperator)
{
    int i = 0;
    int height = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == seperator) {
            height += 1;
        }
    }
    height += 1;
    return height;
}

static int get_line_width(char *str, int istart, char seperator)
{
    int j = istart;
    int counter = 0;

    for (; str[j] != '\0' && str[j] != seperator; j++, counter++);
    return counter;
}

static int **manage_stuff(int *height, int *width, char *str, char sep)
{
    int **array;

    *height = get_tab_height(str, sep);
    array = malloc(sizeof(int *) * (*height + 1));
    array = (int **)hl_prep_table((void **)array, NULL, *height);
    array[0] = malloc(sizeof(int) * (*width + 1));
    array[0] = (int *)hl_memset((void *)array[0], whois('\0'), *width);
    return array;
}

int **hl_str_to_int_array(char *str, char sep, int *width, int *height)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int lw = 0;
    int **array;

    *width = get_line_width(str, i, sep);
    array = manage_stuff(height, width, str, sep);
    for (; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            array[y++][x] = whois('\0');
            lw = get_line_width(str, i + 1, sep);
            array[y] = malloc(sizeof(int) * (lw + 1));
            x = 0;
        } else
            array[y][x++] = whois(str[i]);
    }
    hl_free(array[y]);
    array[y] = NULL;
    return array;
}
