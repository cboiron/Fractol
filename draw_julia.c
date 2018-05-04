/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 04:57:19 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 23:20:14 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc(t_env *env, int x, int y)
{
	int		i;

	Z_R = ((double)x - WIDTH / 2) / env->zoom + env->mov_x + env->zoom_x;
	Z_I = ((double)y - HEIGHT / 2) / env->zoom + env->mov_y + env->zoom_y;
	C_R = 0.285 + env->mouse_x;
	C_I = 0.01 + env->mouse_y;
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

void		draw_julia(t_env *env)
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
