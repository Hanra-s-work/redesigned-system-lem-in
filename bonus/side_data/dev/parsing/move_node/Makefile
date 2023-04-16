##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## jitter jitter
##

SRC	=	./main.c	\

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

MAK	=	$(SILENT)make -s -C

CFLAGS	=	-I./include

CPPFLAGS	=	-Wall -Wextra

OBJ	=	$(SRC:.c=.o)

LIBS	=	-L./lib/linked_lists -llinklist

NAME	=	"helm_in"

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAK) ./lib/linked_lists
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LIBS)

clean:
	$(MAK) ./lib/linked_lists clean
	$(RM) $(OBJ)

fclean: clean
	$(MAK) ./lib/linked_lists fclean
	$(RM) $(NAME)
	$(RM) $(NAME)_debug

re: fclean all clean

debug:	CFLAGS	+=	-g3
debug:	NAME	:=	$(NAME)_debug
debug:	all

.PHONY: fclean all clean re

