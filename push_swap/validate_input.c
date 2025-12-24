/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:56:04 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 16:11:41 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_num(char *num)
{
	int	i;

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

static int	is_whitespace(char *arg)
{
	int	i;

	if (!arg || !arg[0])
		return (1);
	i = 0;
	while (arg[i])
	{
		if (arg[i] != ' ' && arg[i] != '\t' && arg[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	validate_input(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (is_whitespace(arg[i]))
			return (0);
		if (!is_valid_num(arg[i]))
			return (0);
		i++;
	}
	return (1);
}
