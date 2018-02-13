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

	// IMPOSSIBLE A FREE ?
	// for (i = 0; i != 8; i++)
	 	//free(sys->drink[i].name);
	for (i = 0; sys->obj[i] != NULL; i++)
		free(sys->obj[i]);
	for (i = 0; sys->txt[i] != NULL; i++)
		free(sys->txt[i]);
	for (i = 0; sys->button[i] != NULL; i++)
		free(sys->button[i]);
	free(sys->player);
	free(sys->money);
	free(sys);
}

void destroy_objects(sys_t *sys)
{
	int i = 0;

	for (i = 0; sys->obj[i] != NULL; i++) {
		sfSprite_destroy(sys->obj[i]->sprite);
		sfTexture_destroy(sys->obj[i]->texture);
	}
	// for (i = 0; sys->wsup[i] != NULL; i++) {
	// 	if (sys->wsup[i]->sprite != NULL)
	// 		sfSprite_destroy(sys->wsup[i]->sprite);
	// 	if (sys->wsup[i]->texture != NULL)
	// 		sfTexture_destroy(sys->wsup[i]->texture);
	// }
	for (i = 0; sys->button[i] != NULL; i++) {
		sfSprite_destroy(sys->button[i]->sprite);
		sfTexture_destroy(sys->button[i]->texture);
		sfRectangleShape_destroy(sys->button[i]->rect);
	}
	for (i = 0; sys->nb[i] != NULL; i++) {
		sfSprite_destroy(sys->nb[i]->sprite);
		sfTexture_destroy(sys->nb[i]->texture);
		sfRectangleShape_destroy(sys->nb[i]->rect);
	}
	for (i = 0; sys->txt[i] != NULL; i++) {
		sfFont_destroy(sys->txt[i]->font);
		sfText_destroy(sys->txt[i]->text);
	}
	for (i = 0; sys->bshop[i] != NULL; i++)
		sfRectangleShape_destroy(sys->bshop[i]->rect);
	for (i = 0; i != 8; i++)
		sfRectangleShape_destroy(sys->drink[i].rect);
	sfClock_destroy(sys->clock);
	sfClock_destroy(sys->clock_player);
	sfMusic_destroy(sys->m_game);
	sfMusic_destroy(sys->m_menu);
	sfMusic_destroy(sys->m_button);
	sfRenderWindow_destroy(sys->win);
	free_options(sys);
}
