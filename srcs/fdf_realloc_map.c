/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_realloc_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:16:10 by ametta            #+#    #+#             */
/*   Updated: 2021/11/15 11:43:35 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** alloco il contenitore (formato da varie linee) + 1 (NULL)
** alloco quante parole contiene ogni linea + 1 (NULL)
** allocco la parola
** alloco la nuova linea e le nuove parole come precedentemnte fatto
*/
char	***reallocate_map(char ***old_map, int prev_dim, char **new_line)
{
	char	***new_map;
	int		i;

	i = 0;
	new_map = (char ***)malloc(sizeof(char **) * (prev_dim + 1));
	if (!new_map)
		return (NULL);
	while (i < prev_dim)
	{
		new_map[i] = old_map[i];
		i++;
	}
	free(old_map);
	new_map[i] = new_line;
	new_map[prev_dim + 1] = NULL;
	return (new_map);
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
		free(line);
	}
	free(line);
	return (map);
}
