/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validateInput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:56:04 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/08 00:10:17 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isValidNum(char *num)
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



int validateInput(int argc, char **argv)
{
	int i;
	int j;
	char **part;

	i = 1;
	while (i < argc)
	{
		part = ft_split(argv[i], ' ');
		if (!part)
			return (0);
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
		ft_free_split(part, j - 1);
		i++;
	}
	return (1);
}
