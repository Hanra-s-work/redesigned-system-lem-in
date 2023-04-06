/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** free_tunnels.c
*/

#include <stdlib.h>
#include "parse/free.h"
#include "li_structs.h"
#include "linked_lists.h"
#include "li_structs_parser.h"

void free_tunnels(linked_lists_t *ll)
{
    linked_lists_t *tmp = NULL;
    tunnel_t *tmp_tunnels = NULL;

    for (tmp = ll; tmp != NULL; tmp = tmp->next) {
        tmp_tunnels = (tunnel_t *)tmp->data;
        if (tmp_tunnels != NULL) {
            free(tmp_tunnels);
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
