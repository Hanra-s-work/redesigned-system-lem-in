##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## mul
##

SRC	=	./src/main.c	\

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

MAK	=	$(SILENT)make -C

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-iquote ./include/

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

LIBFLAGS	=	-Llib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAK) ./lib
	$(CC) $(SRC) -o $(NAME) $(LIBFLAGS) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(MAK) ./lib clean

fclean: clean
	$(RM) $(NAME)
	$(MAK) ./lib fclean

re: fclean all

.PHONY: re fclean clean all
