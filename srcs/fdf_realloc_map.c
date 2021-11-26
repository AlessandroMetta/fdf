/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_realloc_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:16:10 by ametta            #+#    #+#             */
/*   Updated: 2021/11/26 12:27:47 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char *ft_append(char *s1, char *s2)
{
	char	*s;
	int	i;
	int	j;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s)
		return (NULL);
	while (s1[j] != '\0')
		s[i++] = s1[j++];
	j = 0;
	s[i++] = '\n';
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i++] = '\0';
	free(s1);
	return (s);
}

void	print_map(char ***map, int height)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			ft_putstr(map[i][j]);
			write(1, "\t", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void free_map(char ***map, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free_split(map[i]);
		i++;
	}
	free(map);
}

char ***map_populate(char **buff_split, int height)
{
	int		i;
	char	***map;

	map = malloc(sizeof(char **) * height);
	i = 0;
	while (i < height)
	{
		map[i] = ft_split(buff_split[i], ' ');
		i++;
	}
	return (map);
}

char	***map_create(int fd)
{
	char	*buff;
	char	*line_red;
	char	**buff_split;
	int		height;
	char	***map;

	buff = NULL;
	height = 0;
	while (get_next_line(fd, &line_red))
	{
		if (!buff)
			buff = ft_strdup(line_red);
		else
			buff = ft_append(buff, line_red);
		free(line_red);
		height++;
	}
	free(line_red);
	buff_split = ft_split(buff, '\n');
	free(buff);
	map = map_populate(buff_split, height);
	free_split(buff_split);
//	print_map(map, height);
	free_map(map, height);
	return (NULL);
}
