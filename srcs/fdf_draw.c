/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:44:25 by ametta            #+#    #+#             */
/*   Updated: 2021/11/17 12:56:59 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define WHITE 0x00FFFFFF

int ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void iso(int x, int y, t_fdf *this)
{
	int isoX = (x - y) * cos(0.523599);
	int isoY = (x + y) * sin(0.523599) - ft_atoi(this->map.map[x][y]);
	int scale_fator = ft_min((SCREEN_WIDTH / this->map.width / 2), 
			(SCREEN_HEIGHT / this->map.height / 2));

	isoX += SCREEN_WIDTH / 2;
	isoY += (SCREEN_HEIGHT + this->map.height * scale_fator) / 2;
	my_mlx_pixel_put(&this->img, isoX, isoY, WHITE);
}

void draw(t_fdf *this)
{
	int x;
	int y;

	x = 0;
	while (x < this->map.height)
	{
		y = 0;
		while (y < this->map.width)
		{
			iso(x, y, this);
			y++;
		}
		x++;
	}
}
