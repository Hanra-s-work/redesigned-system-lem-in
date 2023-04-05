##
## EPITECH PROJECT, 2022
## B-CPE-200-PAR-2-1-lemin-thomas.lebouc
## File description:
## Makefile
##

SILENT	=	@

MAK	=	$(SILENT)make -C

all:
	$(MAK) ./my
	$(MAK) ./linked_lists
	$(MAK) ./batch_colouriser

clean:
	$(MAK) ./my clean
	$(MAK) ./linked_lists clean
	$(MAK) ./batch_colouriser clean

fclean:
	$(MAK) ./my fclean
	$(MAK) ./linked_lists fclean
	$(MAK) ./batch_colouriser fclean

debug:
	$(MAK) ./my debug
	$(MAK) ./linked_lists debug
	$(MAK) ./batch_colouriser debug

re: fclean all

.PHONY: all clean fclean debug re
