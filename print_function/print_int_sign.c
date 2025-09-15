/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:16:26 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/09/15 14:13:37 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_int_len(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (1 + numlen_base(-n, 10));
	return (numlen_base(n, 10));
}

int	print_int_sign(const char *format, int *i, va_list args)
{
	int	count;
	int	num;

	count = 0;
	if (format[*i + 1] == 'i' || format[*i + 1] == 'd')
	{
		num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
		count += get_int_len(num);
	}
	else if (format[*i + 1] == '%')
	{
		write(1, "%", 1);
		count += 1;
	}
	*i += 2;
	return (count);
}
