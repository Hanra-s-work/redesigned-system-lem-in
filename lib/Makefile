##
## EPITECH PROJECT, 2022
## B-CPE-200-PAR-2-1-lemin-thomas.lebouc
## File description:
## Makefile
##

SILENT	=	@

MAK	=	$(SILENT)make -C

TMP_LIB	=	../bonus/side_data/dev/parsing/move_node/lib/linked_lists

all:
	$(MAK) ./my
	$(MAK) ./linked_lists
	$(MAK) ./batch_colouriser
	echo "other libs built"
	$(MAK) $(TMP_LIB)
	echo "tmp_lib built"

clean:
	$(MAK) ./my clean
	$(MAK) ./linked_lists clean
	$(MAK) ./batch_colouriser clean
	$(MAK) $(TMP_LIB) clean

fclean:
	$(MAK) ./my fclean
	$(MAK) ./linked_lists fclean
	$(MAK) ./batch_colouriser fclean
	$(MAK) $(TMP_LIB) fclean

debug:
	$(MAK) ./my debug
	$(MAK) ./linked_lists debug
	$(MAK) ./batch_colouriser debug
	$(MAK) $(TMP_LIB) debug

re: fclean all

.PHONY: all clean fclean debug re
