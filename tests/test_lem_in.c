/*
** EPITECH PROJECT, 2022
** B-PSU-200-PAR-2-1-minishell2-henry.letellier
** File description:
** test_minishell.c
*/

#include <stddef.h>
#include <stdbool.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"
// #include "parse/is.h"

// redirecting the visual outputs
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}


// Test(hl_rm_empty_spaces, test_space_removal)
// {
//     char data[] = "a                                                        ";
//     char *res = NULL;
//     res = hl_rm_empty_spaces(data);
//     cr_assert_str_eq(res, "a", "Expected %s but got %s.", res);
//     hl_free(res);
// }

Test(my_putstr, test_string, .init = redirect_all_std)
{
    char *data = "Hello World\n";
    my_putstr(data);
    cr_assert_stdout_eq_str(data);
}

// Test(set_colour, test_colouriser, .init = redirect_all_std)
// {
//     char *data = "Hello World";
//     bcol_t *bc = init_colours();
//     set_colour(bc, "0A", data);
//     free_colours(bc);
//     cr_assert_stdout_neq_str(data);
// }

// Test(is_a_standalone, test_if_standalone)
// {
//     char *data = "/bin/ls";
//     bool response = is_a_standalone(data);
//     cr_assert_eq(response, true);
// }

// Test(is_bin_present, test_if_present)
// {
//     char *data = "/bin/";
//     char *data2 = "ls";
//     bool response = is_bin_present(data2, data);
//     cr_assert_eq(response, true);
// }

// Test(is_empty, test_if_empty)
// {
//     char *data = "ttt";
//     bool response = is_empty(data);
//     cr_assert_eq(response, false);
// }

// Test(is_exit, test_if_exit)
// {
//     char *data = "exit\n";
//     bool response = is_exit(data, my_strlen(data));
//     cr_assert_eq(response, true);
// }

// Test(is_foldpath_present, test_if_fold_path_present)
// {
//     char *data = "/bin/";
//     bool response = is_foldpath_present(data);
//     cr_assert_eq(response, true);
// }

// Test(is_help, test_if_help)
// {
//     char *data = "-h";
//     bool response = is_help(data);
//     cr_assert_eq(response, true);
// }

// Test(is_here, test_if_here)
// {
//     char data[] = "aa;;ff|gg;hh<ii;jj>kk;ll<<mm;nn>>oo;";
//     char *sep[] = { ";", "|","<<", ">>", "<", ">", NULL };
//     int isep = 0;
//     bool response = is_here((data + 2), sep, &isep);
//     cr_assert_eq(isep, 0);
//     cr_assert_eq(response, true);
// }

// Test(get_input_length, test_get_input_length)
// {
//     char data[] = "aa;;ff|gg;hh<ii;jj>kk;ll<<mm;nn>>oo;";
//     char *sep[] = { ";", "|","<<", ">>", "<", ">", NULL };
//     int isep = 0;
//     int response = get_input_length(data, sep, 0, &isep);
//     cr_assert_eq(isep, 0);
//     cr_assert_eq(response, 2);
// }

// Test(is_in_str, test_if_in_str)
// {
//     char data[] = "azerty";
//     char sep[] = "r";
//     bool response = is_in_str(sep, data);
//     cr_assert_eq(response, true);
// }

// Test(is_setenv, test_if_setenv)
// {
//     char *data[] = { "setenv", "a","v",NULL };
//     bool response = is_setenv(data);
//     cr_assert_eq(response, true);
// }

// Test(is_standalone_present, test_if_standalone_is_present)
// {
//     char data[] = "/bin/ls";
//     bool response = is_standalone_present(data);
//     cr_assert_eq(response, true);
// }

// Test(is_unsetenv, test_if_unsetenv)
// {
//     char *data[] = { "unsetenv", "e","r",NULL };
//     bool response = is_unsetenv(data);
//     cr_assert_eq(response, true);
// }

// Test(disp_cd_command_not_found, disp_cd_command_not_found, .init = redirect_all_std)
// {
//     char data[] = "eee";
//     disp_cd_command_not_found(data, NULL);
//     cr_assert_stdout_eq_str("eee: No such file or directory.\n");
// }

// Test(disp_command_not_found, test_disp_command_not_found, .init = redirect_all_std)
// {
//     char data[] = "eee";
//     disp_command_not_found(data, NULL);
//     cr_assert_stdout_eq_str("eee: Command not found.\n");
// }

// Test(disp_correct_execve_err, test_disp_correct_execve_err, .init = redirect_all_std)
// {
//     int status = disp_correct_execve_err((-1));
//     cr_assert_stderr_eq_str("Error on Wait\n");
//     cr_assert_eq(status, err);
// }

// Test(disp_debug_map, test_disp_debug_map, .init = redirect_all_std)
// {
//     char *data[] = { "e","l",NULL };
//     char name[] = "m";
//     disp_debug_map(NULL, data, name);
//     cr_assert_stdout_eq_str("m[0] = 'e'\nm[1] = 'l'\n");
// }

// Test(disp_debug_var_int, test_disp_debug_var_int, .init = redirect_all_std)
// {
//     char data[] = "é";
//     int nb = 0;
//     char end[] = "\n";
//     disp_debug_var_int(NULL, data, nb, end);
//     cr_assert_stdout_eq_str("é0\n");
// }

// Test(disp_debug_var_str, test_disp_debug_var_str, .init = redirect_all_std)
// {
//     char data1[] = "é";
//     char data2[] = "r";
//     char data3[] = "\n";
//     disp_debug_var_str(NULL, data1, data2, data3);
//     cr_assert_stdout_eq_str("ér\n");
// }

// Test(disp_env_help, test_disp_env_help, .init = redirect_all_std)
// {
//     disp_env_help();
//     cr_assert_stdout_eq_str("Usage: env[OPTION]...[-][NAME = VALUE]...[COMMAND[ARG]...]\nSet each NAME to VALUE in the environment and run COMMAND.\n\nMandatory arguments to long options are mandatory for short options too.\n - i, --ignore - environment  start with an empty environment\n - 0, --null           end each output line with NUL, not newline\n - u, --unset = NAME     remove variable from the environment\n - C, --chdir = DIR      changeworking directory to DIR\n - S, --split - string = S  process and split S into separate arguments;\nused to pass multiple arguments on shebang lines\n--block - signal[=SIG]    block delivery of SIG signal(s) to COMMAND\n--default - signal[=SIG]reset handling of SIG signal(s) to the default\n--ignore - signal[=SIG]   set handling of SIG signals(s) to do nothing\n--list - signal - handling  list non default signal handling to stderr\n - v, --debug          print verbose information for each processing step\n--help     display this help and exit\n--version  output version information and exit\n\nA mere-implies - i.If no COMMAND, print the resulting environment.\n\nSIG may be a signal name like 'PIPE', or a signal number like '13'.\nWithout SIG, all known signals are included.  Multiple signals can be\ncomma - separated.\n\nGNU coreutils online help : < https ://www.gnu.org/software/coreutils/>\n  Full documentation < https ://www.gnu.org/software/coreutils/ env > \n or available locally via : info '(coreutils) envinvocation'\n");
// }

// Test(disp_file_not_existent, test_disp_file_not_existent, .init = redirect_all_std)
// {
//     char data[] = "/bin/my_ass";
//     disp_file_not_existent(NULL, data);
//     cr_assert_stdout_eq_str("/bin/my_ass: No such file or directory.\n");
// }

// Test(disp_pipe_error, test_disp_pipe_error, .init = redirect_all_std)
// {
//     disp_pipe_error(NULL);
//     cr_assert_stdout_eq_str("Invalid null command.\n");
// }

// Test(disp_prompt, test_disp_prompt, .init = redirect_all_std)
// {
//     disp_prompt(NULL, NULL);
//     cr_assert_stdout_eq_str("[Hello World]> ");
// }

// Test(disp_shell_help, test_disp_shell_help, .init = redirect_all_std)
// {
//     disp_shell_help();
//     cr_assert_stdout_eq_str("GNU bash, version 5.1.0(1) - release - (x86_64 - redhat - linux - gnu)\n\tUsage:	bash[GNU long option][option] ...\n\tbash[GNU long option][option] script - file ...\n\tGNU longoptions: \n\t--debug\n\t--debugger\n\t--dump - po - strings\n\t--dump - strings\n\t--help\n\t--init - file\n\t--login\n\t--noediting\n\t--noprofile\n\t--norc\n\t--posix\n\t--pretty - print\n\t--rcfile\n\t--rpm - requires\n\t--restricted\n\t--verbose\n\t--version\n\tShell options : \n\t - ilrsD or -c command or -O shopt_option(invocation only)\n\t - abefhkmnptuvxBCHP or -o option\n\tType `bash - c \"help set\"' for more information about shell options.\n\tType `bash - c help' for more information about shell builtin commands.\n\tUse the `bashbug' command to report bugs.\n\n\tbash home page: < http ://www.gnu.org/software/bash>\n\tGeneral help using GNU software : < http ://www.gnu.org/gethelp/>\n");
// }
