/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp_pretty_output.c
*/

#include "li_constants.h"
#include "linked_lists.h"
#include "batch_colouriser.h"
#include "li_colour_constants.h"

void disp_pretty_output(bcolours_t *bc, linked_lists_t *file_content)
{
    set_colour(bc, SUCCESS_COL, (char *)file_content->data);
}
