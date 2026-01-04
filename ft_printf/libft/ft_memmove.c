/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:07:45 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 18:06:18 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t c)
{
	const char		*tmp_src;
	char			*tmp_dest;
	size_t			i;

	i = 0;
	tmp_src = (const char *)src;
	tmp_dest = (char *)dest;
	if (tmp_dest > tmp_src)
		while (c-- > 0)
			tmp_dest[c] = tmp_src[c];
	else
	{
		while (i < c)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}
// int main(){
// 	char arr[] = "";
// 	char arr2[4];
// 	ft_memmove(NULL, arr, 0);
// 	memmove(NULL, NULL, 0);
// 	printf("%s\n", arr2);
// }
