/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:45:30 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:45:31 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	tok_word(char *line, int *index, t_token **t)
{
	int	end;
	int	start;
	
	end = 0; // the end of token 
	start = (*index); // the start of token of word

	while (line[*index] && check_char_t(line[*index]) == 0) // find the end of token
	{
		end++;
		(*index)++;
	}
	(*index)--;
	(*t)->value = ft_substr(line, start, end); // save the value
	if (!(*t)->value)
	{
		free(*t);
		*t = NULL;
		return ;
	}
	(*t)->type = WORD;
}

static void	tok_quote(char *line, int *index, t_token **t , char c)
{
	int	end;
	int	start;
	
	start = (*index) + 1; // the start of token of word after quote
	(*index)++;
	while (line[*index] && line[*index] != c) // find the end of token    
		(*index)++;
	end = (*index) - start;
	(*t)->value = ft_substr(line, start, end); // save the value
	if (!(*t)->value)
	{
		free(*t);
		*t = NULL;
		return ;
	}
	if (c == 39)
		(*t)->type = WORD_SQ;
	if (c == 34)
		(*t)->type = WORD_DQ;
}

//static void tok_pipe(char *line, int *index, t_token *t)
static void	tok_pipe(t_token *t)
{   
	t->value = NULL;
	t->type = PIPE;
}

static void	tok_redirec(char *line, int *index, t_token **t)
{
	if (line[*index] == '<')
	{
		(*t)->type = REDIR_I;
		if (line[(*index) + 1] == '<')
		{
			(*t)->type = HEREDOC;
			(*index)++;
		}
	}
	else if (line[*index] == '>')
	{
		(*t)->type = REDIR_O;
		if (line[(*index) + 1] == '>')
		{
			(*t)->type = REDIR_A;
			(*index)++;
		}
	}
	else
		return ;
}

// note check the token before return it 
t_token	*lexer(char *line, int *index)
{
	t_token	*t;

	t = ft_calloc(1, sizeof(t_token)); // new token
	if (!t)
		return (NULL);
	if (line[*index] == 34 || line[*index] == 39)
		tok_quote(line, index, &t, line[*index]);
	// tok_pipe(line, index, t);    
	else  if (line[*index] == '|')
		tok_pipe(t);
	else if (line[*index] == '<' || line[*index] == '>')
		tok_redirec(line, index, &t);
	else
		tok_word(line, index, &t);  // كل شي ثاني = WORD
	if (!t)
		return (NULL);
	return (t);
}
