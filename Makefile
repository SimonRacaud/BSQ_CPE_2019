##
## EPITECH PROJECT, 2019
## CPE_BSQ_2019
## File description:
## Project makefile
##

SRC	=	main.c		\
		bsq.c		\
		file.c		\
		resolve.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ) LIB
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY :        clean fclean re
