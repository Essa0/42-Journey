/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cur_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:22:30 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/03/06 03:57:23 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	return the current path
*/

char	*get_cur_path(void)
{
	char	*buf;

	buf = malloc(PATH_MAX);
	if (!buf)
		return (NULL);
	if (getcwd(buf, PATH_MAX) == NULL)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}
