/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:54:00 by iabiesat         #+#    #+#             */
/*   Updated: 2025/08/19 17:05:15 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*c;
	long		num;

	len = ft_numlen(n);
	c = malloc(len + 1);
	num = n;
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (num < 0)
		num = -num;
	if (n == 0)
		c[0] = '0';
	while (num)
	{
		c[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		c[0] = '-';
	return (c);
}
// int main(void)
// {
// 	int n = -123;
// 	char *str;

// 	str = ft_itoa(n);
// 	if (!str)
// 		return (1); // malloc failed

// 	printf("ft_itoa(%d) = \"%s\"\n", n, str);

// 	free(str);
// 	return (0);
// }