/*
** EPITECH PROJECT, 2023
** get_ants
** File description:
** cpe
*/

#include <stddef.h>
#include "my.h"
#include "li_constants.h"
#include "linked_lists.h"

int get_ants(linked_lists_t *file_content)
{
    char *data = NULL;
    int ants_nb = 0;
    linked_lists_t *tmp = NULL;

    tmp = file_content;
    if (tmp->type == STRING) {
        data = my_strdup((char const *)tmp->data);
    }
    if (my_str_isnum(data) == 84) {
        free(data);
        return ant_error;
    }
    ants_nb = my_getnbr(data);
    if (ants_nb <= 0) {
        free(data);
        return ant_error;
    }
    free(data);
    return ants_nb;
}
