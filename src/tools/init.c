/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void init_inventory(sys_t *sys)
{
	for(int i = 0; i != 8; i++) {
		sys->inventory[i].stock = 0;
		sys->inventory[i].ingredient = malloc(sizeof(char) * 20);
	}
	sys->inventory[0].ingredient = "beer";
	sys->inventory[1].ingredient = "coffee";
	sys->inventory[2].ingredient = "orange";
	sys->inventory[3].ingredient = "pineapple";
	sys->inventory[4].ingredient = "cherry";
	sys->inventory[5].ingredient = "watermelon";
	sys->inventory[6].ingredient = "banana";
	sys->inventory[7].ingredient = "apple";

}

void init_window(sys_t *sys)
{
	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "Cook",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	sys->clock = sfClock_create();
	sys->status = 0;
	sys->select = 1;
	sys->mixor = 0;
	sys->error_message = 0;
	init_inventory(sys);
	init_objects(sys);
	init_text_menu(sys);
	init_button(sys);
	sfRenderWindow_setMouseCursorVisible(sys->win, sfFalse);
}
