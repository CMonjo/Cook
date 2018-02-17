/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Init objects file
*/

#include "main.h"

void init_bubble_name(sys_t *sys)
{
	sys->obj[3]->name = "capple";
	sys->obj[4]->name = "cbananas";
	sys->obj[5]->name = "cbeer";
	sys->obj[6]->name = "ccherry";
	sys->obj[7]->name = "ccoffee";
	sys->obj[8]->name = "corange";
	sys->obj[9]->name = "cpineapple";
	sys->obj[10]->name = "cwatermelon";
}

void init_objects_third(sys_t *sys)
{
	sys->obj[17] = add_obj("assets/img/blender/blender_step3.png",
	(sfVector2f){400, 200}, (sfIntRect){0, 0, 1200, 735});
	sys->obj[18] = add_obj("assets/img/blender/success.png",
	(sfVector2f){760, 200}, (sfIntRect){0, 0, 468, 222});
	sys->obj[19] = add_obj("assets/img/blender/failure.png",
	(sfVector2f){760, 200}, (sfIntRect){0, 0, 468, 220});
	sys->obj[20] = add_obj("assets/img/hud/door.png",
	(sfVector2f){970, 1058}, (sfIntRect){0, 0, 670, 22});
	sys->obj[21] = add_obj("assets/img/hud/mouse.png",
	(sfVector2f){900, 440}, (sfIntRect){0, 0, 40, 40});
	init_bubble_name(sys);
}

void init_objects_second(sys_t *sys)
{
	sys->obj[8] = add_obj("assets/img/bubble/orange.png",
	(sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[9] = add_obj("assets/img/bubble/pineapple.png",
	(sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[10] = add_obj("assets/img/bubble/watermelon.png",
	(sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[11] = add_obj("assets/img/player/p.png",
	(sfVector2f){1000, 1100}, (sfIntRect){0, 0, 73, 131});
	sys->obj[12] = add_obj("assets/img/player/p.png",
	(sfVector2f){1300, 1100}, (sfIntRect){0, 0, 73, 131});
	sys->obj[13] = add_obj("assets/img/player/p.png",
	(sfVector2f){1550, 1100}, (sfIntRect){0, 0, 73, 131});
	sys->obj[14] = add_obj("assets/img/blender/blender_bg.png",
	(sfVector2f){400, 200}, (sfIntRect){0, 0, 1200, 735});
	sys->obj[15] = add_obj("assets/img/blender/blender_step1.png",
	(sfVector2f){400, 200}, (sfIntRect){0, 0, 1200, 735});
	sys->obj[16] = add_obj("assets/img/blender/blender_step2.png",
	(sfVector2f){400, 200}, (sfIntRect){0, 0, 1200, 735});
	init_objects_third(sys);
}

void init_objects(sys_t *sys)
{
	for (int i = 0; i < 22; i++)
		sys->obj[i] = NULL;
	sys->obj[0] = add_obj("assets/img/hud/bg_menu.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[1] = add_obj("assets/img/hud/bg.png",
	(sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
	sys->obj[2] = add_obj("assets/img/hud/coin.png",
	(sfVector2f){115, 5}, (sfIntRect){0, 0, 50, 50});
	sys->obj[3] = add_obj("assets/img/bubble/apple.png",
	(sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[4] = add_obj("assets/img/bubble/bananas.png",
	(sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[5] = add_obj("assets/img/bubble/beer.png",
	(sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[6] = add_obj("assets/img/bubble/cherry.png",
	(sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	sys->obj[7] = add_obj("assets/img/bubble/coffee.png",
	(sfVector2f){1000, 50}, (sfIntRect){0, 0, 225, 143});
	init_objects_second(sys);
}
