/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:36:55 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 13:35:14 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			word++;
		i++;
	}
	return (word);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

static void	ft_free_split(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
}

static int	ft_fill_word(char **arr, char const *s, char c)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			len = ft_word_len(&s[i], c);
			arr[j] = malloc(len + 1);
			if (!arr[j])
			{
				ft_free_split(arr, j - 1);
				return (0);
			}
			ft_strlcpy(arr[j++], &s[i], (len + 1));
			i += len;
		}
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;

	if (!s)
		return (NULL);
	arr = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_fill_word(arr, s, c))
		return (NULL);
	return (arr);
}

// int main(){
// 	char str[] = "isssa,,,, saleh,, abiesat";
// 	int i=0;
// 	while (i < ft_count_words(str, ','))
// 	{
// 		printf("%s", ft_split(str, ',')[i]);
// 		i++;
// 	}
// }
 