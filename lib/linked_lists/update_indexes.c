/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** update_indexes.c
*/

#include <stddef.h>
#include "linked_lists.h"

void update_indexes(linked_lists_t *ll)
{
    int i = 0;
    llists_t *tmp = NULL;

    for (tmp = ll; tmp != NULL; tmp = tmp->next, i++) {
        tmp->index = i;
    }
}
