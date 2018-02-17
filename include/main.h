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
		void(*callback)();
		sfSprite *sprite;
		sfTexture *texture;
		sfVector2f pos;
	} newbar_t;

	typedef struct button_s {
		sfRectangleShape *rect;
		sfIntRect square;
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
		int error_message;
		int status;
		int select;
		int blender;
		int limit;
		int *wave;
		int *angry;
		player_t player;
		inventory_t inventory[8];
		txt_t *txt[34];
		obj_t *obj[22];
		wsup_t *wsup[5];
		button_t *button[5];
		newbar_t *nb[9];
		bshop_t *bshop[9];
		cocktail_t cocktail[18];
		drink_t drink[9];
	} sys_t;

	// PROTOTYPES

	int main(int ac, char **av);
	void set_cocktail_stock();
	void sell_cocktail();
	void init_cocktail_button();
	void reinit_ingredient();
	void init_drink_stock();
	int list_recipe();
	void cocktail_finished();
	void init_cocktail();
	void blender_disp();
	void close_other_window();
	void blender_verif();
	void disp_text_menu();
	void verif_shop();
	void increment_stock();
	void init_button_shop();
	void error_message();
	int my_clock();
	void adding_recipe();
	int new_button_is_clicked();
	void init_nbbuttom();
	newbar_t *add_new_buttom();
	bshop_t *newbutton_shop();
	void disp_menu();
	void disp_cook();
	void verif_button();
	void button_cook();
	void disp_recipe();
	wsup_t *add_sup();
	drink_t *add_cocktail_button();
	void init_windowsup();
	void init_window();
	void analyse_events();
	int print_h();
	void my_window();
	void set_wave_values();
	void init_objects();
	void init_text_menu();
	void init_button();
	obj_t *add_obj();
	txt_t *set_text();
	button_t *add_buttom();
	void render_objects();
	void which_status();
	void which_status_game_loop();
	void display_money();
	char *init_money(int nbr);
	void free_options();
	void destroy_objects();
	void button_menu();
	void button_recipe();
	void button_ingredient();
	void display_actionbar();
	int button_is_clicked();
	void main_menu();
	void render_main_menu();
	void select_main_menu();
	void display_text_main_menu();
	void move_select_menu();
	void choose_game_main_menu();
	void verif_bubble();
	void pause_menu();
	void select_pause_menu();
	void choose_game_pause_menu();
	void display_text_pause_menu();
	void render_pause_menu();
	void verif_bubble();
	void move_player();
	void player_detection();
	int generate_random_cocktail();
	void set_move_player();
	void end_menu();
	void choose_status_end_menu();
	void select_end_menu();
	void render_end_menu();
	void display_text_end_menu();
	void reset_game();
	void init_string_stock();
	void init_player_system();
	void init_bubble_name();
	void init_inventory();
	void move_back_player();
#endif
