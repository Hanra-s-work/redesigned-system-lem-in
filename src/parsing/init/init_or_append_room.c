/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** init_or_append_room.c
*/

#include <stddef.h>

#include "li_structs.h"
#include "linked_lists.h"
#include "li_structs_parser.h"

void init_or_append_room(parser_t *parser, rooms_t *room)
{
    if (parser->rooms != NULL) {
        append(parser->rooms, (void *)room, STRUCT, ROOMS);
    } else {
        parser->rooms = init_list((void *)room, STRUCT, ROOMS);
    }
}
