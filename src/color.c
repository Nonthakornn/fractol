/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:12:01 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/23 20:52:56 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// Ensure that color will stay in  the same range
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

//Dark area: For early escape
static void	dark_area(int *r, int *g, int *b)
{
	*r = (int)(*r * 0.3);
	*g = (int)(*g * 0.1);
	*b = (int)(*b * 0.4);
}

//Bright area: For late escape
static void	bright_area(int *r, int *g, int *b)
{
	*r = (int)(*r * 0.1);
	*g = (int)(*g * 0.2);
	*b = (int)(*b * 0.1);
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
	data->pattern = sin(t * 800) * cos(t * 400);
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

/*
I really love the sin wave so if you want more beautiful image
increse the number of the sin * cos
sin ranges from -1 to 1
cos ranges from -1 to 1
So pattern will range from -1 to 1
Multiplying t by 800 and 400 creates more frequent oscillations

For pattern:
It make the the frequency and the graph look more complicate
For luxe:
If the color gets brighter luxe is coming to help
with out pattern and luxe if the color switch it will be ugly

Zooming part:
When you're not zoomed (zoom = 1):
data->interate = 50 + log10(1 * 20)
data->interate = 50 + 1.3 = 51.3
Then t = 51.3/500 = 0.102 (dark colors)

When you zoom 10x:
data->interate = 50 + log10(10 * 20)
data->interate = 50 + 2.3 = 52.3
Then t = 52.3/500 = 0.104 (slightly lighter)
When you zoom 100x:

data->interate = 50 + log10(100 * 20)
data->interate = 50 + 3.3 = 53.3
Then t = 53.3/500 = 0.106 (even lighter)

The connection is:
More zoom → More iterations
More iterations → Higher t value
Higher t value → Lighter colors

This creates the effect that:
no zoom: Simpler detail, darker colors
Zoomed in: More detail, lighter colors
The log10 makes change smoother
*/