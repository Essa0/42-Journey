/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 02:09:35 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 18:05:23 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char upper_index(unsigned int i, char c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		c -= 32;
// 	return c + (i % 2);
// }

// char	ft_tolower1(unsigned int d, char c)
// {
// 	(void)d;
// 	if (c >= 65 && c <= 90)
// 	{
// 		return (c + 32);
// 	}
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
// int main(){
// 	char *result;

// 	result = ft_strmapi("HELLO", ft_tolower1);
// 	printf("test 1: %s\n", result);
// 	free(result);
// }