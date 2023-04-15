/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** check_queue.h
*/

#ifndef PATH_FINDER_H_
    #define PATH_FINDER_H_
    #include "li_structs.h"


typedef struct line_s {
    int size;
    int f;
    int r;
    int *arr;
} line_t;

int empty_line(line_t *l);
int full_line(line_t *l);
void in_line_wait(line_t *l, int val);
int withdraw(line_t *l);

#endif
