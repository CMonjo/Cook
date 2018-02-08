/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void blender_verif(sys_t *sys, int i)
{
	if (i == 0 || i == 1)
		sys->blen_step = 17;
	sys->cocktail[sys->blen_step].name = sys->inventory[i].ingredient;
	printf("ingredient = %s\n", sys->cocktail[sys->blen_step].name);
}

void cocktail_finished(sys_t *sys)
{
	if (sys->blen_step == 17) {
		printf("vous avez utiliser : \n%s\n%s\n%s\n", sys->cocktail[15].name, sys->cocktail[16].name,
		sys->cocktail[17].name);
		sfRenderWindow_drawSprite(sys->win, sys->obj[18]->sprite, NULL);
	}
}

void blender_disp(sys_t *sys)
{
	if (sys->blen_step >= 14 && sys->blen_step <= 17) {
		sfRenderWindow_drawSprite(sys->win,
		sys->obj[sys->blen_step]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->blen_step]->sprite,
		sys->obj[sys->blen_step]->rect);
		cocktail_finished(sys);
	} else if (sys->blen_step >= 17) {
		sys->blen_step = 14;
		sfRenderWindow_drawSprite(sys->win,
		sys->obj[sys->blen_step]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->blen_step]->sprite,
		sys->obj[sys->blen_step]->rect);
	}
	close_other_window(sys, 3);
}
