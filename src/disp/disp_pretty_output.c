/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp_pretty_output.c
*/

#include <stddef.h>
#include <stdbool.h>

#include "li_constants.h"
#include "linked_lists.h"
#include "batch_colouriser.h"
#include "li_colour_constants.h"

static bool is_in(char const *str, char sep)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            return true;
        }
    }
    return false;
}

static void who_to_display(bcol_t *bc, char const *str)
{
    bool done = false;
    if (str != NULL && is_in(str, '-') == true && false == done) {
        set_colour(bc, TUNNEL_COL, str);
        done = true;
    }
    if (str != NULL && is_in(str, ' ') == true && false == done) {
        set_colour(bc, ROOMS_COL, str);
        done = true;
    }
    if (str != NULL && str[0] == '#' && false == done) {
        set_colour(bc, SUCCESS_COL, str);
        done = true;
    }
    if (str != NULL && is_in(str, 'P') == true && false == done) {
        set_colour(bc, MOVES_COL, str);
        done = true;
    }
    if (str != NULL && false == done)
        set_colour(bc, LINE_COL, str);
}

void disp_pretty_output(bcolours_t *bc, linked_lists_t *file_content)
{
    char *str = NULL;
    bool done = false;
    linked_lists_t *tmp = NULL;

    for (tmp = file_content; tmp != NULL; tmp = tmp->next) {

        if (tmp->type == STRING)
            str = (char *)tmp->data;
        else
            str = NULL;
        who_to_display(bc, str);
        set_colour(bc, RESET_COL, "\n");
    }
}
