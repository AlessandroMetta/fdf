/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:03:45 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:08:38 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
	{
		ft_printf("Wrong number of argument\n");
		exit(0);
	}
	init_mlx_and_img(&env);
	env.map = parse(argv[1], &env.draw->height, &env.draw->width);
	update_settings(&env);
	init_pixels(&env.map, env.draw);
	put_img(&env);
	mlx_hook(env.win, 2, 1L << 0, key_hook, &env);
	mlx_hook(env.win, 17, 1L << 2, exit_fdf, &env);
	ft_printf("Successfully reached end of program\n");
	mlx_loop(env.mlx);
	return (0);
}
