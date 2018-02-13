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
	#include <time.h>
	#include "tools.h"

	// DEFINE

	// STRUCT

	typedef struct obj_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfVector2f pos;
		sfIntRect rect;
		char *name;
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
		int imopen;
	} wsup_t;

	typedef struct inventory_s {
		int stock;
		char *ingredient;
		int price;
		char *cstock;
	} inventory_t;

	typedef struct bshop_s {
		sfRectangleShape *rect;
		sfIntRect square;
		char *name;
		void(*callback)();
		sfVector2f pos;
	} bshop_t;

	typedef struct player_s {
		int one;
		int two;
		int three;
		int p1;
		int p2;
		int p3;
		int rp1;
		int rp2;
		int rp3;
	} player_t;

	typedef struct cocktail_s {
		int stock;
		char *name;
		int ingredient;
	} cocktail_t;

	typedef struct drink_s {
		sfRectangleShape *rect;
		sfIntRect square;
		void(*callback)();
		sfVector2f pos;
		int stock;
		char *name;
	} drink_t;

	typedef struct sys_s {
		sfRenderWindow* win;
		sfEvent event;
		sfClock *clock;
		sfTime time;
		sfMusic *m_game;
		sfMusic *m_menu;
		sfMusic *m_button;
		float seconds;
		sfClock *clock_player;
		sfTime time_player;
		float seconds_player;
		int int_money;
		int blen_step;
		char *money;
		sfMusic *music;
		int error_message;
		int status;
		int select;
		int blender;
		int *wave;
		player_t player;
		inventory_t inventory[10];
		txt_t *txt[100];
		obj_t *obj[100];
		wsup_t *wsup[100];
		button_t *button[100];
		newbar_t *nb[100];
		bshop_t *bshop[10];
		cocktail_t cocktail[20];
		drink_t drink[10];
	} sys_t;

	// PROTOTYPES

	void sell_cocktail(sys_t *sys, int i);
	void init_cocktail_button(sys_t *sys);
	void reinit_ingredient(sys_t *sys);
	void init_drink_stock(sys_t *sys);
	int list_recipe(sys_t *sys, char *i1, char *i2, char *i3);
	void cocktail_finished(sys_t *sys);
	void init_cocktail(sys_t *sys);
	void blender_disp(sys_t *sys);
	void close_other_window(sys_t *sys, int wind_open);
	void blender_verif(sys_t *sys, int i);
	void disp_text_menu(sys_t *sys);
	void verif_shop(sys_t *sys);
	void increment_stock(sys_t *sys, int i);
	void init_button_shop(sys_t *sys);
	void error_message(sys_t *sys);
	int my_clock(sys_t *sys);
	void adding_recipe(sys_t *sys, int i);
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
	char *init_money(int nbr);
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
	void verif_bubble(sys_t *sys);
	void pause_menu(sys_t *sys);
	void select_pause_menu(sys_t *sys);
	void choose_game_pause_menu(sys_t *sys);
	void display_text_pause_menu(sys_t *sys);
	void render_pause_menu(sys_t *sys);
	void verif_bubble(sys_t *sys);
	void move_player();
	void player_detection(sys_t *sys, int i);
	int generate_random_cocktail();
	void set_move_player(sys_t *sys);
#endif
