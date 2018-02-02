/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Game detection file
*/

#include "main.h"

void which_end_option(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		sys->select --;
		sfMusic_play(sys->music_menu);
	}
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		sys->select ++;
		sfMusic_play(sys->music_menu);
	}
	move_select_menu(sys, 2, 1);
}

void display_end_menu(sys_t *sys)
{
	int i = 0;

	for (i = 14; i < 16; i++) {
		sfText_setColor(sys->menu[i]->text, sfWhite);
		sfText_setCharacterSize(sys->menu[i]->text, 60);
	}
	sfText_setColor(sys->menu[sys->select + 13]->text, sfGreen);
	sfText_setCharacterSize(sys->menu[sys->select + 13]->text, 80);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 1)
		sfRenderWindow_close(sys->win);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 2)
		restart_game_loop(sys);
}

void render_end(sys_t *sys)
{
	sfRenderWindow_clear(sys->win, sfBlack);
	sys->menu[10] = set_text("assets/font/bold.ttf",
	(sfVector2f){450, 900}, sys->score, 50);
	sfRenderWindow_drawSprite(sys->win, sys->bg[0]->sprite, NULL);
	sfRenderWindow_drawText(sys->win, sys->menu[10]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->menu[11]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->menu[14]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->menu[15]->text, NULL);
	if (sys->game_status == 0)
		sfRenderWindow_drawText(sys->win, sys->menu[12]->text, NULL);
	if (sys->game_status == 1)
		sfRenderWindow_drawText(sys->win, sys->menu[13]->text, NULL);
	sfRenderWindow_display(sys->win);
}
