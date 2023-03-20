/*
** EPITECH PROJECT, 2022
** B-CPE-110-PAR-1-1-antman-henry.letellier
** File description:
** hl_itoa.c
*/

#include <stdlib.h>

#include "src/hl.h"

static int nb_size(int nb)
{
    long int res = nb;
    int tot_size = 0;
    if (nb == 0) {
        return 1;
    }
    if (nb < 0) {
        tot_size += 1;
        res *= (-1);
    }

    while (res > 0) {
        res /= 10;
        tot_size += 1;
    }
    return tot_size;

}

char *hl_itoa(int nb)
{
    int tot_nb_size = nb_size(nb);
    char *res = malloc(sizeof(char) * (tot_nb_size + 1));
    long int lnb = nb;
    int i = tot_nb_size - 1;int tmp = 0;

    res = (char *)hl_memset(res, (int)'\0', tot_nb_size + 1);
    if (lnb == 0) {
        res[0] = '0';
        return res;
    }
    if (lnb < 0) {
        lnb *= (-1);
        res[0] = '-';
    }
    while (lnb > 0) {
        tmp = lnb % 10;
        lnb /= 10;
        res[i--] = tmp + '0';
    }
    return res;
}
