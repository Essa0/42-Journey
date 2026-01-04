/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:15:18 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/09/15 13:45:10 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str_chr(const char *format, int *i, va_list args)
{
	char	c;
	char	*s;
	int		count;

	count = 0;
	if (format[*i + 1] == 'c')
	{
		c = (char)va_arg(args, int);
		ft_putchar_fd(c, 1);
		count += 1;
	}
	else if (format[*i + 1] == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(null)";
		ft_putstr_fd(s, 1);
		count += ft_strlen(s);
	}
	*i += 2;
	return (count);
}
