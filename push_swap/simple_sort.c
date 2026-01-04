/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:21:22 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/25 03:24:59 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **stack_a, t_node **stack_b)
{
	int	pos_max;

	pos_max = max_idx(*stack_a);
	if (pos_max == 0)
	{
		r_operation("ra", stack_a, stack_b);
		if ((*stack_a)->val > (*stack_a)->next->val)
			s_operation("sa", stack_a, stack_b);
	}
	else if (pos_max == 1)
	{
		rr_operation("rra", stack_a, stack_b);
		if ((*stack_a)->val > (*stack_a)->next->val)
			s_operation("sa", stack_a, stack_b);
	}
	else
	{
		if ((*stack_a)->val > (*stack_a)->next->val)
			s_operation("sa", stack_a, stack_b);
	}
}

static void	move_top(t_node **stack_a, t_node **stack_b, int pos)
{
	int		size;

	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			r_operation("ra", stack_a, stack_b);
	}
	else
	{
		while (pos < size)
		{
			rr_operation("rra", stack_a, stack_b);
			pos++;
		}
	}
}

static void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	pos_min;

	pos_min = min_idx(*stack_a);
	if (pos_min == 0)
		p_operation("pb", stack_a, stack_b);
	else if (pos_min == 1)
	{
		r_operation("ra", stack_a, stack_b);
		p_operation("pb", stack_a, stack_b);
	}
	else if (pos_min == 2)
	{
		r_operation("ra", stack_a, stack_b);
		r_operation("ra", stack_a, stack_b);
		p_operation("pb", stack_a, stack_b);
	}
	else if (pos_min == 3)
	{
		rr_operation("rra", stack_a, stack_b);
		p_operation("pb", stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	p_operation("pa", stack_a, stack_b);
}

static void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	pos_min;

	pos_min = min_idx(*stack_a);
	move_top(stack_a, stack_b, pos_min);
	p_operation("pb", stack_a, stack_b);
	pos_min = min_idx(*stack_a);
	move_top(stack_a, stack_b, pos_min);
	p_operation("pb", stack_a, stack_b);
	sort_three(stack_a, stack_b);
	p_operation("pa", stack_a, stack_b);
	p_operation("pa", stack_a, stack_b);
}

void	simple_sort(t_node **stack_a, t_node **stack_b)
{
	int		size;
	t_node	*cur;

	size = 0;
	cur = *stack_a;
	while (cur != NULL)
	{
		size++;
		cur = cur->next;
	}
	if (size == 2)
		s_operation("sa", stack_a, stack_b);
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
