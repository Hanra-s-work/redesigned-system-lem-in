/*
** EPITECH PROJECT, 2022
** BSQ (Workspace)
** File description:
** hl_str_to_word_array.c
*/

#include <stdlib.h>
#include <stdbool.h>

#include "src/hl.h"

static bool is_a_sep(char chr, char *sep)
{
    for (int i = 0; sep[i] != '\0'; i++) {
        if (chr == sep[i]) {
            return true;
        }
    }
    return false;
}

static int get_tab_height(char *str, char *seperator)
{
    int i = 0;
    int height = 0;
    for (; str[i] != '\0'; i++) {
        if (is_a_sep(str[i], seperator) == true) {
            height += 1;
        }
    }
    return height;
}

static int get_line_width(char *str, int istart, char *seperator)
{
    int j = istart;
    int counter = 0;
    bool found_sep = false;

    if (j > 0 && str[j - 1] == '\0')
        return 0;
    for (; str[j] != '\0'; j++, counter++) {
        if (is_a_sep(str[j], seperator) == true) {
            found_sep = true;
            break;
        }
    }
    if (!found_sep) {
        counter++;
    }
    return counter;
}

static char **manage_stuff(int *height, int *width, char *str, char *sep)
{
    char **array;
    *height = get_tab_height(str, sep);
    array = malloc(sizeof(char *) * (*height + 2));
    array = (char **)hl_prep_table((void **)array, NULL, *height);
    array[0] = malloc(sizeof(char) * (*width + 1));
    array[0] = (char *)hl_memset((void *)array[0], 'a', *width);
    return array;
}

char **hl_str_to_word_array(char *str, char *sep, int *width, int *height)
{
    int i = 0;
    int x = 0;
    int y = 0;
    int lw = 0;
    char **array;

    *width = get_line_width(str, i, sep);
    array = manage_stuff(height, width, str, sep);
    for (; str[i] != '\0'; i++) {
        if (is_a_sep(str[i], sep) == true) {
            array[y++][x] = '\0';
            x = 0;
            lw = get_line_width(str, i + 1, sep);
            array[y] = malloc(sizeof(char) * (lw + 1));
        } else
            array[y][x++] = str[i];
    }
    array[y][x] = '\0';
    array[++y] = NULL;
    return array;
}
