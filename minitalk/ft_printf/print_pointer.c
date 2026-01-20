/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:13:23 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/09/15 13:46:24 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_pointer(int *i, va_list args)
{
	void	*p;
	char	*hex;
	int		count;

	count = 0;
	p = va_arg(args, void *);
	if (!p)
	{
		write(1, "(nil)", 5);
		*i += 2;
		return (5);
	}
	hex = itoa_base((uintptr_t)p, "0123456789abcdef");
	write(1, "0x", 2);
	ft_putstr_fd(hex, 1);
	count += ft_strlen(hex) + 2;
	free(hex);
	*i += 2;
	return (count);
}
