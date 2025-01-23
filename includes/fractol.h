/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 02:54:45 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/23 19:50:11 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800 
# define HEIGHT 800 
# define MAX_ITER 400
# define MIN_ITER 300
# define ERR_ARGS "Invalid Input:\n\
./fractol mandelbrot \n\
./fractol julia <complex> <imaginary>\n\
Mandelbrot:\n\
z starts at 0 + 0i (always fixed)\n\
c is the point to test (x0 + y0i from each pixel)\n\
\n\
Julia:\n\
z is the point to test (x0 + y0i from each pixel)\n\
c is fixed (data->r + data->i*i, set when program starts)\n\
\n\
Recommend: The number of julia should be between (-2, 2)\n\
Try These number:\n\
./fractol julia 0.285 0.01 || 0.8 0 || -0.8 0.156" 

# define BLACK  0x000000
# define WHITE	0xFFFFFF

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdbool.h>
# include <math.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			fractal_type;
	int			interate;
	int			height;
	int			width;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	double		r;
	double		i;
	double		pattern; //For my beautiful images
	double		luxe;
	double		zoom;
	double		x_center;
	double		y_center;

}	t_data;

//event listener
void	scroll_hook(double xdelta, double y_delta, void *param);
void	event_listener(t_data *data);
void	my_keyhook(mlx_key_data_t key_data, void *param);

//init
void	init_fractol(t_data *data, int argc, char **argv);

//draw_image
void	render(void *param);
double	map_x(t_data *data, int x);
double	map_y(t_data *data, int y);
void	draw_image(t_data *data);
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);

//color
int		get_color(t_data *data);

//parser
bool	valid_args(int argc, char **argv);
bool	valid_coords(char *str);

//utils
void	err_msg(char *str);
bool	check_digit_dot(char c, bool *digit, bool space, int *dot_count);
double	ft_atof(char *str);
#endif