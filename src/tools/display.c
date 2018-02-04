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

void disp_recipe(sys_t *sys)
{
	sfRenderWindow_drawSprite(sys->win, sys->wsup[0]->sprite, NULL);
}
