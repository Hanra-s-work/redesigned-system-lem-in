/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** main.c
*/

#include <stdio.h>
#include <stddef.h>

#include "linked_lists.h"

static void disp_list(llists_t *ll, char const *msg, int status)
{
    int i = 0;
    llists_t *tmp = NULL;

    printf("\033[1;93m%s\n\033[0m", msg);
    if (ll == NULL) {
        printf("ll is null\n");
    }
    for (tmp = ll; tmp != NULL; tmp = tmp->next, i++) {
        if (tmp->type == STRING) {
            printf("i = %d: ll[%d] = '%s'\n", tmp->index, i, (char *)tmp->data);
        }
    }
    printf("\033[1;96mThe status of the test is: ");
    if (ll_err == status) {
        printf("\033[1;91m%d (err)\033[0m\n", status);
    } else {
        printf("\033[1;92m%d (success)\033[0m\n", status);
    }
}

static int run_test(llists_t *ll, uint from, uint to, char const *msg)
{
    int status = ll_success;
    llists_t *tmp = NULL;

    tmp = move(ll, from, to, &status);
    disp_list(tmp, msg, status);
    tmp = move(ll, from, to, &status);
    return status;
}

int main(void)
{
    int status = ll_success;
    llists_t *ll = NULL;

    ll = init_list((void *)"hello world", STRING, NONE);
    append(ll, (void *)"goodbye world", STRING, NONE);
    append(ll, (void *)"good morning world", STRING, NONE);
    append(ll, (void *)"good night world", STRING, NONE);
    append(ll, (void *)"good evening world", STRING, NONE);
    disp_list(ll, "Default list:", ll_success);
    status = run_test(ll, 4, 3, "List after running 'move(ll,4,3)'");
    if (ll_success != status)
        return status;
    status = run_test(ll, 0, 0, "List after running 'move(ll,0,0)'");
    if (ll_success != status)
        return status;
    status = run_test(ll, 1, 0, "List after running 'move(ll,1,0)'");
    if (ll_success != status)
        return status;
    status = run_test(ll, 0, 1, "List after running 'move(ll,0,1)'");
    if (ll_success != status)
        return status;
    status = run_test(NULL, 4, 3, "List after running 'move(NULL,4,3)'");
    status = run_test(ll, 100, 100, "List after running 'move(ll,100,100)'");
    status = run_test(ll, 1, 100, "List after running 'move(ll,1,100)'");
    status = run_test(ll, 100, 1, "List after running 'move(ll,100,1)'");
    if (ll_success != status)
        return status;
    disp_list(ll, "Default list after tests:", ll_success);
    free_linked_list(ll);
    return 0;
}
