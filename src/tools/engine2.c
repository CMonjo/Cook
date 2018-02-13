/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Engine file
*/

#include "main.h"

drink_t *add_cocktail_button(sfVector2f pos, sfVector2f size, sfIntRect square,
void (*func)())
{
	drink_t *new = malloc(sizeof(sys_t));
	if (new == NULL)
		return (NULL);
	new->square = square;
	new->pos = pos;
	new->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(new->rect, pos);
	sfRectangleShape_setSize(new->rect, size);
	sfRectangleShape_setFillColor(new->rect, (sfColor){255, 0, 0, 0});
	new->callback = func;
	return (new);
}

void sell_cocktail(sys_t *sys, int i)
{
	printf("i = %dcocktail demander = %s et moi je lui donne %s j'en ai %d\n", i, sys->obj[sys->player.p1]->name, sys->drink[i].name, sys->drink[i].stock);
	if (sys->drink[i].stock > 0 && my_strcmp(sys->obj[sys->player.p1]->name,
	sys->drink[i].name) == 0)
	{
		sys->int_money += 10;
		sys->drink[i].stock -= 1;
		sys->wave = 0;
	}
	else if (sys->drink[i].stock > 0 && my_strcmp(sys->obj[sys->player.p2]->name,
	sys->drink[i].name) == 0)
	{
		sys->int_money += 10;
		sys->drink[i].stock -= 1;
		sys->wave = 0;
	}
	else if (sys->drink[i].stock > 0 && my_strcmp(sys->obj[sys->player.p3]->name,
	sys->drink[i].name) == 0)
	{
		sys->int_money += 10;
		sys->drink[i].stock -= 1;
		sys->wave = 0;
	}
}

void init_cocktail_button(sys_t *sys)
{
	sys->drink[0] = *add_cocktail_button((sfVector2f){310, 10},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[1] = *add_cocktail_button((sfVector2f){420, 10},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[2] = *add_cocktail_button((sfVector2f){540, 12},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[3] = *add_cocktail_button((sfVector2f){650, 10},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[4] = *add_cocktail_button((sfVector2f){310, 80},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[5] = *add_cocktail_button((sfVector2f){420, 78},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[6] = *add_cocktail_button((sfVector2f){540, 79},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
	sys->drink[7] = *add_cocktail_button((sfVector2f){650, 80},
	(sfVector2f){50, 50}, (sfIntRect){0, 0, 80, 80}, sell_cocktail);
}
