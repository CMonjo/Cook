/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Engine file
*/

#include "main.h"

obj_t *add_obj(const char *path_sprite, sfVector2f pos, sfIntRect rect)
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
	return (new);
}

newbar_t *add_new_buttom(const char *path_sprite, sfVector2f pos,
sfVector2f size, sfIntRect square, void (*func)(void))
{
	newbar_t *new = malloc(sizeof(sys_t));

	if (new == NULL)
		return (NULL);
	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_sprite, NULL);
	new->square = square;
	new->pos = pos;
	new->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(new->rect, pos);
	sfRectangleShape_setSize(new->rect, size);
	sfRectangleShape_setFillColor(new->rect, sfRed);
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, new->square);
	sfSprite_setPosition(new->sprite, new->pos);
	new->callback = func;
	return (new);
}

wsup_t *add_sup(const char *path_sprite, sfVector2f pos, sfIntRect rect)
{
	wsup_t *new = malloc(sizeof(wsup_t));

	if (new == NULL)
		return (NULL);
	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_sprite, NULL);
	new->rect = rect;
	new->pos = pos;
	new->key = 1;
	new->imopen = 0;
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, new->rect);
	sfSprite_setPosition(new->sprite, new->pos);
	return (new);
}

txt_t *set_text(char *font, sfVector2f pos, char *text, int size)
{
	txt_t *new = malloc(sizeof(txt_t));

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

button_t *add_buttom(const char *path_sprite, sfVector2f pos,
sfVector2f size, sfIntRect square, void (*func)(void))
{
	button_t *new = malloc(sizeof(sys_t));

	if (new == NULL)
		return (NULL);
	new->sprite = sfSprite_create();
	new->texture = sfTexture_createFromFile(path_sprite, NULL);
	new->square = square;
	new->pos = pos;
	new->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(new->rect, pos);
	sfRectangleShape_setSize(new->rect, size);
	sfRectangleShape_setFillColor(new->rect, sfRed);
	sfSprite_setTexture(new->sprite, new->texture, sfTrue);
	sfSprite_setTextureRect(new->sprite, new->square);
	sfSprite_setPosition(new->sprite, new->pos);
	new->callback = func;
	return (new);
}
