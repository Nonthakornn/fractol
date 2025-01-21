/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:07:01 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/21 21:56:16 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//Mandelbrot formula: z = z^2 + c
//For Mandelbrot we typically use |z| ≤ 2 (which is equivalent to x² + y² ≤ 4)
static int	escape_time_mandel(double x0, double y0)
{
	double	x;
	double	y;
	double	x_temp;
	int		iter;

	x = 0;
	y = 0;
	x_temp = 0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < MAX_ITER)
	{
		x_temp = (x * x) - (y * y) + x0;
		y = 2 * x * y + y0;
		x = x_temp;
		iter++;
	}
	return (iter);
}

void	draw_image(t_data *data)
{
	if (data->fractal_type == 1)
		draw_mandelbrot(data);
	// else if (data->fractal_type == 2)
	// 	draw_julia(data);
	else
		exit(1);
}

void	draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	x0;
	double	y0;
	int color;

	x = 0;
	y = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->height)
		{
			x0 = map_x(data, x);
			y0 = map_y(data, y);
			data->interate = escape_time_mandel(x0, y0);
			color = get_color(data);
			mlx_put_pixel(data->img, x, y, color);
			y++;
		}
		x++;
	}
}
