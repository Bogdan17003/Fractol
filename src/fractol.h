/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:37:17 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/03 15:49:52 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>

# define HEIGHT 1200
# define WIDTH 1200

typedef struct	s_fractol
{
	void		*mlx_ptr;
	void		*win_ptr;

	const char	*text;

	unsigned	x;
	unsigned	y;

	double		min_re;
	double		min_im;
	unsigned	iteration;

	double		c_im;
	double		c_re;
	double		z_re;
	double		z_im;
	double		z_re2;
	double		z_im2;

	double		c_im_const;
	double		c_re_const;

	double		zoom;
	double		x1;
	double		y1;

	int			result;
	int			error;
}				t_fractol;

unsigned		make_color(int red, int green, int blue);
void			putpixel(t_fractol *data, unsigned color);
void			calculate_collor(t_fractol *sdata, unsigned n);
void			calculation(t_fractol *data);

void			initialization_mandelbrot(t_fractol *data);
void			calculate_mandelbrot(t_fractol *data);

void			initialization_julia(t_fractol *data);
void			calculate_julia(t_fractol *data);
int				move_julia(int x, int y, t_fractol *data);

void			initialization_burningship(t_fractol *data);
void			calculate_burningship(t_fractol *data);

void			initialization_newton(t_fractol *data);
void			calculate_newton(t_fractol *data);

int				mouse_hook(int mousecode, int x, int y, t_fractol *data);
int				hook_keydown(int key, t_fractol *data);

void			zoom_plus(int x, int y, t_fractol *data);
void			zoom_minus(int x, int y, t_fractol *data);

void			show_error(t_fractol *data);

#endif
