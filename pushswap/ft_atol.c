/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:57:01 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/20 01:52:01 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_skip_white_space(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

long long ft_atoll(char *c)
{
    int i;
	long long sign;
	long long res;

	sign = 1;
	res = 0;
    i = 0;
    while (ft_skip_white_space(c[i]))
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i]=='-')
			sign *= -1;
		i++;
	}
	while (c[i] && (c[i] >= '0' && c[i] <= '9'))
	{
		res = res * 10 + (c[i] - '0');
		i++;
	}
	return res * sign; 	    
}
