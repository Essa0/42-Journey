/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 00:43:04 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/03/15 00:47:25 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**add_env(char **env, char *key, char *val)
{
	int		i;
	char	**new_env;
	char	*temp;
	
	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (env);
	i = 0;
	while (env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	temp = ft_strjoin(key, "=");
	new_env[i] = ft_strjoin(temp, val);
	free(temp);
	new_env[i + 1] = NULL;
	free(env);
	return (new_env);
}

int	ft_export(t_data *data, char **av)
{
	int		i;
	char	*key;
	char	*val;
	char	*path;
	char	*check_var;

	if (!av[1])
		return (0);
	check_var = ft_strchr(av[1], '=');
	if (!check_var)
		return (1);
	key = ft_substr(av[1], 0, check_var - av[1]);
	val = ft_strdup(check_var + 1);
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], key, ft_strlen(key)) == 0
			&& data->env[i][ft_strlen(key)] == '=')
		{
			path = ft_strjoin(key, "=");
			free(data->env[i]);
			data->env[i] = ft_strjoin(path, val);
			free(path);
			free(key);
			free(val);
			return (0);
		}
		i++;
	}
	data->env = add_env(data->env, key, val);
	free(key);
	free(val);
	return (0);
}
