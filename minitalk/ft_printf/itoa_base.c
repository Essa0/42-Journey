/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:19:38 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/11/08 12:08:36 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*itoa_base(unsigned long n, char *base)
{
	char	*str;
	int		len_base;
	int		digit_len;
	int		index;

	len_base = ft_strlen(base);
	digit_len = numlen_base(n, len_base);
	index = digit_len - 1;
	str = malloc(digit_len + 1);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (n != 0)
	{
		str[index] = base[n % len_base];
		n /= len_base;
		index--;
	}
	str[digit_len] = '\0';
	return (str);
}
