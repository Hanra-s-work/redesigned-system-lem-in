/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** free.h
*/

#ifndef FREE_H_
    #define FREE_H_
    #include "li_structs.h"
    #include "linked_lists.h"
    #include "li_structs_parser.h"

void li_free(void *data);
void free_parser(parser_t *parsed);
void free_rooms(linked_lists_t *ll);
void free_tunnels(linked_lists_t *ll);
void free_file_content(linked_lists_t *ll);
void free_array(char **array);

#endif
