/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** get_node_data.c
*/

#include <stddef.h>
#include "linked_lists.h"

data_type_e get_node_type(linked_lists_t *ll, int data_index)
{
    data_type_e type = UNKNOWN;
    linked_lists_t *llt = get_node(ll, data_index);
    if (llt == NULL) {
        return type;
    }
    type = llt->type;
    return type;
}
