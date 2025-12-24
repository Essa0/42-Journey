/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_idx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 00:06:36 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 15:53:33 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_idx(t_node *stack)
{
	int		min_val;
	int		idx;
	int		m_idx;
	t_node	*cur;

	if (!stack)
		return (-1);
	cur = stack;
	min_val = cur->val;
	m_idx = 0;
	idx = 0;
	while (cur != NULL)
	{
		if (cur->val < min_val)
		{
			min_val = cur->val;
			m_idx = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (m_idx);
}
