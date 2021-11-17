/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:09 by ametta            #+#    #+#             */
/*   Updated: 2021/11/17 10:35:10 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_data
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
}				t_fdf;

void	free_map(char ***map);
int		dim_line(char **line);
void	free_split(char **l_split);
void	print_map(char ***map);
char	***map_create(int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_fdf(t_fdf *this);
int		key_pressed(int keycode, t_fdf *this);
void	win_gen(t_fdf *this);

#endif
