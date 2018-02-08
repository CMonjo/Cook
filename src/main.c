/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

//SYS->STATUS == 0 -> Menu d'accueil
//SYS->STATUS == 1 -> Menu Pause
//SYS->STATUS == 2 -> Menu end
//SYS->STATUS != 1, 2 et 0 -> Game loop

void which_status_game_loop(sys_t *sys)
{
	// if (sys->status == 2)
	// 	end_menu(sys);
	// else {
		display_money(sys);
		render_objects(sys);
		if (sys->seconds_player > 0.01) {
			move_player(sys, 11, 544);
			move_player(sys, 12, 544);
			move_player(sys, 13, 544);
			sfClock_restart(sys->clock_player);
		}
	//}
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

void my_window(sys_t *sys)
{
	init_window(sys);
	init_windowsup(sys);
	init_button_shop(sys);
	init_cocktail(sys);
	while (sfRenderWindow_isOpen(sys->win)) {
		sfRenderWindow_clear(sys->win, sfBlack);
		analyse_events(sys);
		sys->time = sfClock_getElapsedTime(sys->clock);
		sys->seconds = sys->time.microseconds / 1000000.0;
		sys->time_player = sfClock_getElapsedTime(sys->clock_player);
		sys->seconds_player = sys->time_player.microseconds / 1000000.0;
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
	else if (ac != 2) {
		my_putstr("You must type './my_cook <wave value>'\n");
		my_putstr("For more information use -h\n");
		return (84);
	}
	sys->wave = my_getnbr(av[1]);
	if (sys->wave <= 0)
		return (84);
	my_window(sys);
	return (0);
}
