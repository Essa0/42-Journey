/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldl_mshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:20:33 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:20:46 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	add_next(t_node **head, t_node *next)
{
	t_node	*temp;

	if (!next)
		return (1);
	if (!*head)
	{
		*head = next;
		return (0);
	}
	temp = *head;
	while (temp->next != NULL)    
		temp = temp->next;
	temp->next = next;
	next->prev = temp;
	next->next = NULL;
	return (0);
}
t_node	*new_node(void *cont)
{
	t_node	*node = NULL;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = cont;
	node->next = NULL;
	node->prev = NULL;    
	return (node);
}