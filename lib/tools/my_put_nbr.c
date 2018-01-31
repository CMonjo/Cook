/*
** EPITECH PROJECT, 2017
** c
** File description:
** File
*/

#include <unistd.h>
#include "tools.h"

int my_put_nbr(int nb)
{
	int right;
	int left;

	if (nb == -2147483648) {
		write(1, "-2147483648", 11);
		return (0);
	}
	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	left = nb % 10;
	right = nb / 10;
	if (right != 0)
		my_put_nbr(right);
	my_putchar(left + '0');
	return (0);
}
