/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 02:57:50 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 23:24:59 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** 1 = julia
** 2 = mandel
** 3 = ship
** 4 = jules
*/

void	init_color(t_env *env)
{
	env->color[0] = 0x0FFFFFF;
	env->color[1] = 0x9A32CD;
	env->color[2] = 0x87CEEB;
	env->color[3] = 0x8B8386;
	env->color[4] = 0x66CD00;
	env->color[5] = 0x54FF9F;
	env->color[6] = 0x7A378B;
	env->color[7] = 0xFF4040;
	env->color[8] = 0xF4A460;
	env->color[9] = 0xF5DEB3;
	env->color2[0] = 0x0000000;
	env->color2[1] = 0xE0FFFF;
	env->color2[2] = 0xCDB83B;
	env->color2[3] = 0xFF8247;
	env->color2[4] = 0xFF8C00;
}

t_env	*init_env(void)
{
	t_env *env;

	env = malloc(sizeof(t_env));
	if (!env)
		exit(EXIT_FAILURE);
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->mouse_x = 0;
	env->mouse_y = 0;
	env->mov_x = 0;
	env->mov_y = 0;
	env->it_max = 100;
	env->index = 0;
	env->index_2 = 0;
	env->modulo = 40;
	env->zoom_x = 0;
	env->zoom_y = 0;
	env->zoom = 200;
	env->julia = 1;
	env->info = 0;
	init_color(env);
	return (env);
}
