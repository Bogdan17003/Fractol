/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:47:22 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/02 16:24:42 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_plus(int x, int y, t_fractol *data)
{
	data->min_re = (x / data->zoom + data->min_re) - (x / (data->zoom * 1.3));
	data->min_im = (y / data->zoom + data->min_im) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->iteration++;
}

void	zoom_minus(int x, int y, t_fractol *data)
{
	data->min_re = (x / data->zoom + data->min_re) - (x / (data->zoom / 1.3));
	data->min_im = (y / data->zoom + data->min_im) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->iteration--;
}
