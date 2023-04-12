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

static int process_start(int *whois, char const *data, llists_t **fc)
{
    if (whois == 0 && my_strcmp(data, "##start") == 0) {
        nb_start+=1;
        name = my_strdup((char const *)(*fc)->data);
        (*fc) = (*fc)->next;
        room = init_rooms(name, true, false, nb_ants);
        room->nb_occupents = room->nb_max_occupents;
        whois = 1;
    }
}

void get_room(parser_t *parser, char const *data, llists_t **fc, int nb_ants)
{
    tmp_room_track_t track = init_tmp_room_track(0);
    char *name = NULL;
    char tmp[2];
    rooms_t *room = NULL;
    int ints[4];

    ints[0] = 0; //whois
    ints[1] = 0; //nb_start
    ints[2] = 0; //nb_end
    ints[3] = (-666);

    if (ints[0] == 0 && my_strcmp(data, "##start") == 0) {
        ints[1]+=1;
        name = my_strdup((char const *)(*fc)->data);
        (*fc) = (*fc)->next;
        room = init_rooms(name, true, false, nb_ants);
        room->nb_occupents = room->nb_max_occupents;
        ints[0] = 1;
    }
    name = manage_name(fc, &ints[0], name);
    if (ints[0] == 2 && my_strcmp(data, "##end") == 0) {
        ints[2]+=1
        room = init_rooms(name, false, true, nb_ants);
    }
    if (ints[0] == 0) {
        tmp[0] = ((char const *)(*fc)->data)[0];
        tmp[1] = '\0';
        name = my_strdup(tmp);
        room = init_rooms(name, false, false, 1);
    }
    init_or_append(parser, room);
    li_free(name);
}
