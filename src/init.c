/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:30:30 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/21 18:23:41by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_mlx(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!data->mlx)
		err_msg("Fail to init mlx");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		err_msg("Fail to create new image butter");
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		err_msg("Fail drawing image to window");
}

static void mandelbrot_data(t_data *data)
{
	data->height = HEIGHT;
	data->width =  WIDTH;
	data->xmax = 1.0;
	data->xmin = -2.0;
	data->ymax = 1.5;
	data->ymin = -1.5;
	data->zoom = 1;
	data->x_center = ((data->xmax + data->xmin) / 2);
	data->y_center = ((data->ymax + data->ymin) / 2);

	
}

static void julia_data(t_data *data)
{
	data->height = HEIGHT;
	data->width = WIDTH;
	data->xmax = 2.0;
	data->xmin = -2.0;
	data->ymax = 2.0;
	data->ymin = -2.0;
	//Finish mandelbot first
}

void	init_fractol(t_data *data, int argc)
{
	init_mlx(data);
	if (argc == 2)
	{
		data->fractal_type = 1;
		mandelbrot_data(data);
	}
	else if (argc == 4)
	{
		data->fractal_type = 2;
		julia_data(data);
	}
	else
		err_msg(ERR_ARGS);
}