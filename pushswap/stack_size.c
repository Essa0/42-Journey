/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:10:11 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/22 01:59:14 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_node *stack)
{
	int i;

	if (!stack)
		return(0);

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}