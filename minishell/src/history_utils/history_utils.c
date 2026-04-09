/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:22:51 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:29:28 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	history_add(char *line)
{
	int	i;    

	i = 0;
	while (line[i])
	{
		if ((unsigned char)line[i] >= 33 && (unsigned char)line[i] != 127)
		{
			add_history(line);
			return (0);
		}
		i++;
	}
	return (1);
}
