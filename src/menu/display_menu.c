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

void main_menu(sys_t *sys)
{
	render_main_menu(sys);
	if (sys->seconds > 0.1) {
		select_main_menu(sys);
		choose_game_main_menu(sys);
		display_text_main_menu(sys);
	}
}

void pause_menu(sys_t *sys)
{
	render_pause_menu(sys);
	if (sys->seconds > 0.1) {
		select_pause_menu(sys);
		choose_game_pause_menu(sys);
		display_text_pause_menu(sys);
	}
}

// void end_menu(sys_t *sys)
// {
// 	render_end(sys);
// 	if (sys->seconds > 0.1) {
// 		which_end_option(sys);
// 		display_end_menu(sys);
// 		sfClock_restart(sys->clock);
// 	}
// }
