/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** add_sections.c
*/

#include <stddef.h>

#include "my.h"
#include "li_structs.h"
#include "linked_lists.h"
#include "li_constants.h"
#include "li_structs_parser.h"

void add_section(parser_t *parse)
{
    int i = 0;
    int status = success;
    int length = get_list_size(parse->file_content);
    llists_t *tmp = NULL;
    llists_t *f_tmp = parse->file_content;
    llists_t *rooms_tmp = parse->rooms;
    llists_t *tunnel_tmp = parse->tunnels;
    char *tmp = NULL;

    append(f_tmp, (void *)my_strdup("#number_of_ants"), STRING, NONE);
    append(f_tmp, (void *)my_strdup("#rooms"), STRING, NONE);
    append(f_tmp, (void *)my_strdup("#tunnels"), STRING, NONE);
    append(f_tmp, (void *)my_strdup("#moves"), STRING, NONE);
    f_tmp = move(f_tmp, length-3, 0, &status);
    f_tmp = move(f_tmp, length-3, 3, &status);
    if (NULL != f_tmp) {
        parse->file_content = f_tmp;
    }
}
