##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -g -I include/ -lc_graph_prog

CFLAGT	=	-Wall -Wextra -W -g -I include/ -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

LIB	=	-L ./lib/tools/ -ltools

SRC	=	src/main.c				\
		src/action_bar/recipes.c		\
		src/action_bar/sell_options.c		\
		src/engine/text_obj.c			\
		src/engine/windows.c			\
		src/tools/display.c			\
		src/initialisation/init_drink.c		\
		src/initialisation/set_inventory.c	\
		src/tools/objects_handling.c		\
		src/game/close_game.c			\
		src/menu/display_menu.c			\
		src/menu/main_menu.c			\
		src/menu/end_game_menu.c		\
		src/menu/pause_menu.c			\
		src/game/event_handling.c		\
		src/action_bar/button_function.c 	\
		src/error_handling/error_handling.c 	\
		src/action_bar/button_shop.c		\
		src/game/money_handling.c		\
		src/game/player.c			\
		src/game/player_mouvement.c		\
		src/game/blender_and_cocktail.c 	\
		src/initialisation/init_obj.c		\
		src/initialisation/init_text.c		\
		src/initialisation/init_window_sup.c	\
		src/initialisation/init_button.c	\
		src/game/cocktail_recipe.c		\
		src/initialisation/set_options.c	\
		src/game/reset_options.c

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
