/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idx_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 00:43:49 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 15:56:18 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	idx_stack(t_node **stack)
{
	t_node	*cur;
	t_node	*temp;
	int		new_idx;

	cur = *stack;
	temp = *stack;
	while (cur)
	{
		new_idx = 0;
		temp = *stack;
		while (temp)
		{
			if (cur->val > temp->val)
				new_idx++;
			temp = temp->next;
		}
		cur->idx = new_idx;
		cur = cur->next;
	}
}
