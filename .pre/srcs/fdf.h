/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:09 by ametta            #+#    #+#             */
/*   Updated: 2021/12/07 12:01:56 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

#define WIN_H	800
#define WIN_W	600
#define ESC_K 53

typedef struct s_map
{
	int	z;
	int	color;
	int	pix_x;
	int	pix_y;
}	t_map;

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
	t_map	**map;
	int		height;
	int		width;
	int		scale;
	void	*ptr;
	void	*win;
	t_data	img;
}	t_fdf;

t_map	**parse(char *file_name, int *height, int *width);

// utils
void	free_split(char **l_split);
void	map_free(t_map **map, int height);
void	map_print(t_map **map, int height, int width);
int		fdf_close(t_fdf *info);
int		key_manager(int keycode, t_fdf *info);
int		ft_min(int a, int b);
int		ft_puterror(int error);
t_fdf	*struct_init(char *file_name);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
