/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 08:49:09 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 23:25:23 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		redo(t_env *env)
{
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->sizeline),
			&(env->endian));
	choose_fractal(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	print_info(env);
	mlx_loop(env->mlx);
}

int			get_key2(int key_code, t_env *env)
{
	if (key_code == 49 && env->julia == 1)
		env->julia = 0;
	else if (key_code == 49 && env->julia == 0)
		env->julia = 1;
	if (key_code == 119)
	{
		env->zoom = 200;
		env->zoom_x = 0;
		env->zoom_y = 0;
		env->it_max = 100;
	}
	if (key_code == 8 && env->index < 10)
		env->index++;
	else if (env->index == 10)
		env->index = 0;
	if (key_code == 9 && env->index_2 < 5)
		env->index_2++;
	else if (env->index_2 == 5)
		env->index_2 = 0;
	if (key_code == 4 && env->info == 0)
		env->info = 1;
	else if (key_code == 4)
		env->info = 0;
	redo(env);
	return (0);
}

int			get_key(int key_code, t_env *env)
{
	if (key_code == 53)
		exit(EXIT_SUCCESS);
	if (key_code == 123)
		env->mov_x += 0.1;
	if (key_code == 124)
		env->mov_x -= 0.1;
	if (key_code == 125)
		env->mov_y -= 0.1;
	if (key_code == 126)
		env->mov_y += 0.1;
	if (key_code == 78 && env->it_max >= 20)
		env->it_max -= 10;
	if (key_code == 69 && env->it_max <= 700)
		env->it_max += 10;
	if (key_code == 18 && env->modulo > -2000000)
		env->modulo--;
	if (key_code == 19 && env->modulo < 2000000)
		env->modulo++;
	if (key_code == 20 && env->modulo > -2000000)
		env->modulo -= 100;
	if (key_code == 21 && env->modulo < 2000000)
		env->modulo += 100;
	get_key2(key_code, env);
	return (0);
}

void		put_pixel_to_image(t_env *env, int x, int y, int z)
{
	int		pos;

	pos = (x * (*env).bpp / 8) + ((y) * (*env).sizeline);
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT && z == -1)
	{
		env->data[pos] = (env->color2[env->index_2]) % 256;
		env->data[pos + 1] = ((env->color2[env->index_2]) / 256) % 256;
		env->data[pos + 2] = ((env->color2[env->index_2]) / (256 * 256)) % 256;
		env->data[pos + 3] = 0;
	}
	else if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		env->data[pos] = (env->color[env->index] + z) % 256;
		env->data[pos + 1] = ((env->color[env->index] + z) / 256) % 256;
		env->data[pos + 2] = ((env->color[env->index] + z) / (256 * 256)) % 256;
		env->data[pos + 3] = 0;
	}
}
