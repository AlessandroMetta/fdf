/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:48:32 by ametta            #+#    #+#             */
/*   Updated: 2021/12/03 10:53:54 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*info;

	info = malloc(sizeof(t_fdf));
	info->width = 0;
	info->height = 0;
	if (argc != 2)
		return (1);
	info->map = parse(argv[1], &info->height, &info->width);
	//map_print(info->map, info->height, info->width);
	//map_free(info->map, info->height);
	info->ptr = mlx_init();
	info->win = mlx_new_window(info->ptr, WIN_H, WIN_W, "fdf");
	mlx_hook(info->win, 2, 1L<<0, key_manager, info);
	mlx_hook(info->win, 17, 1L<<2, fdf_close, info);
	mlx_loop(info->ptr);
	return (0);
}
