/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void button_event(sys_t *sys)
{
	display_actionbar(sys);
}

void analyse_events(sys_t *sys)
{
	while (sfRenderWindow_pollEvent(sys->win, &(sys->event))) {
		if (sys->event.type == sfEvtClosed) {
			sfRenderWindow_close(sys->win);
		}
		if (sys->event.type == sfEvtMouseMoved) {
			sys->obj[99]->pos.x = sys->event.mouseMove.x - 21;
			sys->obj[99]->pos.y = sys->event.mouseMove.y - 21;
			sfSprite_setPosition(sys->obj[99]->sprite, sys->obj[99]->pos);
		}
		button_event(sys);
	}
}
