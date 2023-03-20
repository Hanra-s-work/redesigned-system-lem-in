#!/bin/bash
##
## EPITECH PROJECT, 2022
## B-MAT-200-PAR-2-1-106bombyx-henry.letellier
## File description:
## ftest_functions.sh
##

# Functions

# Set colour
function set_colour {
    echo -ne "$1$2"
}

function set_default_colour {
    set_colour $RESET_COL "\n"
}

function set_full_default_colour {
    set_colour $F_RESET_COL "\n"
}

# display text with specific visual changes
function disp_title {
    echo -e "${TITLE_COL}$1${RESET_COL}"
}

function disp_sub_title {
    echo -e "${SUB_TITLE_COL}$1${RESET_COL}"
}

function disp_info {
    echo -ne "${INFO_COL}$1${RESET_COL}"
}

function disp_var {
    disp_info "$1: "
    echo -e "${HIGHLIGHT_INFO}$2${RESET_COL}"
    return $2
}

function disp_a_tracking_value {
    disp_info "Number of $1: "
    echo -e "$2$3${RESET_COL}"
}

# Add some spacing to the display
function insert_padding {
    set_default_colour $RESET_COL "\n\n\n\n"
}

# Function that will display the current working directory
function get_current_working_directory {
    disp_title "Displaying the path of the current directory (cwd)"
    disp_info "This script is currently running in: "
    echo -ne "$HIGHLIGHT_INFO $(pwd)$RESET_COL\n"
    insert_padding
}

# display the percentage with a specific colour depending on the amount
function disp_percentage {
    TMP_VAL="$(printf "%.0f" $1)"
    COMP_SENTENCE="${COMPRESSION_COL}$2: "
    if [ $TMP_VAL -lt 10 ]; then
        echo -e "${COMP_SENTENCE}${CRITICAL_COL}$1 %${RESET_COL}"
    elif [ $TMP_VAL -ge 10 ] && [ $TMP_VAL -lt 50 ]; then
        echo -e "${COMP_SENTENCE}${LOW_COL}$1 %${RESET_COL}"
    elif [ $TMP_VAL -ge 50 ] && [ $TMP_VAL -lt 60 ]; then
        echo -e "${COMP_SENTENCE}${OK_COL}$1 %${RESET_COL}"
    elif [ $TMP_VAL -ge 60 ] && [ $TMP_VAL -lt 80 ]; then
        echo -e "${COMP_SENTENCE}${GOOD_COL}$1 %${RESET_COL}"
    elif [ $TMP_VAL -ge 80 ] && [ $TMP_VAL -le 100 ]; then
        echo -e "${COMP_SENTENCE}${GREAT_COL}$1 %${RESET_COL}"
    elif [ $TMP_VAL -gt 100 ]; then
        echo -e "${COMP_SENTENCE}${CRITICAL_COL}$1 %${RESET_COL}"
    else
        echo -ne "${COMP_SENTENCE}${ERR_COL}Bad Input (Got $1 but expected "
        echo -e "a number)${RESET_COL}"
    fi
}

# Function in charge of displaying the tracking data of the program
function display_overall_coverage {
    disp_title "Checking the status of the global coverage"
    disp_info "Global Coverage Status: "
    disp_status $1
    echo ""
    disp_a_tracking_value "tests" $SUCCESS_COL $NB_CHECKED
    disp_a_tracking_value "SUCCESSEFULL tests" $SUCCESS_COL $NB_SUCCESS
    disp_a_tracking_value "SKIPPED tests" $INFO_TEST_COL $NB_SKIPPED
    disp_a_tracking_value "FAILED tests" $ERR_COL $NB_FAIL
    disp_a_tracking_value "CRASHED tests" $ERR_COL $NB_CRASHED
    echo ""
    disp_sub_title "More details about the execution:${RESET_COL}\n"
    disp_a_tracking_value "SEGFAULTS" $ERR_COL $NB_SEGFAULT
    disp_a_tracking_value "ERROR 'NOT FOUND'" $ERR_COL $NB_NOT_FOUND
    disp_a_tracking_value "UNKNOWN ERRORS" $ERR_COL $NB_UNKNOWN
}

# Display the status of the program accordingly
function disp_status {
    if [[ $1 -eq $SUCCESS ]]; then
        echo -ne "${SUCCESS_COL}OK${RESET_COL}"
        return $SUCCESS
    else
        echo -ne "${ERR_COL}KO${RESET_COL}"
    fi
    return $ERROR
}

# Exit the program if a critical error appears
function when_fatal {
    if [[ $1 -eq $ERROR ]]; then
        echo -e "${F_RESET_COL}"
        exit $GLOBAL_STATUS
    fi
}

# Functions in charge of monitoring the test results of the script
# update the global status appropriately based on the return statuses
function update_global_status {
    if [[ $1 -ne $SUCCESS ]] && [[ $1 -ne $SKIPPED ]]; then
        return $ERROR
    elif [[ $1 -eq $SKIPPED ]]; then
        return $SKIPPED
    elif [[ $1 -eq $SUCCESS ]] && [[ $2 -eq $SUCCESS ]]; then
        return $SUCCESS
    else
        return $2
    fi
}

# Update the variables 'skipped' when a test fails
function update_skipped {
    let "NB_SKIPPED=NB_SKIPPED+$1"
    let "NB_CHECKED=NB_CHECKED+$1"
}

# Universalise the status while following the Epitech error norm
function translate_status_to_epitech {
    if [ $1 -eq $SUCCESS ]; then
        return $SUCCESS
    else
        return $ERROR
    fi
}

# Update the variable tracking the data about the advancement of the tests
function update_nb_success {
    if [[ $1 -ne $SUCCESS ]]; then
        if [[ $1 -eq $ERROR ]]; then
            let "NB_FAIL=NB_FAIL+1"
        elif [[ $1 -eq $SEGFAULT ]]; then
            let "NB_SEGFAULT=NB_SEGFAULT+1"
            let "NB_CRASHED=NB_CRASHED+1"
        elif [[ $1 -eq $COMMAND_NOT_FOUND ]]; then
            let "NB_NOT_FOUND=NB_NOT_FOUND+1"
            let "NB_CRASHED=NB_CRASHED+1"
        else
            let "NB_UNKNOWN=NB_UNKNOWN+1"
            let "NB_CRASHED=NB_CRASHED+1"
        fi
    elif [[ $1 -eq $SUCCESS ]]; then
        let "NB_SUCCESS=NB_SUCCESS+1"
    else
        let "NB_SKIPPED=NB_SKIPPED+1"
    fi
    let "NB_CHECKED=NB_CHECKED+1"
}

# Update the variable tracking the data about the global status and the success
function update_tracking {
    update_global_status $1 $GLOBAL_STATUS
    GLOBAL_STATUS=$?
    update_nb_success $1
    return $GLOBAL_STATUS
}

# Function in charge of checking and displaying the compression rate of the data between two files
function check_compression_size {
    SRC_FILE=$1
    FINAL_FILE=$2
    VAR=$(stat -c %s $SRC_FILE)
    VAR2=$(stat -c %s $FINAL_FILE)
    RESULT=$(bc <<<"scale=2; 100 - ($VAR2/$VAR * 100)")
    disp_percentage $RESULT "Compression rate"
    return $?
}

# Function in charge of checking and displaying the restoration rate of the data between two files
function check_restoration_size {
    SRC_FILE=$1
    FINAL_FILE=$2
    VAR=$(stat -c %s $SRC_FILE)
    VAR2=$(stat -c %s $FINAL_FILE)
    RESULT=$(bc <<<"scale=2; ($VAR2/$VAR * 100)")
    disp_percentage $RESULT "Restoration rate"
}

# Function in charge calling a binary without passing any arguments
function run_test_no_args {
    BIN_PATH=$1
    $BIN_PATH 1>$FILE_TMP_RUN 2>$FILE_TMP_ERROR
    STATUS=$?
    return $STATUS
}

# Function in charge of calling a binary with arguments
function run_test_with_args {
    BIN_PATH=$1
    shift #removing the first argument
    $BIN_PATH "$@" 1>$FILE_TMP_RUN 2>$FILE_TMP_ERROR
    return $?
}

# Function that will call the makefile in charge of compling the code
function rebuild_code {
    disp_title "Building code"
    make -C ./ "$@" >$FILE_TMP_BUILD 2>&1
    insert_padding
    return $?
}

# Function in charge of checking if the output of the program is the same as the given arg
function is_same {
    EXPECTED=$1
    BIN_PATH=$2
    shift #removing the first argument
    shift #removing the second argument
    run_test_with_args $BIN_PATH "$@"
    STATUS=$?
    VAR="$(cat ./$FILE_TMP_RUN)"
    if [[ $STATUS -eq $SUCCESS ]] && [[ $VAR == $EXPECTED ]]; then
        return $SUCCESS
    else
        return $STATUS
    fi
}

# Function in charge of checking if the program has output content to the terminal
function has_output {
    BIN_PATH=$1
    shift #removing the first argument
    run_test_with_args $BIN_PATH "$@"
    STATUS=$?
    VAR="$(cat ./$FILE_TMP_RUN)"
    if [[ $STATUS -eq $SUCCESS ]] && [[ $VAR != "" ]]; then
        return $SUCCESS
    else
        return $STATUS
    fi
}

# Function that will check if the rebuild option has been called
function rebuild_necessary {
    rebuild_code
    GLOBAL_STATUS=$?
    when_fatal $GLOBAL_STATUS
    return $GLOBAL_STATUS
}

# Function in charge of checking if the output is an error
function is_error {
    STATUS=$1
    if [[ $STATUS -eq $SUCCESS ]]; then
        return $ERROR
    else
        return $SUCCESS
    fi
}

# Function in charge of running and displaying the status of the binary
function run_and_display_status {
    BIN_PATH=$1
    shift #removing the first argument
    run_test_with_args $BIN_PATH "$@"
    STATUS=$?
    disp_status $STATUS
    return $STATUS
}

# Function in charge of running and displaying the status of the content of the binary
function check_output_and_display_status {
    BIN_PATH=$1
    shift #removing the first argument
    has_output $BIN_PATH "$@"
    STATUS=$?
    disp_status $STATUS
    echo ""
    return $STATUS
}

# Function in charge of testing the binary and display the status of the execution
function check_if_no_output_and_display_status {
    BIN_PATH=$1
    shift #removing the first argument
    has_output $BIN_PATH "$@"
    is_error $?
    STATUS=$?
    disp_status $STATUS
    echo ""
    return $STATUS
}
STATUS=$?
# Function in charge of checking if a run was supposed to result in an error
function check_if_run_is_error_and_display_status {
    BIN_PATH=$1
    shift #removing the first argument
    run_test_with_args $BIN_PATH "$@"
    is_error $?
    STATUS=$?
    disp_status $STATUS
    echo ""
    return $STATUS
}

# Function in charge of checking a a status of 1 was returned by error (the false negative value)
function is_false_negative {
    if [[ $1 -eq 1 ]]; then
        return $SUCCESS
    else
        return $1
    fi
}

# Function in charge of cleaning the files that were temporarily created
function clean_ressources {
    disp_title "Cleaning ressources:"
    rm -f $FILE_TMP_RUN
    rm -f $FILE_TMP_ERROR
    rm -f $FILE_TMP_BUILD
    rm -f $FILE_TMP_OUTPUT
    rm -f $FILE_TMP_DIFF
    rm -f $FILE_TMP_DIFF_ERROR
    rm -f $FILE_TMP_DIFF_OUTPUT
    rm -f $FILE_TMP_DIFF_OUTPUT_ERROR
    rm -f $FILE_TMP_DIFF_OUTPUT_ERROR_COMPRESSED
    disp_percentage 100 "Progression"
}
