/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_store.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 00:12:54 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 17:21:48 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(int argc, char **argv)
{
	int		i;
	int		n;
	int		count;
	char	**result;

	i = 1;
	count = 0;
	while (i < argc)
	{
		result = ft_split(argv[i], ' ');
		if (!result)
		{
			printf("Error: Word Count");
			return (-1);
		}
		n = 0;
		while (result[n])
		{
			count++;
			n++;
		}
		free_full_arr(result);
		i++;
	}
	return (count);
}

static int	arg_fill(char **result, char *argv, int k)
{
	int		i;
	char	**part;

	i = 0;
	part = ft_split(argv, ' ');
	if (!part)
		return (-1);
	while (part[i])
	{
		result[k] = ft_strdup(part[i]);
		if (!result[k])
		{
			free_full_arr(part);
			return (-1);
		}
		i++;
		k++;
	}
	free_full_arr(part);
	return (k);
}

char	**split_and_store(int argc, char **argv)
{
	int		i;
	int		k;
	int		temp_k;
	char	**result;

	i = count_word(argc, argv);
	if (i < 0)
		return (NULL);
	result = malloc((i + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		temp_k = k;
		k = arg_fill(result, argv[i], k);
		if (k < 0)
			return (free_partial_arr(result, temp_k));
		i++;
	}
	result[k] = NULL;
	return (result);
}
