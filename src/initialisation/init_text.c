/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init text file
*/

#include "main.h"

void init_text_four(sys_t *sys)
{
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

void init_text_third(sys_t *sys)
{
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
	init_text_four(sys);
}

void init_text_second(sys_t *sys)
{
	sys->txt[7] = set_text("assets/font/bold.ttf",
	(sfVector2f){1350, 850}, "RageQuit", 50);
	sys->txt[8] = set_text("assets/font/bold.ttf",
	(sfVector2f){160, 50}, "Game over...", 100);
	sys->txt[9] = set_text("assets/font/bold.ttf",
	(sfVector2f){220, 220}, "You lose...", 50);
	sys->txt[10] = set_text("assets/font/bold.ttf",
	(sfVector2f){220, 220}, "You win !", 50);
	sys->txt[11] = set_text("assets/font/bold.ttf",
	(sfVector2f){600, 850}, "Home", 50);
	sys->txt[12] = set_text("assets/font/bold.ttf",
	(sfVector2f){1120, 850}, "Quit", 50);
	sys->txt[13] = set_text("assets/font/bold.ttf",
	(sfVector2f){650, 150}, "You lose !", 120);
	sys->txt[16] = set_text("assets/font/bold.ttf",
	(sfVector2f){450, 280}, "Not enough ingredient in stock", 70);
	init_text_third(sys);
}

void init_text_menu(sys_t *sys)
{
	int i = 0;

	for (i = 0; i != 34; i++)
		sys->txt[i] = NULL;
	sys->txt[0] = set_text("assets/font/bold.ttf",
	(sfVector2f){180, 0}, sys->money, 50);
	sys->txt[1] = set_text("assets/font/bold.ttf",
	(sfVector2f){200, 50}, "My Cook ! ", 100);
	sys->txt[2] = set_text("assets/font/bold.ttf",
	(sfVector2f){600, 850}, "Play", 50);
	sys->txt[3] = set_text("assets/font/bold.ttf",
	(sfVector2f){1120, 850}, "Quit", 50);
	sys->txt[4] = set_text("assets/font/bold.ttf",
	(sfVector2f){180, 50}, "Pause !", 100);
	sys->txt[5] = set_text("assets/font/bold.ttf",
	(sfVector2f){150, 850}, "Continue", 50);
	sys->txt[6] = set_text("assets/font/bold.ttf",
	(sfVector2f){780, 850}, "Go to home", 50);
	init_text_second(sys);
}
