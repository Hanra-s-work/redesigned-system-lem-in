/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** get_tunnel.c
*/

#include "my.h"
#include "parse/init.h"
#include "parse/free.h"
#include "li_structs.h"
#include "linked_lists.h"
#include "li_structs_parser.h"

void get_tunnel(parser_t *parser, char const *data)
{
    char **tab_temp = my_str_to_word_array((char *)data, '-');
    tunnel_t *tunnel = NULL;
    int start = my_getnbr(tab_temp[0]);
    int end = my_getnbr(tab_temp[1]);

    tunnel = init_tunnels(start, end, 1);
    init_or_append_tunnel(parser, tunnel);
    free_array(tab_temp);
}
