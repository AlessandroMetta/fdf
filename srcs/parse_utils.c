/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:46:30 by ametta            #+#    #+#             */
/*   Updated: 2021/12/01 12:21:03 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **l_split)
{
	int	w;

	w = 0;
	while (l_split[w])
		free(l_split[w++]);
	free(l_split[w]);
	free(l_split);
}

void	map_free(t_map **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

void	ft_putnbr_base(int nbr, int base)
{
	char	*ref_base = "0123456789ABCDEF";

	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base);
		ft_putnbr_base(nbr % base, base);
	}
	else
		write(1, &ref_base[nbr], 1);
}

void	map_print(t_map **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			ft_putnbr_fd(map[i][j].z, 1);
			write(1, ",", 1);
			ft_putnbr_base(map[i][j].color, 16);
			write(1, "\t", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
