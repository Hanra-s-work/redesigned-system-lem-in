##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## jitter jitter
##

SRC	=	./get_input_non_blocking.c	\

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

CFLAGS	=	-I./include

CPPFLAGS	=	-Wall -Wextra

NAME	=	helm_in

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean

.PHONY: fclean all clean re

