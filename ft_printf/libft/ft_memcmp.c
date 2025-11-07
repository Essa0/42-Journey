/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:36:47 by iabiesat         #+#    #+#             */
/*   Updated: 2025/08/12 16:37:26 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp_s1;
	size_t			i;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)tmp_s1[i] != (unsigned char)tmp_s2[i])
		{
			return ((unsigned char)tmp_s1[i] - (unsigned char)tmp_s2[i]);
		}
		i++;
	}
	return (0);
}
// int main(){
//     char s1[] = "Essa saleh";
//     char s2[] = "issa abeisat";
//     printf("%d\n", ft_memcmp(s1, s2, 4));    
//     return (0);
// }
