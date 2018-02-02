/*
** EPITECH PROJECT, 2017
** CSFML MyRunner
** File description:
** Main file
*/

#include "main.h"

int print_h(char const *filepath)
{
	int fd = 0;
	int rd = 0;
	char *buffer;

	fd = open(filepath, O_RDONLY);
	buffer = malloc(sizeof(char *) * 1200 + 1);
	rd = read(fd, buffer, 1200);
	if (rd <= 0)
		return (84);
	write(1, buffer, rd);
	free(buffer);
	return (0);
}

int open_map(sys_t *sys, char const *filepath)
{
	FILE *fp = fopen(filepath, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	if (!fp)
		return (84);
	sys->map = malloc(sizeof(char *) * 10);
	while ((read = getline(&line, &len, fp)) != -1) {
		sys->map[i] = malloc(sizeof(char) * read + 1);
		sys->map[i] = line;
		line = NULL;
		i++;
	}
	if (i != 10)
		return (84);
	fclose(fp);
	free (line);
	return (0);
}

int init_runner(char **av)
{
	sys_t *sys = malloc(sizeof(sys_t));

	sys->key = 0;
	sys->count_obj = 0;
	if (av[1] != NULL && my_strlen(av[1]) == 2 && av[1][0] == '-'
	&& av[1][1] == 'i' && open_map(sys, av[2]) != 84) {
		sys->key = 1;
		sys->infinite_mod = 1;
		my_window(sys);
		free_options(sys);
	}
	if (open_map(sys, av[1]) != 84) {
		my_window(sys);
		free_options(sys);
	} else
		return (84);
	return (0);
}

int main(int ac, char **av)
{
	if (av[1] != NULL && my_strlen(av[1]) == 2 && av[1][0]
	== '-' && av[1][1] == 'h') {
		print_h(".legend");
		return (0);
	}
	else if (ac != 2 && ac != 3) {
		my_putstr("You must type './my_runner map/your_map'\n");
		return (84);
	}
	if (init_runner(av) == 84)
		return (84);
	return (0);
}
