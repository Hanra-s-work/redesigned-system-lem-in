/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** get_file_content.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "linked_lists.h"


linked_lists_t *get_file_content(void)
{
    size_t size = 0;
    int size_read = 0;
    char *line = NULL;
    linked_lists_t *file_content = NULL;

    while (size_read != (-1)) {
        size_read = getline(&line, &size, stdin);
        if (size_read == (-1)) {
            (line != NULL) ? free(line) : (size_read = 0);
            return file_content;
        }
        line[size_read - 1] = '\0';
        if (file_content != NULL) {
            file_content = init_list((void *)my_strdup(line), STRING, NONE);
        } else {
            append(file_content, (void *)my_strdup(line), STRING, NONE);
        }
    }
}
