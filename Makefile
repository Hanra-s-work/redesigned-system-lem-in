##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## mul
##

SRC	=	./main.c	\
		./src/sub_main.c	\

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

MAK	=	$(SILENT)make -C

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

LIBFLAGS	=	-Llib/my/ -lmy	\
				-Llib/linked_lists -llinklist

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAK) ./lib
	$(CC) $(SRC) -o $(NAME) $(LIBFLAGS) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(MAK) ./lib clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_debug
	$(MAK) ./lib fclean

re: fclean all

debug: CFLAGS	+=	-g3
debug: NAME	:=	$(NAME)_debug
debug: clean all

.PHONY: re fclean clean all debug
