/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 06:10:43 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 23:21:08 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_info(t_env *env)
{
	char	*str;

	mlx_string_put(env->mlx, env->win, 10, 25, 0x0FF3030, "iteration = ");
	str = ft_itoa(env->it_max);
	mlx_string_put(env->mlx, env->win, 130, 25, 0x0FF3030, str);
	str = ft_itoa(env->modulo);
	mlx_string_put(env->mlx, env->win, 10, 50, 0x0FF3030, "modulo = ");
	mlx_string_put(env->mlx, env->win, 130, 50, 0x0FF3030, str);
	if (env->info)
	{
		mlx_string_put(env->mlx, env->win, 10, 75, 0x0FF3030,
				"c and v for colors");
		mlx_string_put(env->mlx, env->win, 10, 100, 0x0FF3030, "1234 : modulo");
		mlx_string_put(env->mlx, env->win, 10, 125, 0x0FF3030,
				"arrows to move");
		mlx_string_put(env->mlx, env->win, 10, 150, 0x0FF3030,
				"+ - : iteration");
		mlx_string_put(env->mlx, env->win, 10, 175, 0x0FF3030, "scroll : zoom");
		mlx_string_put(env->mlx, env->win, 10, 200, 0x0FF3030,
				"space : stop variation (julia)");
	}
	else
		mlx_string_put(env->mlx, env->win, 10, 75, 0x0FF3030, "h for help");
}
