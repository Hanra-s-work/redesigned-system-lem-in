/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
** File description:
** free_node.c
*/

#include <stdlib.h>
#include "linked_lists.h"

linked_lists_t *free_node(linked_lists_t *ll, int index)
{
    int i = 0;
    linked_lists_t *tmp = NULL;

    if (ll == NULL)
        return ll;
    for (tmp = ll; i < index && tmp->next != NULL; tmp = tmp->next, i++);
    if (tmp->prev != NULL) {
        tmp->prev->next = tmp->next;
    }
    if (tmp->next != NULL) {
        tmp->next->prev = tmp->prev;
    }
    free(tmp);
    return ll;
}
