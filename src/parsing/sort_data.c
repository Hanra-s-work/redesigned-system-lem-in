/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** sort_data.c
*/

#include <stddef.h>
#include <stdbool.h>

#include "parse.h"
#include "li_structs.h"
#include "li_constants.h"
#include "linked_lists.h"

static void who_to_send_to(parser_t *parser, char const *data, llists_t **fc)
{
    bool done = false;
    if (data != NULL && is_in(data, 'P') == true && false == done) {
        parser->status = err;
        done = true;
    }
    if (data != NULL && is_in(data, '-') == true && false == done) {
        done = true;
    }
    if (data != NULL && is_in(data, ' ') == true && false == done) {
        done = true;
    }
    if (data != NULL && is_in(data, '#') == true && false == done) {
        done = true;
    }
    if (data != NULL && false == done) {
        parser->status = err;
        done = true;
    }
}

void sort_data(parser_t *p)
{
    char *data = NULL;
    linked_lists_t *fcontent = p->file_content;

    for (; fcontent != NULL && p->status != err; fcontent = fcontent->next) {
        if (fcontent->type == STRING) {
            data = (char *)fcontent->data;
        } else {
            continue;
        }
        who_to_send_to(p, data, &fcontent);
    }

}
