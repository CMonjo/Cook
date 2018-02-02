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

	for (i = 0; i < 10000; i++)
		sys->obj[i] = NULL;
	for (i = 0; i < 8; i++)
		sys->bg[i] = NULL;
	sys->bg[0] = add_sprite_bg("assets/img/hud/menu.jpg",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->bg[1] = add_sprite_bg("assets/img/hud/coins.png",
	(sfVector2f){1160, 550}, (sfIntRect){0, 0, 200, 300});
	sys->bg[2] = add_sprite_bg("assets/img/hud/red.png",
	(sfVector2f){800, 350}, (sfIntRect){0, 0, 73, 73});
	sys->bg[3] = add_sprite_bg("assets/img/hud/blue.png",
	(sfVector2f){800, 450}, (sfIntRect){0, 0, 73, 73});
	sys->bg[4] = add_sprite_bg("assets/img/hud/bg_first.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 3840, 1080});
	sys->bg[5] = add_sprite_bg("assets/img/hud/bg_second.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 3840, 1080});
	sys->bg[6] = add_sprite_bg("assets/img/hud/bg_third.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 3840, 1080});
}

void init_text_menu_second(sys_t *sys)
{
	sys->menu[7] = set_text("assets/font/bold.ttf",
	(sfVector2f){900, 450}, "Blue", 100);
	sys->menu[8] = set_text("assets/font/bold.ttf",
	(sfVector2f){900, 550}, "Back", 100);
	sys->menu[9] = set_text("assets/font/bold.ttf",
	(sfVector2f){500, 100}, "Choose your skin !", 100);
	sys->menu[10] = set_text("assets/font/bold.ttf",
	(sfVector2f){180, 0}, "0", 50);
	sys->menu[11] = set_text("assets/font/bold.ttf",
	(sfVector2f){100, 900}, "Your score : ", 50);
	sys->menu[12] = set_text("assets/font/bold.ttf",
	(sfVector2f){650, 150}, "You win !", 120);
	sys->menu[13] = set_text("assets/font/bold.ttf",
	(sfVector2f){650, 150}, "You lose !", 120);
	sys->menu[14] = set_text("assets/font/bold.ttf",
	(sfVector2f){400, 600}, "RageQuit", 70);
	sys->menu[15] = set_text("assets/font/bold.ttf",
	(sfVector2f){1200, 600}, "Restart", 70);
}

void init_text_menu(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 20; i++)
		sys->menu[i] = NULL;
	sys->menu[0] = set_text("assets/font/bold.ttf",
	(sfVector2f){0, 0}, "Score", 50);
	sys->menu[1] = set_text("assets/font/bold.ttf",
	(sfVector2f){1000, 350}, "Runner", 150);
	sys->menu[2] = set_text("assets/font/bold.ttf",
	(sfVector2f){300, 350}, "Play", 50);
	sys->menu[3] = set_text("assets/font/bold.ttf",
	(sfVector2f){300, 450}, "Infinite mode", 50);
	sys->menu[4] = set_text("assets/font/bold.ttf",
	(sfVector2f){300, 550}, "Option", 50);
	sys->menu[5] = set_text("assets/font/bold.ttf",
	(sfVector2f){300, 650}, "RageQuit", 50);
	sys->menu[6] = set_text("assets/font/bold.ttf",
	(sfVector2f){900, 350}, "Red", 100);
	init_text_menu_second(sys);
}

void move_player(sys_t *sys)
{
	int max_value_p = 1416;

	if (sys->obj[0]->rect.top >= max_value_p - sys->obj[0]->rect.width)
		sys->obj[0]->rect.top = 0;
	else {
		sys->obj[0]->rect.top = sys->obj[0]->rect.top +
		sys->obj[0]->rect.width;
	}
}

void render_objects(sys_t *sys)
{
	int i = 0;

	for (i = 1; sys->bg[i] != NULL; i++)
		sfRenderWindow_drawSprite(sys->win, sys->bg[i]->sprite, NULL);
	for (i = 1; sys->obj[i] != NULL; i++) {
		sfRenderWindow_drawSprite(sys->win, sys->obj[i]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[i]->sprite, sys->obj[i]->rect);
	}
	sfRenderWindow_drawSprite(sys->win, sys->obj[0]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[0]->sprite, sys->obj[0]->rect);
	sfRenderWindow_drawText(sys->win, sys->menu[0]->text, NULL);
	sfRenderWindow_drawText(sys->win, sys->menu[10]->text, NULL);
	sfRenderWindow_display(sys->win);
}
