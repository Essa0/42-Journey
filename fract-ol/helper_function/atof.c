/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 04:01:31 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/18 04:25:35 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	get_decimal_part(char *str, int *i)
{
	double	res;
	double	power;

	res = 0.0;
	power = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			res = res * 10.0 + (str[*i] - '0');
			power *= 10.0;
			(*i)++;
		}
	}
	return (res / power);
}

double	ft_atof(char *str)
{
	int		sign;
	int		i;
	double	res;

	sign = 1;
	i = 0;
	res = 0.0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10.0 + (str[i] - '0');
		i++;
	}
	return (sign * (res + get_decimal_part(str, &i)));
}
