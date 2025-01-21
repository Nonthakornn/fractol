/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:12:51 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/21 23:18:49 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	update_zoom(t_data *data, double zoom_factor)
{
	data->zoom *= zoom_factor;
	if (data->zoom < 0.1)
		data->zoom = 0.1;
	if (data->zoom > 10000000)
		data->zoom = 10000000;
}

//mouse_r = mouse_real
//moust_i = mouse_imaginary
//zoom_ft = zoom_factor
static void	update_center(t_data *data, double mouse_r,
	double mouse_i, double zoom_ft)
{
	data->x_center += (mouse_r - data->x_center) * (1 - 1 / zoom_ft);
	data->y_center += (mouse_i - data->y_center) * (1 - 1 / zoom_ft);
}

void	event_listener(t_data *data)
{
	mlx_scroll_hook(data->mlx, (mlx_scrollfunc)scroll_hook, data);
	mlx_key_hook(data->mlx, (mlx_keyfunc)my_keyhook, data);
	mlx_loop_hook(data->mlx, render, data);
}

void my_keyhook(mlx_key_data_t key_data, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	double	zoom_factor;
	int32_t	mouse_x;
	int32_t	mouse_y;

	data = (t_data *)param;
	(void)xdelta;
	zoom_factor = 0.9;
	if (ydelta > 0)
		zoom_factor = 1.1;
	mlx_get_mouse_pos(data->mlx, &mouse_x, &mouse_y);
	update_center(data, map_x(data, mouse_x),
		map_y(data, mouse_y), zoom_factor);
	update_zoom(data, zoom_factor);
	draw_image(data);
}
