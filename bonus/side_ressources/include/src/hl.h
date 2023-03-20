/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier
** File description:
** hl.h
*/

#ifndef HL_H_
    #define HL_H_

int hl_atoi(char *nb);
int hl_str_is_alnum(char *str);
int hl_is_a_sep(char chr, char *sep);
int hl_char_is_alpha(char const chr);
int hl_count_character_occurrence(char *str, char chr);

char *hl_itoa(int nb);
char *hl_dup_char(char chr);
char *hl_strdup(char const *str);
char *hl_tab_to_str(char **tab, char *sep);
char *hl_copy_from(char *src, char *dest, int i);
char *hl_strtok(char *str, char *sep, int nb_skip);

char **hl_dup_map(char **map);
char **hl_str_to_word_array(char *str, char *sep, int *width, int *height);

void hl_puterror(char const *str);
void hl_show_int_table(int **tab);
void hl_put_str_int(char *str, int nb, char *end);

void hl_free(void *data);

void *hl_memset(void *tab, int value, int size);

void **hl_prep_table(void **table, void *value, int height);
void **hl_dup_tab(void **tab, void *eot, int eol, int type_size);
#endif
