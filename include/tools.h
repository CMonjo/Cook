/*
** EPITECH PROJECT, 2017
** Header file
** File description:
** Library tools
*/

#ifndef _TOOLS_H_
	#define _TOOLS_H_
	#include "main.h"

	void my_putchar(char c);
	int my_putstr(char const *str);
	int my_strlen(char const *str);
	char *my_strcpy(char *dest, char const *src);
	char *my_strcat(char *dest, char const *src);
	int my_getnbr(char const *str);
	int my_str_isnum(char const *str);
	int my_put_nbr(int nb);
	int my_strcmp(char const *s1, char const *s2);
#endif
