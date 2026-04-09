/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:49:21 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/08 22:58:41 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	customize cd command
*/

int	ft_cd(t_data *data, char **av)
{
	char	*cur_dir;
	char	*dir;
	char	*new_pwd;

	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
		return (1);
	if (av[1] == NULL )
	{
		dir = get_env_val(data->env, "HOME");
		if (!dir)
		{
			ft_putendl_fd("minishell: cd: HOME not set", 2);
			free(cur_dir);
			return (1);
		}
	}
	else if (strcmp(av[1], "-") == 0)
	{
		dir = get_env_val(data->env, "OLDPWD");
		if (!dir)
		{
			ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
			free(cur_dir);
			return (1);
		}
		printf("%s\n", dir);
	}
	else
		dir = av[1];
	if (chdir(dir) != 0)
	{
		perror("minishell: cd");
		free(cur_dir);
		return (1);
	}
	data->env = set_env(data->env, "OLDPWD", cur_dir);
	new_pwd = get_cur_path();
	if (new_pwd)
	{
		data->env = set_env(data->env, "PWD", new_pwd);
		free(new_pwd);
	}
	free(cur_dir);
	return (0);
}
