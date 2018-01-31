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

// int buttonIsClicked(sys_t *sys, sfVector2f clickPosition)
// {
// 	return (clickPosition.x < sfRectangleShape_getPosition(sys->button->rect[0]).x + sfRectangleShape_getSize(sys->button->rect[0]).x && clickPosition.x > sfRectangleShape_getPosition(sys->button->rect[0]).x && clickPosition.y < sfRectangleShape_getPosition(sys->button->rect[0]).y + sfRectangleShape_getSize(sys->button->rect[0]).y && clickPosition.y > sfRectangleShape_getPosition(sys->button->rect[0]).y);
// }

void analyse_events(sys_t *sys)
{
	while (sfRenderWindow_pollEvent(sys->win, &(sys->event))) {
		if (sys->event.type == sfEvtClosed) {
			sfRenderWindow_close(sys->win);
		}
		// if (sys->event.type == sfEvtMouseButtonPressed) {
		// 	if (buttonIsClicked(sys, (sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
		// 		printHello();
		// }
	}
}

button_t *buttonInitialise(sys_t *sys, sfVector2f position, sfVector2f size, sfColor color)
{
	button_t *new = malloc(sizeof(button_t));

	if (new == NULL)
		return (NULL);
	new->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(new->rect, position);
	sfRectangleShape_setSize(new->rect, size);
	sfRectangleShape_setFillColor(new->rect, color);
	return (new);
}

void addButton(sys_t *sys)
{
	sys->button[0]->rect = buttonInitialise(sys, (sfVector2f){100, 100}, (sfVector2f){100, 100}, sfRed);
}

int main(void)
{
	sys_t *sys = malloc(sizeof(sys_t));

	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "Cook",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	sys->clock = sfClock_create();
	addButton(sys);
	while (sfRenderWindow_isOpen(sys->win)) {
		sfRenderWindow_clear(sys->win, sfBlack);
		analyse_events(sys);
		sfRenderWindow_drawRectangleShape(sys->win, sys->button[0]->rect, NULL);
		sfRenderWindow_display(sys->win);
	}
	return (0);
}
