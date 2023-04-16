/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** append.c
*/

#include <stdlib.h>
#include "linked_lists.h"

int append(linked_lists_t *ll, void *data, data_type_e type, struct_name_e sn)
{
    linked_lists_t *new = init_list(data, type, sn);
    linked_lists_t *tmp;

    for (tmp = ll; tmp->next != NULL; tmp = tmp->next);
    new->index = tmp->index + 1;
    new->prev = tmp;
    tmp->next = new;
    return new->index;
}
