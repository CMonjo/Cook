/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void move_select_menu(sys_t *sys, int max, int min)
{
	if (sys->select > max)
		sys->select = min;
	if (sys->select < min)
		sys->select = max;
}

void back_option(sys_t *sys)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) && sys->select == 3) {
		sys->select = 1;
		sys->status = 0;
		sfMusic_play(sys->music_menu_back);
	}
}

void main_menu(sys_t *sys)
{
	render_main_menu(sys);
	if (sys->seconds > 0.1) {
		select_main_menu(sys);
		choose_game_main_menu(sys);
		choose_player_main_menu(sys);
		choose_option_main_menu(sys);
		display_text_main_menu(sys);
	}
}

void option_menu(sys_t *sys)
{
	render_option_menu(sys);
	if (sys->seconds > 0.1) {
		select_option_menu(sys);
		choose_color_player_option_menu(sys);
		display_text_option_menu(sys);
		sfClock_restart(sys->clock);
	}
}

void end_menu(sys_t *sys)
{
	render_end(sys);
	if (sys->seconds > 0.1) {
		which_end_option(sys);
		display_end_menu(sys);
		sfClock_restart(sys->clock);
	}
}
