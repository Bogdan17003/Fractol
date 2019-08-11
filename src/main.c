/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:45:21 by bdeomin           #+#    #+#             */
/*   Updated: 2019/07/03 15:50:43 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_error(t_fractol *data)
{
	(void)data;
	write(1, "Fractols allowed:\nmandelbrot\njulia\nburningship\n", 47);
	exit(EXIT_SUCCESS);
}

void	check_input(const char *input, t_fractol *data)
{
	if (!ft_strcmp(input, "mandelbrot"))
		initialization_mandelbrot(data);
	else if (!ft_strcmp(input, "julia"))
		initialization_julia(data);
	else if (!ft_strcmp(input, "burningship"))
		initialization_burningship(data);
	else
		show_error(data);
}

void	calculation(t_fractol *data)
{
	if (data->result == 0)
		check_input(data->text, data);
	if (data->result == 1)
		calculate_mandelbrot(data);
	else if (data->result == 2)
		calculate_julia(data);
	else if (data->result == 3)
		calculate_burningship(data);
}

int		main(int argc, char **argv)
{
	t_fractol	*data;

	if (!(data = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	data->error = 0;
	data->result = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fract'ol");
	data->text = argv[1];
	if (argc != 2)
		show_error(data);
	else
		calculation(data);
	if (data->error == -1)
		return (-1);
	mlx_hook(data->win_ptr, 6, 0, move_julia, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_key_hook(data->win_ptr, hook_keydown, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}
