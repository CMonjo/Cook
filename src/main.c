/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

int print_h(char const *filepath)
{
	int fd = 0;
	int rd = 0;
	char *buffer;

	fd = open(filepath, O_RDONLY);
	buffer = malloc(sizeof(char *) * 1200 + 1);
	rd = read(fd, buffer, 1200);
	if (rd <= 0)
		return (84);
	write(1, buffer, rd);
	free(buffer);
	return (0);
}

void analyse_events(sys_t *sys)
{
	while (sfRenderWindow_pollEvent(sys->win, &(sys->event))) {
		if (sys->event.type == sfEvtClosed) {
			sfRenderWindow_close(sys->win);
		}
		if (sys->event.type == sfEvtMouseMoved) {
			sys->obj[99]->pos.x = sys->event.mouseMove.x - 21;
			sys->obj[99]->pos.y = sys->event.mouseMove.y - 21;
			sfSprite_setPosition(sys->obj[99]->sprite, sys->obj[99]->pos);
		}
		display_actionbar(sys);
	}
}

void init_window(sys_t *sys)
{
	sfVideoMode mode = {1920, 1080, 32};
	sys->win = sfRenderWindow_create(mode, "Cook",
	sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(sys->win, 60);
	sys->clock = sfClock_create();
	sys->status = 0;
	init_objects(sys);
	init_text_menu(sys);
	init_button(sys);
	sfRenderWindow_setMouseCursorVisible(sys->win, sfFalse);
}

void which_status_game_loop(sys_t *sys)
{
	// if (sys->status == 2)
	// 	option_menu(sys);
	// else {
		render_objects(sys);
		if (sys->seconds > 0.02) {
			//display_money(sys);
			sfClock_restart(sys->clock);
		}
		//which_mod(sys);
	//}
}

void which_status(sys_t *sys)
{
	// if (sys->status == 0)
	// 	main_menu(sys);
	// else if (sys->status == 1)
	// 	end_menu(sys);
	// else
		which_status_game_loop(sys);
}

void my_window(sys_t *sys)
{
	init_window(sys);
	while (sfRenderWindow_isOpen(sys->win)) {
		sfRenderWindow_clear(sys->win, sfBlack);
		analyse_events(sys);
		sys->time = sfClock_getElapsedTime(sys->clock);
		sys->seconds = sys->time.microseconds / 1000000.0;
		which_status(sys);
	}
	destroy_objects(sys);
}

int main(int ac, char **av)
{
	sys_t *sys = malloc(sizeof(sys_t));

	if (av[1] != NULL && my_strlen(av[1]) == 2 && av[1][0]
	== '-' && av[1][1] == 'h') {
		print_h(".legend");
		return (0);
	}
	else if (ac != 1) {
		my_putstr("You must type './my_cook'\n");
		my_putstr("For more information use -h\n");
		return (84);
	}
	my_window(sys);
	return (0);
}
