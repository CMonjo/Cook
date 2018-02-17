/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init windowsup file
*/

#include "main.h"

void init_windowsup(sys_t *sys)
{
	int i = 0;

	for (i = 0; i != 5; i++)
		sys->wsup[i] = NULL;
	sys->wsup[0] = add_sup("assets/img/action_bar/marketplace.png",
	(sfVector2f){400, 200}, (sfIntRect){0, 0, 1096, 780});
	sys->wsup[1] = add_sup("assets/img/action_bar/pause_menu.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->wsup[2] = add_sup("assets/img/action_bar/recipes.png",
	(sfVector2f){400, 200}, (sfIntRect){0, 0, 1096, 780});
	sys->wsup[3] = add_sup("assets/img/food/newbar.png",
	(sfVector2f){10, 0}, (sfIntRect){0, 0, 100, 1080});
}
