/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_remove_empty.c
*/

#include <aio.h>
#include <stdlib.h>
#include "my.h"
#include "src/hl.h"

static int get_real_height(void **tab, int eol)
{
    int y = 0;
    int real_height = 0;

    for (; tab[y] != NULL; y++) {
        if (((char *)tab[y])[0] != eol) {
            real_height++;
        }
    }
    real_height++;
    return real_height;
}

static size_t get_line_size(void *data, int eol)
{
    size_t i = 0;
    unsigned char *tmp_data = (unsigned char *)data;
    for (; tmp_data[i] != eol; i++);
    return i;
}

//Function is not clean memory speaking
void **hl_remove_empty(void **tab, size_t size, int eol)
{
    int y = 0;
    int tracker = 0;
    int real_height = get_real_height(tab, eol);
    size_t lsize = 0;
    void **res_tab = malloc(size * (real_height + 1));
    if (res_tab == NULL) {
        return NULL;
    }
    res_tab = hl_prep_table(res_tab, NULL, real_height);
    for (; tab[y] != NULL; y++) {
        if (((int *)tab[y])[0] != eol) {
            lsize = get_line_size(tab[y], eol);
            res_tab[tracker] = malloc(size * (lsize + 1));
            res_tab[tracker] = hl_copy_line(res_tab[tracker], tab[y], lsize);
            tracker += 1;
        }
    }
    res_tab[tracker] = NULL;
    return res_tab;
}
