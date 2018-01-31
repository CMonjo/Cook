/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** Renvoi un nombre sous la forme d'une chaîne
*/

int my_getnbr(char const *str)
{
	int calc_neg = 0;
	long nbr = 0;

	if (!str)
		return (0);
	while (*str == '-' || *str == '+')
		(*str++ == '-') ? calc_neg++ : 0;
	while (*str >= '0' && *str <= '9') {
		nbr = nbr * 10;
		nbr = nbr + *str++ -48;
		if (nbr > 2147483647) {
			nbr = calc_neg % 2 == 1?nbr * -1 : nbr;
			if (nbr == -2147483648)
				return (-2147483648);
			return (0);
		}
	}
	return (calc_neg % 2 == 1 ? nbr * -1 : nbr);
}
