/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init map file
*/

#include "main.h"

void init_obstacles(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/chracters/obstacles.png",
	(sfVector2f){pos_x * 96, pos_y * 120}, (sfIntRect){0, 0, 96, 32});
	sys->obj[obj]->kill = 1;
}

void init_mace(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/chracters/mace.png",
	(sfVector2f){pos_x * 96, pos_y * 108}, (sfIntRect){0, 0, 96, 108});
	sys->obj[obj]->kill = 1;
}

void init_saw(sys_t *sys, int obj, int pos_y, int pos_x)
{
	sys->obj[obj] = add_sprite(sys, "assets/img/chracters/saw.png",
	(sfVector2f){pos_x * 96, pos_y * 118}, (sfIntRect){0, 0, 96, 108});
	sys->obj[obj]->kill = 1;
}
