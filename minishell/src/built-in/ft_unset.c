/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:20:55 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/03/15 00:49:56 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_unset(t_data *data, char **av)
{
	int	i;
	int j;

	if (!av[1])
		return (0);
	j = 1;
	while (av[j])
	{
		i = 0;
		while (data->env[i])
		{
			if (strncmp(data->env[i], av[j], ft_strlen(av[j])) == 0 
				&& data->env[i][ft_strlen(av[j])] == '=')
			{
				free(data->env[i]);
				while (data->env[i])
				{
					data->env[i] = data->env[i + 1];
					i++;
				}
				break;
			}
			i++;
		}
		j++;
	}
	return (0);
}
