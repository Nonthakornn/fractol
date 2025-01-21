/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:48:18 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/21 22:50:01 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	err_msg(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
}

void	render(void *param)
{
	t_data *data;

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
	return data->x_center + range * ((x - WIDTH / 2.0) / WIDTH);
}

double	map_y(t_data *data, int y)
{
	double	y_min;
	double	y_max;
	double	range;

	y_min = data->ymin;
	y_max = data->ymax;
	range = (y_max - y_min) / data->zoom;
	return data->y_center + range * ((HEIGHT / 2.0 - y) / HEIGHT);
}

bool	check_digit_dot(char c, bool *digit, bool space, int *dot_count)
{
	if (c == ' ' || c == '\t')
		return (true);
	else if (ft_isdigit(c))
	{
		if (space)
			return (false);
		*digit = true;
	}
	else if (c == '.')
	{
		if (++(*dot_count) > 1)
			return (false);
	}
	else
		return (false);
	return (true);
}
