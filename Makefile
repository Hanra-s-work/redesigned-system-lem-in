##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## mul
##

##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## mul
##

SRC_PARSING	=	./src/parsing/sort_data.c	\
				./src/parsing/parse_main.c	\
				./src/parsing/count_char.c	\
\
				./src/parsing/is/is_in.c	\
				./src/parsing/is/is_corr_nb_args.c	\
\
				./src/parsing/get/get_ants.c 	\
				./src/parsing/get/get_room.c 	\
				./src/parsing/get/get_tunnel.c 	\
				./src/parsing/get/get_char_index.c	\
				./src/parsing/get/get_file_content.c	\
\
				./src/parsing/free/li_free.c	\
				./src/parsing/free/free_rooms.c	\
				./src/parsing/free/free_array.c	\
				./src/parsing/free/free_parser.c	\
				./src/parsing/free/free_tunnels.c	\
				./src/parsing/free/free_file_content.c	\
\
				./src/parsing/init/init_rooms.c	\
				./src/parsing/init/init_parser.c	\
				./src/parsing/init/init_tunnels.c	\
				./src/parsing/init/init_tmp_room_track.c	\

SRC_PATH_FINDER	=	./src/path_finder/path_finder_main.c	\

SRC	=	./src/is_help.c	\
		./src/sub_main.c	\
		./src/disp/disp_help.c	\
		./src/disp/disp_error.c	\
		./src/disp/disp_rooms.c	\
		./src/disp/disp_parser.c	\
		./src/disp/disp_tunnels.c	\
		./src/disp/disp_file_content.c	\
		./src/disp/disp_pretty_output.c	\

MAIN_SRC	=	./main.c

SRC	+=	$(SRC_PARSING)
SRC	+=	$(SRC_PATH_FINDER)

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

MAK	=	$(SILENT)make -C

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include/

OBJ	=	$(SRC:.c=.o)

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

NAME	=	lem_in

TEST_FILES	=	./tests/test_lem_in.c

LIBFLAGS	=	-Llib/my/	\
				-Llib/linked_lists	\
				-Llib/batch_colouriser	\

LIBS	=	-lmy	\
			-llinklist	\
			-lbcolour	\

all:	$(NAME)

$(NAME):	update_libs $(OBJ) $(MAIN_OBJ)
	$(CC) $(OBJ) $(MAIN_OBJ) -o $(NAME) $(LIBFLAGS) $(LIBS) $(CPPFLAGS)

update_libs:
	$(MAK) ./lib

clean_tests:
	$(SILENT)find . \( -iname "*.gcno" -o -iname "*.gcda" -type f \) -delete

clean:
	$(RM) $(OBJ)
	$(RM) $(MAIN_OBJ)
	$(MAK) ./lib clean

fclean: clean clean_tests
	$(RM) $(NAME)
	$(RM) $(NAME)_debug
	$(RM) $(NAME)_tests
	$(MAK) ./lib fclean

debug: CFLAGS	+=	-g3
debug: NAME	:=	$(NAME)_debug
debug: clean all

re: fclean all

compile_tests: CPPFLAGS	+=	--coverage
compile_tests: LIBS	+=	-lcriterion
compile_tests: NAME	:=	$(NAME)_tests
compile_tests: clean_tests
compile_tests: update_libs $(OBJ)
	$(CC) -o $(NAME) $(TEST_FILES) $(OBJ) $(CPPFLAGS) $(LIBFLAGS) $(LIBS)
	$(SILENT)./$(NAME)

tests_run: compile_tests

test_coverage: $(OBJ)
test_coverage:	tests_run
test_coverage:
	$(SILENT)gcovr .

.PHONY: re fclean clean all debug update_libs	\
		clean_tests compile_tests tests_run	\
		test_coverage
