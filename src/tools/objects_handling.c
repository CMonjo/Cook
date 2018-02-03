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
	(sfVector2f){0, -70}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[1] = add_obj("assets/img/hud/bar.png",
	(sfVector2f){0, 1000}, (sfIntRect){0, 0, 1980, 105});
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

void init_text_menu(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->txt[i] = NULL;
	// sys->txt[0] = set_text("assets/font/bold.ttf",
	// (sfVector2f){0, 0}, "Money", 50);
	// sys->txt[1] = set_text("assets/font/bold.ttf",
	// (sfVector2f){180, 0}, "0$", 50);
        //
	// sys->txt[2] = set_text("assets/font/bold.ttf",
	// (sfVector2f){1000, 350}, "Cook", 150);
	// sys->txt[3] = set_text("assets/font/bold.ttf",
	// (sfVector2f){300, 350}, "Play", 50);
	// sys->txt[4] = set_text("assets/font/bold.ttf",
	// (sfVector2f){300, 450}, "Infinite mode", 50);
	// sys->txt[5] = set_text("assets/font/bold.ttf",
	// (sfVector2f){300, 550}, "Option", 50);
	// sys->txt[6] = set_text("assets/font/bold.ttf",
	// (sfVector2f){300, 650}, "RageQuit", 50);
	// sys->txt[7] = set_text("assets/font/bold.ttf",
	// (sfVector2f){900, 350}, "Red", 100);
	// sys->txt[8] = set_text("assets/font/bold.ttf",
	// (sfVector2f){900, 450}, "Blue", 100);
	// sys->txt[9] = set_text("assets/font/bold.ttf",
	// (sfVector2f){900, 550}, "Back", 100);
	// sys->txt[10] = set_text("assets/font/bold.ttf",
	// (sfVector2f){500, 100}, "Choose your skin !", 100);
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
