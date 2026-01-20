/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 23:38:55 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/20 03:50:52 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_server
{
	char	c;
	int		bit_count;
	char	*str;
}			t_server;

int str_len(char *str)
{
	int i;

	i = 0;
	if (!str)
		return(0);
	while (str[i])
		i++;
	return(i);
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
	static t_server var = { 0, 0,NULL};

	(void)context;
	if (sig == SIGUSR1)
		var.c = var.c | (1 << var.bit_count);
	var.bit_count++;
	if (var.bit_count == 8)
	{
		var.str = join_string(var.str, var.c);
		if (var.c == '\0')
		{
			ft_printf("%s\n", var.str);
			free(var.str);
			var.str = NULL;
		}
		var.bit_count = 0;
		var.c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int main()
{
	struct sigaction sa;

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
