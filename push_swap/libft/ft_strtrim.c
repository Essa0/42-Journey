/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:10:17 by iabiesat          #+#    #+#             */
/*   Updated: 2025/09/02 19:13:20 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inset(char chr, const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (chr == s[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	j = ft_strlen(s) - 1;
	i = 0;
	if (!s || !set)
		return (NULL);
	while (s[i] && inset(s[i], set))
		i++;
	while (j > i && inset(s[j], set))
		j--;
	if (i > j)
		return (ft_strdup(""));
	len = j - i + 1;
	newstr = malloc((len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s + i, len + 1);
	return (newstr);
}
// int main()
// {
//     char s1[] = "saaasssassIssa Saleh Abiesatsssaaasasas";
//     char s2[] = "as";

//     char *s = ft_strtrim(s1, s2);    
//     printf("%s\n", s);
// }
