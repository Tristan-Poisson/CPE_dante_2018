##
## EPITECH PROJECT, 2019
## Makefile matchstick
## File description:
## compile programe
##

all:
	make -C generator
	make -C solver

clean:
	make -C	generator clean
	make -C solver clean

fclean:	clean
	make -C	generator fclean
	make -C solver fclean

re: fclean all

.PHONY: all lib clean fclean re
