/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:12:50 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 19:09:51 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (ft_strlen(src));
	while (src[i] && (i < (c - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
//int main()
//{
//    char buffer1[20];
//    char buffer2[5];
//    char buffer3[20];
//    // Test 1: Normal copy
//    printf("Test 1:\n");
//}
