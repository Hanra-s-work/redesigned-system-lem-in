/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp_file_content.c
*/

#include <stdbool.h>

#include "my.h"
#include "parse/is.h"
#include "parse/init.h"
#include "li_structs.h"
#include "linked_lists.h"

static void who_to_display(who_was_displayed_t *wwd, char const *str, int i)
{
    if (0 == i) {
        my_putstr("#number_of_ants\n");
        wwd->number_of_ants = true;
    }
    if (1 == i) {
        my_putstr("#rooms\n");
        wwd->rooms = true;
    }
    if (is_in(str, '-') == true && is_in(str, 'P') == false) {
        if (false == wwd->tunnels) {
            my_putstr("#tunnels\n");
            wwd->tunnels = true;
        }
    }
    if (is_in(str, 'P') == true && false == wwd->moves) {
        my_putstr("#moves\n");
        wwd->moves = false;
    }
    my_putstr(str);
    my_putchar('\n');
}

void disp_file_content(linked_lists_t *file_content)
{
    int i = 0;
    who_was_displayed_t wwd = init_who_was_displayed(false);
    linked_lists_t *tmp = NULL;

    for (tmp = file_content; tmp != NULL; tmp = tmp->next, i++) {
        if (tmp->type == STRING) {
            who_to_display(&wwd, (char *)tmp->data, i);
        }
    }
    if (wwd.moves == false) {
        my_putstr("#moves\n");
    }
}
