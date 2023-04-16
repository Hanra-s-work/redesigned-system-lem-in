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
linked_lists_t *move(linked_lists_t *head, int from_index, int to_index) {
    // Check if the linked list is empty
    if (head == NULL) {
        return NULL;
    }

    // Check if the node to move is the head of the linked list
    if (from_index == 0) {
        // Remove the head node from the linked list
        linked_lists_t *node = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }

        // Insert the head node at the new position
        linked_lists_t *next_node = head;
        for (int i = 0; i < to_index && next_node != NULL; i++) {
            next_node = next_node->next;
        }

        node->prev = NULL;
        node->next = next_node;
        if (next_node != NULL) {
            next_node->prev = node;
        }

        return node;
    }

    // Find the node to move
    linked_lists_t *node = head;
    for (int i = 0; i < from_index && node != NULL; i++) {
        node = node->next;
    }
    if (node == NULL) {
        return head;
    }

    // Remove the node from the linked list
    node->prev->next = node->next;
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    // Insert the node at the new position
    linked_lists_t *next_node = head;
    for (int i = 0; i < to_index && next_node != NULL; i++) {
        next_node = next_node->next;
    }

    node->prev = next_node->prev;
    node->next = next_node;
    if (next_node->prev != NULL) {
        next_node->prev->next = node;
    }
    next_node->prev = node;

    return head;
}
