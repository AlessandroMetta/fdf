/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:44:25 by ametta            #+#    #+#             */
/*   Updated: 2021/11/17 17:13:55 by ametta           ###   ########.fr       */
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

void	iso(int *isoX, int *isoY, int z)
{
	int	x;
	int	y;

	x = *isoX;
	y = *isoY;
	*isoX = (x - y) * cos(0.523599);
	*isoY = (x + y) * sin(0.523599) - z;
}

static void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	iso_projection(int x, int y, t_fdf *this)
{
	int	z;
	int	scale_factor;

	scale_factor = ft_min((SCREEN_WIDTH / this->map.width / 2),
			(SCREEN_HEIGHT / this->map.height / 2));
	z = ft_atoi(this->map.map[y][x]) * scale_factor;
	x *= scale_factor;
	y *= scale_factor;
	x -= (this->map.width * scale_factor) / 2;
	y -= (this->map.height * scale_factor) / 2;
	rotate_x(&y, &z, 0);
	rotate_y(&x, &z, 0);
	rotate_z(&x, &y, 0);
	iso(&x, &y, z);
	x += (SCREEN_WIDTH / 2);
	y += (SCREEN_HEIGHT + this->map.height * scale_factor) / 2;
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
