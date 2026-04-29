// done zeyad

#include "../../include/minishell.h"

int	check_tok_type(t_token *t)
{
	if (t->type != TOKEN_WORD && t->type != TOKEN_WORD_DQ
		&& t->type != TOKEN_WORD_SQ)
		return (1);
	return (0);
}
