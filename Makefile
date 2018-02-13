##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -I include/ -lc_graph_prog

CFLAGT	=	-Wall -Wextra -W -I include/ -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3 -g

LIB	=	-L ./lib/tools/ -ltools

SRC	=	src/main.c			\
		src/action_bar/recipes.c	\
		src/tools/engine.c		\
		src/tools/display.c		\
		src/tools/init.c		\
		src/tools/objects_handling.c	\
		src/game/close_game.c		\
		src/menu/display_menu.c		\
		src/menu/main_menu.c		\
		src/menu/pause_menu.c		\
		src/game/event_handling.c	\
		src/action_bar/button_function.c \
		src/tools/objects_handling2.c	\
		src/error_handling/error_handling.c \
		src/action_bar/button_shop.c	\
		src/game/money_handling.c	\
		src/game/player.c	\
		src/game/blender_and_cocktail.c \
		src/game/cocktail_recipe.c	\
		src/tools/engine2.c		\
		src/tools/display_cocktail_stock.c

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
