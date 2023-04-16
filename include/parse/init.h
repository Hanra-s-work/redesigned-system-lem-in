/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** init.h
*/

#ifndef INIT_H_
    #define INIT_H_
    #include "li_structs.h"
    #include "li_structs_parser.h"

parser_t *init_parser(void);
tunnel_t *init_tunnels(int start, int end, int weight);
who_was_displayed_t init_who_was_displayed(bool status);
void init_or_append_room(parser_t *parser, rooms_t *room);
void init_or_append_tunnel(parser_t *parser, tunnel_t *tunnel);
rooms_t *init_rooms(char *name, bool is_start, bool is_end, int nb_max_occ);

#endif
