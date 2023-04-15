/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-1-lemin-thomas.lebouc
** File description:
** li_structs.h
*/

#ifndef LI_STRUCTS_PARSER_H_
    #define LI_STRUCTS_PARSER_H_
    #include <stdbool.h>
    #include "linked_lists.h"

typedef struct rooms_s {
    char *name;
    int posx;
    int posy;
    bool is_start;
    bool is_end;
    int nb_occupents;
    int nb_max_occupents;
    llists_t *next;
    int cost;
    bool was_here;
} rooms_t;


typedef struct tunnel_s {
    int start;
    int end;
    int weight;
} tunnel_t;

typedef struct tmp_room_track_s {
    char *name;
    char *prev_name;
    int posx;
    int posy;
    int whois;
    int nb_end;
    int nb_ants;
    int nb_start;
    rooms_t *room;
} tmp_room_track_t;

typedef struct tmp_room_track_s trtrack_t;
typedef struct tmp_room_track_s troom_track_t;
typedef struct tmp_room_track_s tmp_room_track_t;

#endif
