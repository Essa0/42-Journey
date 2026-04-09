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

#include "linked_list.h"

void	free_ldl(t_node *head)
{
	t_node	*temp = NULL;    
	t_node	*temp2 = NULL;

	if (!head)
		return ;
	temp = head;
	while (temp)
	{        
		temp2 = temp->next;
		if (temp->content != NULL)
			free(temp->content);
		free(temp);        
		temp = temp2;
	}
}
