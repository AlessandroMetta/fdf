/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:35:30 by ametta            #+#    #+#             */
/*   Updated: 2021/11/17 17:12:28 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	debugging(t_fdf *this)
{
	print_map(this->map.map);
	ft_putstr("width\t");
	ft_putnbr_fd(this->map.width, 1);
	write(1, "\n", 1);
	ft_putstr("height\t");
	ft_putnbr_fd(this->map.height, 1);
	write(1, "\n", 1);
}

int	exit_fdf(t_fdf *this)
{
	debugging(this);
	free_map(this->map.map);
	close(this->fd);
	mlx_destroy_image(this->connect_id, this->img.img);
	mlx_destroy_window(this->connect_id, this->window_id);
	exit(0);
	return (0);
}

int	key_pressed(int keycode, t_fdf *this)
{
	if (keycode == 53)
		exit_fdf(this);
	return (0);
}

void	win_gen(t_fdf *this)
{
	this->connect_id = mlx_init();
	this->window_id = mlx_new_window(this->connect_id, SCREEN_WIDTH,
			SCREEN_HEIGHT, "fdf");
	this->img.img = mlx_new_image(this->connect_id, SCREEN_WIDTH,
			SCREEN_HEIGHT);
	this->img.addr = mlx_get_data_addr(this->img.img,
			&this->img.bits_per_pixel,
			&this->img.line_length, &this->img.endian);
}
