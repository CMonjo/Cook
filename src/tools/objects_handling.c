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
	sys->obj[0] = add_obj("assets/img/hud/bg_menu.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[1] = add_obj("assets/img/hud/bg.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[3] = add_obj("assets/img/hud/coin.png",
	(sfVector2f){115, 5}, (sfIntRect){0, 0, 50, 50});
	sys->obj[2] = add_obj("assets/img/player/P1.png",
	(sfVector2f){1000, 1000}, (sfIntRect){0, 0, 80, 136});
	sys->obj[98] = add_obj("assets/img/hud/door.png",
	(sfVector2f){953, 1058}, (sfIntRect){0, 0, 205, 23});
	sys->obj[99] = add_obj("assets/img/hud/mouse.png",
	(sfVector2f){900, 440}, (sfIntRect){0, 0, 40, 40});
}

void init_button(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->button[i] = NULL;
	sys->button[0] = add_buttom("assets/img/action_bar/pause.png",
	(sfVector2f){31, 120}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, button_menu);
	sys->button[1] = add_buttom("assets/img/action_bar/list.png",
 	(sfVector2f){31, 400}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, button_recipe);
	sys->button[2] = add_buttom("assets/img/action_bar/market.png",
	(sfVector2f){31, 680}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, button_ingredient);
	sys->button[3] = add_buttom("assets/img/action_bar/cook.png",
	(sfVector2f){31, 960}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, button_cook);
	init_nbbuttom(sys);
}

void init_windowsup(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->wsup[i] = NULL;
	sys->wsup[0] = add_sup("assets/img/action_bar/recette/recette.png",
	(sfVector2f){200, 0}, (sfIntRect){0, 0, 1555, 1080});

	//WSUP DE 1 == MENU PAUSE
	sys->wsup[1] = add_sup("assets/img/action_bar/recipes.png",
	(sfVector2f){200, 0}, (sfIntRect){0, 0, 1555, 1080});
	sys->wsup[2] = add_sup("assets/img/action_bar/recipes.png",
	(sfVector2f){400, 200}, (sfIntRect){0, 0, 1096, 780});
	sys->wsup[3] = add_sup("assets/img/food/newbar.png",
	(sfVector2f){10, 0}, (sfIntRect){0, 0, 100, 1080});
}

void init_text_menu(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->txt[i] = NULL;
	sys->txt[1] = set_text("assets/font/bold.ttf",
	(sfVector2f){710, 250}, "My Cook ! ", 100);
	sys->txt[2] = set_text("assets/font/bold.ttf",
	(sfVector2f){500, 550}, "Play", 50);
	sys->txt[3] = set_text("assets/font/bold.ttf",
	(sfVector2f){1220, 550}, "Quit", 50);

	sys->txt[11] = set_text("assets/font/bold.ttf",
	(sfVector2f){100, 900}, "Your score : ", 50);
	sys->txt[12] = set_text("assets/font/bold.ttf",
	(sfVector2f){650, 150}, "You win !", 120);
	sys->txt[13] = set_text("assets/font/bold.ttf",
	(sfVector2f){650, 150}, "You lose !", 120);
	sys->txt[14] = set_text("assets/font/bold.ttf",
	(sfVector2f){400, 600}, "RageQuit", 70);
	sys->txt[15] = set_text("assets/font/bold.ttf",
	(sfVector2f){1200, 600}, "Restart", 70);
	sys->txt[16] = set_text("assets/font/bold.ttf",
	(sfVector2f){200, 400}, "Not enough ingredient in stock", 70);
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
	for (i = 0; i < 4; i++) {
		sfRenderWindow_drawRectangleShape(sys->win, sys->button[i]->rect, NULL);
		sfRenderWindow_drawSprite(sys->win, sys->button[i]->sprite, NULL);
	}
	sfRenderWindow_drawText(sys->win, sys->txt[0]->text, NULL);
	verif_button(sys);
	error_message(sys);
	// PRINT DE LA MOUSE
	// CHANGER SA VALEUR UNE FOIS TOUS LES OBJS LOADS
	sfRenderWindow_drawSprite(sys->win, sys->obj[98]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[98]->sprite, sys->obj[98]->rect);
	sfRenderWindow_drawSprite(sys->win, sys->obj[99]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[99]->sprite, sys->obj[99]->rect);
	sfRenderWindow_display(sys->win);
}
