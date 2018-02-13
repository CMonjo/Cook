/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void init_drink_stock(sys_t *sys)
{
	sys->drink[0] = *add_cocktail_button((sfVector2f){310, 10},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[1] = *add_cocktail_button((sfVector2f){420, 10},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[2] = *add_cocktail_button((sfVector2f){540, 12},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[3] = *add_cocktail_button((sfVector2f){650, 10},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[4] = *add_cocktail_button((sfVector2f){310, 80},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[5] = *add_cocktail_button((sfVector2f){420, 78},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[6] = *add_cocktail_button((sfVector2f){540, 79},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[7] = *add_cocktail_button((sfVector2f){650, 80},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	for (int i = 0; i != 9; i++) {
		sys->drink[i].stock = 0;
		sys->drink[i].name = malloc(sizeof(char) * 20);
	}
	sys->drink[0].name = "ccoffee";
	sys->drink[1].name = "cwatermelon";
	sys->drink[2].name = "ccherry";
	sys->drink[3].name = "cbananas";
	sys->drink[4].name = "cbeer";
	sys->drink[5].name = "cpineapple";
	sys->drink[6].name = "corange";
	sys->drink[7].name = "capple";
}

void init_cocktail(sys_t *sys)
{
	sys->cocktail[0].name = "beer";
	sys->cocktail[1].name = "coffee";
	sys->cocktail[2].name = "cherry";
	sys->cocktail[3].name = "watermelon";
	sys->cocktail[4].name = "bananas";
	sys->cocktail[5].name = "pineapple";
	sys->cocktail[6].name = "apple";
	sys->cocktail[7].name = "orange";
	sys->cocktail[15].name = "noname";
	sys->cocktail[16].name = "noname";
	sys->cocktail[17].name = "noname";
}

void init_inventory(sys_t *sys)
{
	for (int i = 0; i != 8; i++) {
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

void init_player_system(sys_t *sys)
{
	sys->player.one = 0;
	sys->player.two = 0;
	sys->player.three = 0;
	sys->player.p1 = 0;
	sys->player.p2 = 0;
	sys->player.p3 = 0;
	sys->player.rp1 = 0;
	sys->player.rp2 = 0;
	sys->player.rp3 = 0;
}

void init_string_stock(sys_t *sys)
{
	for (int i = 0; i != 8; i++) {
		sys->inventory[i].cstock = malloc(sizeof(char) * 30);
		sys->inventory[i].cstock = "0";
	}
}

void init_window(sys_t *sys)
{
	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "Cook",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	srand(time(NULL));
	sys->clock = sfClock_create();
	sys->clock_player = sfClock_create();

	sys->m_game = sfMusic_createFromFile("assets/music/game.wav");
	sys->m_menu = sfMusic_createFromFile("assets/music/select.wav");
	sys->m_button = sfMusic_createFromFile("assets/music/button.wav");

	sys->status = 0;
	sys->blen_step = 14;
	sys->select = 1;
	sys->blender = 0;
	sys->error_message = 0;
	sys->money = malloc(sizeof(char) * 10);
	sys->money = NULL;
	sys->int_money = 50;
	init_string_stock(sys);
	init_player_system(sys);
	init_inventory(sys);
	init_objects(sys);
	init_text_menu(sys);
	init_button(sys);
	sfRenderWindow_setMouseCursorVisible(sys->win, sfFalse);
}
