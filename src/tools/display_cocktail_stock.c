/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Sprite management file
*/

#include "main.h"

void disp_cocktail_stock(sys_t *sys)
{
	sys->txt[32] = set_text("assets/font/bold.ttf",
	(sfVector2f){700, 80}, sys->inventory[7].cstock, 50);
	for (int i = 25; i != 33; i++) {
		sfText_setColor(sys->txt[i]->text, sfBlack);
		sfRenderWindow_drawText(sys->win, sys->txt[i]->text, NULL);
	}
}

void set_cocktail_stock(sys_t *sys)
{
	for (int i = 0; i != 8; i++) {
		sys->inventory[i].cstock = init_money(sys->drink[i].stock);
	}
	sys->txt[25] = set_text("assets/font/bold.ttf",
	(sfVector2f){360, 10}, sys->inventory[0].cstock, 50);
	sys->txt[26] = set_text("assets/font/bold.ttf",
	(sfVector2f){470, 10}, sys->inventory[1].cstock, 50);
	sys->txt[27] = set_text("assets/font/bold.ttf",
	(sfVector2f){590, 12}, sys->inventory[2].cstock, 50);
	sys->txt[28] = set_text("assets/font/bold.ttf",
	(sfVector2f){700, 10}, sys->inventory[3].cstock, 50);
	sys->txt[29] = set_text("assets/font/bold.ttf",
	(sfVector2f){360, 80}, sys->inventory[4].cstock, 50);
	sys->txt[30] = set_text("assets/font/bold.ttf",
	(sfVector2f){470, 78}, sys->inventory[5].cstock, 50);
	sys->txt[31] = set_text("assets/font/bold.ttf",
	(sfVector2f){590, 79}, sys->inventory[6].cstock, 50);
	disp_cocktail_stock(sys);
}
