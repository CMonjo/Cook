/*
** EPITECH PROJECT, 2017
** CSFML MyCook
** File description:
** Main file
*/

#include "main.h"

void which_status_game_loop(sys_t *sys)
{
	if (sys->status == 2)
		end_menu(sys);
	else {
		display_money(sys);
		render_objects(sys);
		if (sys->seconds_player > 0.01) {
			set_move_player(sys);
			sfClock_restart(sys->clock_player);
		}
	}
}

void which_status(sys_t *sys)
{
	if (sys->status == 0)
		main_menu(sys);
	else if (sys->status == 1)
		pause_menu(sys);
	else
		which_status_game_loop(sys);
}

void my_window(sys_t *sys, char **av)
{
	set_wave_values(sys, av);
	init_window(sys);
	init_windowsup(sys);
	init_button_shop(sys);
	init_drink_stock(sys);
	init_cocktail(sys);
	sfMusic_play(sys->m_game);
	sfMusic_setLoop(sys->m_game, sfTrue);
	while (sfRenderWindow_isOpen(sys->win)) {
		sfRenderWindow_clear(sys->win, sfBlack);
		analyse_events(sys);
		sys->time = sfClock_getElapsedTime(sys->clock);
		sys->seconds = sys->time.microseconds / 1000000.0;
		sys->time_player = sfClock_getElapsedTime(sys->clock_player);
		sys->seconds_player =
		sys->time_player.microseconds / 1000000.0;
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
	else if (ac != 2 || my_str_isnum(av[1]) == 0) {
		my_putstr("You must type './my_cook <limit money>'\n");
		my_putstr("For more information use -h\n");
		return (84);
	}
	my_window(sys, av);
	return (0);
}
