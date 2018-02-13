/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

int my_clock(sys_t *sys)
{
	if (sys->seconds > 0.4) {
		sfClock_restart(sys->clock);
		if (sys->blen_step >= 17)
			sys->blen_step = 14;
		sys->error_message = 0;
		return (1);
	}
	return (0);
}

void verif_button(sys_t *sys)
{
	if (sys->wsup[3]->key == 0)
		disp_cook(sys);
	else if (sys->wsup[1]->key == 0)
		sys->status = 1;
	else if (sys->wsup[0]->key == 0)
		disp_menu(sys);
	else if (sys->wsup[2]->key == 0)
		disp_recipe(sys);
}

void button_cook(sys_t *sys)
{
	if (sys->wsup[3]->key == 0) {
		sys->wsup[3]->imopen = 1;
		sys->wsup[3]->key = 1;
	} else if (sys->wsup[3]->key == 1) {
		sys->wsup[3]->key = 0;
		sys->wsup[3]->imopen = 0;
	}
}

void button_menu(sys_t *sys)
{
	if (sys->wsup[1]->key == 1) {
		sys->wsup[1]->key = 0;
		if (sys->wsup[3]->imopen == 1) {
			close_other_window(sys, 1);
		}
	}
}

void button_recipe(sys_t *sys)
{
	if (sys->wsup[2]->key == 0) {
		sys->wsup[2]->key = 1;
	} else if (sys->wsup[2]->key == 1) {
		if (sys->wsup[3]->imopen == 1) {
			close_other_window(sys, 2);
		}
		sys->wsup[2]->key = 0;
	}
}

void button_ingredient(sys_t *sys)
{
	if (sys->wsup[0]->key == 0) {
		sys->wsup[0]->key = 1;
	} else if (sys->wsup[0]->key == 1) {
		sys->wsup[0]->key = 0;
		if (sys->wsup[3]->imopen == 1) {
			close_other_window(sys, 0);
		}
	}
}
