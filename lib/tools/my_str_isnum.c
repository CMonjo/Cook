/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** return 1 if str contain only digits else 0
*/

#include "main.h"

int my_str_isnum(char const *str)
{
	int i = 0;

	if (str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] < 58 && str[i] > 47) {
		i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}
