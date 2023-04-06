/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** sort_data.c
*/

#include <stddef.h>
#include <stdbool.h>

#include "disp.h"
#include "parse.h"
#include "parse/get.h"
#include "li_structs.h"
#include "li_constants.h"
#include "linked_lists.h"

static void who_to_send_to(parser_t *parser, char *d, llists_t **fc, int ants)
{
    bool done = false;
    if (d != NULL && is_in(d, 'P') == true && false == done) {
        parser->status = err;
        done = true;
    }
    if (d != NULL && is_in(d, '-') == true && false == done) {
        get_tunnel(parser, d);
        done = true;
    }
    if (d != NULL && is_in(d, ' ') == true && false == done) {
        get_room(parser, d, fc, ants);
        done = true;
    }
    if (d != NULL && is_in(d, '#') == true && false == done) {
        get_room(parser, d, fc, ants);
        done = true;
    }
    if (d != NULL && false == done) {
        parser->status = err;
        done = true;
    }
}

void sort_data(parser_t *p)
{
    char *data = NULL;
    linked_lists_t *fcontent = p->file_content;
    int nb_ants = get_ants(fcontent);

    fcontent = fcontent->next;
    for (; fcontent != NULL && p->status != err; fcontent = fcontent->next) {
        if (fcontent->type == STRING) {
            data = (char *)fcontent->data;
        } else {
            continue;
        }
        who_to_send_to(p, data, &fcontent, nb_ants);
    }

}
