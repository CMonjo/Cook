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
		sys->blen_step = 17;
	}
	if (sys->inventory[i].stock > 0)
		sys->cocktail[sys->blen_step].name = sys->inventory[i].ingredient;
}

int verif_cocktail(sys_t *sys)
{
	if ((sys->cocktail[17].name == sys->inventory[0].ingredient ||
	sys->cocktail[17].name == sys->inventory[1].ingredient) &&
	my_strcmp(sys->cocktail[15].name, "beeroucoffee") == 0 &&
	my_strcmp(sys->cocktail[16].name, "beeroucoffee") == 0)
			return (0);
	return (list_recipe(sys->cocktail[15].name, sys->cocktail[16].name,
	sys->cocktail[17].name));
}

void cocktail_finished(sys_t *sys)
{
	if (sys->blen_step == 17 && verif_cocktail(sys) == 0) {
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
