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

void disp_menu(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->wsup[0]->sprite, NULL);
	verif_shop(sys);
	for (int i = 0; i != 8; i++)
		sys->inventory[i].cstock = init_money(sys->inventory[i].stock);
	sfText_setString(sys->txt[17]->text, sys->inventory[0].cstock);
	sfText_setString(sys->txt[18]->text, sys->inventory[1].cstock);
	sfText_setString(sys->txt[19]->text, sys->inventory[2].cstock);
	sfText_setString(sys->txt[20]->text, sys->inventory[3].cstock);
	sfText_setString(sys->txt[21]->text, sys->inventory[4].cstock);
	sfText_setString(sys->txt[22]->text, sys->inventory[5].cstock);
	sfText_setString(sys->txt[23]->text, sys->inventory[6].cstock);
	sfText_setString(sys->txt[24]->text, sys->inventory[7].cstock);
	for (int i = 17; i != 25; i++) {
		sfText_setColor(sys->txt[i]->text, sfBlack);
		sfRenderWindow_drawText(sys->win, sys->txt[i]->text, NULL);
	}
}

void disp_recipe(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->wsup[2]->sprite, NULL);
}

void disp_cook(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->wsup[3]->sprite, NULL);
	for (int i = 0; sys->nb[i] != NULL; i++) {
		sfRenderWindow_drawRectangleShape(sys->win,
			sys->nb[i]->rect, NULL);
		sfRenderWindow_drawSprite(sys->win, sys->nb[i]->sprite, NULL);
	}
	sfRenderWindow_drawSprite(sys->win, sys->button[3]->sprite, NULL);
	if (sys->event.type == sfEvtMouseButtonPressed && my_clock(sys) == 1) {
		for (int i = 0; sys->nb[i] != NULL; i++) {
			if (new_button_is_clicked(sys, i,
			(sfVector2f){sys->event.mouseButton.x,
			sys->event.mouseButton.y}) == 1) {
				sys->nb[i]->callback(sys, i);
			}
		}
	}
	blender_disp(sys);
}

void set_cocktail_stock(sys_t *sys)
{
	for (int i = 0; i != 8; i++)
		sys->inventory[i].cstock = init_money(sys->drink[i].stock);
	sfText_setString(sys->txt[25]->text, sys->inventory[0].cstock);
	sfText_setString(sys->txt[26]->text, sys->inventory[1].cstock);
	sfText_setString(sys->txt[27]->text, sys->inventory[2].cstock);
	sfText_setString(sys->txt[28]->text, sys->inventory[3].cstock);
	sfText_setString(sys->txt[29]->text, sys->inventory[4].cstock);
	sfText_setString(sys->txt[30]->text, sys->inventory[5].cstock);
	sfText_setString(sys->txt[31]->text, sys->inventory[6].cstock);
	sfText_setString(sys->txt[32]->text, sys->inventory[7].cstock);
	for (int i = 25; i != 33; i++) {
		sfText_setColor(sys->txt[i]->text, sfBlack);
		sfRenderWindow_drawText(sys->win, sys->txt[i]->text, NULL);
	}
}
