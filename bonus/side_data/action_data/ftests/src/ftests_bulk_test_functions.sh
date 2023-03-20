#!/bin/bash
##
## EPITECH PROJECT, 2022
## B-MAT-200-PAR-2-1-106bombyx-henry.letellier
## File description:
## ftests_bulk_test_functions.sh
##

function display_variables {
    disp_title "Displaying the content of variables:"
    disp_sub_title "# Constants:"
    disp_var "SUCCESS" $SUCCESS
    disp_var "ERROR" $ERROR
    disp_var "SKIPPED" $SKIPPED
    disp_var "COMMAND_NOT_FOUND" $COMMAND_NOT_FOUND
    disp_var "SEGFAULT" $SEGFAULT
    disp_var "F_RESET_COL" $F_RESET_COL
    disp_var "BACKGROUND_COL" $BACKGROUND_COL
    disp_var "RESET_COL" $RESET_COL
    disp_var "ERR_COL" $ERR_COL
    disp_var "SUCCESS_COL" $SUCCESS_COL
    disp_var "INFO_COL" $INFO_COL
    disp_var "TITLE_COL" $TITLE_COL
    disp_var "SUB_TITLE_COL" $SUB_TITLE_COL
    disp_var "INFO_TEST_COL" $INFO_TEST_COL
    disp_var "HIGHLIGHT_INFO" $HIGHLIGHT_INFO
    disp_var "COMPRESSION_COL" $COMPRESSION_COL
    disp_var "CRITICAL_COL" $CRITICAL_COL
    disp_var "LOW_COL" $LOW_COL
    disp_var "OK_COL" $OK_COL
    disp_var "GOOD_COL" $GOOD_COL
    disp_var "GREAT_COL" $GREAT_COL
    echo ""
    disp_sub_title "# Data Tracking"
    disp_var "GLOBAL_STATUS" $GLOBAL_STATUS
    disp_var "NB_SUCCESS" $NB_SUCCESS
    disp_var "NB_FAIL" $NB_FAIL
    disp_var "NB_CRASHED" $NB_CRASHED
    disp_var "NB_SEGFAULT" $NB_SEGFAULT
    disp_var "NB_NOT_FOUND" $NB_NOT_FOUND
    disp_var "NB_UNKNOWN" $NB_UNKNOWN
    disp_var "NB_CHECKED" $NB_CHECKED
    disp_var "NB_SKIPPED" $NB_SKIPPED
    echo ""
}

function self_test {
    get_current_working_directory
    display_variables
    disp_title "Test basic options"
    disp_sub_title "Testing options${RESET_COL}\n"
    disp_info "Testing $OK success"
    disp_info " message: "
    disp_status $SUCCESS 1 1
    echo -e "$RESET_COL"
    disp_info "Testing $KO error"
    disp_info " message error status: "
    disp_status $ERROR 1 1
    echo -e "$RESET_COL"
    disp_info "Testing $KO error"
    disp_info " message different inputs: "
    disp_status $SUCCESS 1 2
    echo -e "$RESET_COL"
    insert_padding
    disp_sub_title "Test compression status${RESET_COL}\n"
    disp_percentage "0" "Test percentage"
    disp_percentage "10" "Test percentage"
    disp_percentage "20" "Test percentage"
    disp_percentage "30" "Test percentage"
    disp_percentage "40" "Test percentage"
    disp_percentage "50" "Test percentage"
    disp_percentage "60" "Test percentage"
    disp_percentage "70" "Test percentage"
    disp_percentage "80" "Test percentage"
    disp_percentage "90" "Test percentage"
    disp_percentage "100" "Test percentage"
    disp_percentage "101" "Test percentage"
    insert_padding
    disp_title "Test Compressions size"
    TEST_FILE1="./a.txt"
    TEST_FILE2="./b.txt"
    disp_sub_title "Creating required files${RESET_COL}\n"
    echo "aaaaa" >$TEST_FILE1
    echo -ne "${INFO_COL}File '$TEST_FILE1' created, containing "
    echo -ne "'$(cat $TEST_FILE1)'.\n"
    echo "aaaa" >$TEST_FILE2
    echo -ne "${INFO_COL}File '$TEST_FILE2' created, containing "
    echo -ne "'$(cat $TEST_FILE2)'.\n\n"
    disp_sub_title "Testing the maths${RESET_COL}\n"
    # if a is larger than b by one character, the value equals 25%
    check_compression_size "./a.txt" "./b.txt"
    # if a is larger than b by one character, the value equals 75%
    check_restoration_size "./a.txt" "./b.txt"
    disp_sub_title "Cleaning residues${RESET_COL}\n"
    rm $TEST_FILE1
    echo -e "${INFO_COL}Removed $TEST_FILE1."
    rm $TEST_FILE2
    echo -e "${INFO_COL}Removed $TEST_FILE2."
    insert_padding
    disp_title "Testing with existing file:"
    run_test_with_args $ANTMAN $NG_RICK_ROLL_TXT $OPTION_TXT
    STATUS=$?
    disp_info "Run Status: "
    disp_status $STATUS

    return $SUCCESS
}

function test_compression_decompression_file {
    SRC_FILE=$1
    OPTION=$2
    disp_title "Testing with filename: $SRC_FILE"
    disp_info "Compression: "
    run_test_with_args $ANTMAN $SRC_FILE $OPTION
    TMP_STATUS=$?
    # translate_status_to_epitech $TMP_STATUS
    # VALVE_STATUS=$?
    update_tracking $TMP_STATUS
    GLOBAL_STATUS=$?
    echo ""
    if [ $TMP_STATUS -eq $SUCCESS ]; then
        check_compression_size $SRC_FILE $TMP_RUN
        cat $TMP_RUN >"outsourcing1.txt"
        TMP_STATUS=$?
        # translate_status_to_epitech $TMP_STATUS
        # VALVE_STATUS=$?
        update_tracking $TMP_STATUS
        GLOBAL_STATUS=$?
        if [ $TMP_STATUS -eq $SUCCESS ]; then
            disp_info "Decompression: "
            run_test_with_args $GIANTMAN $TMP_RUN $SRC_FILE
            TMP_STATUS=$?
            # translate_status_to_epitech $TMP_STATUS
            # VALVE_STATUS=$?
            update_tracking $TMP_STATUS
            GLOBAL_STATUS=$?
            echo ""
            if [ $TMP_STATUS -eq $SUCCESS ]; then
                check_restoration_size $SRC_FILE $TMP_RUN
                TMP_STATUS=$?
                # translate_status_to_epitech $TMP_STATUS
                # VALVE_STATUS=$?
                update_tracking $TMP_STATUS
                GLOBAL_STATUS=$?
            else
                insert_padding
                update_skipped 1
                return $GLOBAL_STATUS
            fi
        else
            insert_padding
            update_skipped 2
            return $GLOBAL_STATUS
        fi
    else
        insert_padding
        update_skipped 3
        return $GLOBAL_STATUS
    fi
    insert_padding
    return $GLOBAL_STATUS
}

# Ask the program to test itself
function self_test {
    if [ $# -ge 1 ]; then
        if [[ $1 == "st" ]] || [[ $2 == "st" ]]; then
            self_test
        elif [[ $3 == "st" ]] || [[ $4 == "st" ]]; then
            self_test
        fi
    fi
}

#  Rebuild code
function rebuild_code {
    if [ $# -ge 1 ]; then
        if [ $1 != "nr" ] && [ $2 != "nr" ]; then
            if [ $3 != "nr" ] && [ $4 != "nr" ]; then
                rebuild_necessary
                update_global_status $?
                GLOBAL_STATUS=$?
                when_fatal $GLOBAL_STATUS
            fi
        fi
    fi
}

function test_help {
    disp_title "Testing help"
    # Testing option number 1
    disp_info "Testing '$OPTION_HELP_ONE' status: "
    check_output_and_display_status $BINARY_PATH $OPTION_HELP_ONE
    update_tracking $?
    GLOBAL_STATUS=$?
    # Testing option number 2
    disp_info "Testing '$OPTION_HELP_TWO' status: "
    check_output_and_display_status $BINARY_PATH $OPTION_HELP_TWO
    update_tracking $?
    GLOBAL_STATUS=$?
    # Testing option number 3
    disp_info "Testing '$OPTION_HELP_THREE' status: "
    check_if_no_output_and_display_status $BINARY_PATH $OPTION_HELP_THREE
    update_tracking $?
    GLOBAL_STATUS=$?
    # Testing option number 4
    disp_info "Testing '$OPTION_HELP_FOUR' status: "
    check_if_no_output_and_display_status $BINARY_PATH $OPTION_HELP_FOUR
    update_tracking $?
    GLOBAL_STATUS=$?
    # Testing option number 5
    disp_info "Testing '$OPTION_HELP_FIVE' status: "
    check_if_no_output_and_display_status $BINARY_PATH $OPTION_HELP_FIVE
    update_tracking $?
    GLOBAL_STATUS=$?
    insert_padding
    return $GLOBAL_STATUS
}

function test_for_errors {
    disp_sub_title "Testing for errors:"
    disp_info "No arguments: "
    check_if_run_is_error_and_display_status $BINARY_PATH
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Not enough arguments: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Too many arguments: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT2_K $ARGUMENT3_I0 $ARGUMENT4_I1
    update_tracking $?
    GLOBAL_STATUS=$?
    insert_padding
    disp_sub_title "Invalid arguments:"
    disp_info "Arg n is not a number (only 2 args): "
    check_if_run_is_error_and_display_status $BINARY_PATH "${ARGUMENT1_N}a" $ARGUMENT2_K
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg k is not a number: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N "${ARGUMENT2_K}b"
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n and k are not a number: "
    check_if_run_is_error_and_display_status $BINARY_PATH "${ARGUMENT1_N}a" "${ARGUMENT2_K}b"
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n is not a number (only 3 args): "
    check_if_run_is_error_and_display_status $BINARY_PATH "${ARGUMENT1_N}a" $ARGUMENT3_I0 $ARGUMENT4_I1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg i0 is not a number: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N "${ARGUMENT3_I0}b" $ARGUMENT4_I1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg i1 is not a number: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT3_I0 "${ARGUMENT4_I1}c"
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n and i0 are not a numbers: "
    check_if_run_is_error_and_display_status $BINARY_PATH "${ARGUMENT1_N}a" "${ARGUMENT3_I0}b" $ARGUMENT4_I1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n and i1 are not a numbers: "
    check_if_run_is_error_and_display_status $BINARY_PATH "${ARGUMENT1_N}a" $ARGUMENT3_I0 "${ARGUMENT4_I1}c"
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg i0 and i1 are not a numbers: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N "${ARGUMENT3_I0}b" "${ARGUMENT4_I1}c"
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n,i0 and i1 are not a numbers: "
    check_if_run_is_error_and_display_status $BINARY_PATH "${ARGUMENT1_N}a" "${ARGUMENT3_I0}b" "${ARGUMENT4_I1}c"
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg k is to big: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT2_K_TO_BIG
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg k is to small: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT2_K_TO_SMALL
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg i0 is greater than i1: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT4_I1 $ARGUMENT3_I0
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg i0 is equal to i1: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT3_I0 $ARGUMENT3_I0
    update_tracking $?
    GLOBAL_STATUS=$?
    insert_padding
    return $GLOBAL_STATUS
}

function test_for_float_errors {
    disp_sub_title "Testing for invalid int's:"
    disp_info "Arg n is a float (only 2 args): "
    check_if_run_is_error_and_display_status $BINARY_PATH ${ARGUMENT1_N}.1 $ARGUMENT2_K
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n is a float (only 3 args): "
    check_if_run_is_error_and_display_status $BINARY_PATH ${ARGUMENT1_N}.1 $ARGUMENT3_I0 $ARGUMENT4_I1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg i0 is a float: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N ${ARGUMENT3_I0}.1 $ARGUMENT4_I1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg i1 is a float: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT3_I0 ${ARGUMENT4_I1}.1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n and i0 are floats: "
    check_if_run_is_error_and_display_status $BINARY_PATH ${ARGUMENT1_N}.1 ${ARGUMENT3_I0}.1 $ARGUMENT4_I1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n and i1 are floats: "
    check_if_run_is_error_and_display_status $BINARY_PATH ${ARGUMENT1_N}.1 $ARGUMENT3_I0 ${ARGUMENT4_I1}.1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg i0 and i1 are floats: "
    check_if_run_is_error_and_display_status $BINARY_PATH $ARGUMENT1_N ${ARGUMENT3_I0}.1 ${ARGUMENT4_I1}.1
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Arg n,i0 and i1 floats: "
    check_if_run_is_error_and_display_status $BINARY_PATH ${ARGUMENT1_N}.1 ${ARGUMENT3_I0}.1 ${ARGUMENT4_I1}.1
    update_tracking $?
    GLOBAL_STATUS=$?
    insert_padding
    return $GLOBAL_STATUS
}

function test_with_success {
    disp_sub_title "Testing when errors:"
    disp_info "Testing for output with n and k: "
    check_output_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT2_K
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Testing for output with n and k_min: "
    check_output_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT2_K_MIN
    update_tracking $?
    GLOBAL_STATUS=$?
    disp_info "Testing for output with n and k_max: "
    check_output_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT2_K_MAX
    update_tracking $?
    GLOBAL_STATUS=$?
    return $GLOBAL_STATUS
    disp_info "Testing for output with n, i0 and i1: "
    check_output_and_display_status $BINARY_PATH $ARGUMENT1_N $ARGUMENT3_I0 $ARGUMENT4_I1
    update_tracking $?
    GLOBAL_STATUS=$?
    insert_padding
    return $GLOBAL_STATUS
}

function test_statuses {
    disp_title "Checking binary status"
    test_for_errors
    is_false_negative $?
    update_global_status $?
    GLOBAL_STATUS=$?
    test_for_float_errors $?
    is_false_negative $?
    update_global_status $?
    test_with_success
    is_false_negative $?
    update_global_status $?
    GLOBAL_STATUS=$?
    return $GLOBAL_STATUS
}
