/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 02:21:30 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 15:02:07 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_integer(char **part, int *count)
{
	int			i;
	int			j;
	int			*numbers;
	long long	num;

	i = 0;
	j = 0;
	while (part[i] != NULL)
		i++;
	*count = i;
	numbers = malloc(i * sizeof(int));
	if (!numbers)
		return (NULL);
	while (j < i)
	{
		num = ft_atoll(part[j]);
		if (num < INT_MIN || num > INT_MAX)
		{
			free(numbers);
			return (NULL);
		}
		numbers[j] = (int)num;
		j++;
	}
	return (numbers);
}
