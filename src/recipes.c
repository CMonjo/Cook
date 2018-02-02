/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void button_menu()
{
	printf("menu\n");
}

void button_recipe()
{
	printf("recipe\n");
}

void button_ingredient()
{
	printf("ingredient\n");
}

int buttonIsClicked(sys_t *sys, int i, sfVector2f clickPosition)
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
			if (buttonIsClicked(sys, i,
			(sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
				sys->button[i]->callback();
		}
	}
}