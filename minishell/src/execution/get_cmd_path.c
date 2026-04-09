/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:01:54 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/03/15 02:50:24 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_cmd_path(char **env, char *cmd)
{
	char	**split_path;
	char	*path;
	char	*new_path;
	int		i;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return(ft_strdup(cmd));
		return (NULL);
	}
	split_path = ft_split(get_env_val(env, "PATH"), ':');
	if (!split_path)
		return (NULL);
	while (split_path[i])
	{
		path = ft_strjoin(split_path[i], "/");
		new_path = ft_strjoin(path, cmd);
		free(path);
		if (access(new_path, F_OK | X_OK) == 0)
		{
			free_env(split_path);
			return(new_path);
		}
		free(new_path);
		i++;
	}
	free_env(split_path);
	return (NULL);
}
