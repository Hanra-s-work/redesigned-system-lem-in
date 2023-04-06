##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## mul
##

SRC_PARSING	=	./src/parsing/is_in.c	\
				./src/parsing/sort_data.c	\
				./src/parsing/parse_main.c	\
				./src/parsing/get/get_ants.c 	\
				./src/parsing/get/get_room.c 	\
				./src/parsing/get/get_tunnel.c 	\
				./src/parsing/get/get_file_content.c	\
				./src/parsing/free/li_free.c	\
				./src/parsing/free/free_rooms.c	\
				./src/parsing/free/free_array.c	\
				./src/parsing/free/free_parser.c	\
				./src/parsing/free/free_tunnels.c	\
				./src/parsing/free/free_file_content.c	\
				./src/parsing/init/init_rooms.c	\
				./src/parsing/init/init_parser.c	\
				./src/parsing/init/init_tunnels.c	\

SRC_PATH_FINDER	=	./src/path_finder/path_finder_main.c	\

SRC	=	./main.c	\
		./src/is_help.c	\
		./src/sub_main.c	\
		./src/disp/disp_help.c	\
		./src/disp/disp_error.c	\
		./src/disp/disp_rooms.c	\
		./src/disp/disp_parser.c	\
		./src/disp/disp_tunnels.c	\
		./src/disp/disp_file_content.c	\
		./src/disp/disp_pretty_output.c	\

SRC	+=	$(SRC_PARSING)
SRC	+=	$(SRC_PATH_FINDER)

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

MAK	=	$(SILENT)make -C

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

LIBFLAGS	=	-Llib/my/ -lmy	\
				-Llib/linked_lists -llinklist	\
				-Llib/batch_colouriser -lbcolour	\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAK) ./lib
	$(CC) $(OBJ) -o $(NAME) $(LIBFLAGS) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(MAK) ./lib clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_debug
	$(MAK) ./lib fclean

debug: CFLAGS	+=	-g3
debug: NAME	:=	$(NAME)_debug
debug: clean all

re: fclean all

.PHONY: re fclean clean all debug
