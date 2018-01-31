##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Library my
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I ../../include/

SRC	=	my_putchar.c		\
		my_getnbr.c		\
		my_str_isnum.c		\
		my_putstr.c		\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtools.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
