/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchencha <nchencha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:48:18 by nchencha          #+#    #+#             */
/*   Updated: 2025/01/20 23:48:13 by nchencha         ###   ########.fr       */
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
