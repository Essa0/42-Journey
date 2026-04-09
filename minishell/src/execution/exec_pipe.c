/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:05:12 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/09 00:36:39 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_pipe(t_data *data, t_cmd *cmd)
{
	pid_t	pid;
	t_cmd	*temp;
	int		prev_pipe;
	int		fd[2];
	int		status;

	prev_pipe = -1;
	temp = cmd;
	while (temp)
	{
		if (temp->next)
			pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			signal(SIGINT, SIG_DFL);
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			if (temp->next)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				close(fd[0]);
			}
			if (redirec(temp->redirs) == 1)
				exit(0);
			exec_cmd(data, temp);
			exit(0);
		}
		if (prev_pipe != -1)
				close(prev_pipe);
		if (temp->next)
		{
			close(fd[1]);
			prev_pipe = fd[0];
		}
		else
			prev_pipe = -1;
		temp = temp->next;
	}
	// to avoid print the prompt many time
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);

	while(wait(&status) > 0) // we pass the status var to update val
	{
		if (WIFSIGNALED(status)) //if the child ended abnormally
		{
			data->exit_status = 128 + WTERMSIG(status); // here they return encrypt status so we must add 128 to the proccess that end with signal
			if ((WTERMSIG(status) == SIGINT))
				printf("\n");
			else if (WTERMSIG(status) == SIGQUIT) // if the child end because ctrl+\ sig, to be know this macro return the signal that caused end the child
				printf("Quit (core dumped)\n");
		}
		else if (WIFEXITED(status))
			data->exit_status = WEXITSTATUS(status);
	}
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
}
// استخدم متغيراً بسيطاً (Flag) أو اطبع السطر لمرة واحدة فقط إذا اكتشفت أن هناك إشارة قتلت أياً من الأبناء.