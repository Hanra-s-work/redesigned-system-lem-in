/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** parse.h
*/

#ifndef PARSE_H_
    #define PARSE_H_
    #include <stdbool.h>
    #include "li_structs.h"
    #include "li_structs_parser.h"

parser_t *parse_main(void);

tmp_room_track_t init_tmp_room_track(int nb);
int count_char(char *str, char sep);

int sort_data(parser_t *parser);

#endif
