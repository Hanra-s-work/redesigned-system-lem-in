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
 * @param head The head of the linked list.
 * @param from_index The index of the node to move.
 * @param to_index The index to move the node to.
 * @return The new head of the linked list.
 */
linked_lists_t *move(linked_lists_t *head, int from_index, int to_index)
{
    int i;
    linked_lists_t *node;
    linked_lists_t *next_node;

    /* Check if the linked list is empty */
    if (NULL == head) {
        return NULL;
    }

    /* Check if the node to move is the head of the linked list */
    if (0 == from_index) {
        /* Remove the head node from the linked list */
        node = head;
        head = head->next;
        if (NULL != head) {
            head->prev = NULL;
        }

        /* Insert the head node at the new position */
        next_node = head;
        for (i = 0; i < to_index && NULL != next_node; i++) {
            next_node = next_node->next;
        }

        node->prev = NULL;
        node->next = next_node;
        if (NULL != next_node) {
            next_node->prev = node;
        }

        return node;
    }

    /* Find the node to move */
    node = head;
    for (i = 0; i < from_index && NULL != node; i++) {
        node = node->next;
    }
    if (NULL == node) {
        return head;
    }

    /* Remove the node from the linked list */
    node->prev->next = node->next;
    if (NULL != node->next) {
        node->next->prev = node->prev;
    }

    /* Insert the node at the new position */
    next_node = head;
    for (i = 0; i < to_index && NULL != next_node; i++) {
        next_node = next_node->next;
    }

    node->prev = next_node->prev;
    node->next = next_node;
    if (NULL != next_node->prev) {
        next_node->prev->next = node;
    }
    next_node->prev = node;

    return head;
}
