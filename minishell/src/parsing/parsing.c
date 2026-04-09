#include "../../include/minishell.h"

static void	skip_p(t_node **current)
{
	t_token	*t;

	while (*current)
	{
		t = (t_token *)(*current)->content;    
		if (t->type == PIPE)
		{
			*current = (*current)->next;
			break;
		}
		*current = (*current)->next;
	}
}

static t_cmd	*parse_command(t_node **start)
{
	t_cmd *clear_cmd;
	
	clear_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!clear_cmd)
		return (NULL);
	build_cmd(*start, &clear_cmd);
	if (!clear_cmd->args)
	{
		free(clear_cmd);
		return (NULL);
	}
	if (!clear_cmd->types)
	{
		free(clear_cmd);
		return (NULL);
	}
	clear_cmd->next = NULL;
	skip_p(start);
	return (clear_cmd);
}

t_cmd	*parsing(t_node *head_t)
{
	t_cmd	*cmd_head;
	t_cmd	*temp;
	t_node	*current;

	if (check_syntax(head_t) == 1)
		return (NULL);
	current = head_t;
	cmd_head = NULL;
	temp = NULL;
	while (current)
	{
		if (!cmd_head)
		{
			cmd_head = parse_command(&current);
			temp = cmd_head;
		}
		else
		{
			temp->next = parse_command(&current);
			if (temp->next)
				temp = temp->next;
		}
	}
	return (cmd_head);
}
