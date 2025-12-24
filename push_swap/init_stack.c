/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:58:15 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 17:17:58 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*create_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->val = value;
	n->idx = 0;
	n->next = NULL;
	return (n);
}

t_node	*init_stack(int *num, int count)
{
	t_node	*node;
	t_node	*curr;
	int		i;

	node = NULL;
	node = create_node(num[0]);
	if (!node)
		return (NULL);
	curr = node;
	i = 1;
	while (i < count)
	{
		curr->next = create_node(num[i]);
		if (!curr->next)
		{
			free_stack(node);
			return (NULL);
		}
		curr = curr->next;
		i++;
	}
	return (node);
}
