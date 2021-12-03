/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 10:51:45 by ametta            #+#    #+#             */
/*   Updated: 2021/12/03 10:53:07 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_close(t_fdf *info)
{
	map_free(info->map, info->height);
	free(info);
	exit(0);
	return (0);
}

int	key_manager(int keycode, t_fdf *info)
{
	if (keycode == ESC_K)
		fdf_close(info);
	return (0);
}
