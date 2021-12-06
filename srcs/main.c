/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:48:32 by ametta            #+#    #+#             */
/*   Updated: 2021/12/06 11:57:04 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	draw(t_fdf *info)
{
	int	x;
	int	y;
	int pix_x;
	int pix_y;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			pix_x = ((x - y) * cos(0.523599)) * info->scale;
			pix_y = ((x + y) * sin(0.523599) - info->map[y][x].z) * info->scale;
//			pix_x += (WIN_W + info->width * info->scale) / 2;
//			pix_y += (WIN_H + info->height * info->scale) / 2;
			pix_x += WIN_H / 2;
			pix_y += WIN_W / 2;
			if (!(pix_x < 0 || pix_x > WIN_H || pix_y < 0 || pix_y > WIN_W))
			if (!(pix_x < 0 || pix_x > WIN_H || pix_y < 0 || pix_y > WIN_W))
				my_mlx_pixel_put(&info->img, pix_x, pix_y, info->map[y][x].color);	
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->ptr, info->win, info->img.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fdf	*info;

	if (argc != 2)
		return (ft_puterror(1));
	info = struct_init(argv[1]);
	draw(info);
	mlx_loop(info->ptr);
	return (0);
}
