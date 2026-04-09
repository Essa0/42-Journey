/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 02:33:32 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/02 23:23:42 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_builtin(t_data *data, char **av)
{
	if (strcmp(av[0], "echo") == 0)
		return (ft_echo(av));
	else if (strcmp(av[0], "pwd") == 0)
		return (ft_pwd());
	else if (strcmp(av[0], "export") == 0)
		return (ft_export(data, av));
	else if (strcmp(av[0], "unset") == 0)
		return (ft_unset(data, av));
	else if (strcmp(av[0], "exit") == 0)
		return (5);
	else if (strcmp(av[0], "cd") == 0)
		return (ft_cd(data, av));
	return (-1);
}