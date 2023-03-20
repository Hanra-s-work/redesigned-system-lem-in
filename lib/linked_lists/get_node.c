/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** get_node.c
*/

#include <stddef.h>
#include "linked_lists.h"

linked_lists_t *get_node(linked_lists_t *ll, int node_index)
{
    int i = 0;
    linked_lists_t *tmp;
    for (tmp = ll; i < node_index && tmp->next != NULL; tmp = tmp->next, i++);
    return tmp;
}
