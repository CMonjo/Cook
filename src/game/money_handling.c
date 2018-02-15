/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Convert int to str for the money
*/

#include "main.h"

char *init_money(int nbr)
{
	int tmp = nbr;
	int end_str = 0;
	char *ns = malloc(sizeof(char) * 10);

	while (tmp > 0) {
		tmp = tmp / 10;
		end_str++;
	}
	ns[end_str] = '\0';
	while (end_str--) {
		ns[end_str] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	if (ns[0] == '\0') {
		ns[0] = '0';
		ns[1] = '\0';
	}
	return (ns);
}

void display_money(sys_t *sys)
{
	if (sys->int_money < 0 || sys->int_money >= sys->limit) {
		sys->status = 2;
		return;
	}
	sys->money = init_money(sys->int_money);
	sfText_setString(sys->txt[0]->text, sys->money);
}
