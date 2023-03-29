/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-1-lemin-thomas.lebouc
** File description:
** sub_main.c
*/

#include <stddef.h>
#include "parse.h"
#include "li_structs.h"
#include "linked_lists.h"

// les solver se trouverons entre parsed et disp_file_content
int sub_main(int argc, char **argv)
{
    parser_t *parsed = NULL;

    parsed = parse_main();
    disp_file_content(parsed->file_content);
    return 0;
}
