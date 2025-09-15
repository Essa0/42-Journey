/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:09:21 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 19:04:56 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
// int main()
// {
// 	char s = '10';
// 	char ss = '10';
// 	printf("%d\n", ft_isdigit(s));
// 	printf("%d\n", isdigit(ss));
// }
