/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 02:30:00 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/07 01:26:38 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	external_cmd(t_data *data, t_cmd *cmd)
{
	char	*path;
	int		pid;
	int		status;

	path = get_cmd_path(data->env, cmd->args[0]);
	if (!path)
	{
		ft_putstr_fd(cmd->args[0], 2);
		ft_putendl_fd(": command not found", 2);
		data->exit_status = 127;
		return ;
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL); // the external cmd should be end and print quit(core dumped) when use ctrl+\ only the parent can ignore the signal
		if (redirec(cmd->redirs) == 1)
			exit(1);
		if (execve(path, cmd->args, data->env) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			data->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			data->exit_status = 128 + WTERMSIG(status);
			if (WTERMSIG(status) == SIGINT)
				printf("\n");
			else if (WTERMSIG(status) == SIGQUIT)
				printf("Quit (core dumped)\n");
		}
	}
	else
		perror("fork");
	free(path);
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
}
