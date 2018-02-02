/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Background file
*/

#include "main.h"

void which_mod(sys_t *sys)
{
	if (sys->infinite_mod == 0) {
		scrolling_map(sys);
		check_victory(sys);
	} else
		scrolling_infinite_map(sys);
}

void scrolling_map(sys_t *sys)
{
	int i = 1;

	sys->reset_map += 14;
	for (i = 1; sys->obj[i] != NULL; i++) {
		sys->obj[i]->pos.x = sys->obj[i]->pos.x - 14;
		sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
	}
}

void scrolling_infinite_map(sys_t *sys)
{
	int i = 1;

	sys->reset_map += 14;
	for (i = 1; sys->obj[i] != NULL; i++) {
		if (sys->obj[i]->pos.x <= -200) {
			sys->obj[i]->pos.x = sys->obj[i]->pos.x + 2200;
		}
		sys->obj[i]->pos.x = sys->obj[i]->pos.x - 14;
		sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
	}
}

void draw_background(sys_t *sys)
{
	int i = 3;
	sfVector2f pos_tmp = {0, 0};

	for (i = 3; i < 6; i++) {
		if (sys->bg[i]->pos.x == -1920)
			sys->bg[i]->pos.x = 0;
		pos_tmp.x = sys->bg[3]->pos.x - 1920;
		sfSprite_setPosition(sys->bg[i]->sprite, pos_tmp);
		sfRenderWindow_drawSprite(sys->win, sys->bg[i]->sprite, NULL);
	}
	sys->bg[3]->pos.x = sys->bg[3]->pos.x - 5;
	sys->bg[4]->pos.x = sys->bg[4]->pos.x - 4;
	sys->bg[5]->pos.x = sys->bg[5]->pos.x - 3;
	sfSprite_setPosition(sys->bg[3]->sprite, sys->bg[3]->pos);
	sfSprite_setPosition(sys->bg[4]->sprite, sys->bg[4]->pos);
	sfSprite_setPosition(sys->bg[5]->sprite, sys->bg[5]->pos);
}
