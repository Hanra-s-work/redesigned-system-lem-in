/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** init_or_append_tunnel.c
*/

#include <stddef.h>

#include "li_structs.h"
#include "linked_lists.h"
#include "li_structs_parser.h"

void init_or_append_tunnel(parser_t *parser, tunnel_t *tunnel)
{
    if (parser->tunnels != NULL) {
        append(parser->tunnels, (void *)tunnel, STRUCT, TUNNELS);
    } else {
        parser->tunnels = init_list((void *)tunnel, STRUCT, TUNNELS);
    }
}
