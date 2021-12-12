/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:48:32 by ametta            #+#    #+#             */
/*   Updated: 2021/12/07 12:57:15 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define ANGLE 0.523599 

void	align(t_fdf *info, int x, int y)
{
	info->map[y][x].pix_x += WIN_H / 2;
	info->map[y][x].pix_y += WIN_W / 2;
	my_mlx_pixel_put(&info->img, info->map[y][x].pix_x, info->map[y][x].pix_y, info->map[y][x].color);
}

void	projection(t_fdf *info, int x, int y)
{
	info->map[y][x].pix_x = (x - y) * cos(ANGLE) * info->scale;
	info->map[y][x].pix_y = ((x + y) * sin(ANGLE) - info->map[y][x].z) * info->scale;
}

void	update_pixels(t_fdf *info, void(*f)(t_fdf *, int, int))
{
	int	x;
	int	y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			f(info, x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*info;

	if (argc != 2)
		return (ft_puterror(1));
	info = struct_init(argv[1]);
	update_pixels(info, &projection);
	update_pixels(info, &align);
	mlx_put_image_to_window(info->ptr, info->win, info->img.img, 0, 0);
	mlx_loop(info->ptr);
	return (0);
}
