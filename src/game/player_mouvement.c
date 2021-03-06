/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void check_random(sys_t *sys)
{
	if (sys->player.rp1 == 1)
		move_player(sys, 11, 1045);
	if (sys->player.rp2 == 1)
		move_player(sys, 12, 1045);
	if (sys->player.rp3 == 1)
		move_player(sys, 13, 1045);
}

void set_move_player(sys_t *sys)
{
	if (sys->player.rp1 != 1)
		sys->player.rp1 = (rand() % (150 - 1 + 1)) + 1;
	if (sys->player.rp2 != 1)
		sys->player.rp2 = (rand() % (150 - 1 + 1)) + 1;
	if (sys->player.rp3 != 1)
		sys->player.rp3 = (rand() % (150 - 1 + 1)) + 1;
	check_random(sys);
}

void player_detection(sys_t *sys, int i)
{
	if (i == 11) {
		sys->player.one = i;
		sys->angry[11] = 1;
		if (sys->player.p1 == 0)
			sys->player.p1 = generate_random_cocktail();
	}
	if (i == 12) {
		sys->player.two = i;
		sys->angry[12] = 1;
		if (sys->player.p2 == 0)
			sys->player.p2 = generate_random_cocktail();
	}
	if (i == 13) {
		sys->player.three = i;
		sys->angry[13] = 1;
		if (sys->player.p3 == 0)
			sys->player.p3 = generate_random_cocktail();
	}
}

void move_player(sys_t *sys, int i, int max_value)
{
	if (sys->wave[i] == 0)
		move_back_player(sys, i, max_value);
	else if (sys->obj[i]->pos.y >= 200 && sys->wave[i] != 0) {
		sys->obj[i]->rect.left = 73;
		if (sys->obj[i]->rect.top >=
			max_value - sys->obj[i]->rect.height)
			sys->obj[i]->rect.top = sys->obj[i]->rect.height;
		else
			sys->obj[i]->rect.top += sys->obj[i]->rect.height;
		sys->obj[i]->pos.y += -7;
		if (sys->obj[i]->pos.y <= -150)
			sys->obj[i]->pos.y = 1150;
		sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
	} else {
		player_detection(sys, i);
		sys->wave[i]--;
	}
}
