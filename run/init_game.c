/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void create_variable(sys_t *sys)
{
	sys->clock = sfClock_create();
	sys->music_game =
	sfMusic_createFromFile("assets/music/game.wav");
	sys->music_menu =
	sfMusic_createFromFile("assets/music/menu_select.wav");
	sys->music_menu_back =
	sfMusic_createFromFile("assets/music/menu_back.wav");
	sys->status = 0;
	sys->select = 1;
	sys->have_player = 0;
	if (sys->key == 0)
		sys->infinite_mod = 0;
	sys->jump = 0;
	sys->int_score = 0;
	sys->score = malloc(sizeof(char) * 10 + 1);
}

void init_window(sys_t *sys)
{
	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "MyRunner",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	create_variable(sys);
	init_text_menu(sys);
	init_objects(sys);
	compare_map(sys);
	sfRenderWindow_setMouseCursorVisible(sys->win, sfFalse);
}
