/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:09 by ametta            #+#    #+#             */
/*   Updated: 2021/12/01 12:06:08 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

typedef struct s_map
{
	int	z;
	int	color;
}	t_map;

t_map	**parse(char *file_name, int *height, int *width);

// utils
void	free_split(char **l_split);
void	map_free(t_map **map, int height);
void	map_print(t_map **map, int height, int width);

#endif
