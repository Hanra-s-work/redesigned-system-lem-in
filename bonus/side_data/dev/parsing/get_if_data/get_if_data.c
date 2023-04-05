/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** get_if_data.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t nread;
    size_t len = 0;
    char *line = NULL;

    // read from channel 0 using read function
    nread = read(STDIN_FILENO, buffer, BUFFER_SIZE);

    printf("nread = '%ld'\n", nread);

    // check if there was an error while reading the input
    if (nread == -1) {
        printf("An error occurred while reading input.\n");
        return -1;
    }

    // if no data was read, print -1 and exit
    if (nread == 0) {
        printf("-1\n");
        return -1;
    }

    // allocate memory for line using getline
    // line = malloc(BUFFER_SIZE);

    // read a line of input from buffer using getline
    // if (getline(&line, &len, stdin) == -1) {
    //     printf("An error occurred while reading input.\n");
    //     free(line);
    //     return -1;
    // }

    // // print the input that was read
    // printf("%s", line);

    // // free the memory allocated for the input buffer
    // free(line);

    return 0;
}
