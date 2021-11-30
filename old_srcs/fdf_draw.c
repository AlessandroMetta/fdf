/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:44:25 by ametta            #+#    #+#             */
/*   Updated: 2021/11/18 12:59:18 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define WHITE 0x00FFFFFF

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	iso(size_t *isoX, size_t *isoY, int z)
{
	int	x;
	int	y;

	x = *isoX;
	y = *isoY;
	*isoX = (x - y) * cos(0.523599);
	*isoY = (x + y) * sin(0.523599) - z;
}

void	iso_projection(size_t x, size_t y, t_fdf *this)
{
	int	scale_factor;
	int	z;

	scale_factor = ft_min((SCREEN_WIDTH / this->map.width / 2),
			(SCREEN_HEIGHT / this->map.height / 2));
	z = ft_atoi(this->map.map[y][x]) * scale_factor;
	x *= scale_factor;
	y *= scale_factor;
	iso(&x, &y, z);
	x += SCREEN_WIDTH / 2;
	y += SCREEN_HEIGHT / 2;
	my_mlx_pixel_put(&this->img, x, y, WHITE);
}

void	draw(t_fdf *this)
{
	int	x;
	int	y;

	y = 0;
	while (y < this->map.height)
	{
		x = 0;
		while (x < this->map.width)
		{
			iso_projection(x, y, this);
			x++;
		}
		y++;
	}
}
