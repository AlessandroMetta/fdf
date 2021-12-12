/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_utils_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:07:04 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:08:38 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	ft_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_point	ft_distance(t_map ***map, t_draw *draw)
{
	t_point	leftest_pix;
	t_point	highest_pix;
	t_point	offset;

	leftest_pix = ft_pix_leftest(map, draw);
	highest_pix = ft_pix_highest(map, draw);
	offset.x = map[0][0]->pix_x - leftest_pix.x;
	offset.y = map[0][0]->pix_y - highest_pix.y;
	return (offset);
}
