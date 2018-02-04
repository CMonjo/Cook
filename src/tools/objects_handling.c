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
	sys->obj[0] = add_obj("assets/img/hud/menu_bg.jpg",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[1] = add_obj("assets/img/hud/background.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[99] = add_obj("assets/img/hud/mouse.png",
	(sfVector2f){900, 440}, (sfIntRect){0, 0, 40, 40});
}

// 85 par 72

void init_button(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->button[i] = NULL;
	sys->button[0] = add_buttom("assets/img/action_bar/pause.png",
	(sfVector2f){400, 1000}, (sfVector2f){80, 90},
	(sfIntRect){0, 0, 85, 100}, button_menu);
	sys->button[1] = add_buttom("assets/img/action_bar/couvert.png",
 	(sfVector2f){950, 1000}, (sfVector2f){78, 88},
	(sfIntRect){0, 0, 85, 100}, button_recipe);
	sys->button[2] = add_buttom("assets/img/action_bar/cocktail.png",
	(sfVector2f){1450, 1000}, (sfVector2f){65, 60},
	(sfIntRect){0, 0, 85, 100}, button_ingredient);
}

void init_windowsup(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->wsup[i] = NULL;
	sys->wsup[0] = add_sup("assets/img/action_bar/recette/recette.png",
	(sfVector2f){200, 0}, (sfIntRect){0, 0, 1555, 1080});
}

void init_text_menu(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->txt[i] = NULL;
	sys->txt[0] = set_text("assets/font/bold.ttf",
	(sfVector2f){10, 0}, "0$", 50);
	sys->txt[1] = set_text("assets/font/bold.ttf",
	(sfVector2f){710, 250}, "My Cook ! ", 100);
	sys->txt[2] = set_text("assets/font/bold.ttf",
	(sfVector2f){500, 550}, "Play", 50);
	sys->txt[3] = set_text("assets/font/bold.ttf",
	(sfVector2f){1220, 550}, "Quit", 50);

	// sys->txt[11] = set_text("assets/font/bold.ttf",
	// (sfVector2f){100, 900}, "Your score : ", 50);
	// sys->txt[12] = set_text("assets/font/bold.ttf",
	// (sfVector2f){650, 150}, "You win !", 120);
	// sys->txt[13] = set_text("assets/font/bold.ttf",
	// (sfVector2f){650, 150}, "You lose !", 120);
	// sys->txt[14] = set_text("assets/font/bold.ttf",
	// (sfVector2f){400, 600}, "RageQuit", 70);
	// sys->txt[15] = set_text("assets/font/bold.ttf",
	// (sfVector2f){1200, 600}, "Restart", 70);
}

void render_objects(sys_t *sys)
{
	int i = 0;

	sfRenderWindow_drawSprite(sys->win, sys->obj[0]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[0]->sprite, sys->obj[0]->rect);
	for (i = 1; sys->obj[i] != NULL; i++) {
		sfRenderWindow_drawSprite(sys->win, sys->obj[i]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[i]->sprite, sys->obj[i]->rect);
	}
	for (i = 0; sys->button[i] != NULL; i++) {
		sfRenderWindow_drawRectangleShape(sys->win, sys->button[i]->rect, NULL);
		sfRenderWindow_drawSprite(sys->win, sys->button[i]->sprite, NULL);
	}
	sfRenderWindow_drawText(sys->win, sys->txt[0]->text, NULL);
	if (sys->wsup[0]->key == 0)
		disp_recipe(sys);
	// PRINT DE LA MOUSE
	// CHANGER SA VALEUR UNE FOIS TOUS LES OBJS LOADS
	sfRenderWindow_drawSprite(sys->win, sys->obj[99]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[99]->sprite, sys->obj[99]->rect);
	sfRenderWindow_display(sys->win);
}
