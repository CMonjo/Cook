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
	char *msg;
	void(*callback)(void);
} button_t;

// typedef struct scene_s {
// 	struct game_object_s *objs;
// 	button_t *button[10];
// } scene_t;

typedef struct sys_s {
	sfRenderWindow* win;
	sfEvent event;
	sfClock *clock;
	sfTime time;
	button_t *button[10];
} sys_t;

#endif
