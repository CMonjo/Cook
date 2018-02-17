/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

int my_clock(sys_t *sys)
{
	if (sys->seconds > 0.4) {
		sfClock_restart(sys->clock);
		if (sys->blen_step >= 17)
			sys->blen_step = 14;
		sys->error_message = 0;
		return (1);
	}
	return (0);
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
			sfSprite_setPosition(sys->obj[21]->sprite,
				sys->obj[21]->pos);
		}
		display_actionbar(sys);
	}
}
