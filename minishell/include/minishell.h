/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:39 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:17:40 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ==============================================================
// Defines
#define PROMPT "minishell > "

// Includes

#include "linked_list/linked_list.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"
#include "structs.h"
#include "execution.h"

# include <sys/param.h>
# include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
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



// this function in shell.c
void	shell(char **envp); // in progress 

// init shell 
t_shell	*init_shell(char **envp_main); // maybe full

// free shell 
void	free_shell(t_shell *shell); // not full 
void	free_line(t_shell *shell);

/*command mode*/
// history
int		history_add(char *line);

// this function in validation not required
int		check_required(char *line); // done

// tokenization and lexer 
t_node	*tokenization(char *line); // in progress 
t_token	*lexer(char *line, int *index);
int		check_char_t(char c);
void	free_token_list(t_node *head);

//parsing
t_cmd	*parsing(t_node *head_t); // it takes a command after tonknization it
int		check_syntax(t_node *head); // check syntax of command
int		check_tok_type(t_token *t);
void	build_cmd(t_node *start, t_cmd **cmd);
//t_redir *build_redirs(t_node *head);
void	free_cmd(t_cmd **cmd);


//exp
char	*get_env_val(char **env, char *key);
int		is_var_char(char c);
char	*expand_tilde(char *str, char **envp);
char	*expand_string(char *str, t_shell *shell);
void	expand_all(t_cmd *cmd, t_shell *shell);
int		redirec(t_redir *re);

/*            command mode                  */
#endif