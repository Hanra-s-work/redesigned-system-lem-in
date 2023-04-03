/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** init_parser.c
*/

#include <stdlib.h>
#include "li_structs.h"

parser_t *init_parser(void)
{
    parser_t *parser = malloc(sizeof(parser_t));

    parser->rooms = NULL;
    parser->tunnels = NULL;
    parser->file_content = NULL;
    return parser;
}
