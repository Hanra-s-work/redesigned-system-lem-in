/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** is_bin_present.c
*/

#include <stddef.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "my.h"
#include "src/hl.h"

bool is_bin_present(char *bin, char *path)
{
    char *path_copy = hl_append_to_str(path, bin, '/');
    struct stat stat_buff;
    int size = 0;

    if (path == NULL || bin == NULL) {
        return false;
    }
    if (path_copy == NULL) {
        return false;
    }
    size = stat(path_copy, &stat_buff);
    if (size == 0) {
        hl_free(path_copy);
        return true;
    }
    hl_free(path_copy);
    return false;
}
