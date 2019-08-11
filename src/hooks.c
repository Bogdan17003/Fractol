/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:14:19 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/02 16:15:01 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1)
		zoom_plus(x, y, data);
	else if (mousecode == 5 || mousecode == 2)
		zoom_minus(x, y, data);
	calculation(data);
	return (0);
}

int		hook_keydown(int key, t_fractol *data)
{
	(void)data;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
