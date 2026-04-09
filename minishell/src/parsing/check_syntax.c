#include "../../include/minishell.h"

static int	check_double_pipe(t_node *head)
{
	t_node 	*temp;
	t_token	*t;
	t_token	*t_next;

	temp = head;
	while (temp->next != NULL)
	{
		t = (t_token *)temp->content;
		if (t->type == PIPE)
		{
			t_next = (t_token *)temp->next->content;
			if (t_next->type == PIPE)
				return (1);
		}
		temp = temp->next;
	}
	return (0);
}
static int	check_pipe(t_node *head)
{
	t_node	*temp;
	t_token	*t;
	int		err;

	err = 0;
	if (check_double_pipe(head) == 1) // check if pipe after pipe
		err = 1;
	t = (t_token *)head->content;
	if (t->type == PIPE) // check if first token is pipe 
		err = 1;
	temp = head; // check if last token is pipe 
	while (temp->next != NULL)
		temp = temp->next;
	t = (t_token *)temp->content;
	if (t->type == PIPE) 
		err = 1;
	if (err == 1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	return (0);
}

static int check_redir(t_node *head)
{
	t_node	*temp;
	t_token	*t;

	temp = head;
	while (temp != NULL)
	{
		t = (t_token *)temp->content;
		if (t->type == REDIR_I || t->type == REDIR_O 
			|| t->type == REDIR_A || t->type == HEREDOC)
		{
			if (!temp->next 
				|| check_tok_type(temp->next->content) == 1)
			{
				ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n", 2);
				return (1);
			}
		}
		temp = temp->next;
	}
	return (0);
}
int	check_syntax(t_node *head)
{
	if (!head)
		return (1);
	else if (check_pipe(head) == 1)
		return (1);
	else if (check_redir(head) == 1)
		return (1);
	return (0);
}