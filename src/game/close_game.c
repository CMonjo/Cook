/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void free_options(sys_t *sys)
{
	int i = 0;

	for (i = 0; sys->obj[i] != NULL; i++)
		free(sys->obj[i]);
	for (i = 0; sys->txt[i] != NULL; i++)
		free(sys->txt[i]);
	for (i = 0; sys->button[i] != NULL; i++)
		free(sys->button[i]);
	//free(sys->score);
	free(sys);
}

void destroy_objects(sys_t *sys)
{
	int i = 0;

	for (i = 0; sys->obj[i] != NULL; i++) {
		sfSprite_destroy(sys->obj[i]->sprite);
		sfTexture_destroy(sys->obj[i]->texture);
	}
	// FAUDRA DESTROY LES BUTTON (shape + sprite) AINSI QUE LES TXT
	sfClock_destroy(sys->clock);
	//sfMusic_destroy(sys->music);
	sfRenderWindow_destroy(sys->win);
	free_options(sys);
}
