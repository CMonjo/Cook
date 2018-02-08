/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

int list_recipe3(char *i1, char *i2, char *i3)
{
	//cocktail orange
	if (my_strcmp(i1, "orange") == 0 && my_strcmp(i2, "orange") == 0 &&
	my_strcmp(i3, "orange") == 0)
		return (0);
	else if ((my_strcmp(i1, "pineapple") == 0 || my_strcmp(i1, "banana") == 0 ||
	my_strcmp(i1, "watermelon") == 0) && (my_strcmp(i2, i1) == 1 &&
	(my_strcmp(i2, "pineapple") == 0 || my_strcmp(i2, "banana") == 0 ||
	my_strcmp(i2, "watermelon") == 0)) &&
	(my_strcmp(i3, i2) == 1 && my_strcmp(i3, i1) == 1 &&
	(my_strcmp(i3, "pineapple") == 0 || my_strcmp(i3, "watermelon") == 0 ||
	my_strcmp(i3, "banana") == 0)))
		return (0);
	else
		return (1);
}

int list_recipe2(char *i1, char *i2, char *i3)
{
	//cocktail banana
	if ((my_strcmp(i1, "pineapple") == 0 && my_strcmp(i2, "banana")
	== 0 && my_strcmp(i3, "banana") == 0) || (my_strcmp(i1,
	"banana") == 0 && my_strcmp(i2, "pineapple")
	== 0 && my_strcmp(i3, "banana") == 0) || (my_strcmp(i1,
	"banana") == 0 && my_strcmp(i2, "banana") == 0 &&
	my_strcmp(i3, "pineapple") == 0))
		return (0);
	else if ((my_strcmp(i1, "pineapple") == 0 && my_strcmp(i2, "apple")
	== 0 && my_strcmp(i3, "apple") == 0) || (my_strcmp(i1,
	"apple") == 0 && my_strcmp(i2, "cherry")
	== 0 && my_strcmp(i3, "apple") == 0) || (my_strcmp(i1,
	"apple") == 0 && my_strcmp(i2, "apple") == 0 &&
	my_strcmp(i3, "cherry") == 0))
		return (0);
	else
		return (list_recipe3(i1, i2, i3));

}

int list_recipe(char *i1, char *i2, char *i3)
{
	//cocktail cherry
	if ((my_strcmp(i1, "cherry") == 0 || my_strcmp(i1, "apple") == 0 ||
	my_strcmp(i1, "orange") == 0) && (my_strcmp(i2, i1) == 1 &&
	(my_strcmp(i2, "cherry") == 0 || my_strcmp(i2, "apple") == 0 ||
	my_strcmp(i2, "orange") == 0)) &&
	(my_strcmp(i3, i2) == 1 && my_strcmp(i3, i1) == 1 &&
	(my_strcmp(i3, "cherry") == 0 || my_strcmp(i3, "orange") == 0 ||
	my_strcmp(i3, "apple") == 0)))
		return (0);
	//cocktail watermelon
	else if ((my_strcmp(i1, "banana") == 0 && my_strcmp(i2, "watermelon")
	== 0 && my_strcmp(i3, "watermelon") == 0) || (my_strcmp(i1,
	"watermelon") == 0 && my_strcmp(i2, "banana")
	== 0 && my_strcmp(i3, "watermelon") == 0) || (my_strcmp(i1,
	"watermelon") == 0 && my_strcmp(i2, "watermelon") == 0 &&
	my_strcmp(i3, "banana") == 0))
			return (0);
	else
		return (list_recipe2(i1, i2, i3));
}
