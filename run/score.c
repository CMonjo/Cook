/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Convert int to str for the score
*/

#include "main.h"

void init_score(sys_t *sys, long nbr)
{
	long tmp = nbr;
	long end_str = 0;

	while (tmp > 0) {
		tmp = tmp / 10;
		end_str++;
	}
	sys->score[end_str] = '\0';
	while (end_str--) {
		sys->score[end_str] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
}

void display_score(sys_t *sys)
{
	sys->int_score = sys->int_score + 30;
	init_score(sys, sys->int_score);
	sys->menu[10] = set_text("assets/font/bold.ttf",
	(sfVector2f){180, 0}, sys->score, 50);
}
