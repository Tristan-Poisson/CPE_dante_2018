##
## EPITECH PROJECT, 2019
## Makefile dante
## File description:
## compile programe
##

NAME	=	generator

SRC	=	main.c \
		gen.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all lib clean fclean re
