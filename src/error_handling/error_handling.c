/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void error_message(sys_t *sys)
{
	if (sys->error_message == 1) {
		sfRenderWindow_drawText(sys->win, sys->txt[16]->text, NULL);
	}
}

void close_other_window2(sys_t *sys, int wind_open)
{
	if (wind_open == 1) {
		sys->wsup[0]->key = 1;
		for (int i = 2; i <= 3; i++)
			sys->wsup[i]->key = 1;
	}
	else if (wind_open == 0) {
		for (int i = 1; i <= 3; i++)
			sys->wsup[i]->key = 1;
	}
}

void close_other_window(sys_t *sys, int wind_open)
{
	if (wind_open == 3) {
		for (int i = 0; i != wind_open; i++)
			sys->wsup[i]->key = 1;
	}
	else if (wind_open == 2) {
		sys->wsup[3]->key = 1;
		for (int i = 0; i != 2; i++)
			sys->wsup[i]->key = 1;
	}
	else
		close_other_window2(sys, wind_open);
}
