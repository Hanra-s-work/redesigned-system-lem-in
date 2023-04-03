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
rooms_t *init_rooms(char *name, bool is_start, bool is_end, int nb_max_occ);

#endif
