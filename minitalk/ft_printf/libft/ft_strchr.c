/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 02:48:48 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 19:08:25 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tmp_c;
	int		i;

	i = 0;
	tmp_c = (char) c;
	while (s[i])
	{
		if (s[i] == tmp_c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (tmp_c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
// int main(){
//     char a = 'a';
//     char str[] = "issa saleh";    
//     printf("%s \n", ft_strchr(str, a));
// }
