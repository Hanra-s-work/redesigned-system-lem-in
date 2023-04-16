/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** get_room.c
*/

#include <stddef.h>
#include <stdbool.h>
#include "my.h"
#include "parse.h"
#include "parse/is.h"
#include "parse/get.h"
#include "parse/free.h"
#include "parse/init.h"
#include "linked_lists.h"
#include "li_structs.h"
#include "li_structs_parser.h"


static char *manage_name(llists_t **fc, int *w, char *name)
{
    if (*w == 0 && ((char *)(*fc)->data)[0] == '#') {
        *w = 2;
        name = my_strdup((char const *)(*fc)->data);
        (*fc) = (*fc)->next;
    }
    return name;
}

static void init_or_append(parser_t *parser, rooms_t *room)
{
    if (parser->rooms != NULL) {
        append(parser->rooms, (void *)room, STRUCT, ROOMS);
    } else {
        parser->rooms = init_list((void *)room, STRUCT, ROOMS);
    }
}

static bool check_if_correct(char const *data)
{
    int nb_spaces = 0;
    nb_spaces = count_char((char *)data, ' ');
    if (nb_spaces != 2)
        return false;

    return true;
}

static void process_start(trtrack_t *track, char const *data, llists_t **fc)
{
    if (track->whois == 0 && my_strcmp(data, "##start") == 0) {
        track->nb_start += 1;
        track->name = my_strdup((char const *)(*fc)->data);
        (*fc) = (*fc)->next;
        track->room = init_rooms(track->name, true, false, track->nb_ants);
        track->room->nb_occupents = track->room->nb_max_occupents;
        track->whois = 1;
    }
}

static void process_end(trtrack_t *track, char const *data, llists_t **fc)
{
    if (track->whois == 2 && my_strcmp(data, "##end") == 0) {
        track->nb_end += 1;
        track->room = init_rooms(track->name, false, true, track->nb_ants);
    }
}

void get_room(parser_t *parser, char const *data, llists_t **fc, int nb_ants)
{
    tmp_room_track_t track = init_tmp_room_track(-666);
    char *name = NULL;
    char tmp[2];
    rooms_t *room = NULL;

    process_start(&track, data, fc);
    name = manage_name(fc, &track.whois, name);
    process_end(&track, data, fc);
    if (track.whois == 0) {
        tmp[0] = ((char const *)(*fc)->data)[0];
        tmp[1] = '\0';
        track.name = my_strdup(tmp);
        track.room = init_rooms(name, false, false, 1);
    }
    init_or_append(parser, room);
    li_free(track.name);
}
