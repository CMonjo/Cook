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
	if (sys->event.type == sfEvtMouseButtonPressed) {

		for (int i = 0; sys->nb[i] != NULL; i++) {
			if (new_button_is_clicked(sys, i,
			(sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
				sys->nb[i]->callback(sys);
		}
	}
}
