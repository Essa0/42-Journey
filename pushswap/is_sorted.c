/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:10:55 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/20 01:53:01 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_node *stack)
{
    t_node *cur;

    if (!stack)
        return (1);
    cur = stack;
    while (cur->next != NULL)
    {
        if (cur->val > cur->next->val)
        {
            return(0);
        }
        cur = cur->next;
    }
    return (1);
}
