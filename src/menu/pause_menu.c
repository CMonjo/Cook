/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void select_pause_menu(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		sys->select--;
		sfMusic_play(sys->m_menu);
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		sys->select++;
		sfMusic_play(sys->m_menu);
	}
	move_select_menu(sys, 3, 1);
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
	int i = 4;

	for (i = 4; i != 8; i++) {
		sfText_setColor(sys->txt[i]->text, sfWhite);
		sfText_setCharacterSize(sys->txt[i]->text, 60);
	}
	sfText_setColor(sys->txt[sys->select + 4]->text, sfRed);
	sfText_setCharacterSize(sys->txt[sys->select + 4]->text, 62);
	sfClock_restart(sys->clock);
}

void render_pause_menu(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->wsup[1]->sprite, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[4]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[5]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[6]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[7]->text, NULL);
	sfRenderWindow_display(sys->win);
}
