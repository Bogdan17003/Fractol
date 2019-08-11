/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:39:46 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/02 16:50:48 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		putpixel(t_fractol *data, unsigned color)
{
	if (data->x < WIDTH && data->y < HEIGHT)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, color);
}

unsigned	make_color(int red, int green, int blue)
{
	unsigned color;

	color = 0;
	color = color | (red << 16);
	color = color | (green << 8);
	color = color | blue;
	return (color);
}

void		calculate_collor(t_fractol *data, unsigned n)
{
	int		color;
	double	t;
	int		r;
	int		g;
	int		b;

	if (n == data->iteration)
		putpixel(data, make_color(0, 0, 0));
	else
	{
		color = 256;
		t = (double)n / (double)data->iteration;
		n = (int)(t * (double)pow(color, 3));
		b = n / (color * color);
		r = (n - b * color * color) / color;
		g = (n - b * color * color) - r * color;
		putpixel(data, make_color(r, g, b));
	}
}
