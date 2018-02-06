/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void init_window(sys_t *sys)
{
	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "Cook",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	sys->clock = sfClock_create();
	sys->status = 0;
	sys->select = 1;
	sys->mixor = 0;
	init_objects(sys);
	init_text_menu(sys);
	init_button(sys);
	sfRenderWindow_setMouseCursorVisible(sys->win, sfFalse);
}
