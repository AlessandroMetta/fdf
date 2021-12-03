/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:48:32 by ametta            #+#    #+#             */
/*   Updated: 2021/12/03 19:35:57 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_puterror(int error)
{
	if (error == 1)
		ft_putendl("usage: ./fdf /map_path");
	return (error);
}

t_fdf	*struct_init(char *file_name)
{
	t_fdf	*info;

	info = malloc(sizeof(t_fdf));
	info->width = 0;
	info->height = 0;
	info->map = parse(file_name, &info->height, &info->width);
	info->scale = ft_min((WIN_W / info->width / 2), (WIN_H / info->height / 2));
	info->ptr = mlx_init();
	info->win = mlx_new_window(info->ptr, WIN_H, WIN_W, "fdf");
	info->img.img = mlx_new_image(info->ptr, WIN_H, WIN_W);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits_per_pixel,
			&info->img.line_length, &info->img.endian);
	mlx_hook(info->win, 2, 1L<<0, key_manager, info);
	mlx_hook(info->win, 17, 1L<<2, fdf_close, info);
	return (info);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
			pix_x += (WIN_W + info->width * info->scale) / 2;
//			pix_y += WIN_H / 2 + info->height / 2;
			pix_y += (WIN_H + info->height * info->scale) / 2;
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
