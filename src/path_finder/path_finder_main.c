/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** path_finder_main.c
*/

#include <stddef.h>

#include "my.h"
#include "disp.h"
#include "li_structs.h"
#include "li_constants.h"
#include "batch_colouriser.h"

int path_finding_main(batch_colours_t *bc, parser_t *parsed)
{
    int status = success;
    if (parsed == NULL) {
        status = disp_error(bc, "parsed is uninitialised\n");
    }
    return status;
}
