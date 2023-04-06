/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp_file_content.c
*/

#include "my.h"
#include "linked_lists.h"

void disp_file_content(linked_lists_t *file_content)
{
    linked_lists_t *tmp = NULL;

    for (tmp = file_content; tmp != NULL; tmp = tmp->next) {
        if (tmp->type == STRING) {
            my_putstr((char *)tmp->data);
            my_putchar('\n');
        }
    }
}
