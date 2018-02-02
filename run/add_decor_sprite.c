/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init map file
*/

#include "main.h"

void init_ground(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/ground.png",
	(sfVector2f){pos_x * 96, pos_y * 108}, (sfIntRect){0, 0, 96, 108});
	sys->obj[obj]->kill = 0;
}

void init_dirt(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/dirt.png",
	(sfVector2f){pos_x * 96, pos_y * 108}, (sfIntRect){0, 0, 96, 108});
	sys->obj[obj]->kill = 0;
}

void init_tree(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/tree.png",
	(sfVector2f){pos_x * 90, pos_y * 88}, (sfIntRect){0, 0, 220, 256});
	sys->obj[obj]->kill = 0;
}

void init_square_tree(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/square_tree.png",
	(sfVector2f){pos_x * 96, pos_y * 91}, (sfIntRect){0, 0, 149, 239});
	sys->obj[obj]->kill = 0;
}

void init_water(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/hud/water.png",
	(sfVector2f){pos_x * 96, pos_y * 108}, (sfIntRect){0, 0, 96, 108});
	sys->obj[obj]->kill = 0;
}
