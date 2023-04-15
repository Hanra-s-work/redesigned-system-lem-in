/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** algo.c BFS
*/

#include "linked_lists.h"
#include "my.h"

void init_struct(void)
{
    line_t *l;
    l->size = 500;
    l->f = 0;
    l->r = 0;
    l->arr = malloc(sizeof(int*) * (l->size + 1));
}

int empty_line(line_t *l)
{
    if (q->r == l->f)
        return 1;
    return 0;
}

int full_line(line_t *l)
{
    if (l->r == (l->size - 1))
        return 1;
    return 0;
}

void in_line_wait(line_t *l, int val)
{
    if (full_line(l) == 1) {
        my_putstr("line is full\n");
    } else {
        l->r++;
        l->arr[l->r] = val;
    }
}

int withdraw(line_t *l)
{
    int i = - 1;

    if (empty_line(l) == 1) {
        my_putstr("line is empty")
    } else {
        l->f++;
        i = l->arr[l->f];
    }
    return i;
}
