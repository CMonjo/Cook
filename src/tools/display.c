/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

int print_h(char const *filepath)
{
	int fd = 0;
	int rd = 0;
	char *buffer;

	fd = open(filepath, O_RDONLY);
	buffer = malloc(sizeof(char *) * 1200 + 1);
	rd = read(fd, buffer, 1200);
	if (rd <= 0)
		return (84);
	write(1, buffer, rd);
	free(buffer);
	return (0);
}

void disp_text_menu(sys_t *sys)
{
	sys->txt[24] = set_text("assets/font/bold.ttf",
	(sfVector2f){1390, 740}, sys->inventory[7].cstock, 50);
	for (int i = 17; i != 25; i++) {
		sfText_setColor(sys->txt[i]->text, sfBlack);
		sfRenderWindow_drawText(sys->win, sys->txt[i]->text, NULL);
	}
}

void disp_menu(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->wsup[0]->sprite, NULL);
	verif_shop(sys);
	for (int i = 0; i != 8; i++)
		sys->inventory[i].cstock = init_money(sys->inventory[i].stock);
	sys->txt[17] = set_text("assets/font/bold.ttf",
	(sfVector2f){890, 300}, sys->inventory[0].cstock, 50);
	sys->txt[18] = set_text("assets/font/bold.ttf",
	(sfVector2f){890, 442}, sys->inventory[1].cstock, 50);
	sys->txt[19] = set_text("assets/font/bold.ttf",
	(sfVector2f){890, 584}, sys->inventory[2].cstock, 50);
	sys->txt[20] = set_text("assets/font/bold.ttf",
	(sfVector2f){890, 726}, sys->inventory[3].cstock, 50);
	sys->txt[21] = set_text("assets/font/bold.ttf",
	(sfVector2f){1390, 300}, sys->inventory[4].cstock, 50);
	sys->txt[22] = set_text("assets/font/bold.ttf",
	(sfVector2f){1390, 435}, sys->inventory[5].cstock, 50);
	sys->txt[23] = set_text("assets/font/bold.ttf",
	(sfVector2f){1390, 599}, sys->inventory[6].cstock, 50);
	disp_text_menu(sys);
}

void disp_recipe(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->wsup[2]->sprite, NULL);
}

void disp_cook(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->wsup[3]->sprite, NULL);
	for (int i = 0; sys->nb[i] != NULL; i++) {
		sfRenderWindow_drawRectangleShape(sys->win, sys->nb[i]->rect, NULL);
		sfRenderWindow_drawSprite(sys->win, sys->nb[i]->sprite, NULL);
	}
	sfRenderWindow_drawSprite(sys->win, sys->button[3]->sprite, NULL);
	if (sys->event.type == sfEvtMouseButtonPressed && my_clock(sys) == 1) {
		for (int i = 0; sys->nb[i] != NULL; i++) {
			if (new_button_is_clicked(sys, i,
			(sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
				sys->nb[i]->callback(sys, i);
		}
	}
}
