/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:48:32 by ametta            #+#    #+#             */
/*   Updated: 2021/12/03 11:29:41 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	info->scale = ft_min((WIN_W / info->width), (WIN_H / info->height));
	info->ptr = mlx_init();
	info->win = mlx_new_window(info->ptr, WIN_H, WIN_W, "fdf");
	return (info);
}

int	main(int argc, char **argv)
{
	t_fdf	*info;

	if (argc != 2)
		return (ft_puterror(1));
	info = struct_init(argv[1]);
	mlx_hook(info->win, 2, 1L<<0, key_manager, info);
	mlx_hook(info->win, 17, 1L<<2, fdf_close, info);
	mlx_loop(info->ptr);
	return (0);
}
