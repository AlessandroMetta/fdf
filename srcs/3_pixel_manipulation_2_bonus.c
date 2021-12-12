/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_pixel_manipulation_2_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:06:22 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:08:38 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_up(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].pix_y += MOVEMENT_STEP;
}

void	move_down(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].pix_y -= MOVEMENT_STEP;
}

void	move_left(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].pix_x += MOVEMENT_STEP;
}

void	move_right(t_map ***map, int x, int y, t_draw *draw)
{
	t_map	**tmp;

	if (draw)
		;
	tmp = *map;
	tmp[y][x].pix_x -= MOVEMENT_STEP;
}

void	zoom(t_env *env, float value)
{
	if ((value == 2 && env->draw->scale * 2 < 300) || \
		(value == 0.5 && env->draw->scale / 2 != 0))
	{
		env->draw->scale *= value;
		init_pixels(&env->map, env->draw);
		put_img(env);
	}
}
