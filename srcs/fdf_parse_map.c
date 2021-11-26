/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_realloc_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:16:10 by ametta            #+#    #+#             */
/*   Updated: 2021/11/26 18:29:22 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*new_raw(char *line_red, int height)
{
	t_map	*raw;
	int		i;
	int		x;

	x = 0;
	i = 0;
	raw = NULL;
	while (line_red[i])
	{
		ft_lstadd_back(&raw, ft_lstnew(x, height, ft_atoi(line_red + i), 0));
		while (line_red[i] != ' ' && line_red[i] != '\0')
			i++;
		while (line_red[i] == ' ' && line_red[i] != '\0')
			i++;
		x++;
	}
	return (raw);
}

t_map	*ft_lstlast(t_map *lst)
{
	t_map	*last;

	last = lst;
	while (last->down)
		last = last->down;
	return (last);
}

void	ft_mapfree(t_map *map)
{
	if (map->down)
		ft_mapfree(map->down);
	if (map->next)
		ft_mapfree(map->next);
	free(map);
}

void	ft_heightprint(t_map *map)
{
	ft_putnbr_fd(map->z, 1);
	if (map->color > 0)
	{
		ft_putnbr_fd(map->z, 1);
		write(1, ",", 1);
	}
	write(1, "\t", 1);
	if (map->next)
		ft_heightprint(map->next);
}

void	ft_mapprint(t_map *map)
{
	ft_heightprint(map->next);
	write(1, "\n", 1);
	if (map->down)
		ft_mapprint(map->down);
}

char	***map_create(int fd)
{
	char	*line_red;
	int		height;
	t_map	*map;

	height = 0;
	while (get_next_line(fd, &line_red))
	{
		if (height == 0)
			map = new_raw(line_red, height);
		else
			ft_lstlast(map)->down = new_raw(line_red, height);
		free(line_red);
		height++;
	}
	free(line_red);
	ft_mapprint(map);
	ft_mapfree(map);
	return (NULL);
}
