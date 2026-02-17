/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:52:19 by iabiesat          #+#    #+#             */
/*   Updated: 2026/01/20 15:11:28 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 500

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*join_string(char *o_str, char c)
{
	char	*new_str;
	int		len;
	int		i;

	len = str_len(o_str);
	new_str = malloc(len + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	if (o_str)
	{
		while (o_str[i])
		{
			new_str[i] = o_str[i];
			i++;
		}
		free(o_str);
	}
	new_str[i] = c;
	new_str[++i] = '\0';
	return (new_str);
}

void	receive_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit_count = 0;
	static char	c = 0;
	static char	*str = NULL;

	(void)context;
	if (sig == SIGUSR1)
		c = c | (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		str = join_string(str, c);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		bit_count = 0;
		c = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	ac = ac++;
	(void)av;
	ft_printf("my pid: %d\n", getpid());
	sa.sa_sigaction = receive_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
