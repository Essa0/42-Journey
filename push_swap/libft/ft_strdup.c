/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:57:44 by iabiesat          #+#    #+#             */
/*   Updated: 2025/09/02 19:22:21 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*s1;
	size_t		len;

	len = ft_strlen(s);
	s1 = (char *) malloc (len + 1);
	if (!s1)
		return (NULL);
	ft_strlcpy(s1, s, len + 1);
	return (s1);
}
// int main()
// {
//     // char s[] = "";
//     char *result = ft_strdup("issa");
//     printf("%s\n", result);
//     free(result);
// }
