/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp.h
*/

#ifndef DISP_H_
    #define DISP_H_
    #include "li_structs.h"
    #include "linked_lists.h"
    #include "batch_colouriser.h"

int disp_error(bcol_t *bc, char const *msg);

void disp_room(bcolours_t *bc, llists_t *room);
void disp_help(bcol_t *bc, char const *bin_name);
void disp_parser(bcolours_t *bc, parser_t *parser);
void disp_tunnels(bcolours_t *bc, llists_t *tunnel);
void disp_file_content(linked_lists_t *file_content);
void disp_pretty_output(bcolours_t *bc, linked_lists_t *file_content);

#endif
