/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 00:02:41 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 15:52:50 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_node(t_node **dest, t_node **src)
{
	t_node	*new_dest;

	if (!*src)
		return ;
	new_dest = *src;
	*src = (*src)->next;
	new_dest->next = *dest;
	*dest = new_dest;
}

static void	pa(t_node **stack_a, t_node **stack_b)
{
	push_node(stack_a, stack_b);
	write(1, "pa\n", 3);
}

static void	pb(t_node **stack_a, t_node **stack_b)
{
	push_node(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	p_operation(char *operation, t_node **a, t_node **b)
{
	if (ft_strcmp("pa", operation) == 0)
		pa(a, b);
	else if (ft_strcmp("pb", operation) == 0)
		pb(a, b);
}
