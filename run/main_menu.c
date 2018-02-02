/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void choose_option_main_menu(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 3) {
		sys->select = 1;
		sys->status = 2;
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 4)
		sfRenderWindow_close(sys->win);
}

void choose_player_main_menu(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 2
	&& sys->have_player == 1) {
		sys->infinite_mod = 1;
		sys->status = 3;
	}
	else if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 2
	&& sys->have_player == 0) {
		sys->obj[0] = add_sprite(sys,
			"assets/img/chracters/playerR.png",
			(sfVector2f){100, 764},
			(sfIntRect){0, 0, 118, 100});
		sys->obj[0]->kill = 0;
		sys->infinite_mod = 1;
		sys->status = 3;
	}
}

void choose_game_main_menu(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 1
	&& sys->have_player == 1)
		sys->status = 3;
	else if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 1
	&& sys->have_player == 0) {
		sys->obj[0] = add_sprite(sys,
			"assets/img/chracters/playerR.png",
			(sfVector2f){100, 764},
			(sfIntRect){0, 0, 118, 100});
		sys->obj[0]->kill = 0;
		sys->status = 3;
	}
}

void display_text_main_menu(sys_t *sys)
{
	int i = 1;

	for (i = 2; i != 6; i++) {
		sfText_setColor(sys->menu[i]->text, sfWhite);
		sfText_setCharacterSize(sys->menu[i]->text, 60);
	}
	sfText_setColor(sys->menu[sys->select + 1]->text, sfGreen);
	sfText_setCharacterSize(sys->menu[sys->select + 1]->text, 80);
	sfClock_restart(sys->clock);
}

void render_main_menu(sys_t *sys)
{
	int i = 1;

	sfRenderWindow_drawSprite(sys->win, sys->bg[0]->sprite, NULL);
	sfRenderWindow_drawSprite(sys->win, sys->bg[1]->sprite, NULL);
	for (i = 1; i != 6; i++)
	sfRenderWindow_drawText(sys->win, sys->menu[i]->text, NULL);
	sfRenderWindow_display(sys->win);
}
