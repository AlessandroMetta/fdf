/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:50:46 by ametta            #+#    #+#             */
/*   Updated: 2021/11/10 12:52:45 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr("Wrong number of argument\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Impossible to open the specific file\n");
		return (1);
	}
	ft_putstr("File open\n");
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		write(1, "\n", 1);
		free(line);
	}
	close(fd);
	return (0);
}
