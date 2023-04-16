/*
** EPITECH PROJECT, 2023
** is_corr_nb_args
** File description:
** cpe
*/

#include <stdbool.h>

#include "parse.h"
#include "parse/is.h"
#include "parse/get.h"
#include "li_structs_parser.h"

bool is_corr_nb_args(char const *room)
{
    int offset = 0;
    int nb_args = 0;
    int char_pos = 0;
    const int nb_authed = 3;

    nb_args = count_char((char *)room, ' ');
    if (nb_authed == nb_args)
        return true;
    if (nb_args > nb_authed && is_in(room, '#') == true) {
        char_pos = get_char_index(room, '#');
        offset = get_char_index((room + char_pos), ' ');
        if (room[char_pos] != '\0' && nb_authed == (nb_args - offset))
            return true;
    }
    return false;
}
