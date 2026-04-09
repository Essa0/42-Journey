/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:37:48 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:38:28 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heredoc(char *del)
{
	int		fd;
	char	*line;

	fd = open(".temp_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = readlin("> ");
		if (!line || strcmp(line, del) == 0)
		{
			free(line);
			break;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
}