/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:14:03 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/03 14:12:00 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initialization_burningship(t_fractol *data)
{
	data->min_re = -1.85;
	data->min_im = -0.15;
	data->iteration = 60;
	data->zoom = 4000;
	data->result = 3;
}

void	calculate_burningship(t_fractol *data)
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
			while (++n < data->iteration &&
				data->z_re * data->z_re + data->z_im * data->z_im < 4)
			{
				data->c_re_const = data->z_re * data->z_re - data->z_im
												* data->z_im + data->c_re;
				data->z_im = fabs(2 * data->z_re * data->z_im) + data->c_im;
				data->z_re = fabs(data->c_re_const);
			}
			calculate_collor(data, n);
		}
	}
}
