/*
** EPITECH PROJECT, 2023
** disp_tunnels
** File description:
** cpe
*/

#include "my.h"
#include "li_structs.h"
#include "linked_lists.h"
#include "batch_colouriser.h"
#include "li_structs_parser.h"
#include "li_colour_constants.h"

void disp_tunnels(bcolours_t *bc, llists_t *tunnel)
{
    llists_t *tmp = NULL;
    tunnel_t *tmp_tunnel = NULL;

    for (tmp = tunnel; tmp != NULL; tmp = tmp->next) {
        tmp_tunnel = (tunnel_t *)tmp->data;
        set_colour(bc, INFO_COL, "start  = ");
        my_put_nbr(tmp_tunnel->start);
        set_colour(bc, RESET_COL, "\n");
        set_colour(bc, INFO_COL, "end    = ");
        my_put_nbr(tmp_tunnel->end);
        set_colour(bc, RESET_COL, "\n");
        set_colour(bc, INFO_COL, "weight = ");
        my_put_nbr(tmp_tunnel->weight);
        set_colour(bc, RESET_COL, "\n");
    }
}
