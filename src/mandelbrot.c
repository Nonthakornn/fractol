/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:01:30 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/23 20:22:59 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	escape_time_mandel(double x0, double y0);

void	draw_mandelbrot(t_data *data)
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
			data->interate = escape_time_mandel(x0, y0);
			color = get_color(data);
			mlx_put_pixel(data->img, x, y, color);
			y++;
		}
		x++;
	}
}

//Mandelbrot formula: z = z^2 + c
//For Mandelbrot we typically use |z| ≤ 2 (which is equivalent to x² + y² ≤ 4)
//x0 y0 is C constant
//https://www.geogebra.org/m/mfewjrek
/*
z starts at 0 (fixed)
c changes for each pixel (x0, y0)
*/
static int	escape_time_mandel(double x0, double y0)
{
	double	z_real;
	double	z_img;
	double	z_rtemp;
	int		iter;

	z_real = 0;
	z_img = 0;
	iter = 0;
	while (z_real * z_real + z_img * z_img <= 4 && iter < MAX_ITER)
	{
		z_rtemp = (z_real * z_real) - (z_img * z_img) + x0;
		z_img = 2 * z_real * z_img + y0;
		z_real = z_rtemp;
		iter++;
	}
	return (iter);
}
/*
iter 0: z = 0
iter 1: z = 0² + 0 = 0
iter 2: z = 0² + 0 = 0
(Continues forever, never escapes)
Returns MAX_ITER

iter = 0: x = 0, y = 0	// 0² + 0² = 0 ≤ 4
iter = 1: x = 0, y = 0	// 0² + 0² = 0 ≤ 4
iter = 2: x = 0, y = 0	// 0² + 0² = 0 ≤ 4
...keeps going
iter = MAX_ITER: loop stops and returns MAX_ITER

iter 0: z = 0                 |z| = 0
iter 1: z = 0² + 0.5 = 0.5    |z| = 0.5
iter 2: z = 0.25 + 0.5 = 0.75 |z| = 0.75
iter 3: z = 0.56 + 0.5 = 1.06 |z| = 1.06
iter 4: z = 1.12 + 0.5 = 1.62 |z| = 1.62
iter 5: z = 2.62 + 0.5 = 3.12 |z| > 2 (ESCAPES!)
Total iterations: 5

iter 0: z = 0 + 0i            |z| = 0
iter 1: z = 0² + 2 = 2        |z| = 2
iter 2: z = 2² + 2 = 6        |z| > 2 (ESCAPES!)
Total iterations: 2
*/