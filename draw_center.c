/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 07:09:15 by cboiron           #+#    #+#             */
/*   Updated: 2017/04/16 06:34:50 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_center(t_env *env)
{
	int	x;
	int	y;

	x = WIDTH / 2 - 30;
	while (x < WIDTH / 2 + 30)
	{
		put_pixel_to_image(env, x, HEIGHT / 2, 10);
		x++;
	}
	y = HEIGHT / 2 - 30;
	while (y < HEIGHT / 2 + 30)
	{
		put_pixel_to_image(env, WIDTH / 2, y, 10);
		y++;
	}
}
