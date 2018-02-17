/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Sprite management file
*/

#include "main.h"

void render_window(sys_t *sys)
{
	int i = 0;

	for (i = 0; i != 8; i++) {
		sfRenderWindow_drawRectangleShape(sys->win,
			sys->drink[i].rect, NULL);
	}
	sfRenderWindow_drawText(sys->win, sys->txt[0]->text, NULL);
	verif_button(sys);
	verif_bubble(sys);
	error_message(sys);
	sfRenderWindow_drawSprite(sys->win, sys->obj[20]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[20]->sprite, sys->obj[20]->rect);
	sfRenderWindow_drawSprite(sys->win, sys->obj[21]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[21]->sprite, sys->obj[21]->rect);
	sfRenderWindow_display(sys->win);
}

void render_objects(sys_t *sys)
{
	int i = 0;

	for (i = 1; i != 3; i++) {
		sfRenderWindow_drawSprite(sys->win, sys->obj[i]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[i]->sprite, sys->obj[i]->rect);
	}
	set_cocktail_stock(sys);
	for (i = 11; i != 14; i++) {
		sfRenderWindow_drawSprite(sys->win, sys->obj[i]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[i]->sprite, sys->obj[i]->rect);
	}
	for (i = 0; i < 4; i++) {
		sfRenderWindow_drawRectangleShape(sys->win,
			sys->button[i]->rect, NULL);
		sfRenderWindow_drawSprite(sys->win,
			sys->button[i]->sprite, NULL);
	}
	render_window(sys);
}
