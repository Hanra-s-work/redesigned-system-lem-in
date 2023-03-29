/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** free_parser.c
*/

#include <stdlib.h>

#include "parse/free.h"
#include "li_structs.h"
#include "linked_lists.h"

void free_parser(parser_t *parsed)
{
    if (parsed != NULL) {
        free_rooms(parsed->rooms);
        free_tunnels(parsed->tunnels);
        free_file_content(parsed->file_content);
        li_free(parsed);
    }
}
