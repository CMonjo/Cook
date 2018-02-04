/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void verif_button(sys_t *sys)
{
	printf("%s\n", "dans verif button");
	if (sys->wsup[3]->key == 0) // 3 = cook
	{
		printf("%s\n", "dans le cook");
		disp_cook(sys);
	}
	// else if (sys->wsup[1]->key == 0) // 1 = pause
	else if (sys->wsup[0]->key == 0) // 0 = market
	{
		printf("%s\n", "au market");
		disp_recipe(sys);
	}
}

void button_cook(sys_t *sys)
{
	if (sys->wsup[3]->key == 0) {
		sys->wsup[3]->key = 1;
	} else if (sys->wsup[3]->key == 1) {
		sys->wsup[3]->key = 0;
	}
}

void button_menu(sys_t *sys)
{
	if (sys->wsup[1]->key == 0) {
		sys->wsup[1]->key = 1;
	} else if (sys->wsup[1]->key == 1) {
		sys->wsup[1]->key = 0;
	}
}

void button_recipe(sys_t *sys)
{
	if (sys->wsup[0]->key == 0) {
		sys->wsup[0]->key = 1;
	} else if (sys->wsup[0]->key == 1) {
		sys->wsup[0]->key = 0;
	}
}

void button_ingredient(sys_t *sys)
{
	if (sys->wsup[0]->key == 0) {
		sys->wsup[0]->key = 1;
	} else if (sys->wsup[0]->key == 1) {
		sys->wsup[0]->key = 0;
	}
}
