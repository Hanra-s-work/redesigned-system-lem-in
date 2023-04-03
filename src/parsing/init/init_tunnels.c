/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** init_tunnels.c
*/

#include <stdlib.h>

#include "li_structs_parser.h"

tunnel_t *init_tunnels(int start, int end, int weight)
{
    tunnel_t *tunnel = malloc(sizeof(tunnel_t));

    tunnel->start = start;
    tunnel->end = end;
    tunnel->weight = weight;
    return tunnel;
}
