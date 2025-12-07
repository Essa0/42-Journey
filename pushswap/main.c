/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:48:48 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/01 23:55:31 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (ft_strlen(src));
	while (src[i] && (i < (c - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
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
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
int	isValidNum(char *num)
{
	int i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (num[i] == '\0')
		return (0);
	while (num[i])
	{
		if (!ft_isdigit((unsigned char)num[i]))
			return (0);
		i++;
	}
	return (1);
}
int	validateInput(int argc, char **argv)
{
	int i;
	int j;
	char **part;

	i = 1;
	while (i < argc)
	{
		part = ft_split(argv[i], ' ');
		if (!part)
		{
			free(part);
			return (0);
		}
		j = 0;
		while (part[j])
		{
			if (!isValidNum(part[j]))
			{
				ft_free_split(part, j);
				return (0);
			}
			j++;
		}
		ft_free_split(part, j);
		i++;
	}
	return (1);
}
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!validateInput(argc, argv))
		{
			write(1, "Error\n", 6);
		}
		else
		{
			write(1, "lets play\n", 10);
		}
	}
	return (0);
}