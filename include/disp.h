/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp.h
*/

#ifndef DISP_H_
    #define DISP_H_
    #include "linked_lists.h"
    #include "batch_colouriser.h"

int disp_error(bcol_t *bc, char const *msg);

void disp_help(bcol_t *bc, char const *bin_name);
void disp_file_content(linked_lists_t *file_content);
void disp_pretty_output(linked_lists_t *file_content);

#endif
