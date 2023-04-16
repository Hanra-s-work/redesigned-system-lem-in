/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** init_who_was_displayed.c
*/

#include <stdbool.h>

#include "li_structs.h"

who_was_displayed_t init_who_was_displayed(bool status)
{
    who_was_displayed_t wwd;
    wwd.moves = status;
    wwd.number_of_ants = status;
    wwd.rooms = status;
    wwd.tunnels = status;
    return wwd;
}
