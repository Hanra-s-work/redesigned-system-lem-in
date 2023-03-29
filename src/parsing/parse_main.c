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

parser_t *parse_main(void)
{
    parser_t *parsed = NULL;

    parsed = init_parser();
    parsed = get_file_content();
    return parsed;
}
