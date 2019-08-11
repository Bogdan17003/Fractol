/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:58:41 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/03 15:49:29 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		move_julia(int x, int y, t_fractol *data)
{
	if (data->result == 2)
	{
		data->c_re_const = 1.0 / 600.0 * (double)x - 1.0;
		data->c_im_const = 1.0 / 600.0 * (double)y - 1.0;
		calculation(data);
	}
	return (0);
}

void	initialization_julia(t_fractol *data)
{
	data->c_im_const = -0.3842;
	data->c_re_const = -0.70176;
	data->iteration = 50;
	data->zoom = 450;
	data->min_re = -1.3;
	data->min_im = -1.3;
	data->result = 2;
}

void	calculate_julia(t_fractol *data)
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
				data->z_im = 2 * data->z_re * data->z_im + data->c_im_const;
				data->z_re = data->z_re2 - data->z_im2 + data->c_re_const;
			}
			calculate_collor(data, n);
		}
	}
}
