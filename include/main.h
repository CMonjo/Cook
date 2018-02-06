/*
** EPITECH PROJECT, 2017
** Main
** File description:
** Header file
*/

#ifndef MAIN_H_
	#define MAIN_H_

	// INCLUDES

	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <stdarg.h>
	#include <math.h>
	#include <SFML/Graphics.h>
	#include <SFML/Graphics/Color.h>
	#include <SFML/Window.h>
	#include <SFML/System/Vector2.h>
	#include <SFML/Audio.h>
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include "tools.h"

	// DEFINE

	// STRUCT

	typedef struct obj_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfVector2f pos;
		sfIntRect rect;
	} obj_t;

	typedef struct newbar_s {
		sfRectangleShape *rect;
		sfIntRect square;
		char *msg;
		void(*callback)();
		sfSprite *sprite;
		sfTexture *texture;
		sfVector2f pos;
	} newbar_t;

	typedef struct button_s {
		sfRectangleShape *rect;
		sfIntRect square;
		char *msg;
		void(*callback)();
		sfSprite *sprite;
		sfTexture *texture;
		sfVector2f pos;
	} button_t;

	typedef struct txt_s {
		sfFont *font;
		sfText *text;
		sfVector2f pos;
	} txt_t;

	typedef struct wsup_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfVector2f pos;
		sfIntRect rect;
		int key;
	} wsup_t;

	typedef struct sys_s {
		sfRenderWindow* win;
		sfEvent event;
		sfClock *clock;
		sfTime time;
		float seconds;
		sfMusic *music;
		int status;
		int select;
		int mixor;
		txt_t *txt[100];
		obj_t *obj[100];
		wsup_t *wsup[100];
		button_t *button[100];
		newbar_t *nb[100];
	} sys_t;

	// PROTOTYPES
	void adding_recipe(sys_t *sys);
	int new_button_is_clicked(sys_t *sys, int i, sfVector2f clickPosition);
	void init_nbbuttom(sys_t *sys);
	newbar_t *add_new_buttom(const char *path_sprite, sfVector2f pos,
	sfVector2f size, sfIntRect square, void (*func)());
	void disp_menu(sys_t *sys);
	void disp_cook(sys_t *sys);
	void verif_button(sys_t *sys);
	void button_cook(sys_t *sys);
	void disp_recipe(sys_t *sys);
	wsup_t *add_sup(const char *path_sprite, sfVector2f pos, sfIntRect
	rect);
	void init_windowsup(sys_t *sys);
	int main(int ac, char **av);
	void init_window(sys_t *sys);
	void analyse_events(sys_t *sys);
	int print_h(char const *filepath);
	void my_window(sys_t *sys);
	void init_objects(sys_t *sys);
	void init_text_menu(sys_t *sys);
	void init_button(sys_t *sys);
	obj_t *add_obj(const char *path_sprite, sfVector2f pos, sfIntRect rect);
	txt_t *set_text(char *font, sfVector2f pos, char *text, int size);
	button_t *add_buttom(const char *path_sprite, sfVector2f pos, sfVector2f size, sfIntRect square, void (*func)());
	void render_objects(sys_t *sys);
	void which_status(sys_t *sys);
	void which_status_game_loop(sys_t *sys);
	void display_money(sys_t *sys);
	void init_money(sys_t *sys, long nbr);
	void free_options(sys_t *sys);
	void destroy_objects(sys_t *sys);
	void button_menu();
	void button_recipe();
	void button_ingredient();
	void display_actionbar(sys_t *sys);
	int button_is_clicked(sys_t *sys, int i, sfVector2f clickPosition);
	void main_menu(sys_t *sys);
	void render_main_menu(sys_t *sys);
	void select_main_menu(sys_t *sys);
	void display_text_main_menu(sys_t *sys);
	void move_select_menu(sys_t *sys, int max, int min);
	void choose_game_main_menu(sys_t *sys);
#endif
