/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:45:23 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:45:24 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_char(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 92)
			return (1);
		else if (line[index] == ';')
			return (1);
		else if (line[index] == 34)
		{
			index++;
			while (line[index] && line[index] != 34)
				index++;
		}
		else if (line[index] == 39)
		{
			index++;
			while (line[index] && line[index] != 39)
				index++;
		}
		index++;
	}
	return (0);
}

static int	check_quote(char *line, int c, int *index)
{
	(*index)++;
	while (line[*index])
	{
		if (line[*index] == c)
			return (0);
		(*index)++;
	}
	return (1);
}

static int	check_unclosed(char *line)
{
	int	index;    

	index = 0;
	while (line[index])
	{
		if (line[index] == 34)
		{
			if (check_quote(line, 34, &index) == 1)
				return (1);
		}
		else if (line[index] == 39)
		{
			if (check_quote(line, 39, &index) == 1)
				return (1);
		}
		index++;
	}
	return (0);
}

int	check_required(char *line)
{
	if (!line)
		return (1);
	// check qoute if not closed
	if (check_unclosed(line) == 1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected unclosed quote\n", 2);
		return (1);
	}
	if (check_char(line) == 1) // 
		return (1);
	return (0);
}
