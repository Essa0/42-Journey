/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 02:19:46 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 15:39:40 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_node(t_node **stack_a)
{
	t_node	*curr;
	t_node	*head;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	curr = *stack_a;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = head;
	head->next = NULL;
}

static void	ra(t_node **stack_a)
{
	rotate_node(stack_a);
	write(1, "ra\n", 3);
}

static void	rb(t_node **stack_b)
{
	rotate_node(stack_b);
	write(1, "rb\n", 3);
}

static void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_node(stack_a);
	rotate_node(stack_b);
	write(1, "rr\n", 3);
}

void	r_operation(char *operation, t_node **a, t_node **b)
{
	if (ft_strcmp("ra", operation) == 0)
		ra(a);
	else if (ft_strcmp("rb", operation) == 0)
		rb(b);
	else if (ft_strcmp("rr", operation) == 0)
		rr(a, b);
}
