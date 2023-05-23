##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## lib
##

SRC	=	./my_putstr.c	\
		./my_strlen.c	\
		./my_getnbr.c	\
		./my_strcmp.c	\
		./my_strdup.c	\
		./my_strcpy.c	\
		./my_strcat.c	\
		./my_putchar.c	\
		./my_put_nbr.c	\
		./my_strncmp.c	\
		./my_strncpy.c	\
		./my_str_isnum.c 	\
		./my_show_word_array.c	\
		./my_str_to_word_array.c	\

CC	=	gcc

RM	=	rm -f

CFLAG	=	-Wall -Wextra

COPY	=	$(SILENT)cp -f

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	$(COPY) my.h ../../include/
	ar rc $(NAME) $(OBJ)
	$(COPY) $(NAME) ../$(NAME)
	$(COPY) $(NAME) ../../$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
	$(RM) ../../$(NAME)

re: fclean all

.PHONY: re all fclean clean
