/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:28:27 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 15:57:15 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_node(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

static void	sa(t_node **stack_a)
{
	swap_node(stack_a);
	write(1, "sa\n", 3);
}

static void	sb(t_node **stack_b)
{
	swap_node(stack_b);
	write(1, "sb\n", 3);
}

static void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_node(stack_a);
	swap_node(stack_b);
	write(1, "ss\n", 3);
}

void	s_operation(char *operation, t_node **a, t_node **b)
{
	if (ft_strcmp("sa", operation) == 0)
		sa(a);
	else if (ft_strcmp("sb", operation) == 0)
		sb(b);
	else if (ft_strcmp("ss", operation) == 0)
		ss(a, b);
}
