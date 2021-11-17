/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:50:46 by ametta            #+#    #+#             */
/*   Updated: 2021/11/17 12:51:02 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	main(int argc, char **argv)
{
	t_fdf	this;

	this.fd = open_file(argc, argv);
	if (this.fd < 0)
		return (-1);
	this.map = map_create(this.fd);
	win_gen(&this);
	mlx_hook(this.window_id, 2, 1L << 0, key_pressed, &this);
	mlx_hook(this.window_id, 17, 1L << 5, exit_fdf, &this);
	draw(&this);
	mlx_put_image_to_window(this.connect_id, this.window_id, this.img.img,
			0, 0);
	mlx_loop(this.connect_id);
	return (0);
}
