/*
** EPITECH PROJECT, 2022
** redesigned-system-lem-in
** File description:
** get_without_blocking.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *read_input(void)
{
    char buffer[BUFFER_SIZE];
    ssize_t nread;
    size_t len = 0;
    char *line = NULL;
    char *input = NULL;

    // read from channel 0 using read function
    nread = read(STDIN_FILENO, buffer, BUFFER_SIZE);

    // check if there was an error while reading the input
    if (nread == -1) {
        printf("An error occurred while reading input.\n");
        return NULL;
    }

    // if no data was read, return immediately
    if (nread == 0) {
        return NULL;
    }

    // allocate memory for input buffer
    input = malloc(nread);

    // copy the read data into input buffer
    memcpy(input, buffer, nread);

    // parse input into lines using getline
    while ((nread = getline(&line, &len, input)) != -1) {
        // print the line that was read
        printf("%s", line);
    }

    // free memory allocated for line and input buffers
    free(line);
    free(input);

    return NULL;
}

int main(void)
{
    read_input();
    return 0;
}
