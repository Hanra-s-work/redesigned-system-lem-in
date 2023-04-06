/*
** EPITECH PROJECT, 2023
** free_array
** File description:
** cpe
*/

#include <malloc.h>

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i += 1) {
        free(array[i]);
    }
    free(array);
}
