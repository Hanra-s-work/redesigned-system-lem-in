/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** get_last_node_index.c
*/


#include <stddef.h>
#include "linked_lists.h"

int get_last_node_index(linked_lists_t *ll)
{
    linked_lists_t *tmp = ll;

    for (; tmp->next != NULL; tmp = tmp->next);
    return tmp->index;
}
