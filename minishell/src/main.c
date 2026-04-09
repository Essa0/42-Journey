#include "../include/minishell.h"

void	handle_interrupt_signal(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int main(int argc, char **argv , char **envp)
{
	(void)argv;
	if (argc != 1)
		return (1);
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
	shell(envp); // check exit code
	return (0);
}