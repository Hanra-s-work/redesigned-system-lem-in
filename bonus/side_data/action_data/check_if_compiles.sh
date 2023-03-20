#!/bin/bash
##
## EPITECH PROJECT, 2022
## redesigned-system-lem-in
## File description:
## check_if_compiles.sh
##

echo "$(uname -a)"
echo "$(gcc --version | head -n 1)"
echo "$(make --version | head -n 1)"
echo "$(ulimit)"

function test_command {
    COMMAND=$@
    $COMMAND
    STATUS=$?
    if [ $STATUS -eq 0 ]; then
        echo "Compilation OK"
    else
        echo "::error file=$COMMAND,line=1,endLine=0,title=Compilation failed!! :-(::$COMMAND=$STATUS"
        exit 1
    fi
    return $STATUS
}

COMMAND='make fclean'
test_command $COMMAND
COMMAND='make'
test_command $COMMAND
COMMAND='make clean'
test_command $COMMAND
COMMAND='make fclean'
test_command $COMMAND
COMMAND='make debug'
test_command $COMMAND
COMMAND='make fclean'
test_command $COMMAND
COMMAND='make re'
test_command $COMMAND
