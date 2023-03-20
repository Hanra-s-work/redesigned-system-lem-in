/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_strtok.c
*/

#include <stdlib.h>
#include <stdbool.h>

#include "my.h"
#include "src/hl.h"

static bool is_seperator_present(char *str, char *sep, int i)
{
    int j = i;
    int combo = 0;

    for (; sep[combo] != '\0' && str[j] != '\0'; combo++, j++) {
        if (sep[combo] != str[j]) {
            return false;
        }
    }
    return true;
}

char *hl_strtok(char *str, char *sep, int nb_skip)
{
    char *dest = NULL;
    int i = 0;int chunk_index = 0;int buffer_size = 0;

    for (; str[i] != '\0'; i++) {
        if (nb_skip > 0 && is_seperator_present(str, sep, i) == true) {
            nb_skip--;
            buffer_size = 0;
            chunk_index = i;
        }
        buffer_size++;
    }
    chunk_index += my_strlen(sep);
    dest = malloc(sizeof(char) * (buffer_size + 1));
    if (dest == NULL) {
        return dest;
    }
    dest = (char *)hl_memset((void *)dest, '\0', buffer_size);
    dest = hl_copy_from(str, dest, chunk_index);
    return dest;
}
