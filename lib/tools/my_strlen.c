/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** Count and return the number of character found in the string
*/

#include "tools.h"

int my_strlen(char const *str)
{
	int var = 0;

	while (str[var] != '\0') {
		var = var + 1;
	}
	return (var);
}
