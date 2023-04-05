/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** get_input_non_blocking.c
*/

#include <aio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    // read a line of input from channel 0
    nread = getline(&line, &len, stdin);

    // check if there was an error or if there was no input available
    if (nread == -1) {
        if (feof(stdin)) {
            printf("No input available.\n");
        } else {
            printf("An error occurred while reading input.\n");
        }
        return -1;
    }

    // print the input that was read
    printf("Input: %s", line);

    // free the memory allocated for the input buffer
    free(line);

    return 0;
}
