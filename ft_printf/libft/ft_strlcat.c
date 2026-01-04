/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:07:27 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 19:09:25 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (len_dest >= s)
		return (len_src + s);
	while (src[i] && (len_dest + i) < (s - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}
//int main(){
//    char dest[7] = "Hi";
//    char *src = " there";
//    int result = ft_strlcat(dest, src, sizeof(dest));
//    printf("Result: %s\n", dest);
//    printf("Length attempted: %d\n", result);
//}
