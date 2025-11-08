/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_unsigned_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:24:17 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/11/08 13:32:43 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		putnbr_unsigned_fd(n / 10, fd);
		putnbr_unsigned_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
