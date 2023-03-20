/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** init.c
*/

#include <stdlib.h>
#include "linked_lists.h"

linked_lists_t *init_list(void *data, data_type_e type)
{
    linked_lists_t *ll = malloc(sizeof(linked_lists_t));
    ll->index = 0;
    ll->prev = NULL;
    ll->next = NULL;
    ll->type = type;
    ll->data = data;
    return ll;
}
