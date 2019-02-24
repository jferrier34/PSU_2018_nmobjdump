##
## EPITECH PROJECT, 2019
## PSU_2018_malloc
## File description:
## Makefile
##

NAME	=	my_objdump

CFLAGS	=	-Wall -Wextra -pedantic

SRC	=	./objdump/src/Obj.c		\
		./objdump/src/64.c

OBJ	=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)

all	:	$(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	: fclean all
