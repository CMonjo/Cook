/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

int button_is_clicked(sys_t *sys, int i, sfVector2f clickPosition)
{
	return (clickPosition.x <
	sfRectangleShape_getPosition(sys->button[i]->rect).x +
	sfRectangleShape_getSize(sys->button[i]->rect).x && clickPosition.x >
	sfRectangleShape_getPosition(sys->button[i]->rect).x && clickPosition.y
	< sfRectangleShape_getPosition(sys->button[i]->rect).y +
	sfRectangleShape_getSize(sys->button[i]->rect).y && clickPosition.y >
	sfRectangleShape_getPosition(sys->button[i]->rect).y);
}

int new_button_is_clicked(sys_t *sys, int i, sfVector2f clickPosition)
{
	return (clickPosition.x <
	sfRectangleShape_getPosition(sys->nb[i]->rect).x +
	sfRectangleShape_getSize(sys->nb[i]->rect).x && clickPosition.x >
	sfRectangleShape_getPosition(sys->nb[i]->rect).x && clickPosition.y
	< sfRectangleShape_getPosition(sys->nb[i]->rect).y +
	sfRectangleShape_getSize(sys->nb[i]->rect).y && clickPosition.y >
	sfRectangleShape_getPosition(sys->nb[i]->rect).y);
}

void adding_recipe(sys_t *sys)
{
	sys->mixor += sys->mixor == 60 ? 40 : 30;
	printf("%d\n", sys->mixor);
	sys->mixor >= 100 ? sys->mixor = 0 : 0;
}

void display_actionbar(sys_t *sys)
{
	if (sys->event.type == sfEvtMouseButtonPressed) {
		for (int i = 0; i < 4; i++) {
			if (button_is_clicked(sys, i,
			(sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
				sys->button[i]->callback(sys);
		}
	}
}
