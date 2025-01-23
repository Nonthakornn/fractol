/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:48:18 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/22 21:59:13 by nchencha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	err_msg(char *str)
{
	ft_putendl_fd(str, 2);
	exit (1);
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

static int	handle_prefix(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

static double	get_decimal(char *str, int *i, int *j)
{
	double	deci_num;

	deci_num = 0;
	if (str[*i] == '.')
		(*i)++;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		deci_num = (deci_num * 10) + (str[*i] - '0');
		(*i)++;
		(*j)++;
	}
	return (deci_num);
}

double	ft_atof(char *str)
{
	double	num;
	double	deci_num;
	int		i;
	int		j;
	int		sign;

	num = 0;
	deci_num = 0;
	i = 0;
	j = 0;
	sign = 1;
	i = handle_prefix(str, &sign);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	deci_num = get_decimal(str, &i, &j);
	num = num + (deci_num / pow(10, j));
	return (num * sign);
}
