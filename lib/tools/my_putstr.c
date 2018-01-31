/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** Display one by one a characters of string
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "tools.h"

int my_putstr(char const *str)
{
	int var = 0;

	while (str[var] != '\0') {
		my_putchar(str[var]);
		var = var + 1;
	}
	return (0);
}
