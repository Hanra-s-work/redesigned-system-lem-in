##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
## File description:
## Makefile
##

SRC	=	./set_colour.c	\
		./init_colours.c	\
		./free_colours.c	\
		./show_all_colours.c	\
		./set_err_out_colour.c	\
		./dependencies/bc_atoi.c	\
		./dependencies/bc_itoa.c	\
		./dependencies/bc_memset.c	\
		./dependencies/bc_putstr.c	\
		./dependencies/bc_strcat.c	\
		./dependencies/bc_strcmp.c	\
		./dependencies/bc_strlen.c	\
		./dependencies/bc_puterror.c	\
		./dependencies/bc_strlowcase.c	\

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

COPY	=	$(SILENT)cp -f

CPPFLAGS	=	-I../../include

CFLAGS	=	-Wall -Wextra -lm

HEADERFILE	=	batch_colouriser.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libbcolour.a

DYNAMIC	=	$(patsubst %.a,%.so,$(NAME))

all: update_includes $(NAME) update_archive

$(NAME):	$(OBJ)
	$(SILENT)ar rc $(NAME) $(OBJ)

update_archive:
	$(COPY) $(NAME) ../

update_dynamic_archive:
	$(COPY) $(DYNAMIC) ../

update_includes:
	$(COPY) $(HEADERFILE) ../../include

shared:	$(DYNAMIC) update_includes update_dynamic_archive

$(DYNAMIC):	$(OBJ)
	$(CC) -shared -o $(DYNAMIC) $(OBJ)

all_types:	all	shared

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DYNAMIC)
	$(RM) ../$(NAME)
	$(RM) ../$(DYNAMIC)

re:	fclean	all

re_share:	fclean	shared

re_all:	fclean	all	shared

.PHONY:	all	shared	all_types	\
		update_archive	update_dynamic_archive	\
		clean	fclean	\
		re	re_share	re_all
