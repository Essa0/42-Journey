/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:35:38 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/03/15 00:43:35 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**set_env(char **env, char *key, char *val)
{
	int		i;
	char	*path;
	char	*new_path;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], key, strlen(key)) == 0
			&& env[i][strlen(key)] == '=')
		{
			free(env[i]);
			path = ft_strjoin(key, "=");
			if (!path)
				return (env);
			if (val)
				new_path = ft_strjoin(path, val);
			else
				new_path = ft_strdup(path);		
			env[i] = new_path;
			free(path);
			return (env);				
		}
		i++;
	}
	return(env);	
}
