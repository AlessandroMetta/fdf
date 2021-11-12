/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:50:46 by ametta            #+#    #+#             */
/*   Updated: 2021/11/12 11:36:13 by ametta           ###   ########.fr       */
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

void	map_create(int fd)
{
	char	*line_red;
	char	**mat;
	int		i;

	i = 0;
	while (get_next_line(fd, &line_red))
	{
		mat = ft_split(line_red, ' ');
		while (mat[i])
		{
			ft_putendl(mat[i]);
			free(mat[i]);
			i++;
		}
		free(mat[i]);
		free(mat);
		mat = NULL;
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
