/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Engine file
*/

#include "main.h"

drink_t *add_cocktail_button(sfVector2f pos, sfVector2f size, sfIntRect square,
void (*func)(void))
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

bshop_t *newbutton_shop(sfVector2f pos, sfVector2f size, sfIntRect square,
void (*func)(void))
{
	bshop_t *new = malloc(sizeof(sys_t));
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
