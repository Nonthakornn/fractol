/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:50:42 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/21 22:47:53 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
	t_data data;

	if (!valid_args(argc, argv))
		err_msg(ERR_ARGS);
	init_fractol(&data, argc);
	draw_image(&data);
	event_listener(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}