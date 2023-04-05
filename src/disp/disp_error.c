/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** disp_error.c
*/

#include <unistd.h>

#include "my.h"
#include "li_constants.h"
#include "batch_colouriser.h"
#include "li_colour_constants.h"

int disp_error(bcol_t *bc, char const *msg)
{
    set_err_out_colour(bc, ERR_COL, (char *)msg);
    set_err_out_colour(bc, RESET_COL, "");
    return err;
}
