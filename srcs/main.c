/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:48:32 by ametta            #+#    #+#             */
/*   Updated: 2021/12/02 16:43:25 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_test
{
	t_map	**map;
	int	height;
	int	width;
	void	*ptr;
	void	*win;
}	t_test;

int	ft_exit(int keycode, t_test *info)
{
	if (keycode == 53)
	{
		map_free(info->map, info->height);
		free(info);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_test	*info;

	info = malloc(sizeof(t_test));
	info->width = 0;
	info->height = 0;
	if (argc != 2)
		return (1);
	info->map = parse(argv[1], &info->height, &info->width);
	map_print(info->map, info->height, info->width);
	map_free(info->map, info->height);
	// info->ptr = mlx_init();
	// info->win = mlx_new_window(info->ptr, WIN_H, WIN_W, "fdf");
	// mlx_key_hook(info->win, ft_exit, info);
	// mlx_loop(info->ptr);
	return (0);
}
