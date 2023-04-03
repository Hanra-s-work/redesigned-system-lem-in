/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** init_rooms.c
*/

#include <stdlib.h>
#include <stdbool.h>

#include "my.h"
#include "li_structs_parser.h"

rooms_t *init_rooms(char *name, bool is_start, bool is_end, int nb_max_occ)
{
    rooms_t *room = malloc(sizeof(rooms_t));

    room->name = my_strdup(name);
    room->is_start = is_start;
    room->is_end = is_end;
    room->nb_max_occupents = nb_max_occ;
    room->posx = (-1);
    room->posy = (-1);
    room->nb_occupents = 0;
    return room;
}
