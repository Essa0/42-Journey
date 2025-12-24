/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:44:13 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 15:38:48 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*curr;

	if (!*stack || !(*stack)->next)
		return ;
	curr = *stack;
	while (curr->next->next != NULL)
		curr = curr->next;
	temp = curr->next;
	curr->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

static void	rra(t_node **stack_a)
{
	reverse_rotate_stack(stack_a);
	write(1, "rra\n", 4);
}

static void	rrb(t_node **stack_b)
{
	reverse_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
}

static void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
}

void	rr_operation(char *operation, t_node **a, t_node **b)
{
	if (ft_strcmp("rra", operation) == 0)
		rra(a);
	else if (ft_strcmp("rrb", operation) == 0)
		rrb(b);
	else if (ft_strcmp("rrr", operation) == 0)
		rrr(a, b);
}
