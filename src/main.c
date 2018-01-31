/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void printHello()
{
	printf("Hello\n");
}

int buttonIsClicked(button_t *button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button->rect).x + sfRectangleShape_getSize(button->rect).x && clickPosition.x > sfRectangleShape_getPosition(button->rect).x && clickPosition.y < sfRectangleShape_getPosition(button->rect).y + sfRectangleShape_getSize(button->rect).y && clickPosition.y > sfRectangleShape_getPosition(button->rect).y);
}

void analyse_events(sys_t *sys, button_t *button)
{
	while (sfRenderWindow_pollEvent(sys->win, &(sys->event))) {
		if (sys->event.type == sfEvtClosed) {
			sfRenderWindow_close(sys->win);
		}
		if (sys->event.type == sfEvtMouseButtonPressed) {
			if (buttonIsClicked(button, (sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
				printHello();
		}
	}
}

void buttonInitialise(button_t *button, sfVector2f position, sfVector2f size)
{
	button->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(button->rect, position);
	sfRectangleShape_setSize(button->rect, size);
	sfRectangleShape_setFillColor(button->rect, sfGreen);
}

int main(void)
{
	sys_t *sys = malloc(sizeof(sys_t));
	button_t *button = malloc(sizeof(button_t));

	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "Cook",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	sys->clock = sfClock_create();
	buttonInitialise(button, (sfVector2f){100, 100}, (sfVector2f){100, 100});
	while (sfRenderWindow_isOpen(sys->win)) {
		sfRenderWindow_clear(sys->win, sfBlack);


		analyse_events(sys, button);
		sfRenderWindow_drawRectangleShape(sys->win, button->rect, NULL);
		sfRenderWindow_display(sys->win);
	}
	return (0);
}
