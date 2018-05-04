/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 21:05:10 by cboiron           #+#    #+#             */
/*   Updated: 2017/05/11 23:24:35 by cboiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 800
# define WIDTH 900
# define C_R env->comp.c_r
# define C_I env->comp.c_i
# define Z_R env->comp.z_r
# define Z_I env->comp.z_i
# define TMP env->comp.tmp
# define X1 env->coord.x1
# define X2 env->coord.x2
# define Y1 env->coord.y1
# define Y2 env->coord.y2

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_complex
{
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
}				t_complex;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			endian;
	int			bpp;
	int			sizeline;
	double		mouse_x;
	double		mouse_y;
	float		mov_x;
	float		mov_y;
	int			color[10];
	int			color2[5];
	int			index;
	int			index_2;
	int			name;
	int			it_max;
	int			modulo;
	double		zoom_x;
	double		zoom_y;
	double		zoom;
	int			julia;
	int			info;
	t_complex	comp;
}				t_env;

t_env			*init_env(void);
void			init_coord(t_env *env);
void			put_pixel_to_image(t_env *env, int x, int y, int z);
void			put_pixel_to_image_2(t_env *env, int x, int y, int z);
void			draw_mandelbrot(t_env *env);
void			draw_julia(t_env *env);
void			draw_burning_ship(t_env *env);
void			draw_jules(t_env *env);
void			draw_center(t_env *env);
int				get_key(int key_code, t_env *env);
int				is_fractal(char **argv);
void			choose_fractal(t_env *env);
int				mouse_hook(int x, int y, t_env *env);
int				mouse_clic(int clic, int x, int y, t_env *env);
int				mouse_wheel(int clic, int x, int y, t_env *env);
void			redo(t_env *env);
void			print_info(t_env *env);
#endif
