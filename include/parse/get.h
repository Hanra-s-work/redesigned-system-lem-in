/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** get.h
*/

#ifndef GET_H_
    #define GET_H_
    #include "li_structs.h"
    #include "linked_lists.h"

linked_lists_t *get_file_content(void);

int get_ants(linked_lists_t *file_content);
int get_char_index(char const *str, char const sep);

void get_tunnel(parser_t *parser, char const *data);
void get_room(parser_t *parser, char const *data, llists_t **fc, int nb_ants);

#endif
