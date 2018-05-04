/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 03:59:49 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 22:21:21 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc(t_env *env, int x, int y)
{
	int		i;

	C_R = ((double)x - WIDTH / 2) / env->zoom + env->mov_x + env->zoom_x;
	C_I = ((double)y - HEIGHT / 2) / env->zoom + env->mov_y + env->zoom_y;
	Z_R = 0;
	Z_I = 0;
	i = 0;
	while (Z_R * Z_R + Z_I * Z_I < 4 && i < env->it_max)
	{
		TMP = Z_R;
		Z_R = (Z_R * Z_R - Z_I * Z_I) + C_R;
		Z_I = (2 * Z_I * TMP) + C_I;
		i++;
	}
	if (i == env->it_max)
		put_pixel_to_image(env, x, y, -1);
	else
		put_pixel_to_image(env, x, y, (i * env->modulo));
}

void		draw_mandelbrot(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			calc(env, x, y);
			y++;
		}
		x++;
	}
}
