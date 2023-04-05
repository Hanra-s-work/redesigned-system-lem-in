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

parser_t *parse_main(void);

bool is_in(char const *str, char sep);

void sort_data(parser_t *parser);

#endif
