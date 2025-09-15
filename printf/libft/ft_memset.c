/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 03:01:10 by iabiesat         #+#    #+#             */
/*   Updated: 2025/08/26 14:38:19 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	char	*pointer;
	char	cc;

	cc = (char) c;
	pointer = (char *)ptr;
	while (len > 0)
	{
		*pointer++ = cc;
		len--;
	}
	return (ptr);
}
// int main() {
//     char arr[20];
// 	char ar2[20];
//     ft_memset(arr, 200, 10);
//     for (int i = 0; i < 5; i++) {
//         printf("custom => %c\n",arr[i]);
//     }
// 	memset(ar2, 200, 10);
// 	for (size_t i = 0; i < 5; i++)
// 	{
// 		printf("standart => %c\n", ar2[i]);
// 	}
//     return 0;
// }
