/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:16:05 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 19:10:03 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*int main(){
	char s[] = "issa";
	char ss[] = "issa";
	printf("%zu\n", ft_strlen(NULL));
	printf("%zu\n", strlen(NULL));
	return (0);
}*/
