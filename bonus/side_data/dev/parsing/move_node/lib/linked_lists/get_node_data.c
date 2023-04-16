/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** get_node_data.c
*/

#include <stddef.h>
#include "linked_lists.h"

void *get_node_data(linked_lists_t *ll, int data_index)
{
    linked_lists_t *llt = get_node(ll, data_index);
    if (llt == NULL) {
        return NULL;
    }
    return llt->data;
}
