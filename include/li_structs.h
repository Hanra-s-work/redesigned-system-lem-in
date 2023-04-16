/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-1-lemin-thomas.lebouc
** File description:
** li_structs.h
*/

#ifndef LI_STRUCTS_H_
    #define LI_STRUCTS_H_
    #include <stdbool.h>
    #include "linked_lists.h"

typedef struct parser_s {
    llists_t *file_content;
    llists_t *tunnels;
    llists_t *rooms;
    int status;
} parser_t;

typedef struct who_was_displayed_s {
    bool number_of_ants;
    bool rooms;
    bool tunnels;
    bool moves;
} who_was_displayed_t;

#endif
