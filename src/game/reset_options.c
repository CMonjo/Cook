/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Game detection file
*/

#include "main.h"

void reset_game(sys_t *sys)
{
	int i = 0;

	for (i = 11; i != 14; i++) {
		sys->wave[i] = 800;
		sys->angry[i] = 1;
		sys->obj[i]->pos.y = 1100;
		sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
	}
	for (int i = 0; i != 4; i++) {
		sys->wsup[i]->imopen = 0;
		sys->wsup[i]->key = 1;
	}
	sys->player.one = 0;
	sys->player.two = 0;
	sys->player.three = 0;
	sys->player.p1 = 0;
	sys->player.p2 = 0;
	sys->player.p3 = 0;
	sys->player.rp1 = 0;
	sys->player.rp2 = 0;
	sys->player.rp3 = 0;
	for (int i = 0; i != 8; i++) {
		sys->inventory[i].cstock = "0";
		sys->inventory[i].stock = 0;
		sys->drink[i].stock = 0;
	}
	sys->blen_step = 14;
	sys->select = 1;
	sys->blender = 0;
	sys->error_message = 0;
	sys->int_money = 50;
	sys->status = 0;
}
