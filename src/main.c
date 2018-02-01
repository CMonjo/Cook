/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

void printRouge()
{
	printf("Rouge\n");
}

void printVert()
{
	printf("Vert\n");
}

void printBlanc()
{
	printf("Blanc\n");
}

int buttonIsClicked(sys_t *sys, int i, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(sys->button[i]->rect).x + sfRectangleShape_getSize(sys->button[i]->rect).x && clickPosition.x > sfRectangleShape_getPosition(sys->button[i]->rect).x && clickPosition.y < sfRectangleShape_getPosition(sys->button[i]->rect).y + sfRectangleShape_getSize(sys->button[i]->rect).y && clickPosition.y > sfRectangleShape_getPosition(sys->button[i]->rect).y);
}

void analyse_events(sys_t *sys)
{
	while (sfRenderWindow_pollEvent(sys->win, &(sys->event))) {
		if (sys->event.type == sfEvtClosed) {
			sfRenderWindow_close(sys->win);
		}
		if (sys->event.type == sfEvtMouseButtonPressed) {
			for (int i = 0; sys->button[i] != NULL; i++) {
				if (buttonIsClicked(sys, i, (sfVector2f){sys->event.mouseButton.x, sys->event.mouseButton.y}) == 1)
					sys->button[i]->callback();
			}
		}
	}
}

button_t *buttonInitialise(sfVector2f position, sfVector2f size, sfColor color, void (*func)(void))
{
	button_t *new = malloc(sizeof(button_t));

	if (new == NULL)
		return (NULL);
	new->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(new->rect, position);
	sfRectangleShape_setSize(new->rect, size);
	sfRectangleShape_setFillColor(new->rect, color);
	new->callback = func;
	return (new);
}

void addButton(sys_t *sys)
{
	sys->button[0] = buttonInitialise((sfVector2f){200, 100}, (sfVector2f){100, 100}, sfRed, printRouge);
	sys->button[1] = buttonInitialise((sfVector2f){400, 100}, (sfVector2f){100, 100}, sfGreen, printVert);
	sys->button[2] = buttonInitialise((sfVector2f){600, 100}, (sfVector2f){100, 100}, sfWhite, printBlanc);
	sys->button[3] = NULL;

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
		for (int i = 0; sys->button[i] != NULL; i++)
			sfRenderWindow_drawRectangleShape(sys->win, sys->button[i]->rect, NULL);
		sfRenderWindow_display(sys->win);
	}
	return (0);
}
