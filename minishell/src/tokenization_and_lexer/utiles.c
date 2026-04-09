/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:45:28 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:45:29 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_token_list(t_node *head)
{
	t_node 	*temp;
	t_node	*next;
	t_token	*tok;

	if (!head)
		return ;
	temp = head;
	while (temp)
	{
		next = temp->next;
		if (temp->content)
		{
			tok = (t_token *)temp->content;
			if (tok->value)
				free(tok->value);
			free(tok);
		}
		free(temp);
		temp = next;
	}
}

int	check_char_t(char c)
{
	if (c == '|' || c == ' ' || c == '<' || c == '>')
		return (1);
	return (0);
}
