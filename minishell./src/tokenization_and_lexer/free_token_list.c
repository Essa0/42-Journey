/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ldl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:18:18 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:18:31 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// done zeyad
#include "../../include/minishell.h"

void	free_token(t_nodes *token)
{
	free(token->data->value);
	free(token->data);
	free(token);
}

void	free_token_list(t_nodes *head)
{
	t_nodes	*temp;
	t_nodes	*next;
	t_token	*tok;

	if (!head)
		return ;
	temp = head;
	next = NULL;
	while (temp)
	{
		next = temp->next;
		tok = temp->data;
		if (tok)
		{
			if (tok->value)
				free(tok->value);
			free(tok);
		}
		free(temp);
		temp = next;
	}
	head = NULL;
}
