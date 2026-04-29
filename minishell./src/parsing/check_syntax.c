#include "../../include/minishell.h"

// done zeyad

static int	check_double_pipe(t_nodes *head)
{
	t_nodes	*temp;
	t_nodes	*t_next;

	temp = head;
	while (temp->next != NULL)
	{
		if (temp->data->type == TOKEN_PIPE)
		{
			t_next = temp->next;
			if (t_next->data->type == TOKEN_PIPE)
				return (1);
		}
		temp = temp->next;
	}
	return (0);
}

static int	check_pipe(t_nodes *head)
{
	t_nodes	*temp;
	int		err;

	err = 0;
	if (check_double_pipe(head) == 1) // check if pipe after pipe
		err = 1;
	if (head->data->type == TOKEN_PIPE) // check if first token is pipe
		err = 1;
	temp = head; // check if last token is pipe
	while (temp->next != NULL)
		temp = temp->next;
	if (temp->data->type == TOKEN_PIPE)
		err = 1;
	if (err == 1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	return (0);
}

static int	check_redir(t_nodes *head)
{
	t_nodes	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->data->type == TOKEN_REDIR_IN
			|| temp->data->type == TOKEN_REDIR_OUT
			|| temp->data->type == TOKEN_REDIR_APPEND
			|| temp->data->type == TOKEN_HEREDOC)
		{
			if (!temp->next || check_tok_type(temp->next->data) == 1)
			{
				ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n",
					2);
				return (1);
			}
		}
		temp = temp->next;
	}
	return (0);
}
int	check_syntax(t_nodes *head, t_shell *shell)
{
	if (!head)
		return (1);
	else if (check_pipe(head) == 1)
	{
		shell->exit_status = 2;
		return (1);
	}
	else if (check_redir(head) == 1)
	{
		shell->exit_status = 2;
		return (1);
	}
	return (0);
}
