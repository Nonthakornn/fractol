/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:50:42 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/07 03:45:06 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fractol.h"

int    main(int ac, char **av)  // 317,955 = 317,899 + 56
{
    (void)ac;
    (void)av;

    void    *mlx;

    mlx = mlx_init(400, 300, "test", true);
    mlx_terminate(mlx);
}