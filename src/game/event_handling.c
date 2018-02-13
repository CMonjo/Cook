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
			sys->obj[21]->pos.x = sys->event.mouseMove.x - 12;
			sys->obj[21]->pos.y = sys->event.mouseMove.y - 2;
			sfSprite_setPosition(sys->obj[21]->sprite, sys->obj[21]->pos);
		}
		button_event(sys);
	}
}
