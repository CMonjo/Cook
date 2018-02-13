/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Sprite management file
*/

#include "main.h"

void init_bubble_name(sys_t *sys)
{
	for (int i = 0; i != 11; i++) {
		sys->obj[i]->name = malloc(sizeof(char) * 30);
		sys->obj[i]->name = NULL;
	}
	sys->obj[3]->name = "capple";
	sys->obj[4]->name = "cbananas";
	sys->obj[5]->name = "cbeer";
	sys->obj[6]->name = "ccherry";
	sys->obj[7]->name = "ccoffee";
	sys->obj[8]->name = "corange";
	sys->obj[9]->name = "cpineapple";
	sys->obj[10]->name = "cwatermelon";
}

void init_objects(sys_t *sys)
{
	int i = 0;

	for (i = 0; i < 100; i++)
		sys->obj[i] = NULL;
	sys->obj[0] = add_obj("assets/img/hud/bg_menu.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[1] = add_obj("assets/img/hud/bg.png", (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[2] = add_obj("assets/img/hud/coin.png", (sfVector2f){115, 5}, (sfIntRect){0, 0, 50, 50});

	sys->obj[3] = add_obj("assets/img/bubble/apple.png", (sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[4] = add_obj("assets/img/bubble/bananas.png", (sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[5] = add_obj("assets/img/bubble/beer.png", (sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[6] = add_obj("assets/img/bubble/cherry.png", (sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[7] = add_obj("assets/img/bubble/coffee.png", (sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[8] = add_obj("assets/img/bubble/orange.png", (sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[9] = add_obj("assets/img/bubble/pineapple.png", (sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[10] = add_obj("assets/img/bubble/watermelon.png", (sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	init_bubble_name(sys);
	sys->obj[11] = add_obj("assets/img/player/P3.png", (sfVector2f){1000, 1100}, (sfIntRect){0, 0, 73, 131});
	sys->obj[12] = add_obj("assets/img/player/P3.png", (sfVector2f){1300, 1100}, (sfIntRect){0, 0, 73, 131});
	sys->obj[13] = add_obj("assets/img/player/P3.png", (sfVector2f){1550, 1100}, (sfIntRect){0, 0, 73, 131});

	sys->obj[14] = add_obj("assets/img/blender/blender_bg.png", (sfVector2f){400, 200}, (sfIntRect){0, 0, 1200, 735});
	sys->obj[15] = add_obj("assets/img/blender/blender_step1.png", (sfVector2f){400, 200}, (sfIntRect){0, 0, 1200, 735});
	sys->obj[16] = add_obj("assets/img/blender/blender_step2.png", (sfVector2f){400, 200}, (sfIntRect){0, 0, 1200, 735});
	sys->obj[17] = add_obj("assets/img/blender/blender_step3.png", (sfVector2f){400, 200}, (sfIntRect){0, 0, 1200, 735});
	sys->obj[18] = add_obj("assets/img/blender/cocktailok.png", (sfVector2f){760, 200}, (sfIntRect){0, 0, 470, 220});
	sys->obj[19] = add_obj("assets/img/blender/cocktailfailure.png", (sfVector2f){760, 200}, (sfIntRect){0, 0, 470, 220});

	sys->obj[98] = add_obj("assets/img/hud/door.png",
	(sfVector2f){970, 1058}, (sfIntRect){0, 0, 670, 22});
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
	sys->wsup[0] = add_sup("assets/img/action_bar/marketplace.png",
	(sfVector2f){400, 200}, (sfIntRect){0, 0, 1096, 780});
	sys->wsup[1] = add_sup("assets/img/action_bar/pause_menu.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
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

	sys->txt[4] = set_text("assets/font/bold.ttf",
	(sfVector2f){790, 10}, "Pause !", 100);
	sys->txt[5] = set_text("assets/font/bold.ttf",
	(sfVector2f){150, 920}, "Continue", 50);
	sys->txt[6] = set_text("assets/font/bold.ttf",
	(sfVector2f){780, 920}, "Go to home", 50);
	sys->txt[7] = set_text("assets/font/bold.ttf",
	(sfVector2f){1550, 920}, "RageQuit", 50);


	sys->txt[11] = set_text("assets/font/bold.ttf",
	(sfVector2f){100, 900}, "Your score : ", 50);
	sys->txt[12] = set_text("assets/font/bold.ttf",
	(sfVector2f){650, 150}, "You win !", 120);
	sys->txt[13] = set_text("assets/font/bold.ttf",
	(sfVector2f){650, 150}, "You lose !", 120);
	sys->txt[16] = set_text("assets/font/bold.ttf",
	(sfVector2f){450, 280}, "Not enough ingredient in stock", 70);

	sys->txt[17] = set_text("assets/font/bold.ttf",
	(sfVector2f){890, 300}, sys->inventory[0].cstock, 50);
	sys->txt[18] = set_text("assets/font/bold.ttf",
	(sfVector2f){890, 442}, sys->inventory[1].cstock, 50);
	sys->txt[19] = set_text("assets/font/bold.ttf",
	(sfVector2f){890, 584}, sys->inventory[2].cstock, 50);
	sys->txt[20] = set_text("assets/font/bold.ttf",
	(sfVector2f){890, 726}, sys->inventory[3].cstock, 50);
	sys->txt[21] = set_text("assets/font/bold.ttf",
	(sfVector2f){1390, 300}, sys->inventory[4].cstock, 50);
	sys->txt[22] = set_text("assets/font/bold.ttf",
	(sfVector2f){1390, 435}, sys->inventory[5].cstock, 50);
	sys->txt[23] = set_text("assets/font/bold.ttf",
	(sfVector2f){1390, 599}, sys->inventory[6].cstock, 50);
	sys->txt[24] = set_text("assets/font/bold.ttf",
	(sfVector2f){1390, 740}, sys->inventory[7].cstock, 50);
	sys->txt[25] = set_text("assets/font/bold.ttf",
	(sfVector2f){360, 10}, sys->inventory[0].cstock, 50);
	sys->txt[26] = set_text("assets/font/bold.ttf",
	(sfVector2f){470, 10}, sys->inventory[1].cstock, 50);
	sys->txt[27] = set_text("assets/font/bold.ttf",
	(sfVector2f){590, 12}, sys->inventory[2].cstock, 50);
	sys->txt[28] = set_text("assets/font/bold.ttf",
	(sfVector2f){700, 10}, sys->inventory[3].cstock, 50);
	sys->txt[29] = set_text("assets/font/bold.ttf",
	(sfVector2f){360, 80}, sys->inventory[4].cstock, 50);
	sys->txt[30] = set_text("assets/font/bold.ttf",
	(sfVector2f){470, 78}, sys->inventory[5].cstock, 50);
	sys->txt[31] = set_text("assets/font/bold.ttf",
	(sfVector2f){590, 79}, sys->inventory[6].cstock, 50);
	sys->txt[32] = set_text("assets/font/bold.ttf",
	(sfVector2f){700, 80}, sys->inventory[7].cstock, 50);
}

void render_objects(sys_t *sys)
{
	int i = 0;

	sfRenderWindow_drawSprite(sys->win, sys->obj[0]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[0]->sprite, sys->obj[0]->rect);
	for (i = 1; i != 3; i++) {
		sfRenderWindow_drawSprite(sys->win, sys->obj[i]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[i]->sprite, sys->obj[i]->rect);
	}
	set_cocktail_stock(sys);
	for (i = 11; i != 14; i++) {
		sfRenderWindow_drawSprite(sys->win, sys->obj[i]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[i]->sprite, sys->obj[i]->rect);
	}
	for (i = 0; i < 4; i++) {
		sfRenderWindow_drawRectangleShape(sys->win, sys->button[i]->rect, NULL);
		sfRenderWindow_drawSprite(sys->win, sys->button[i]->sprite, NULL);
	}
	for (i = 0; i != 8; i++) {
		sfRenderWindow_drawRectangleShape(sys->win, sys->drink[i].rect, NULL);
	}
	sfRenderWindow_drawText(sys->win, sys->txt[0]->text, NULL);
	verif_button(sys);
	verif_bubble(sys);
	error_message(sys);
	// PRINT DE LA MOUSE
	// CHANGER SA VALEUR UNE FOIS TOUS LES OBJS LOADS
	sfRenderWindow_drawSprite(sys->win, sys->obj[98]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[98]->sprite, sys->obj[98]->rect);
	sfRenderWindow_drawSprite(sys->win, sys->obj[99]->sprite, NULL);
	sfSprite_setTextureRect(sys->obj[99]->sprite, sys->obj[99]->rect);
	sfRenderWindow_display(sys->win);
}
