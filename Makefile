##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	src/my_file.c \
		src/my_engine.c \
		src/my_get.c \
		src/my_report.c \
		src/my_put.c \
		src/my_color.c \
		src/my_utils.c \
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):
	make -C bonus
	make -C tests
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -g -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
