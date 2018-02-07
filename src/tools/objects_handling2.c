/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Sprite management file
*/

#include "main.h"

void init_nbbuttom(sys_t *sys)
{
//button cook
	sys->nb[0] = add_new_buttom("assets/img/food/beer.png",
	(sfVector2f){31, 0}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[1] = add_new_buttom("assets/img/food/coffee.png",
	(sfVector2f){31, 120}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[2] = add_new_buttom("assets/img/food/orange.png",
	(sfVector2f){31, 240}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[3] = add_new_buttom("assets/img/food/pineapple.png",
	(sfVector2f){31, 360}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[4] = add_new_buttom("assets/img/food/cherry.png",
	(sfVector2f){31, 480}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80},adding_recipe);
	sys->nb[5] = add_new_buttom("assets/img/food/watermelon.png",
	(sfVector2f){31, 600}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[6] = add_new_buttom("assets/img/food/banana.png",
	(sfVector2f){31, 720}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80}, adding_recipe);
	sys->nb[7] = add_new_buttom("assets/img/food/apple.png",
	(sfVector2f){31, 840}, (sfVector2f){76, 76},
	(sfIntRect){0, 0, 80, 80},adding_recipe);
	sys->nb[8] = NULL;
}
