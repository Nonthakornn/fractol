/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:00:56 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/22 20:53:03 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_image(t_data *data)
{
	if (data->fractal_type == 1)
		draw_mandelbrot(data);
	else if (data->fractal_type == 2)
		draw_julia(data);
	else
		exit(1);
}

void	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	draw_image(data);
}

double	map_x(t_data *data, int x)
{
	double	x_min;
	double	x_max;
	double	range;

	x_min = data->xmin;
	x_max = data->xmax;
	range = (x_max - x_min) / data->zoom;
	return (data->x_center + range * ((x - WIDTH / 2.0) / WIDTH));
}

double	map_y(t_data *data, int y)
{
	double	y_min;
	double	y_max;
	double	range;

	y_min = data->ymin;
	y_max = data->ymax;
	range = (y_max - y_min) / data->zoom;
	return (data->y_center + range * ((HEIGHT / 2.0 - y) / HEIGHT));
}

/*
Coverting Range to Screen pixel
Use Linear mapping equation (LERP)
lerp = start + (end - start) * t
**t go from 0 - 1**
**t is like telling where is start mid and end**
((x - WIDTH/2.0) / WIDTH)  // This is 't'
range = (x_max - x_min)    // This is (end - start)
Putting it together
Lerp:   start + (end - start) * t
Yours:  center + range * normalized_x

WIDTH = 800
x_min = -2.0	// Left edge of Mandelbrot view
x_max = 1.0		// Right edge of Mandelbrot view

// For pixel x = 0 (leftmost pixel):
1. x - WIDTH/2 = 0 - 400 = -400	// Center the coordinate
2. Divide by WIDTH = -400/800 = -0.5 // Normalize to [-0.5, 0.5]
3. range = x_max - x_min = 1 - (-2) = 3
4. Final = -0.5 * 3 = -1.5	// Scale to Mandelbrot space

// For pixel x = 400 (middle of screen):
1. x - WIDTH/2 = 400 - 400 = 0	// Center the coordinate
2. Divide by WIDTH = 0/800 = 0	// Normalize
3. range = 3
4. Final = 0 * 3 = 0	// Middle of screen = 0 in math space

// For pixel x = 800 (rightmost pixel):
1. x - WIDTH/2 = 800 - 400 = 400	// Center the coordinate
2. Divide by WIDTH = 400/800 = 0.5	// Normalize
3. range = 3
4. Final = 0.5 * 3 = 1.5	// Maps to right side of view
*/

/*
(-2,1.5)      (0,1.5)      (1,1.5)
    +------------+------------+
    |            |            |
    |            |            |
(-2,0)        (0,0)        (1,0)    
    |            |            |
    |            |            |
    +------------+------------+
(-2,-1.5)     (0,-1.5)     (1,-1.5)
*/
