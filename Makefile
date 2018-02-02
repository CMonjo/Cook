##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I include/ -lc_graph_prog

CFLAGT	=	-Wall -Wextra -W -I include/ -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

LIB	=	-L ./lib/tools/ -ltools

SRC	=	src/main.c		\
		src/engine.c		\
		src/close_game.c	\
		src/recipes.c	\
		src/objects_handling.c


OBJ	=	$(SRC:.c=.o)

NAME	=	my_cook

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/tools/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C ./lib/tools/

cook: $(OBJ)
	make -C ./lib/tools/
	$(CC) $(OBJ) $(CFLAGT) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C ./lib/tools/
clean:
	rm -f $(OBJ)
	make clean -C ./lib/tools/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/tools/

re: fclean all
