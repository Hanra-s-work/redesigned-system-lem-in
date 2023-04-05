/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell1-henry.letellier
** File description:
** batch_colouriser.h
*/

#ifndef BATCH_COLOURISER_H_
    #define BATCH_COLOURISER_H_
    #include <stdbool.h>

static const int bc_err = 84;
static const int bc_error = 84;
static const int bc_success = 0;
static const int bc_not_found = (-2);
static const int bc_colours_not_initialised = (-3);
static const int bc_colour_code_is_empty = (-4);

struct batch_colours_s {
    int index;
    char *batch_code;
    char *colour_code;
    bool at_end;
    int max_allocated;
    int nb_elems;
};

typedef struct batch_colours_s batch_colours_t;
typedef struct batch_colours_s bcolours_t;
typedef struct batch_colours_s bcol_t;

int bc_atoi(char *nb);
int bc_strlen(char const *chr);
int bc_puterror(char const *str);
int free_colours(batch_colours_t *colours);
int bc_strcmp(char const *s1, char const *s2);
int set_err_out_colour(bcol_t *colours, char *batch_colour_code, char *cont);
int set_colour(batch_colours_t *colours, char *batch_colour_code, char *cont);

void show_all_colours(void);
void bc_putstr(char const *str);
void *bc_memset(void *tab, int value, int size);

char *bc_itoa(int nb);
char *bc_strlowcase(char *str);
char *bc_strcat(char *dest, char const *src);

batch_colours_t *init_colours(void);


#endif
