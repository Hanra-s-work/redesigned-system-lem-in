/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** hl_count_character_occurrence.c
*/

int hl_count_character_occurrence(char *str, char chr)
{
    int i = 0;
    int occurrence = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == chr) {
            occurrence++;
        }
    }
    return occurrence;
}
