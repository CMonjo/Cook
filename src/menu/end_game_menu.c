/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Game detection file
*/

#include "main.h"

void select_end_menu(sys_t *sys)
{
	int tmp = 0;

	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		sys->select--;
		tmp++;
		sfMusic_play(sys->m_menu);
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		sys->select++;
		tmp++;
		sfMusic_play(sys->m_menu);
	}
	if (tmp != 0)
		move_select_menu(sys, 2, 1);
}

void choose_status_end_menu(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 1) {
		reset_game(sys);
		sys->status = 0;
	}
	else if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 2)
		sfRenderWindow_close(sys->win);
}

void display_text_end_menu(sys_t *sys)
{
	int i = 1;

	for (i = 11; i != 13; i++) {
		sfText_setColor(sys->txt[i]->text, sfWhite);
		sfText_setCharacterSize(sys->txt[i]->text, 80);
	}
	sfText_setColor(sys->txt[sys->select + 10]->text, sfMagenta);
	sfText_setCharacterSize(sys->txt[sys->select + 10]->text, 82);
	sfClock_restart(sys->clock);
}

void render_end_menu(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->obj[0]->sprite, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[8]->text, NULL);
	if (sys->int_money <= 0)
		sfRenderWindow_drawText(sys->win, sys->txt[9]->text, NULL);
	else
		sfRenderWindow_drawText(sys->win, sys->txt[10]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[11]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->txt[12]->text, NULL);
	sfRenderWindow_display(sys->win);
}
