/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:12:01 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/21 22:46:38 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	force_rgb(int *r, int *g, int *b)
{
	if (*r < 0)
		*r = 0;
	if (*r > 255)
		*r = 255;
	if (*g < 0)
		*g = 0;
	if (*g > 255)
		*g = 255;
	if (*b < 0)
		*b = 0;
	if (*b > 255)
		*b = 255;
}

static void	dark_area(int *r, int *g, int *b)
{
	*r = (int)(*r * 0.3);
	*g = (int)(*g * 0.1);
	*b = (int)(*b * 0.4);
}

static void	bright_area(int *r, int *g, int *b)
{
	*r = (int)((*r * 1.2 + 255) / 2);
	*g = (int)((*g * 1.1 + 220) / 2);
	*b = (int)((*b + 200) / 2);
}


int	get_color(t_data *data)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (data->interate == MAX_ITER)
		return (BLACK);
	t = (double)data->interate / MAX_ITER;
	data->pattern = sin(t * 30) * cos(t * 15);
	data->luxe = fabs(sin(t * 20));
	r = (int)(255 * (0.8 + 0.2 * sin(data->pattern * 10)));
	g = (int)(255 * (0.4 + 0.4 * sin(t * 15 + 3.0)));
	b = (int)(255 * (0.7 + 0.3 * sin(t * 20 + data->luxe)));
	if (t < 0.3)
		dark_area(&r, &g, &b);
	else if (t > 0.7)
		bright_area(&r, &g, &b);
	else
	{
		r = (int)(r * 0.9);
		g = (int)(g * 0.8);
		b = (int)(b * 0.7);
	}
	force_rgb(&r, &g, &b);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}
