/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-1-lemin-thomas.lebouc
** File description:
** sub_main.c
*/

#include <stddef.h>
#include "parse.h"
#include "li_structs.h"
#include "path_finder.h"
#include "linked_lists.h"
#include "li_constants.h"

int sub_main(int argc, char **argv)
{
    int status = success;
    parser_t *parsed = NULL;
    parsed = parse_main();
    status = path_finding_main(parsed);
    disp_file_content(parsed->file_content);
    return status;
}
