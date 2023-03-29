/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-1-lemin-thomas.lebouc
** File description:
** li_structs.h
*/

#ifndef LI_STRUCTS_PARSER_H_
#define LI_STRUCTS_PARSER_H_
#include <stdbool.h>

typedef struct rooms_s {
    char *name;
    int posx;
    int posy;
    bool is_start;
    bool is_end;
    int nb_occupents;
    int nb_max_occupents;
} rooms_t;


typedef struct tunnel_s {
    int start;
    int end;
    int weight;
} tunnel_t;


#endif
