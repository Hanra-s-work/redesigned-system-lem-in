/*
** EPITECH PROJECT, 2023
** disp_parser
** File description:
** cpe
*/

#include "my.h"
#include "disp.h"
#include "li_structs.h"
#include "batch_colouriser.h"
#include "li_structs_parser.h"
#include "li_colour_constants.h"

void disp_parser(bcolours_t *bc, parser_t *parser)
{
    set_colour(bc, INFO_COL, "file_content\n");
    disp_pretty_output(bc, parser->file_content);
    set_colour(bc, INFO_COL, "tunnels\n");
    disp_tunnels(bc, parser->tunnels);
    set_colour(bc, INFO_COL, "rooms\n");
    disp_room(bc, parser->rooms);
    set_colour(bc, INFO_COL, "status = ");
    set_colour(bc, INFO_COL, "");
    my_put_nbr(parser->status);
    set_colour(bc, RESET_COL, "\n");
}