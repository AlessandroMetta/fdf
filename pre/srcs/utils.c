#include "fdf.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_puterror(int error)
{
	if (error == 1)
		ft_putendl("usage: ./fdf /map_path");
	return (error);
}

t_fdf	*struct_init(char *file_name)
{
	t_fdf	*info;

	info = malloc(sizeof(t_fdf));
	info->width = 0;
	info->height = 0;
	info->map = parse(file_name, &info->height, &info->width);
	info->scale = ft_min((WIN_W / info->width / 2), (WIN_H / info->height / 2));
	info->ptr = mlx_init();
	info->win = mlx_new_window(info->ptr, WIN_H, WIN_W, "fdf");
	info->img.img = mlx_new_image(info->ptr, WIN_H, WIN_W);
	info->img.addr = mlx_get_data_addr(info->img.img, &info->img.bits_per_pixel,
			&info->img.line_length, &info->img.endian);
	mlx_hook(info->win, 2, 1L<<0, key_manager, info);
	mlx_hook(info->win, 17, 1L<<2, fdf_close, info);
	return (info);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < WIN_H && y > 0 && y < WIN_W)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
