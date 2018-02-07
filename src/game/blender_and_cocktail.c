/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void blender_verif(sys_t *sys)
{
	if (sys->blen_step >= 14 && sys->blen_step <= 17) {
		sfRenderWindow_drawSprite(sys->win,
		sys->obj[sys->blen_step]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->blen_step]->sprite,
		sys->obj[sys->blen_step]->rect);
	}
	if (sys->blen_step > 17) {
		sys->blen_step = 14;
		sfText_setColor(sys->txt[17]->text, sfBlue);
		sfRenderWindow_drawText(sys->win, sys->txt[17]->text, NULL);
	}
}
