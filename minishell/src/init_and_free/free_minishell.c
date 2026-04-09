/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:23:34 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:28:37 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_line(t_shell *shell)
{
	if (!shell)
		return ;
	if (!shell->line_input)
		return ;
	free(shell->line_input);
	shell->line_input = NULL;
	return ;
}
void	free_shell(t_shell *shell)
{
	int	i;

	if (!shell)
		return ;
	if (shell->envp_shell)
	{
		i = 0;
		while (shell->envp_shell[i])
		{
			free(shell->envp_shell[i]);
			i++;
		}
		free(shell->envp_shell);
	}
	if (shell->line_input)
		free(shell->line_input);
	free(shell);
}
