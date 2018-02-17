/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init drink file
*/

#include "main.h"

void init_drink_name(sys_t *sys)
{
	int i = 0;

	for (i = 0; i != 9; i++) {
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
	init_drink_name(sys);
}
