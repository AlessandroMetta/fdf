/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:50:46 by ametta            #+#    #+#             */
/*   Updated: 2021/11/12 12:52:14 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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

char ***allocate_map(char ***map, int prev_dim)
{
	char	***new;
	int		i;

	i = 0;
	if (!map)
	{
		new = (char ***)malloc(sizeof(char **) * 1);
		if (!new)
			return (NULL);
	}
	else
	{
		new =  (char ***)malloc(sizeof(char **) * (prev_dim + 1));
		while (i < prev_dim)
		{
			new[i] = map[i];
			i++;
		}
	}
	free(map);
	return (new);
}
/*
char ***add_row(char ***map, char **split_line, int prev_dim)
{
	char	***new;
	int		line;
	int		word;

	// alloco il contenitore (formato da varie linee) + 1 (NULL)
	new = (char ***)malloc(sizeof(char **) * prev_dim + 1);
	// alloco quante parole contiene ogni linea + 1 (NULL)
	new[line] = (char **)malloc(sizeof(char *) * num_word + 1);
	// allocco la parola
	new[line][word] = ft_strdup(map[line][word]);
	// alloco la nuova linea e le nuove parole come precedentemnte fatto
}
*/
void	map_create(int fd)
{
	char	*line_red;
	char	**split_ret;
	int		i;

	i = 0;
	while (get_next_line(fd, &line_red))
	{
		split_ret = ft_split(line_red, ' ');
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
	}
	free(line_red);
}

int	main(int argc, char **argv)
{
	int		fd;

	fd = open_file(argc, argv);
	if (fd < 0)
		return (-1);
	map_create(fd);
	close(fd);
	return (0);
}
