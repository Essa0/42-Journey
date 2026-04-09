#include "../include/minishell.h"

/*
	we dup the stdin/out because if there 
	are redirection and change the stdin/out 
	then finish the redirection and back to 
	shell they will print prompt in the new 
	fd, so we have to duplicate to restore 
	the original stdin/out.
*/

static int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (strcmp(cmd, "echo") == 0 || strcmp(cmd, "cd") == 0 ||
		strcmp(cmd, "pwd") == 0 || strcmp(cmd, "export") == 0 ||
		strcmp(cmd, "unset") == 0 || strcmp(cmd, "env") == 0 ||
		strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

static void	core_layer(t_shell *shell , t_cmd *cmds)
{
	t_data	*data = malloc(sizeof(t_data));
	int		saved_out;
	int		saved_in;
	int		check_builtin;

	data->env = shell->envp_shell;
	if (cmds->next)
		exec_pipe(data, cmds);
	else
	{
		check_builtin = is_builtin(cmds->args[0]);
		if (check_builtin == 1)
		{
			saved_in = dup(STDIN_FILENO);
			saved_out = dup(STDOUT_FILENO);    
			if (redirec(cmds->redirs) == 0)
				exec_cmd(data, cmds);
			dup2(saved_out, STDOUT_FILENO);
			dup2(saved_in, STDIN_FILENO);
			close(saved_in);
			close(saved_out);
		}
		else
			external_cmd(data, cmds);
	}
	shell->envp_shell = data->env;
	shell->exit_status = data->exit_status;
	free(data);
}

static void	command_mod(t_shell *shell)
{
	t_node *head_t;
	t_cmd *cmds;

	if (history_add(shell->line_input) == 0)
		if (check_required(shell->line_input) == 0)
		{
			head_t = tokenization(shell->line_input);
			if (!head_t)
			{
				free_line(shell);
				return ;
			}
			cmds = parsing(head_t);
			expand_all(cmds,shell);
			core_layer(shell, cmds);
			free_token_list(head_t);
			free_cmd(&cmds);
		}
	free_line(shell);
}

int	handle_heredoc(t_cmd *cmd)
{
	t_cmd	*temp_cmd;

	while (cmd)
	{
		if (cmd->redirs->type == 7)
			heredoc(cmd->args);
		cmd = cmd->next;
	}
	return (0);
}

void	shell(char **envp)
{
	char	*line;
	t_shell	*shell;

	shell = init_shell(envp);
	if (!shell)
		return ;
	line = NULL;
	while ((line = readline(PROMPT)))    
	{
		shell->line_input = ft_strdup(line);
		free(line);
		command_mod(shell);
	}
	write(1, "exit\n", 5);
	free_shell(shell);
}
