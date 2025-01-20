/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 21:08:24 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/21 00:22:09 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

bool	valid_args(int argc, char **argv)
{
	if (argc == 2 || argc == 4)
	{
		if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
			&& ft_strlen(argv[1]) == 10)
			return (true);
		else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5)
			&& ft_strlen(argv[1]) == 5)
		{
			if (valid_coords(argv[2]) && valid_coords(argv[3]))
				return (true);
			return (false);
		}
		else
			return (false);
	}
	return (false);
}

bool	valid_coords(char *str)
{
	int		i;
	bool	has_digit;
	bool	after_space;
	int		dot_count;

	i = 0;
	dot_count = 0;
	has_digit = false;
	after_space = false;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			after_space = true;
		else if (!check_digit_dot(str[i], &has_digit, after_space, &dot_count))
			return (false);
		i++;
	}
	return (has_digit);
}

/*
OK Input
"  .123  "
".123"
"+123"
"+.123"
"-.123"

ERR Input
".123.3"
"+-123"
"2x"
"+23     2"
""
"     "
123-+
000000000000.2
0.200000000000
..123
2147483647.1
a
1.a3
*/
