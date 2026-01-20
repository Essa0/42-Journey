/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:11:13 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 19:10:37 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char		*tmp_s1;
	unsigned const char		*tmp_s2;
	size_t					i;

	tmp_s1 = (unsigned const char *)s1;
	tmp_s2 = (unsigned const char *)s2;
	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (tmp_s1[i] != tmp_s2[i])
		{
			return (tmp_s1[i] - tmp_s2[i]);
		}
		i++;
	}
	return (0);
}
// int main()
// {
//     printf("%d\n", ft_strncmp("abce", "abcd", 4)); // negative ('c' - 'd')
//     printf("%d\n", ft_strncmp("abc", "abc", 3)); // 0
//     printf("%d\n", ft_strncmp("abc", "abcde", 5)); // negative
//     return (0);
// }
