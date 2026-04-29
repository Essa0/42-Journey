#include "../include/minishell.h"

void	handle_interrupt_signal(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signal = 130;
}

void	setup_interactive_signals(void)
{
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **envp)
{
	int		g;
	t_shell	*shell_m;

	(void)argv;
	if (argc != 1)
		return (1);
	setup_interactive_signals();
	shell_m = init_shell(envp);
	if (!shell_m)
		return (0);
	g = shell(shell_m);
	return (g);
}
