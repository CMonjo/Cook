/*
** EPITECH PROJECT, 2017
** CSFML Mycook
** File description:
** Main file
*/

#include "main.h"

void reinit_ingredient(sys_t *sys)
{
	sys->cocktail[15].name = "no";
	sys->cocktail[16].name = "no";
	sys->cocktail[17].name = "no";
}

int list_recipe_third(sys_t *sys, char *i1, char *i2, char *i3)
{
	if (my_strcmp(i1, "orange") == 0 && my_strcmp(i2, "orange") == 0 &&
	my_strcmp(i3, "orange") == 0) {
		sys->drink[6].stock++;
		reinit_ingredient(sys);
		return (0);
	} else if ((my_strcmp(i1, "pineapple") == 0 || my_strcmp(i1, "banana")
	== 0 || my_strcmp(i1, "watermelon") == 0) && (my_strcmp(i2, i1) == 1 &&
	(my_strcmp(i2, "pineapple") == 0 || my_strcmp(i2, "banana") == 0 ||
	my_strcmp(i2, "watermelon") == 0)) && (my_strcmp(i3, i2) == 1 &&
	my_strcmp(i3, i1) == 1 && (my_strcmp(i3, "pineapple") == 0 ||
	my_strcmp(i3, "watermelon") == 0 || my_strcmp(i3, "banana") == 0))) {
		sys->drink[5].stock++;
		reinit_ingredient(sys);
		return (0);
	} else
		if (my_strcmp(sys->cocktail[15].name, "no") == 0 &&
		my_strcmp(sys->cocktail[16].name, "no") == 0 &&
		my_strcmp(sys->cocktail[15].name, "no") == 0)
			return (10);
	return (1);
}

int list_recipe_second(sys_t *sys, char *i1, char *i2, char *i3)
{
	if ((my_strcmp(i1, "pineapple") == 0 && my_strcmp(i2, "banana")
	== 0 && my_strcmp(i3, "banana") == 0) || (my_strcmp(i1, "banana") == 0
	&& my_strcmp(i2, "pineapple") == 0 && my_strcmp(i3, "banana") == 0) ||
	(my_strcmp(i1, "banana") == 0 && my_strcmp(i2, "banana") == 0 &&
	my_strcmp(i3, "pineapple") == 0)) {
		sys->drink[3].stock++;
		reinit_ingredient(sys);
		return (0);
	} else if ((my_strcmp(i1, "cherry") == 0 && my_strcmp(i2, "apple")
	== 0 && my_strcmp(i3, "apple") == 0) || (my_strcmp(i1, "apple") == 0 &&
	my_strcmp(i2, "cherry") == 0 && my_strcmp(i3, "apple") == 0) ||
	(my_strcmp(i1, "apple") == 0 && my_strcmp(i2, "apple") == 0 &&
	my_strcmp(i3, "cherry") == 0)) {
		sys->drink[7].stock++;
		reinit_ingredient(sys);
		return (0);
	} else
		return (list_recipe_third(sys, i1, i2, i3));
}

int list_recipe(sys_t *sys, char *i1, char *i2, char *i3)
{
	if ((my_strcmp(i1, "cherry") == 0 || my_strcmp(i1, "apple") == 0 ||
	my_strcmp(i1, "orange") == 0) && (my_strcmp(i2, i1) == 1 &&
	(my_strcmp(i2, "cherry") == 0 || my_strcmp(i2, "apple") == 0 ||
	my_strcmp(i2, "orange") == 0)) && (my_strcmp(i3, i2) == 1 &&
	my_strcmp(i3, i1) == 1 && (my_strcmp(i3, "cherry") == 0 ||
	my_strcmp(i3, "orange") == 0 || my_strcmp(i3, "apple") == 0))) {
		sys->drink[2].stock++;
		reinit_ingredient(sys);
		return (0);
	} else if ((my_strcmp(i1, "banana") == 0 && my_strcmp(i2, "watermelon")
	== 0 && my_strcmp(i3, "watermelon") == 0) || (my_strcmp(i1,
	"watermelon") == 0 && my_strcmp(i2, "banana") == 0 && my_strcmp(i3,
	"watermelon") == 0) || (my_strcmp(i1, "watermelon") == 0 &&
	my_strcmp(i2, "watermelon") == 0 && my_strcmp(i3, "banana") == 0)) {
		sys->drink[1].stock++;
		reinit_ingredient(sys);
		return (0);
	} else
		return (list_recipe_second(sys, i1, i2, i3));
}
