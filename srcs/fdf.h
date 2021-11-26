/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:09 by ametta            #+#    #+#             */
/*   Updated: 2021/11/26 17:34:10 by ametta           ###   ########.fr       */
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
	int		pos_x;
	int		pos_y;
	int		z;
	int		color;
	struct s_map	*next;
	struct s_map	*down;
}				t_map;

typedef struct s_fdf
{
	int		fd;
	t_map	map;
	void	*connect_id;
	void	*window_id;
	t_data	img;
}				t_fdf;

int		dim_line(char **line);
void	free_split(char **l_split);
char	***map_create(int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_fdf(t_fdf *this);
int		key_pressed(int keycode, t_fdf *this);
void	win_gen(t_fdf *this);
void	draw(t_fdf *this);
t_map	*ft_lstnew(int x, int y, int z, int color);
void	ft_lstadd_back(t_map **lst, t_map *new);

#endif
