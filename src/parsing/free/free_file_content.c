/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** free_file_content.c
*/

#include <stdlib.h>

#include "parse/free.h"
#include "linked_lists.h"

void free_file_content(linked_lists_t *ll)
{
    linked_lists_t *tmp = NULL;

    for (tmp = ll; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == STRING) {
            li_free(tmp->data);
        }
        if (tmp->prev != NULL) {
            free(tmp->prev);
        }
    }
}
