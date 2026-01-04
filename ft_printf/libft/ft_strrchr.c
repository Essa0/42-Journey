/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:42:59 by iabiesat          #+#    #+#             */
/*   Updated: 2025/09/02 19:12:52 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_len;

	s_len = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) &s[s_len]);
	while (s_len >= 0)
	{
		if (s[s_len] == (char) c)
		{
			return ((char *) &s[s_len]);
		}
		s_len--;
	}
	return (NULL);
}
// int main(){
//     char a = 'a';
//     char str[] = "issa saleh";    
//     printf("%s \n", ft_strrchr(str, a));
// }
