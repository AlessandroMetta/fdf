/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:50:46 by ametta            #+#    #+#             */
/*   Updated: 2021/11/15 11:14:18 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_file(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putendl("Wrong number of argument");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("Impossible to open the specific file");
		return (-1);
	}
	return (fd);
}

char	***map_create(int fd)
{
	char	***map;
	int		map_dim;
	char	*line;
	char	**line_split;

	map_dim = 0;
	map = (char ***)malloc(sizeof(char **) * (map_dim + 1));
	map[map_dim] = NULL;
	while (get_next_line(fd, &line))
	{
		line_split = ft_split(line, ' ');
		map = reallocate_map(map, map_dim++, line_split);
		// free_split(line_split);
		free(line);
	}
	free(line);
	return (map);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	***map;

	fd = open_file(argc, argv);
	if (fd < 0)
		return (-1);
	map = map_create(fd);
	free_map(map);
	close(fd);
	return (0);
}
