/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** init_colours.c
*/

#include <stdlib.h>
#include <stdbool.h>

#include "batch_colouriser.h"

static char *gen_batch_code(char const background, char const foreground)
{
    int length = 2;
    char *dest = malloc(sizeof(char) * (length + 1));
    if (dest == NULL) {
        return dest;
    }
    dest[0] = background;
    dest[1] = foreground;
    dest[2] = '\0';
    return dest;
}

static char *gen_bash_code(int const background, int const foreground)
{
    char *bash_list[] = { "30","34","32","36","31","35","33","37","90","94",\
        "92", "96", "91", "95", "93", "97", "0" };
    char *code_beg = "\033[";
    char *tmp = NULL;
    int code_length = (bc_strlen(code_beg) * 2) + (3 * 2) + bc_strlen("m") * 2;
    char *res = malloc(sizeof(char) * (code_length + 1));

    if (res == NULL) {
        return res;
    }
    res = (char *)bc_memset((void *)res, '\0', code_length);
    res = bc_strcat(res, code_beg);
    tmp = bc_itoa(bc_atoi(bash_list[background]) + 10);
    res = bc_strcat(res, tmp);
    res = bc_strcat(res, "m\033[");
    res = bc_strcat(res, bash_list[foreground]);
    res = bc_strcat(res, "m");
    free(tmp);
    return res;
}

static void fill_struct_bc(batch_colours_t *bc, char *batch_i, int i, int *trac)
{
    int j = 0;
    int tracker = *trac;
    for (j = 0; batch_i[j] != '\0'; j++, tracker++) {
        bc[tracker].index = tracker;
        bc[tracker].at_end = false;
        bc[tracker].batch_code = gen_batch_code(batch_i[i], batch_i[j]);
        bc[tracker].colour_code = gen_bash_code(i, j);
        bc[tracker].max_allocated = 0;
        bc[0].nb_elems += 1;
        bc[tracker].nb_elems = bc[0].nb_elems;
    }
    *trac = tracker;
}

batch_colours_t *init_colours(void)
{
    int i = 0;
    int tracker = 0;
    char batch_indexes[] = "0123456789ABCDEFr";
    int index_length = bc_strlen(batch_indexes);
    int list_size = index_length * index_length;
    batch_colours_t *colour = malloc(sizeof(batch_colours_t) * (list_size + 1));

    if (colour == NULL) {
        return colour;
    }
    colour[0].nb_elems = 0;
    for (; batch_indexes[i] != '\0'; i++) {
        fill_struct_bc(colour, batch_indexes, i, &tracker);
    }
    colour[tracker].at_end = true;
    return colour;
}
