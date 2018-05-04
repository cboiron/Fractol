/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 02:39:29 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 23:08:19 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	env = init_env();
	env->name = is_fractal(argv);
	if (argc == 2 && env->name)
	{
		env->mlx = mlx_init();
		env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Fract'ol");
		env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
		env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline),
				&(env->endian));
		choose_fractal(env);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_destroy_image(env->mlx, env->img);
		print_info(env);
		if (env->name == 1 && env->julia == 1)
			mlx_hook(env->win, 6, 0, mouse_hook, env);
		mlx_hook(env->win, 4, 0, mouse_clic, env);
		mlx_hook(env->win, 2, 3, get_key, env);
		mlx_loop(env->mlx);
	}
	else
		ft_putendl("usage : ./fractol julia | mandel | ship | jules");
	return (0);
}
