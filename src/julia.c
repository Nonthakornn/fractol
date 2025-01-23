/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:12:19 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/23 20:22:34 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	escape_time_julia(double x0, double y0, t_data *data);

void	draw_julia(t_data *data)
{
	int		x;
	int		y;
	double	x0;
	double	y0;
	int		color;

	x = 0;
	y = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->height)
		{
			x0 = map_x(data, x);
			y0 = map_y(data, y);
			data->interate = escape_time_julia(x0, y0, data);
			color = get_color(data);
			mlx_put_pixel(data->img, x, y, color);
			y++;
		}
		x++;
	}
}

//Julia: z = z² + c, where z is variable and c is fixed
/*
z starts at each pixel point (x0, y0)
c is fixed (data->r, data->i)
*/
static int	escape_time_julia(double x0, double y0, t_data *data)
{
	double	z_real;
	double	z_img;
	double	z_rtemp;
	int		iter;

	z_real = x0;
	z_img = y0;
	iter = 0;
	while (z_real * z_real + z_img * z_img <= 4 && iter < MAX_ITER)
	{
		z_rtemp = (z_real * z_real) - (z_img * z_img) + data->r;
		z_img = 2 * z_real * z_img + data->i;
		z_real = z_rtemp;
		iter++;
	}
	return (iter);
}
