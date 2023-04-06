/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** free_rooms.c
*/


#include <stdlib.h>
#include "parse/free.h"
#include "li_structs.h"
#include "linked_lists.h"
#include "li_structs_parser.h"

void free_rooms(linked_lists_t *ll)
{
    linked_lists_t *tmp = NULL;
    rooms_t *tmp_rooms = NULL;

    for (tmp = ll; tmp != NULL; tmp = tmp->next) {
        tmp_rooms = (rooms_t *)tmp->data;
        if (tmp_rooms != NULL) {
            li_free(tmp_rooms->name);
            free(tmp_rooms);
        }
        if (tmp->prev != NULL) {
            free(tmp->prev);
        }
        if (tmp->next == NULL) {
            ll = tmp;
        }
    }
    li_free(tmp);
    li_free(ll);
}
