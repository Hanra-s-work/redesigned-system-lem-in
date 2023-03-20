##
## EPITECH PROJECT, 2022
## B-CPE-110-PAR-1-1-antman-henry.letellier (Workspace)
## File description:
## Makefile
##

SRC	=	init.c	\
		append.c	\
		get_node.c	\
		free_node.c	\
		get_node_type.c	\
		get_node_data.c	\
		get_list_size.c	\
		get_last_node.c	\
		free_linked_list.c	\
		get_last_node_index.c	\

SILENT	=	@

CC	=	$(SILENT)gcc

RM	=	$(SILENT)rm -f

COPY	=	$(SILENT)cp -f

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra -lm

HEADERFILE	=	linked_lists.h

OBJ	=	$(SRC:.c=.o)

NAME	=	liblinklist.a

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
