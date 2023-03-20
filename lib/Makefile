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

clean:
	$(MAK) ./my clean
	$(MAK) ./linked_lists clean

fclean:
	$(MAK) ./my fclean
	$(MAK) ./linked_lists fclean

debug:
	$(MAK) ./my debug
	$(MAK) ./linked_lists debug

re: fclean all

.PHONY: all clean fclean debug re
