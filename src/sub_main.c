/*
** EPITECH PROJECT, 2022
** B-CPE-200-PAR-2-1-lemin-thomas.lebouc
** File description:
** sub_main.c
*/

#include <stddef.h>
#include <stdbool.h>

#include "my.h"
#include "src.h"
#include "disp.h"
#include "parse.h"
#include "parse/free.h"
#include "li_structs.h"
#include "path_finder.h"
#include "linked_lists.h"
#include "li_constants.h"

int sub_main(int argc, char **argv)
{
    int status = success;
    parser_t *parsed = NULL;
    batch_colours_t *bc = init_colours();

    if (argc != 1) {
        if (argc == 2 && is_help(argv[1]) == true) {
            disp_help(bc, argv[0]);
            return success;
        }
        disp_error(bc, "ERROR: Enter -h for help\n");
        return err;
    }

    parsed = parse_main();
    if (parsed == NULL)
        return error;
    status = path_finding_main(parsed);
    disp_pretty_output(bc, parsed->file_content);
    free_colours(bc);
    free_parser(parsed);
    return status;
}
