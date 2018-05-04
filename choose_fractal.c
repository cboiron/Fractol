/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 02:41:55 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 22:27:45 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_fractal(char **argv)
{
	if (argv[1])
	{
		if (ft_strcmp(argv[1], "julia") == 0)
			return (1);
		else if (ft_strcmp(argv[1], "mandel") == 0)
			return (2);
		else if (ft_strcmp(argv[1], "ship") == 0)
			return (3);
		else if (ft_strcmp(argv[1], "jules") == 0)
			return (4);
	}
	return (0);
}

void	choose_fractal(t_env *env)
{
	if (env->name == 1)
	{
		draw_julia(env);
		draw_center(env);
	}
	else if (env->name == 2)
		draw_mandelbrot(env);
	else if (env->name == 3)
		draw_burning_ship(env);
	else if (env->name == 4)
		draw_jules(env);
}
