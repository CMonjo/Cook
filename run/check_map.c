/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init map file
*/

#include "main.h"

int compare_map_decor(sys_t *sys, int obj, int pos_y, int pos_x)
{
	switch (sys->map[pos_y][pos_x]) {
		case '1':
			obj++;
			init_ground(sys, obj, pos_y, pos_x);
			break;
		case '2':
			obj++;
			init_dirt(sys, obj, pos_y, pos_x);
			break;
		case '3':
			obj++;
			init_water(sys, obj, pos_y, pos_x);
			break;
		case 'T':
			obj++;
			init_square_tree(sys, obj, pos_y, pos_x);
			break;
	}
	return (obj);
}

int compare_map_ennemis(sys_t *sys, int obj, int pos_y, int pos_x)
{
	switch (sys->map[pos_y][pos_x]) {
		case 'F':
			obj++;
			init_tree(sys, obj, pos_y, pos_x);
			break;
		case 'O':
			obj++;
			init_obstacles(sys, obj, pos_y, pos_x);
			break;
		case 'S':
			obj++;
			init_saw(sys, obj, pos_y, pos_x);
			break;
		case 'M':
			obj++;
			init_mace(sys, obj, pos_y, pos_x);
			break;
	}
	return (obj);
}

void compare_map(sys_t *sys)
{
	int pos_y = 0;
	int pos_x = 0;
	int obj = 0;

	while (pos_y != 10) {
		while (sys->map[pos_y][pos_x] != '\n') {
			obj = compare_map_decor(sys, obj, pos_y, pos_x);
			obj = compare_map_ennemis(sys, obj, pos_y, pos_x);
			pos_x++;
		}
		pos_y++;
		pos_x = 0;
	}
}
