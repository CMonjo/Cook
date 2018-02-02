/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Sprite management file
*/

#include "main.h"

void init_objects(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->obj[i] = NULL;
	sys->obj[0] = add_obj("assets/img/hud/background.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[1] = add_obj("assets/img/hud/bar.png",
	(sfVector2f){50, 790}, (sfIntRect){0, 0, 1800, 120});
	sys->obj[99] = add_obj("assets/img/hud/mouse.png",
	(sfVector2f){900, 440}, (sfIntRect){0, 0, 40, 40});
}

void init_button(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->button[i] = NULL;
	sys->button[0] = add_buttom("assets/img/recipes/recipes.png",
	(sfVector2f){400, 800}, (sfVector2f){80, 90},
	(sfIntRect){0, 0, 100, 300}, button_menu);
	sys->button[1] = add_buttom("assets/img/recipes/recipes.png",
 	(sfVector2f){950, 800}, (sfVector2f){78, 88},
	(sfIntRect){100, 0, 100, 300}, button_recipe);
	sys->button[2] = add_buttom("assets/img/recipes/recipes.png",
	(sfVector2f){1450, 800}, (sfVector2f){65, 80},
	(sfIntRect){200, 0, 70, 300},
	button_ingredient);
}


void init_text_menu(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 10; i++)
		sys->txt[i] = NULL;
	sys->txt[0] = set_text("assets/font/bold.ttf",
	(sfVector2f){0, 0}, "Money", 50);
}

void render_objects(sys_t *sys)
{
	int i = 0;

	sfRenderWindow_drawSprite(sys->win, sys->obj[0]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[0]->sprite, sys->obj[0]->rect);
	for (i = 0; sys->txt[i] != NULL; i++) {
		sfRenderWindow_drawText(sys->win, sys->txt[i]->text, NULL);
	}
	for (i = 1; sys->obj[i] != NULL; i++) {
		sfRenderWindow_drawSprite(sys->win, sys->obj[i]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[i]->sprite, sys->obj[i]->rect);
	}
	for (i = 0; sys->button[i] != NULL; i++) {
		sfRenderWindow_drawRectangleShape(sys->win, sys->button[i]->rect, NULL);
		sfRenderWindow_drawSprite(sys->win, sys->button[i]->sprite, NULL);
	}

	// PRINT DE LA MOUSE
	// CHANGER SA VALEUR UNE FOIS TOUS LES OBJS LOADS
	sfRenderWindow_drawSprite(sys->win, sys->obj[99]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[99]->sprite, sys->obj[99]->rect);
	sfRenderWindow_display(sys->win);
}