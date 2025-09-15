/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:10:48 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/09/15 13:37:48 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_specifiers(const char *specifier, int *i, va_list args)
{
	char	s;

	s = specifier[*i + 1];
	if (s == 'd' || s == 'i' || s == '%')
		return (print_int_sign(specifier, i, args));
	else if (s == 'u')
		return (print_unsigned(i, args));
	else if (s == 'c' || s == 's')
		return (print_str_chr(specifier, i, args));
	else if (s == 'p')
		return (print_pointer(i, args));
	else if (s == 'x' || s == 'X')
		return (print_hex_upper_lower(specifier, i, args));
	*i += 2;
	return (0);
}
