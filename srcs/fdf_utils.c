#include "fdf.h"

void free_map(char ***map)
{
	int line = 0;
	int word = 0;

	while (map[line])
	{
		word = 0;
		while (map[line][word])
		{
			free(map[line][word]);
			word++;
		}
		free(map[line][word]);
		free(map[line]);
		line++;
	}
	free(map);
}

int dim_line(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return i;
}

void free_split(char **l_split)
{
	int w;

	w = 0;
	while (l_split[w])
		free(l_split[w++]);
	free(l_split[w]);
	free(l_split);
}

void print_map(char ***map)
{
	int line = 0;
	int word = 0;

	while (map[line])
	{
		word = 0;
		while (map[line][word])
		{
			ft_putstr(map[line][word]);
			write(1, " ", 1);
			word++;
		}
		write(1, "\n", 1);
		line++;
	}
}
