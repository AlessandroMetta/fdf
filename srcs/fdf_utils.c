/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:26 by ametta            #+#    #+#             */
/*   Updated: 2021/11/17 11:18:25 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(char **map)
{
	int	line;

	line = 0;
	while (map[line])
	{
		free(map[line]);
		line++;
	}
	free(map[line]);
	free(map);
}

int	dim_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	free_split(char **l_split)
{
	int	w;

	w = 0;
	while (l_split[w])
		free(l_split[w++]);
	free(l_split[w]);
	free(l_split);
}

void	print_map(char **map)
{
	int	line;

	line = 0;
	while (map[line])
	{
		ft_putstr(map[line]);
		write(1, "\n", 1);
		line++;
	}
}
