/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Engine file
*/

#include "main.h"

obj_t *add_sprite(sys_t *sys, const char *path_sprite, sfVector2f pos,
	sfIntRect rect)
{
	obj_t *new = malloc(sizeof(obj_t));
	if (new == NULL)
		return (NULL);
	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_sprite, NULL);
	new->rect = rect;
	new->pos = pos;
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, new->rect);
	sfSprite_setPosition(new->sprite, new->pos);
	sys->count_obj++;
	return (new);
}

bg_t *add_sprite_bg(const char *path_sprite, sfVector2f pos, sfIntRect rect)
{
	bg_t *new = malloc(sizeof(bg_t));
	if (new == NULL)
		return (NULL);
	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_sprite, NULL);
	new->rect = rect;
	new->pos = pos;
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, new->rect);
	sfSprite_setPosition(new->sprite, new->pos);
	return (new);
}

menu_t *set_text(char *font, sfVector2f pos, char *text, int size)
{
	menu_t *new = malloc(sizeof(menu_t));
	if (new == NULL)
		return (NULL);
	new->font = sfFont_createFromFile(font);
	new->text = sfText_create();
	sfText_setString(new->text, text);
	sfText_setFont(new->text, new->font);
	sfText_setCharacterSize(new->text, size);
	sfText_setPosition(new->text, pos);
	return (new);
}
