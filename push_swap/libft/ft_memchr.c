/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:27:20 by iabiesat         #+#    #+#             */
/*   Updated: 2025/08/12 16:14:36 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tmp_c;
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	tmp_c = (unsigned char )c;
	while (i < n)
	{
		if (str[i] == tmp_c)
		{
			return ((void *) &str[i]);
		}
		i++;
	}
	return (NULL);
}
// int main(){
//     const char str[]="issa saleh";
//     char cc = 'e';
//     char *res = ft_memchr(str, cc, 9); 
//     char c = 'a';
//     printf("%p\n", ft_memchr(str, c, 1));
//     if (res)
//     {
//         /* code */
//         printf("%s\n", res);
//     }else{
//         printf("there some issue\n");
//     } 
//     return (0);
// }
