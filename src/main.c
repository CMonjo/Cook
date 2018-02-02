/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

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
