/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 01:55:45 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/03/14 23:19:10 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	customize pwd command
*/

int	ft_pwd(void)
{
	char	*cur_path;

	cur_path = get_cur_path();
	if (cur_path)
	{
		ft_putendl_fd(cur_path, 1);
		free(cur_path);
	}
	return (0);
}
