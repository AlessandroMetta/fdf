/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:50:46 by ametta            #+#    #+#             */
/*   Updated: 2021/11/12 18:36:54 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct s_line
{
	char	*line;
	char	**l_split;
	int		dim;
}				t_line;

void free_map(char ***map)
{
	int line = 0;
	int word = 0;

	while (map[line])
	{
		word = 0;
		while (map[line][word])
		{
			free(map[line][word]);
			word++;
		}
		free(map[line][word]);
		free(map[line]);
		line++;
	}
	free(map);
}

int dim_line(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return i;
}

void print_map(char ***map)
{
	int line = 0;
	int word = 0;

	while (map[line])
	{
		word = 0;
		while (map[line][word])
		{
			ft_putstr(map[line][word]);
			write(1, " ", 1);
			word++;
		}
		write(1, "\n", 1);
		line++;
	}
}

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
	ft_putendl("---File open---");
	return (fd);
}

char ***reallocate_map(char ***map, int prev_dim, t_line line/*char **split_line, int prev_dim*/)
{
	char	***new;
	int		i_line;
	int		count_word;
	int		i_word;
	
	i_line = 0;
	// alloco il contenitore (formato da varie linee) + 1 (NULL)
	new = (char ***)malloc(sizeof(char **) * (prev_dim + 1));
	if (!new)
		return (NULL);
	while (i_line < prev_dim)
	{
		count_word = dim_line(map[i_line]);
		// alloco quante parole contiene ogni linea + 1 (NULL)
		new[i_line] = (char **)malloc(sizeof(char *) * (count_word + 1));
		if (!new[i_line])
			return (NULL);
		i_word = 0;
		while (i_word < count_word)
		{
			// allocco la parola
			new[i_line][i_word] = ft_strdup(map[i_line][i_word]);
			free(map[i_line][i_word]);
			i_word++;
		}
		free(map[i_line][i_word]);
		free(map[i_line]);
		new[i_line][count_word] = NULL;
		i_line++;
	}
	// alloco la nuova linea e le nuove parole come precedentemnte fatto
	new[i_line] = (char **)malloc(sizeof(char *) * (line.dim + 1));
	if (!new[i_line])
		return (NULL);
	i_word = 0;
	while (i_word < line.dim)
	{
		new[i_line][i_word] = ft_strdup(line.l_split[i_word]);
		i_word++;
	}
	new[i_line][line.dim] = NULL;
	new[prev_dim + 1] = NULL;
	free(map);
	return (new);
}

void free_split(char **l_split)
{
	int w;

	w = 0;
	while (l_split[w])
		free(l_split[w++]);
	free(l_split[w]);
	free(l_split);
}

void	map_create(int fd)
{
	t_line	line;
	char	***map;
	int		map_dim;

	map_dim = 0;
	map = (char ***)malloc(sizeof(char**) * (map_dim + 1));
	map[0] = NULL;
	while (get_next_line(fd, &line.line))
	{
		line.l_split = ft_split(line.line, ' ');
		line.dim = dim_line(line.l_split);
		map = reallocate_map(map, map_dim++, line);
		free_split(line.l_split);
		free(line.line);
		/*
		while (split_ret[i])
		{
			ft_putendl(split_ret[i]);
			free(split_ret[i]);
			i++;
		}
		free(split_ret);
		split_ret = NULL;
		ft_putendl("------");
		free(line_red);
		i = 0;
		*/
	}
	free(line.line);
	print_map(map);
	free_map(map);
}

int	main(int argc, char **argv)
{
	int		fd;

	fd = open_file(argc, argv);
	if (fd < 0)
		return (-1);
	map_create(fd);
	close(fd);
	ft_putendl("---file close---");
	return (0);
}
