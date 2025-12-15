/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_partial_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:30:54 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/10 16:31:58 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_partial_arr(char **result, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
	free(result);
	return (NULL);
}