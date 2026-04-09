/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:37:29 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/03/06 03:57:27 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	return pointer to pos next to (=)
	if found the key you search about
*/

char	*get_env_val(char **env, char *key)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], key, strlen(key)) == 0
			&& env[i][strlen(key)] == '=')
			return ((char *)&env[i][strlen(key) + 1]);
		i++;
	}
	return (NULL);
}
