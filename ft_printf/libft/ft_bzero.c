/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:00:52 by iabiesat         #+#    #+#             */
/*   Updated: 2025/09/02 19:06:40 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	char	*tmp_ptr;
	size_t	i;

	i = 0;
	tmp_ptr = (char *)ptr;
	while (i < n)
	{
		(*tmp_ptr++) = 0;
		i++;
	}
}
// int main(){
//     char str[]="sssaassa sssaasa";    
//     ft_bzero(str+3, 2);
//     printf("%s\n", str);
// }
