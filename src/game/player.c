/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

int generate_random_cocktail(void)
{
	int val = 0;

	val = (rand() % (10 - 3 + 1)) + 3;
	return (val);
}

void bubble_other_player(sys_t *sys)
{
	if (sys->player.two == 12) {
		sys->obj[sys->player.p2]->pos.y = sys->obj[12]->pos.y - 150;
		sys->obj[sys->player.p2]->pos.x = sys->obj[12]->pos.x;
		sfSprite_setPosition(sys->obj[sys->player.p2]->sprite,
			sys->obj[sys->player.p2]->pos);
		sfRenderWindow_drawSprite(sys->win,
			sys->obj[sys->player.p2]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->player.p2]->sprite,
			sys->obj[sys->player.p2]->rect);
	}
	if (sys->player.three == 13) {
		sys->obj[sys->player.p3]->pos.y = sys->obj[13]->pos.y - 150;
		sys->obj[sys->player.p3]->pos.x = sys->obj[13]->pos.x;
		sfSprite_setPosition(sys->obj[sys->player.p3]->sprite,
			sys->obj[sys->player.p3]->pos);
		sfRenderWindow_drawSprite(sys->win,
			sys->obj[sys->player.p3]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->player.p3]->sprite,
			sys->obj[sys->player.p3]->rect);
	}
}

void verif_bubble(sys_t *sys)
{
	if (sys->player.one == 11) {
		sys->obj[sys->player.p1]->pos.y = sys->obj[11]->pos.y - 150;
		sys->obj[sys->player.p1]->pos.x = sys->obj[11]->pos.x;
		sfSprite_setPosition(sys->obj[sys->player.p1]->sprite,
			sys->obj[sys->player.p1]->pos);
		sfRenderWindow_drawSprite(sys->win,
			sys->obj[sys->player.p1]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->player.p1]->sprite,
			sys->obj[sys->player.p1]->rect);
	}
	bubble_other_player(sys);
}

void remove_bubble(sys_t *sys, int i)
{
	if (i == 11) {
		sys->player.one = 0;
		sys->player.p1 = 0;
	}
	if (i == 12) {
		sys->player.two = 0;
		sys->player.p2 = 0;
	}
	if (i == 13) {
		sys->player.three = 0;
		sys->player.p3 = 0;
	}
}

void move_back_player(sys_t *sys, int i, int max_value)
{
	remove_bubble(sys, i);
	if (sys->angry[i] == 1) {
		sys->int_money -= 5;
		sys->angry[i] = 0;
	}
	sys->obj[i]->rect.left = 0;
	if (sys->obj[i]->pos.y >= 1110) {
		i == 11 ? sys->player.rp1 = 0 : 0;
		i == 12 ? sys->player.rp2 = 0 : 0;
		i == 13 ? sys->player.rp3 = 0 : 0;
		sys->wave[i] = sys->wave[0];
	}
	if (sys->obj[i]->rect.top >= max_value - sys->obj[i]->rect.height)
		sys->obj[i]->rect.top = sys->obj[i]->rect.height;
	else
		sys->obj[i]->rect.top += sys->obj[i]->rect.height;
	sys->obj[i]->pos.y += 7;
	sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
}
