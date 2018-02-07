/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Convert int to str for the money
*/

#include "main.h"

char *init_money(long nbr, char *str)
{
	long tmp = nbr;
	long end_str = 0;

	while (tmp > 0) {
		tmp = tmp / 10;
		end_str++;
	}
	str[end_str] = '\0';
	while (end_str--) {
		str[end_str] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}

void display_money(sys_t *sys)
{
	sys->money = init_money(sys->int_money, sys->money);
	sys->txt[0] = set_text("assets/font/bold.ttf",
	(sfVector2f){180, 0}, sys->money, 50);
}
