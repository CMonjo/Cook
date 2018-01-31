/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Struct file
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "main.h"

typedef struct button_s {
	sfRectangleShape *rect;
} button_t;

typedef struct sys_s {
	sfRenderWindow* win;
	sfVector2f mouse;
	sfEvent event;
	sfClock *clock;
	sfTime time;
} sys_t;

#endif
