/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp_pretty_output.c
*/

#include <stddef.h>
#include <stdbool.h>

#include "my.h"
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

static void set_display_condition(bcol_t *bc, char *str, bool done)
{
    static int room = 0;

    if (str != NULL && is_in(str, ' ') == true && false == done) {
        if (room == 0) {
            my_putstr("#rooms\n");
            room = 1;
        }
        set_colour(bc, ROOMS_COL, str);
        done = true;
    }
    if (str != NULL && str[0] == '#' && false == done) {
        if (room == 0) {
            my_putstr("#rooms\n");
            room = 1;
        }
        set_colour(bc, SUCCESS_COL, str);
        done = true;
    }
    if (str != NULL && false == done)
        set_colour(bc, LINE_COL, str);
}

static void who_to_display(bcol_t *bc, char *str)
{
    bool done = false;
    static int tunnel = 0;

    if (str != NULL && is_in(str, 'P') == true && false == done) {
        set_colour(bc, MOVES_COL, str);
        done = true;
    }
    if (str != NULL && is_in(str, '-') == true && false == done) {
        if (tunnel == 0) {
            my_putstr("#tunnels\n");
            tunnel = 1;
        }
        set_colour(bc, TUNNEL_COL, str);
        done = true;
    }
    set_display_condition(bc, str, done);
}

void disp_pretty_output(bcolours_t *bc, linked_lists_t *file_content)
{
    char *str = NULL;
    linked_lists_t *tmp = NULL;

    my_putstr("#number_of_ants\n");
    for (tmp = file_content; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == STRING)
            str = (char *)tmp->data;
        else
            str = NULL;
        who_to_display(bc, str);
        set_colour(bc, RESET_COL, "\n");
    }
}
