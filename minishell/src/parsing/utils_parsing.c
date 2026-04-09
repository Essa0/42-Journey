#include "../../include/minishell.h"

int	check_tok_type(t_token *t)
{
	if (t->type != WORD && t->type != WORD_DQ && t->type != WORD_SQ)
		return (1);
	return (0);
}
static int	is_control_op(int type)
{
	if (type == PIPE)
		return (1);
	return (0);
}

int	check_con_op(t_node *cmd)
{
	t_node	*temp;
	t_token	*temp_t;

	temp = cmd;
	while (temp != NULL)
	{
		temp_t = temp->content;
		 if (is_control_op(temp_t->type))
			return (1);
		temp = temp->next;
	}
	return (0);
}

