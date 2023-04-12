/*
** EPITECH PROJECT, 2023
** disp_room
** File description:
** cpe
*/

#include "my.h"
#include "li_structs.h"
#include "linked_lists.h"
#include "batch_colouriser.h"
#include "li_structs_parser.h"
#include "li_colour_constants.h"

void disp_room(bcolours_t *bc, llists_t *room)
{
    llists_t *tmp = NULL;rooms_t *tmp_room = NULL;

    for (tmp = room; tmp != NULL; tmp = tmp->next) {
        tmp_room = (rooms_t *)tmp->data;
        set_colour(bc, INFO_COL, "name = ");
        my_putstr(tmp_room->name);
        set_colour(bc, INFO_COL, "\nposx = ");
        my_put_nbr(tmp_room->posx);
        set_colour(bc, INFO_COL, "\nposy = ");
        my_put_nbr(tmp_room->posy);
        set_colour(bc, INFO_COL, "\nis_start = ");
        my_put_nbr(tmp_room->is_start);
        set_colour(bc, INFO_COL, "\nis_end = ");
        my_put_nbr(tmp_room->is_end);
        set_colour(bc, INFO_COL, "\nnb_occupents = ");
        my_put_nbr(tmp_room->nb_occupents);
        set_colour(bc, INFO_COL, "\nnb_max_occupents = ");
        my_put_nbr(tmp_room->nb_max_occupents);
        set_colour(bc, RESET_COL, "\n");
    }
}
