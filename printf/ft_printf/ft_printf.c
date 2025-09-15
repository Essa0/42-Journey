/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:30:56 by issa              #+#    #+#             */
/*   Updated: 2025/09/15 13:33:22 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *n, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, n);
	i = 0;
	count = 0;
	while (n[i])
	{
		if (n[i] == '%')
		{
			count += handle_specifiers(n, &i, args);
		}
		else
		{
			write(1, &n[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
