/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** is_a_standalone.c
*/

#include <unistd.h>
#include <stdbool.h>

#include "my.h"
#include "src/hl.h"

bool is_a_standalone(char *bin)
{
    int i = 0;
    int length = my_strlen(bin);
    int occurrence = hl_count_character_occurrence(bin, '/');
    int occurrence_progress = 0;
    char tmp_path[length + 1];
    char *path = hl_memset(tmp_path, '\0', length);

    for (; bin[i] != '\0' && occurrence_progress < occurrence; i++) {
        if (bin[i] == '/') {
            occurrence_progress++;
        }
        path[i] = bin[i];
    }
    path[i] = '\0';
    if (chdir(path) != 0) {
        return false;
    }
    return true;
}
