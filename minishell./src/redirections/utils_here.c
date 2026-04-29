#include "../../include/minishell.h"

void	heredoc_sigint(int sig)
{
	(void)sig;
	g_signal = SIGINT;
	close(STDIN_FILENO);
	signal(SIGINT, SIG_DFL);
	rl_on_new_line();
}

void	setup_heredoc_signals(void)
{
	signal(SIGINT, heredoc_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	print_error(char *del)
{
	ft_printf("minishell: warning: here-document ");
	ft_printf("at line 1 delimited by end-of-file");
	ft_printf("%s%s%s\n", " (wanted `", del, "')");
}
