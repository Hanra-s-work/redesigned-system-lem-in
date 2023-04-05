#!/bin/bash
##
## EPITECH PROJECT, 2022
## redesigned-system-lem-in
## File description:
## launch_it.sh
##

BIN=lem_in

make re

if [ $# -ne 1 ]; then
    echo "This is a bash ment to help you launch the program"
    echo "Usage: $0 [file]"
    if [ -f ./$BIN ]; then
        echo "The help of the program:"
        ./$BIN --help
    fi
    exit 84
fi

if [ $# -eq 1 ]; then
    if [ -f $1 ]; then
        ./$BIN <$1
    else
        echo "File not found"
        exit 84
    fi
else
    ./lem_in
fi
