/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Sprite management file
*/

#include "main.h"

void disp_cocktail_stock(sys_t *sys)
{

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
	sfText_setString(sys->txt[25]->text, sys->inventory[0].cstock);
	sfText_setString(sys->txt[26]->text, sys->inventory[1].cstock);
	sfText_setString(sys->txt[27]->text, sys->inventory[2].cstock);
	sfText_setString(sys->txt[28]->text, sys->inventory[3].cstock);
	sfText_setString(sys->txt[29]->text, sys->inventory[4].cstock);
	sfText_setString(sys->txt[30]->text, sys->inventory[5].cstock);
	sfText_setString(sys->txt[31]->text, sys->inventory[6].cstock);
	sfText_setString(sys->txt[32]->text, sys->inventory[7].cstock);
	disp_cocktail_stock(sys);
}
