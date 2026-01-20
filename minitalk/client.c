/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:39:32 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/20 03:49:55 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"


void	action(int sig)
{
	(void)sig;
}

void	send_str(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
		{
			if(kill(pid, SIGUSR1) == -1)
			{
				ft_printf("invalid pid\n");
				exit(1);
			}
		}
		else
		{
			if(kill(pid, SIGUSR2) == -1)
			{
				ft_printf("invalid pid\n");
				exit(1);
			}
		}
		bit++;
		pause();
	}
	
}

int main(int ac, char **av)
{
	int	i;
	int	pid;

	if(ac != 3)
	{
		ft_printf("invalid number of arg");
		return (0);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, action);
	i = 0;
	while (av[2][i])
	{
		send_str(pid, av[2][i]);
		i++;
	}
	send_str(pid, '\0');
	return (0);
}