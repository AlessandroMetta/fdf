/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_realloc_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:16:10 by ametta            #+#    #+#             */
/*   Updated: 2021/11/17 11:18:32 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** alloco il contenitore (formato da varie linee) + 1 (NULL)
** alloco quante parole contiene ogni linea + 1 (NULL)
** allocco la parola
** alloco la nuova linea e le nuove parole come precedentemnte fatto
*/
char	***reallocate_map(t_map old_map, char **new_line)
{
	char	***new_map;
	int		i;

	i = 0;
	new_map = (char ***)malloc(sizeof(char **) * (old_map.height + 1));
	if (!new_map)
		return (NULL);
	while (i < old_map.height)
	{
		new_map[i] = old_map.map[i];
		i++;
	}
	free(old_map.map);
	new_map[i] = new_line;
	new_map[old_map.height + 1] = NULL;
	return (new_map);
}

t_map	map_create(int fd)
{
	t_map	map;
	char	*line;
	char	**line_split;

	map.height = 0;
	map.width = 0;
	map.map = (char ***)malloc(sizeof(char **) * (map.height + 1));
	map.map[map.height] = NULL;
	while (get_next_line(fd, &line))
	{
		line_split = ft_split(line, ' ');
		map.map = reallocate_map(map, line_split);
		map.width = dim_line(line_split);
		map.height++;
		free(line);
	}
	free(line);
	return (map);
}
