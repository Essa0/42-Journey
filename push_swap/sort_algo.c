/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:10:15 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/25 13:57:08 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bits_count(int x)
{
	int	i;

	if (x == 0)
		return (0);
	i = 0;
	while (x > 0)
	{
		x = x / 2;
		i++;
	}
	return (i);
}

void	sort_algo(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	bit;
	int	size;	
	int	bit_max;

	bit_max = bits_count(stack_size(*stack_a));
	bit = 0;
	while (bit < bit_max)
	{
		size = stack_size(*stack_a);
		i = 0;
		while (i < size)
		{
			if (((*stack_a)->idx >> bit) & 1)
				r_operation("ra", stack_a, stack_b);
			else
				p_operation("pb", stack_a, stack_b);
			i++;
		}
		while (*stack_b)
			p_operation("pa", stack_a, stack_b);
		bit++;
	}
}
