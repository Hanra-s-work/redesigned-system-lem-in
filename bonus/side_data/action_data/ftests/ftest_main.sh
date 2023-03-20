#!/bin/bash
##
## EPITECH PROJECT, 2022
## B-MAT-200-PAR-2-1-106bombyx-henry.letellier
## File description:
## ftest_main.sh
##

# including depencies
source ./src/ftest_functions.sh
source ./src/ftests_constants.sh
source ./src/ftests_bulk_test_functions.sh

# setting the name of the binary
if [ $# -ge 1 ]; then
    BINARY_NAME=$1
else
    BINARY_NAME="helm_in"
fi
if [ $# -ge 2 ]; then
    BINARY_PATH=$2
else
    BINARY_PATH="./${BINARY_NAME}"
fi

# setting the default colour of the program
set_default_colour

# How testing works
# 1. Call your test function and pass the GLOBAL_STATUS variable
# 2. Update the GLOBAL_STATUS variable with the return value of the test function
#    For this, use the function 'update_global_status' pass '$?' for the latest status
# 3. Update the global status variable with the latest status that was returned '$?'
#    Syntax of the line: 'GLOBAL_STATUS=$?'
# 4. Do this for every function call you do in this file

# Calling the functions
test_help $GLOBAL_STATUS
update_global_status $?
GLOBAL_STATUS=$?

test_statuses $GLOBAL_STATUS
update_global_status $?
GLOBAL_STATUS=$?

# This is if a false negative appears in the global status:
is_false_negative $GLOBAL_STATUS
GLOBAL_STATUS=$?

# Displaying the execution results
insert_padding
display_overall_coverage $GLOBAL_STATUS

# Remove any file that was created by this program
clean_ressources

# Resetting the colour to the default shell
set_full_default_colour

# exit $GLOBAL_STATUS
if [ $GLOBAL_STATUS -ne $SUCCESS ]; then
    exit 1
else
    exit $GLOBAL_STATUS
fi
