/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:45:18 by ametta            #+#    #+#             */
/*   Updated: 2021/12/02 16:51:40 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_mapdim(char *file_name, int *height, int *width)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	(*width) = word_counter(line, ' ');
	(*height)++;
	free(line);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		(*height)++;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
}

t_map	**map_alloc(int height, int width)
{
	t_map	**map;
	int		i;

	i = 0;
	map = (t_map **)malloc(sizeof(t_map *) * height);
	while (i < height)
		map[i++] = (t_map *)malloc(sizeof(t_map) * width);
	return (map);
}

void	put_value(t_map *row, char *line)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_split(line, ' ');
	while (split[j])
	{
		row[j].z = ft_atoi_base(split[j], 10);
		if (!ft_strchr(split[j], ','))
			row[j].color = 0xFFFFFF;
		else
			row[j].color = ft_atoi_base(ft_strchr(split[j], ',') + 3, 16);
		j++;
	}
	free_split(split);
}

t_map	**map_create(char *file_name, int height, int width)
{
	int		i;
	t_map	**map;
	char	*line;
	int		fd;

	i = 0;
	line = NULL;
	map = map_alloc(height, width);
	fd = open(file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		put_value(map[i], line);
		i++;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
	return (map);
}

t_map	**parse(char *file_name, int *height, int *width)
{
	t_map	**map;

	get_mapdim(file_name, height, width);
	map = map_create(file_name, *height, *width);
	return (map);
}
