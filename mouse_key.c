/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 04:14:00 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 23:21:24 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int x, int y, t_env *env)
{
	if (env->julia == 1)
	{
		env->mouse_x = (double)(x - WIDTH / 2) / WIDTH;
		env->mouse_y = (double)(y - HEIGHT / 2) / HEIGHT;
		redo(env);
	}
	return (0);
}

int	mouse_clic(int clic, int x, int y, t_env *env)
{
	if (clic == 5)
	{
		env->zoom_x += (double)(x - WIDTH / 2) / env->zoom;
		env->zoom_y += (double)(y - HEIGHT / 2) / env->zoom;
		env->zoom *= 1.5;
		env->it_max += 10;
	}
	else if (clic == 4)
	{
		env->zoom_x += (double)(x - WIDTH / 2) / env->zoom;
		env->zoom_y += (double)(y - HEIGHT / 2) / env->zoom;
		env->zoom /= 1.5;
	}
	redo(env);
	return (0);
}
