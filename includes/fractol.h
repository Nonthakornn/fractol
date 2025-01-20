/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:54:45 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/21 00:01:53 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1204
# define HEIGHT 768
# define MAX_ITER 200
# define MIN_ITER 50
# define ERR_ARGS "Invalid Input:\n\
./fractol mandelbrot \n\
./fractol julia <complex> <imaginary>"

# define RED 0xFF0000FF

typedef struct	s_data
{

}	t_data;

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <math.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//parser
bool valid_args(int argc, char **argv);
bool valid_coords(char *str);

//utils
void	err_msg(char *str);
bool	check_digit_dot(char c, bool *digit, bool space, int *dot_count);
double	ft_atof(char *str);
#endif