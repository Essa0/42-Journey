/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:23:43 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:28:45 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**init_envp(char **e)
{
	int		i;
	char	**envp;

	if (!e)
		return (NULL);
	i = 0;
	while (e[i])
		i++;
	envp = ft_calloc(i + 1 , sizeof(char *));
	if (!envp)
		return (NULL);
	i = 0;
	while (e[i])
	{
		envp[i] = ft_strdup(e[i]);
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

static void	shell_level(t_shell *shell)
{
	char	*lvl;
	char	*new_lvl;
	int		lvl_i;
	
	lvl = getenv("SHLVL");
	lvl_i = 1;
	if (lvl)
		lvl_i = ft_atoi(lvl) + 1;
	new_lvl = ft_itoa(lvl_i);
	if (new_lvl)
	{
		shell->envp_shell =  set_env(shell->envp_shell, "SHLVL", new_lvl);
		free(new_lvl);
	}
}
t_shell		*init_shell(char **envp_main)
{
	t_shell	*shell;

	if (!envp_main)
		return (NULL);
	shell = ft_calloc(1, sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->envp_shell = init_envp(envp_main);
	if (!shell->envp_shell)
	{
		free(shell);
		return (NULL);
	}
	shell_level(shell);
	shell->line_input = NULL;
	shell->exit_status = 0;
	return (shell);
}
