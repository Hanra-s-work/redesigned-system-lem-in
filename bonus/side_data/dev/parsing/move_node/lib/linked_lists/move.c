/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** Untitled-1
*/

#include <stddef.h>
#include "linked_lists.h"

/**
 * Moves a node in a linked list to a new position.
 *
 * @param ll The ll of the linked list.
 * @param from_index The index of the node to move.
 * @param to_index The index to move the node to.
 * @return The new ll of the linked list.
 */
linked_lists_t *move(llists_t *ll, uint from_index, uint to_index, int *status)
{
    int i = 0;
    int to = (int)to_index;
    int from = (int)from_index;
    int max_length = get_list_size(ll);
    linked_lists_t *node = NULL;
    linked_lists_t *next_node = NULL;

    /* Check if the linked list is empty */
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

    /* Check if the node to move is the ll of the linked list */
    if (0 == from) {
        /* Remove the ll node from the linked list */
        node = ll;
        ll = ll->next;
        if (ll != NULL) {
            ll->prev = NULL;
        }

        /* Insert the ll node at the new position */
        next_node = ll;
        for (i = 0; i < to_index && next_node != NULL; i++) {
            next_node = next_node->next;
        }

        node->prev = NULL;
        node->next = next_node;
        if (next_node != NULL) {
            next_node->prev = node;
        }

        return node;
    }

    /* Find the node to move */
    node = ll;
    for (i = 0; i < from && node != NULL; i++) {
        node = node->next;
    }
    if (node == NULL) {
        *status = ll_success;
        return ll;
    }

    /* Remove the node from the linked list */
    node->prev->next = node->next;
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    /* Insert the node at the new position */
    next_node = ll;
    for (i = 0; i < to_index && next_node != NULL; i++) {
        next_node = next_node->next;
    }

    node->prev = next_node->prev;
    node->next = next_node;
    if (next_node->prev != NULL) {
        next_node->prev->next = node;
    }
    next_node->prev = node;
    *status = ll_success;
    return ll;
}
