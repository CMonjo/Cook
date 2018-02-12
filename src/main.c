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

int generate_time_player()
{
	int val = 0;

	val = (rand() % (10 - 3 + 1)) + 3;
	return (val);
}

void set_move_player(sys_t *sys)
{
	if (sys->player.rp1 != 1)
		sys->player.rp1 = (rand() % (sys->rando - 1 + 1)) + 1;
	if (sys->player.rp2 != 1)
		sys->player.rp2 = (rand() % (sys->rando - 1 + 1)) + 1;
	if (sys->player.rp3 != 1)
		sys->player.rp3 = (rand() % (sys->rando - 1 + 1)) + 1;

	if (sys->player.rp1 == 1)
		move_player(sys, 11, 1045);
	if (sys->player.rp2 == 1)
		move_player(sys, 12, 1045);
	if (sys->player.rp3 == 1)
		move_player(sys, 13, 1045);
}

void which_status_game_loop(sys_t *sys)
{
	// if (sys->status == 2)
	// 	end_menu(sys);
	// else {
		display_money(sys);
		render_objects(sys);
		if (sys->seconds_player > 0.01) {
			set_move_player(sys);
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
		sys->seconds_player = sys->time_player.microseconds / 1000000.0;
		which_status(sys);
	}
	destroy_objects(sys);
}

void set_wave_values(sys_t *sys, char *av)
{
	sys->wave = malloc(sizeof(int) * 14);
	for (int i = 0; i != 14; sys->wave[i] = my_getnbr(av) * 800, i++);
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
	sys->rando = my_getnbr(av[1]) * 150;
	set_wave_values(sys, av[1]);
	if (sys->wave <= 0 || sys->rando <= 0)
		return (84);
	my_window(sys);
	return (0);
}
