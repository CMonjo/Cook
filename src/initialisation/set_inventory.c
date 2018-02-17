/*
** EPITECH PROJECT, 2017
** CSFML MyCook
** File description:
** Set inventory file
*/

#include "main.h"

void init_string_stock(sys_t *sys)
{
	for (int i = 0; i != 8; i++) {
		sys->inventory[i].cstock = malloc(sizeof(char) * 30);
		sys->inventory[i].cstock = "0";
	}
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
