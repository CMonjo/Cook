/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Restart game file
*/

#include "main.h"

void restart_game_loop(sys_t *sys)
{
	int i = 0;

	sys->status = 3;
	sys->game_status = 0;
	sys->int_score = 0;
	for (i = 1; sys->obj[i] != NULL; i++) {
		if (sys->infinite_mod == 0) {
			sys->obj[i]->pos.x = sys->obj[i]->pos.x
			+ sys->reset_map;
		}
		else
			sys->obj[i]->pos.x = sys->obj[i]->pos.x - 1020;
		sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
	}
	sys->reset_map = 0;
}
