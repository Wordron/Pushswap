##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC		=	main.c	\
			operations.c	\
			check_array.c	\

OBJ    =    $(SRC:.c=.o)

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(OBJ) -Llib -lmy

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
