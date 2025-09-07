/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 00:44:02 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 19:03:30 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	char	*tmp;

	if (size == 0 || count == 0)
	{
		tmp = malloc(1);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	ft_memset (tmp, 0, count * size);
	return (tmp);
}
// int main()
// {
//     int *number;   
//     number = (int *)ft_calloc(10, sizeof(int));
//     printf("%d\n", number[0]);
//     free(number);
//     return 0;
// }
