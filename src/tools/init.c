/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void init_cocktail(sys_t *sys)
{
	for (int i = 0; i != 10; i++) {
		sys->cocktail[i].stock = 0;
		sys->cocktail[i].name = malloc(sizeof(char) * 20);
	}
	sys->cocktail[0].name = "Beer";
	sys->cocktail[1].name = "Coffee";
	sys->cocktail[2].name = "fuck on the beach";
	sys->cocktail[3].name = "vodka apple";
	sys->cocktail[4].name = "vodka orange";
	sys->cocktail[5].name = "vodka lemon";
	sys->cocktail[6].name = "vodka pineapple";
	sys->cocktail[7].name = "vodka vodka";
}

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
	sys->inventory[0].price = 5;
	sys->inventory[1].price = 3;
	sys->inventory[2].price = 1;
	sys->inventory[3].price = 2;
	sys->inventory[4].price = 1;
	sys->inventory[5].price = 2;
	sys->inventory[6].price = 1;
	sys->inventory[7].price = 1;
}

void init_window(sys_t *sys)
{
	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "Cook",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	sys->clock = sfClock_create();
	sys->clock_player = sfClock_create();
	sys->status = 0;
	sys->blen_step = 14;
	sys->select = 1;
	sys->blender = 0;
	sys->money = malloc(sizeof(char) * 10);
	sys->int_money = 50;
	sys->error_message = 0;
	sys->player.pass = 0;
	init_inventory(sys);
	init_objects(sys);
	init_text_menu(sys);
	init_button(sys);
	sfRenderWindow_setMouseCursorVisible(sys->win, sfFalse);
}
