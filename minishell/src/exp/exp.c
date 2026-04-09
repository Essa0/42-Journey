/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:33 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:17:34 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	expand_arg(t_cmd *cmd, int i, t_shell *shell)
{
	char	*expanded;
	char	*temp;

	if (cmd->types[i] == WORD_SQ) // any thing in ' ' not expand
		return (0);
	temp = expand_tilde(cmd->args[i], shell->envp_shell);
	if (!temp)
		return (1);
	free(cmd->args[i]);
	cmd->args[i] = temp;
	expanded = expand_string(cmd->args[i], shell); 
	if (!expanded)
		return (1);
	free(cmd->args[i]);
	cmd->args[i] = expanded;
	return (0);
}

static int	expand_redirs(t_cmd *cmd, t_shell *shell)
{
	int		i;
	char	*expanded;

	if (!cmd->redirs)
		return (0);
	i = 0;
	while (cmd->redirs[i].file)
	{
		expanded = expand_string(cmd->redirs[i].file, shell);
		if (!expanded)
			return (1);
		free(cmd->redirs[i].file);
		cmd->redirs[i].file = expanded;
		i++;
	}
	return (0);
}



// to expand one cmd
static int	expand_cmd(t_cmd *cmd, t_shell *shell)
{
	int	i;

	if (!cmd || !shell)
		return (1);
	i = 0;
	while (cmd->args && cmd->args[i])
	{
		// expand args 
		if (expand_arg(cmd, i, shell) == 1)
			return (1);
		i++;
	}
	// expand redirections like files 
	if (expand_redirs(cmd, shell) == 1)
		return (1);
	return (0);
}

// first function to expansion
void	expand_all(t_cmd *cmd, t_shell *shell)
{
	t_cmd	*temp;

	temp = cmd;
	while (temp)
	{
		expand_cmd(temp, shell);
		temp = temp->next;
	}
}
