/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_upper_lower.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:12:14 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/11/06 14:45:22 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hex_upper_lower(const char *format, int *i, va_list args)
{
	unsigned int	x;
	char			*hex;
	int				count;

	count = 0;
	x = va_arg(args, unsigned int);
	if (format[*i + 1] == 'x')
		hex = itoa_base(x, "0123456789abcdef");
	else
		hex = itoa_base(x, "0123456789ABCDEF");
	ft_putstr_fd(hex, 1);
	count = ft_strlen(hex);
	free(hex);
	*i += 2;
	return (count);
}
