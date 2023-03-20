/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier (Workspace)
** File description:
** get_list_size.c
*/

#include <stddef.h>

#include "linked_lists.h"

int get_list_size(linked_lists_t *ll)
{
    linked_lists_t *tmp = NULL;
    int size = 0;
    for (tmp = ll; tmp != NULL; tmp = tmp->next, size++);
    return size;
}
