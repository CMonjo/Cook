/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void button_menu(sys_t *sys)
{
	sys->win = sys->win;
	printf("menu\n");
}

void button_recipe(sys_t *sys)
{
	sys->win = sys->win;
	printf("recipe\n");
}

void button_ingredient(sys_t *sys)
{
	if (sys->wsup[0]->key == 0) {
		sys->wsup[0]->key = 1;
	} else if (sys->wsup[0]->key == 1) {
		sys->wsup[0]->key = 0;
	}
}

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

void display_actionbar(sys_t *sys)
{
	if (sys->event.type == sfEvtMouseButtonPressed) {
		for (int i = 0; sys->button[i] != NULL; i++) {
			if (button_is_clicked(sys, i,
			(sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
				sys->button[i]->callback(sys);
		}
	}
}
