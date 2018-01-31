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
	void(*callback)();
} button_t;

typedef struct sys_s {
	sfRenderWindow* win;
	sfEvent event;
	sfClock *clock;
	sfTime time;
	button_t *button[10];
} sys_t;

#endif
