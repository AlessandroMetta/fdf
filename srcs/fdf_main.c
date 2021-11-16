/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:50:46 by ametta            #+#    #+#             */
/*   Updated: 2021/11/16 16:22:16 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_fdf
{
	int		fd;
	char	***map;
	void	*connect_id;
	void	*window_id;
	t_data	img;
}	t_fdf;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	open_file(int argc, char **argv)
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		ft_putendl("Wrong number of argument");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("Impossible to open the specific file");
		return (-1);
	}
	return (fd);
}

int	exit_fdf(t_fdf *this)
{
	free_map(this->map);
	close(this->fd);
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
	this->window_id = mlx_new_window(this->connect_id, 500, 500, "fdf");
	this->img.img = mlx_new_image(this->connect_id, 500, 500);
	this->img.addr = mlx_get_data_addr(this->img.img, &this->img.bits_per_pixel,
									&this->img.line_length, &this->img.endian);
}

int	main(int argc, char **argv)
{
	t_fdf	this;

	this.fd = open_file(argc, argv);
	if (this.fd < 0)
		return (-1);
	this.map = map_create(this.fd);
	map_dim();
	/*
	win_gen(&this);
	mlx_hook(this.window_id, 2, 1L<<0, key_pressed, &this);
	mlx_hook(this.window_id, 17, 1L<<5, exit_fdf, &this);
	mlx_put_image_to_window(this.connect_id, this.window_id, this.img.img, 0, 0);
	mlx_loop(this.connect_id);
	*/
	exit_fdf(this);
	return (0);
}
