/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Engine file
*/

#include "main.h"

void reset_option_second_client(sys_t *sys)
{
	sys->int_money += 10;
	sys->wave[12] = 0;
	sys->angry[12] = 0;
	sys->player.p2 = 0;
	sys->player.two = 0;
}


void verif_third_client(sys_t *sys, int i)
{
	if (sys->wave[13] > 0 && sys->wave[13] < 800 &&
		sys->drink[i].stock > 0 &&
		my_strcmp(sys->obj[sys->player.p3]->name,
			sys->drink[i].name) == 0) {
		sys->int_money += 10;
		sys->drink[i].stock -= 1;
		sys->wave[13] = 0;
		sys->angry[13] = 0;
		sys->player.p3 = 0;
		sys->player.three = 0;
	}
}

void sell_cocktail(sys_t *sys, int i)
{
	if (sys->wave[11] > 0 && sys->wave[11] < 800 && sys->drink[i].stock > 0
		&& my_strcmp(sys->obj[sys->player.p1]->name,
			sys->drink[i].name) == 0) {
		sys->int_money += 10;
		sys->drink[i].stock -= 1;
		sys->wave[11] = 0;
		sys->angry[11] = 0;
		sys->player.p1 = 0;
		sys->player.one = 0;
	}
	else if (sys->wave[12] > 0 && sys->wave[12] < 800 &&
		sys->drink[i].stock > 0 &&
		my_strcmp(sys->obj[sys->player.p2]->name,
			sys->drink[i].name) == 0) {
		sys->drink[i].stock -= 1;
		reset_option_second_client(sys);
	} else
		verif_third_client(sys, i);
}
