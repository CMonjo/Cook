/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void blender_verif(sys_t *sys, int i)
{
	if ((i == 0 || i == 1) && sys->blen_step == 15) {
		sys->cocktail[15].name = "beeroucoffee";
		sys->cocktail[16].name = "beeroucoffee";
		sys->cocktail[17].name = sys->inventory[i].ingredient;
		sys->blen_step = 17;
	}
}

int verif_cocktail(sys_t *sys)
{
	if ((sys->cocktail[17].name == sys->inventory[0].ingredient ||
	sys->cocktail[17].name == sys->inventory[1].ingredient) &&
	my_strcmp(sys->cocktail[15].name, "beeroucoffee") == 0 &&
	my_strcmp(sys->cocktail[16].name, "beeroucoffee") == 0) {
		if (my_strcmp(sys->cocktail[17].name, "beer") == 0)
			sys->drink[4].stock++;
		if (my_strcmp(sys->cocktail[17].name, "coffee") == 0)
			sys->drink[0].stock++;
		reinit_ingredient(sys);
		return (0);
	}
	return (list_recipe(sys, sys->cocktail[15].name, sys->cocktail[16].name,
	sys->cocktail[17].name));
}

void cocktail_finished(sys_t *sys)
{
	if (sys->blen_step == 17 && (verif_cocktail(sys) == 0 ||
	verif_cocktail(sys) == 10)) {
		sfRenderWindow_drawSprite(sys->win, sys->obj[18]->sprite, NULL);
	}
	else if (sys->blen_step == 17 && verif_cocktail(sys) == 1)
		sfRenderWindow_drawSprite(sys->win, sys->obj[19]->sprite, NULL);
}

void blender_disp(sys_t *sys)
{
	if (sys->blen_step >= 14 && sys->blen_step <= 17) {
		sfRenderWindow_drawSprite(sys->win,
		sys->obj[sys->blen_step]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->blen_step]->sprite,
		sys->obj[sys->blen_step]->rect);
		cocktail_finished(sys);
	}
	close_other_window(sys, 3);
}
