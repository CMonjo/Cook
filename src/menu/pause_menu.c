/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void select_pause_menu(sys_t *sys)
{
	int tmp = 0;

	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		sys->select--;
		tmp++;
		//sfMusic_play(sys->music_menu);
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		sys->select++;
		tmp++;
		//sfMusic_play(sys->music_menu);
	}
	if (tmp != 0)
		move_select_menu(sys, 2, 1);
}

void choose_game_pause_menu(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 1) {
		sys->status = 3;
		sys->wsup[1]->key = 1;
	}
	else if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 2)
		sfRenderWindow_close(sys->win);
}

void display_text_pause_menu(sys_t *sys)
{
	int i = 1;

	for (i = 2; i != 4; i++) {
		sfText_setColor(sys->txt[i]->text, sfWhite);
		sfText_setCharacterSize(sys->txt[i]->text, 60);
	}
	sfText_setColor(sys->txt[sys->select + 1]->text, sfRed);
	sfText_setCharacterSize(sys->txt[sys->select + 1]->text, 80);
	sfClock_restart(sys->clock);
}

void render_pause_menu(sys_t *sys)
{
	//sfRenderWindow_drawSprite(sys->win, sys->obj[0]->sprite, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[1]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[2]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[3]->text, NULL);
	sfRenderWindow_display(sys->win);
}
