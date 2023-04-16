/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** init_tmp_room_track
*/

#include <stddef.h>
#include "li_structs_parser.h"

tmp_room_track_t init_tmp_room_track(int nb)
{
    tmp_room_track_t tmp;
    tmp.name = NULL;
    tmp.prev_name = NULL;
    tmp.posx = nb;
    tmp.posy = nb;
    tmp.whois = nb;
    tmp.nb_end = nb;
    tmp.nb_start = nb;
    tmp.room = NULL;
    return tmp;
}
