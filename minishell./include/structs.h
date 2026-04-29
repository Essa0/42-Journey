/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:54 by issa              #+#    #+#             */
/*   Updated: 2026/04/21 20:34:10 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

enum	e_tv_type
{
	TOKEN_WORD, // 0
	TOKEN_WORD_SQ, // 1
	TOKEN_WORD_DQ, // 2 
	TOKEN_PIPE, // 3
	TOKEN_REDIR_IN, // 4
	TOKEN_REDIR_OUT, // 5
	TOKEN_REDIR_APPEND, // 6
	TOKEN_HEREDOC, // 7	
	FLAG_E
};

typedef struct	s_token
{        
	char	*value;
	enum	e_tv_type type;
}				t_token;

typedef struct s_node
{
	t_token                 *data;
	struct s_node     		*next;
	struct s_node		    *prev;	
}                           t_nodes;




typedef struct	s_redir
{
	enum	e_tv_type   type;
	char	*file;
}				t_redir;



typedef struct	s_command_block
{
	char					**args;
	int						*types;
	t_redir					*redirs;
	struct s_command_block	*next;
}				t_cmd;

typedef struct	s_minishell
{
	char	*line_input;
	char	**envp_shell;	
	t_nodes	*tokens;
	t_cmd	*commands;
	int		exit_status;
	int		should_exit;
	int		in_pipe;
}				t_shell;

#endif