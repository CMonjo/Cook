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

 int generate_random_cocktail()
{
	int val = 0;

	val = (rand() % (10 - 3 + 1)) + 3;
	return (val);
}

void verif_bubble(sys_t *sys)
{
	if (sys->player.one == 11) {
		sys->obj[sys->player.p1]->pos.y = sys->obj[11]->pos.y - 150;
		sys->obj[sys->player.p1]->pos.x = sys->obj[11]->pos.x;
		sfSprite_setPosition(sys->obj[sys->player.p1]->sprite, sys->obj[sys->player.p1]->pos);
		sfRenderWindow_drawSprite(sys->win, sys->obj[sys->player.p1]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->player.p1]->sprite, sys->obj[sys->player.p1]->rect);
	}
	if (sys->player.two == 12) {
		sys->obj[sys->player.p2]->pos.y = sys->obj[12]->pos.y - 150;
		sys->obj[sys->player.p2]->pos.x = sys->obj[12]->pos.x;
		sfSprite_setPosition(sys->obj[sys->player.p2]->sprite, sys->obj[sys->player.p2]->pos);
		sfRenderWindow_drawSprite(sys->win, sys->obj[sys->player.p2]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->player.p2]->sprite, sys->obj[sys->player.p2]->rect);
	}
	if (sys->player.three == 13) {
		sys->obj[sys->player.p3]->pos.y = sys->obj[13]->pos.y - 150;
		sys->obj[sys->player.p3]->pos.x = sys->obj[13]->pos.x;
		sfSprite_setPosition(sys->obj[sys->player.p3]->sprite, sys->obj[sys->player.p3]->pos);
		sfRenderWindow_drawSprite(sys->win, sys->obj[sys->player.p3]->sprite, NULL);
		sfSprite_setTextureRect(sys->obj[sys->player.p3]->sprite, sys->obj[sys->player.p3]->rect);
	}
}

void player_detection(sys_t *sys, int i)
{
	if (i == 11) {
		sys->player.one = i;
		sys->player.p1 = generate_random_cocktail();
	}
	if (i == 12) {
		sys->player.two = i;
		sys->player.p2 = generate_random_cocktail();
	}
	if (i == 13) {
		sys->player.three = i;
		sys->player.p3 = generate_random_cocktail();
	}
	printf("%d, %d, %d\n", sys->player.p1, sys->player.p2, sys->player.p3);
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
		player_detection(sys, i);
}

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
	else if (ac != 1) {
		my_putstr("You must type './my_cook'\n");
		my_putstr("For more information use -h\n");
		return (84);
	}
	my_window(sys);
	return (0);
}
