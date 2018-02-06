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
