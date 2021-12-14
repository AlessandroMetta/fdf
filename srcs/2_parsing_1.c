/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_parsing_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:06:05 by ametta            #+#    #+#             */
/*   Updated: 2021/12/14 14:04:48 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	**parse(char *file_name, int *height, int *width)
{
	t_map	**map;

	get_mapdim(file_name, height, width);
	map = map_create(file_name, *height, *width);
	return (map);
}

int	word_counter(const char *line, const char chr)
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	while (line[i])
	{
		if (line[i] == chr)
			i++;
		else
		{
			word_counter++;
			while (line[i] != '\0' && line[i] != chr)
				i++;
		}
	}
	return (word_counter);
}

void	get_mapdim(char *file_name, int *height, int *width)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_printf("Impossible to open the specific file\n");
		exit(0);
	}
	get_next_line(fd, &line);
	*width = word_counter(line, ' ');
	(*height)++;
	free(line);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (word_counter(line, ' ') != 0)
			(*height)++;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(fd);
}
