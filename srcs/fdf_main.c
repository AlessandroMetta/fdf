#include "fdf.h"
#include <stdio.h>

void map_free(t_map **map, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

void	ft_putnbr_base(int nbr, char *ref_base, int base)
{
	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, ref_base, base);
		ft_putnbr_base(nbr % base, ref_base, base);
	}
	else
		write(1, &ref_base[nbr], 1);
}

void map_print(t_map **map, int height, int width)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_putnbr_fd((map[i][j].z), 1);
			write(1, ",", 1);
			ft_putnbr_base(map[i][j].color, "0123456789ABCDEF", 16);
			write(1, "\t", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_map **map;
	int		height;
	int		width;

	width = 0;
	height = 0;
	if (argc != 2)
		return (1);
	map = parse(argv[1], &height, &width);
	map_print(map, height, width);
	map_free(map, height);
	return (0);
}
