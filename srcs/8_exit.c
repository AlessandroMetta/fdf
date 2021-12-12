/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:07:17 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:08:38 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_fdf(t_env *env)
{
	map_free(env->map, env->draw->height);
	free(env->draw);
	mlx_destroy_image(env->mlx, env->img->img);
	free(env->img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}

void	map_free(t_map **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}
