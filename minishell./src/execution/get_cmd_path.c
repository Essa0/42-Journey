/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:01:54 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/27 23:41:54 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*search_in_path(char **split_path, char *cmd)
{
	int		i;
	char	*path;
	char	*new_path;

	i = 0;
	while (split_path[i])
	{
		path = ft_strjoin(split_path[i], "/");
		new_path = ft_strjoin(path, cmd);
		free(path);
		if (access(new_path, F_OK) == 0)
		{
			free_env(split_path);
			return (new_path);
		}
		free(new_path);
		i++;
	}
	free_env(split_path);
	return (NULL);
}

char	*get_cmd_path(char **env, char *cmd)
{
	char	**split_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	split_path = ft_split(get_env_val(env, "PATH"), ':');
	if (!split_path)
		return (NULL);
	return (search_in_path(split_path, cmd));
}
