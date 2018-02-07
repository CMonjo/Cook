/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"


int button_shop_is_clicked(sys_t *sys, int i, sfVector2f clickPosition)
{
	return (clickPosition.x <
	sfRectangleShape_getPosition(sys->bshop[i]->rect).x +
	sfRectangleShape_getSize(sys->bshop[i]->rect).x && clickPosition.x >
	sfRectangleShape_getPosition(sys->bshop[i]->rect).x && clickPosition.y
	< sfRectangleShape_getPosition(sys->bshop[i]->rect).y +
	sfRectangleShape_getSize(sys->bshop[i]->rect).y && clickPosition.y >
	sfRectangleShape_getPosition(sys->bshop[i]->rect).y);
}

void increment_stock(sys_t *sys, int i)
{
	printf("vous avez cliquer sur %d et et le stock est egal à %d\n", i, sys->inventory[i].stock);
	if (sys->int_money >= sys->inventory[i].price) {
		sys->int_money -= sys->inventory[i].price;
		sys->inventory[i].stock++;
	}
	sys->win = sys->win;
}

void verif_shop(sys_t *sys)
{
	for (int i = 0; i != 8; i++) {
		sfRenderWindow_drawRectangleShape(sys->win, sys->bshop[i]->rect, NULL);
	}
	if (sys->event.type == sfEvtMouseButtonPressed && my_clock(sys) == 1) {
		for (int i = 0; i != 8; i++) {
			if (button_shop_is_clicked(sys, i,
			(sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
				sys->bshop[i]->callback(sys, i);
		}
	}
}
