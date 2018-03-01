/*
** EPITECH PROJECT, 2017
** CSFML MyCook
** File description:
** Set options file
*/

#include "main.h"

void set_wave_values(sys_t *sys, char **av)
{
	sys->wave = malloc(sizeof(int) * 14);
	sys->angry = malloc(sizeof(int) * 14);
	for (int i = 0; i != 14; i++) {
		sys->wave[i] = 800;
		sys->angry[i] = 1;
	}
	sys->limit = my_getnbr(av[1]);
	if (sys->limit <= 80)
		sys->limit = 150;
}

void init_struct(sys_t *sys)
{
	sys->status = 0;
	sys->blen_step = 14;
	sys->select = 1;
	sys->blender = 0;
	sys->error_message = 0;
	sys->money = malloc(sizeof(char) * 10);
	sys->money = NULL;
	sys->int_money = 50;
}

void init_window(sys_t *sys)
{
	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "Cook",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	srand(NULL);
	sys->clock = sfClock_create();
	sys->clock_player = sfClock_create();
	sys->m_game = sfMusic_createFromFile("assets/music/game.wav");
	sys->m_menu = sfMusic_createFromFile("assets/music/select.wav");
	sys->m_button = sfMusic_createFromFile("assets/music/button.wav");
	init_struct(sys);
	init_string_stock(sys);
	init_player_system(sys);
	init_inventory(sys);
	init_objects(sys);
	init_text_menu(sys);
	init_button(sys);
	sfRenderWindow_setMouseCursorVisible(sys->win, sfFalse);
}
