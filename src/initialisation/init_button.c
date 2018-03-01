/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init button file
*/

#include "main.h"

void init_button(sys_t *sys)
{
	int i = 0;

	for (i = 0; i != 5; i++)
		sys->button[i] = NULL;
	sys->button[0] = add_buttom("assets/img/action_bar/pause.png",
	(sfVector2f){31, 120}, (sfIntRect){0, 0, 80, 80}, button_menu);
	sys->button[1] = add_buttom("assets/img/action_bar/list.png",
	(sfVector2f){31, 400}, (sfIntRect){0, 0, 80, 80}, button_recipe);
	sys->button[2] = add_buttom("assets/img/action_bar/market.png",
	(sfVector2f){31, 680}, (sfIntRect){0, 0, 80, 80}, button_ingredient);
	sys->button[3] = add_buttom("assets/img/action_bar/cook.png",
	(sfVector2f){31, 960}, (sfIntRect){0, 0, 80, 80}, button_cook);
	init_nbbuttom(sys);
}

void init_button_shop(sys_t *sys)
{
	int i = 0;

	for (i = 0; i != 9; i++)
		sys->bshop[i] = NULL;
	sys->bshop[0] = newbutton_shop((sfVector2f){784, 296},
	(sfVector2f){65, 65}, (sfIntRect){0, 0, 80, 80}, increment_stock);
	sys->bshop[1] = newbutton_shop((sfVector2f){783, 445},
	(sfVector2f){65, 65}, (sfIntRect){0, 0, 80, 80}, increment_stock);
	sys->bshop[2] = newbutton_shop((sfVector2f){783, 585},
	(sfVector2f){65, 65}, (sfIntRect){0, 0, 80, 80}, increment_stock);
	sys->bshop[3] = newbutton_shop((sfVector2f){783, 725},
	(sfVector2f){65, 65}, (sfIntRect){0, 0, 80, 80}, increment_stock);
	sys->bshop[4] = newbutton_shop((sfVector2f){1299, 293},
	(sfVector2f){65, 65}, (sfIntRect){0, 0, 80, 80}, increment_stock);
	sys->bshop[5] = newbutton_shop((sfVector2f){1299, 430},
	(sfVector2f){65, 65}, (sfIntRect){0, 0, 80, 80}, increment_stock);
	sys->bshop[6] = newbutton_shop((sfVector2f){1299, 600},
	(sfVector2f){65, 65}, (sfIntRect){0, 0, 80, 80}, increment_stock);
	sys->bshop[7] = newbutton_shop((sfVector2f){1299, 745},
	(sfVector2f){65, 65}, (sfIntRect){0, 0, 80, 80}, increment_stock);
}

void init_nbbuttom_second(sys_t *sys)
{
	sys->nb[5] = add_new_buttom("assets/img/food/watermelon.png",
	(sfVector2f){31, 600}, (sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[6] = add_new_buttom("assets/img/food/banana.png",
	(sfVector2f){31, 720}, (sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[7] = add_new_buttom("assets/img/food/apple.png",
	(sfVector2f){31, 840}, (sfIntRect){0, 0, 80, 80}, adding_recipe);
}

void init_nbbuttom(sys_t *sys)
{
	for (int i = 0; i != 9; i++)
		sys->nb[i] = NULL;
	sys->nb[0] = add_new_buttom("assets/img/food/beer.png",
	(sfVector2f){31, 0}, (sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[1] = add_new_buttom("assets/img/food/coffee.png",
	(sfVector2f){31, 120}, (sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[2] = add_new_buttom("assets/img/food/orange.png",
	(sfVector2f){31, 240}, (sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[3] = add_new_buttom("assets/img/food/pineapple.png",
	(sfVector2f){31, 360}, (sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[4] = add_new_buttom("assets/img/food/cherry.png",
	(sfVector2f){31, 480}, (sfIntRect){0, 0, 80, 80}, adding_recipe);
	init_nbbuttom_second(sys);
}
