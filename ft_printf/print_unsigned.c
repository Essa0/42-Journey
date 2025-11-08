/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:18:10 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/11/08 13:49:10 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_unsigned(int *i, va_list args)
{
	unsigned int	u;
	int				count;

	count = 0;
	u = va_arg(args, unsigned int);
	putnbr_unsigned_fd(u, 1);
	count += numlen_base(u, 10);
	*i += 2;
	return (count);
}
