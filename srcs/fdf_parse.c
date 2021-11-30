#include "fdf.h"
#include <inttypes.h>

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

void	free_split(char **l_split)
{
	int	w;

	w = 0;
	while (l_split[w])
		free(l_split[w++]);
	free(l_split[w]);
	free(l_split);
}


t_map	**map_create(char *file_name, int height, int width)
{
	int		i;
	int		j;
	t_map	**map;
	char	*line;
	char	**split;
	int		fd;

	i = 0;
	line = NULL;
	map = NULL;
	map = (t_map **)malloc(sizeof(t_map *) * height);
	while (i < height)
		map[i++] = (t_map *)malloc(sizeof(t_map) * width);
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		split = ft_split(line, ' ');
		j = 0;
		while (split[j])
		{
			map[i][j].z = atoi(split[j]);
			if (!ft_strchr(split[j], ','))
				map[i][j].color = 0xFFFFFF;
			else
				map[i][j].color = strtol(ft_strchr(split[j], ',') + 1, NULL, 16); 
			j++;
		}
		i++;
		free_split(split);
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
