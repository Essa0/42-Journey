/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 00:04:36 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 15:54:35 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_idx(t_node *stack)
{
	int		max_val;
	int		idx;
	int		m_idx;
	t_node	*cur;

	if (!stack)
		return (-1);
	cur = stack;
	max_val = cur->val;
	m_idx = 0;
	idx = 0;
	while (cur != NULL)
	{
		if (cur->val > max_val)
		{
			max_val = cur->val;
			m_idx = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (m_idx);
}
