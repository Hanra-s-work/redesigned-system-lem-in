/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** move.c
*/

#include <stddef.h>

#include "linked_lists.h"

static llists_t *when_zero(llists_t *ll, int to, int *status)
{
    llists_t *node = NULL;
    llists_t *next_node = NULL;

    node = ll;
    ll = ll->next;
    if (ll != NULL) {
        ll->prev = NULL;
    }
    next_node = ll;
    for (int i = 0; i < to && next_node != NULL; i++) {
        next_node = next_node->next;
    }
    node->prev = NULL;
    node->next = next_node;
    if (next_node != NULL) {
        next_node->prev = node;
    }
    *status = ll_success;
    return node;
}

static llists_t *check_if_valid(llists_t *ll, int from, int to, int *status)
{
    int max_length = get_list_size(ll);

    if (ll == NULL) {
        *status = ll_err;
        return NULL;
    }
    if (from > max_length || to > max_length) {
        *status = ll_err;
        return ll;
    }
    if (from == to) {
        *status = ll_success;
        return ll;
    }
    *status = ll_nothing;
    return ll;
}

static llists_t *move_nodes(llists_t *ll, int from, int to, int *status)
{
    int i = 0;llists_t *node = NULL;llists_t *next_node = NULL;

    for (node = ll, i = 0; i < from && node != NULL; node = node->next, i++);
    if (node == NULL) {
        *status = ll_success;
        return ll;
    }
    node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    for (next_node = ll, i = 0; i < to && next_node != NULL; i++) {
        next_node = next_node->next;
    }
    node->prev = next_node->prev;
    node->next = next_node;
    if (next_node->prev != NULL)
        next_node->prev->next = node;
    next_node->prev = node;
    *status = ll_success;
    return ll;
}

/**
 * Moves a node in a linked list to a new position.
 *
 * @param head The head of the linked list.
 * @param from_index The index of the node to move.
 * @param to_index The index to move the node to.
 * @return The new head of the linked list.
 **/
linked_lists_t *move(llists_t *ll, uint from_index, uint to_index, int *status)
{
    int to = (int)to_index;
    int from = (int)from_index;
    ll = check_if_valid(ll, from, to, status);
    if (ll_nothing != *status) {
        return ll;
    }
    *status = ll_err;
    if (0 == from) {
        ll = when_zero(ll, to, status);
        update_indexes(ll);
        return ll;
    }
    ll = move_nodes(ll, from, to, status);
    update_indexes(ll);
    return ll;
}
