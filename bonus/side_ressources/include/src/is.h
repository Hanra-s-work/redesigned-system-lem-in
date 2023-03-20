/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** is.h
*/

#ifndef IS_H_
    #define IS_H_
    #include <stdbool.h>

int is_legal(char c);
int is_a_box(char chr);
int is_empty(char chr);
bool is_help(char *arg);
int is_a_wall(char chr);
int is_a_player(char chr);
int is_a_death_block(char chr);
bool is_empty(char *usr_input);
bool is_a_standalone(char *bin);
bool is_setenv(char **usr_input);
bool is_unsetenv(char **usr_input);
int is_a_storage_location(char chr);
int is_equal(int nb_boxes, int nb_holes);
bool is_bin_present(char *bin, char *path);
bool is_in_str(char *needle, char *haystack);
bool is_exit(char *usr_input, int size_read);
int is_char_illegal(char chr, char *authed_str);
int is_screen_correct(int screen_w, int screen_h, int map_w, int map_h);

#endif
