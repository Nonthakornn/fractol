/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:50:42 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/16 13:03:31 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void my_key(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		puts("Exit");
		mlx_close_window(param);
	}
}

int    main(int ac, char **av) 
{
    (void)ac;
    (void)av;

    mlx_t *mlx;
	mlx_image_t *img;

	mlx_set_setting(MLX_DECORATED, 1);
    mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);

	//Create image buffer where you can draw pixels
	img = mlx_new_image(mlx, 256, 256);

	//Draw red pixel at coordinates
	  for (int y = 0; y < 256; y++)
    {
        for (int x = 0; x < 256; x++)
        {
			//Display image on that window position
            mlx_put_pixel(img, x, y, RED);
        }
    }
	//Placing a picture on window at specific coordinate
	mlx_image_to_window(mlx, img, 0 , 0);
	mlx_image_to_window(mlx, img, 300 , 0);
	mlx_image_to_window(mlx, img,  0, 300);

	
	mlx_key_hook(mlx, (mlx_keyfunc)(my_key), mlx);
	//mlx_key_hook(mlx, &my_key, mlx);

	mlx_loop(mlx);
    mlx_terminate(mlx);
	return (0);
}