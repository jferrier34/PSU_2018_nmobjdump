##
## EPITECH PROJECT, 2019
## PSU_2018_malloc
## File description:
## Makefile
##

all	:	$(NAME) $(NAME2)

.PHONY : all

NAME	=	my_objdump

NAME2	=	my_nm

CFLAGS	=	-Wall -Wextra -pedantic

SRC	=	./objdump/src/Obj.c		\
		./objdump/src/64.c

SRC2	=	./nm/src/nm.c

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(CFLAGS) $(OBJ)

$(NAME2)	:	$(OBJ2)
		gcc -o $(NAME2) $(CFLAGS) $(OBJ2)

all	:	$(NAME) $(NAME2)

clean	:
		rm -f $(OBJ) $(OBJ2)

fclean	:	clean
		rm -f $(NAME) $(NAME2)

re	: fclean all