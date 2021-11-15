/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:09 by ametta            #+#    #+#             */
/*   Updated: 2021/11/15 11:28:33 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

void	free_map(char ***map);
int		dim_line(char **line);
void	free_split(char **l_split);
void	print_map(char ***map);
char	***reallocate_map(char ***map, int prev_dim, char **line);

#endif
