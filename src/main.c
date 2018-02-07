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
//SYS->STATUS != 1, 2 et 3 -> Game loop

void verif_bubble(sys_t *sys)
{
	int i = 0;
	//LES BULLES VONT DE OBJ 3 à OBJ 10

	if (sys->player.pass != 0) {
		srand(time(NULL));
		i = (rand() % (10 - 3 + 1)) + 3;
		sfRenderWindow_drawSprite(sys->win, sys->obj[i]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[i]->sprite, sys->obj[i]->rect);
	}
}

void move_player(sys_t *sys, int i, int max_value)
{
	if (sys->obj[i]->pos.y >= 200) {
		if (sys->obj[i]->rect.top >= max_value - sys->obj[i]->rect.height)
			sys->obj[i]->rect.top = sys->obj[i]->rect.height;
		else
			sys->obj[i]->rect.top += sys->obj[i]->rect.height;
		sys->obj[i]->pos.y += -7;
		if (sys->obj[i]->pos.y <= -150)
			sys->obj[i]->pos.y = 1150;
		sfSprite_setPosition(sys->obj[i]->sprite, sys->obj[i]->pos);
	} else
		sys->player.pass = 1;
}

//FUNCTION UTILE POUR LES BOUTONS
int my_clock(sys_t *sys)
{
	if (sys->seconds > 0.4) {
		sfClock_restart(sys->clock);
		return (1);
	}
	return (0);
}

void which_status_game_loop(sys_t *sys)
{
	// if (sys->status == 2)
	// 	pause_menu(sys);
	// else {
		render_objects(sys);
		if (sys->seconds_player > 0.01) {
			move_player(sys, 11, 544);
			sfClock_restart(sys->clock_player);
		}
	//}
}

void which_status(sys_t *sys)
{
	if (sys->status == 0)
		main_menu(sys);
	// else if (sys->status == 1)
	// 	pause_menu(sys);
	else
		which_status_game_loop(sys);
}

void my_window(sys_t *sys)
{
	init_window(sys);
	init_windowsup(sys);
	init_button_shop(sys);
	while (sfRenderWindow_isOpen(sys->win)) {
		sfRenderWindow_clear(sys->win, sfBlack);
		analyse_events(sys);
		sys->time = sfClock_getElapsedTime(sys->clock);
		sys->seconds = sys->time.microseconds / 1000000.0;
		sys->time_player = sfClock_getElapsedTime(sys->clock_player);
		sys->seconds_player = sys->time_player.microseconds / 1000000.0;
		which_status(sys);
		display_money(sys);
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
