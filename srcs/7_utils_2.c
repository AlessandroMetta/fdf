/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_utils_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:07:09 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:08:38 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_pix_lowest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.y < tmp[y][x].pix_y)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

t_point	ft_pix_highest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.y > tmp[y][x].pix_y)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

t_point	ft_pix_rightest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.x < tmp[y][x].pix_x)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}

t_point	ft_pix_leftest(t_map ***map, t_draw *draw)
{
	t_map	**tmp;
	t_point	point;
	int		x;
	int		y;

	tmp = *map;
	y = 0;
	x = 0;
	point.x = tmp[y][x].pix_x;
	point.y = tmp[y][x].pix_y;
	while (y < draw->height)
	{
		x = 0;
		while (x < draw->width)
		{
			if (point.x > tmp[y][x].pix_x)
			{
				point.x = tmp[y][x].pix_x;
				point.y = tmp[y][x].pix_y;
			}
			x++;
		}
		y++;
	}
	return (point);
}
