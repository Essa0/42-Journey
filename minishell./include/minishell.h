/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:39 by issa              #+#    #+#             */
/*   Updated: 2026/04/27 19:45:52 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define PROMPT "minishell > "

#include "token_list.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "structs.h"
#include "execution.h"
# include <sys/param.h>
# include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>


// ==============================================================

/*
https://www.gnu.org/software/bash/manual/bash.html

https://www.geeksforgeeks.org/nlp/what-is-tokenization/

https://mywiki.wooledge.org/BashParser

https://www.linux.org/threads/bash-03-%E2%80%93-command-line-processing.38676/

https://brennan.io/2015/01/16/write-a-shell-in-c/
*/


// ==============================================================
// Function prototypes

extern int g_signal;

int	shell(t_shell *shell);

t_shell	*init_shell(char **envp_main);
void free_string_array(char **arr);
int	shlvl_checked_next(char *lvl);

void free_shell(t_shell *shell);
void free_shell_partial(t_shell *shell);

int		history_add(char *line);

int	check_required(t_shell *shell, char *line);

t_nodes	*tokenization(char *line);
t_token	*lexer(char *line, int *index);
int		check_char_t(char c);
int	skip_inner_quote(char *line, int *index);
int	copy_without_quotes(char *src, char *dst);
char	*remove_quotes(char *str);

char	*get_env_val(char **env, char *key);
char	*expand_tilde(char *str, char **envp);
char	*expand_string(char *str, t_shell *shell);
int	expand_all(t_nodes **head_t, t_shell *shell);
int is_empty_expanded(char *value);
void split_after_exp(t_nodes **head);
void remove_tokens(t_nodes **head);
t_nodes *new_node_from_value(char *val);
char	*append(char *res, char *add);

t_cmd	*parsing(t_nodes *head_t);
int	check_syntax(t_nodes *head, t_shell *shell);
int		check_tok_type(t_token *t);
void	build_cmd(t_nodes *start, t_cmd **cmd);
void	free_cmd(t_cmd **cmd);
void free_args(t_cmd *cmd);

int		redirec(t_redir *re);
int		handle_heredoc(t_cmd *cmd, t_shell *shell);
void	heredoc_sigint(int sig);
void	setup_heredoc_signals(void);
void print_error(char *del);
void	setup_interactive_signals(void);

#endif