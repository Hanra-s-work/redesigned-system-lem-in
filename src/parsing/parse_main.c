/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** parse_main.c
*/

#include <stddef.h>

#include "parse.h"
#include "parse/get.h"
#include "parse/init.h"
#include "li_structs.h"
#include "li_constants.h"

parser_t *parse_main(void)
{
    parser_t *parsed = NULL;
    int status = success;

    parsed = init_parser();
    parsed->file_content = get_file_content();
    status = sort_data(parsed);
    if (ant_error == status)
        return NULL;
    return parsed;
}
