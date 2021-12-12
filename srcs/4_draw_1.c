/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_draw_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:06:29 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:08:38 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_map_color(t_img *img, t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	while (y + 1 <= draw->height)
	{
		x = 0;
		while (x + 1 <= draw->width)
		{
			if (x + 1 < draw->width && y + 1 < draw->height)
			{
				ft_line_bresenham_map(img, tmp[y][x], tmp[y][x + 1]);
				ft_line_bresenham_map(img, tmp[y][x], tmp[y + 1][x]);
			}
			if (x + 1 == draw->width && y + 1 < draw->height)
				ft_line_bresenham_map(img, tmp[y][x], tmp[y + 1][x]);
			if (y + 1 == draw->height && x + 1 < draw->width)
				ft_line_bresenham_map(img, tmp[y][x], tmp[y][x + 1]);
			x++;
		}
		y++;
	}
}
