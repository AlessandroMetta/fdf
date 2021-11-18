/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:09 by ametta            #+#    #+#             */
/*   Updated: 2021/11/18 12:58:52 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h> 
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 800

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_map
{
	char	***map;
	int		width;
	int		height;
}				t_map;

typedef struct s_fdf
{
	int		fd;
	t_map	map;
	void	*connect_id;
	void	*window_id;
	t_data	img;
}				t_fdf;

void	free_map(char ***map);
int		dim_line(char **line);
void	free_split(char **l_split);
void	print_map(char ***map);
t_map	map_create(int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_fdf(t_fdf *this);
int		key_pressed(int keycode, t_fdf *this);
void	win_gen(t_fdf *this);
void	draw(t_fdf *this);

#endif
