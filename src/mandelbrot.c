/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:36:47 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/02 17:01:25 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialization_mandelbrot(t_fractol *data)
{
	data->iteration = 50;
	data->zoom = 500;
	data->min_re = -1.5;
	data->min_im = -1.2;
	data->result = 1;
}

void	calculate_mandelbrot(t_fractol *data)
{
	unsigned n;

	data->y = -1;
	while (++(data->y) < HEIGHT)
	{
		data->x = -1;
		data->c_im = data->y / data->zoom + data->min_im;
		while (++(data->x) < WIDTH)
		{
			data->c_re = data->x / data->zoom + data->min_re;
			data->z_re = data->c_re;
			data->z_im = data->c_im;
			n = -1;
			while (++n < data->iteration)
			{
				data->z_re2 = data->z_re * data->z_re;
				data->z_im2 = data->z_im * data->z_im;
				if (data->z_re2 + data->z_im2 > 4.0)
					break ;
				data->z_im = 2 * data->z_re * data->z_im + data->c_im;
				data->z_re = data->z_re2 - data->z_im2 + data->c_re;
			}
			calculate_collor(data, n);
		}
	}
}
