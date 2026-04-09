/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:54 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:17:55 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

enum	e_tv_type
{    
	WORD, // any thing 0
	WORD_SQ, // word in ' 1
	WORD_DQ, // word in " 2
	PIPE, // |  3

	REDIR_I, // Redirecting Input <  4
	REDIR_O, // Redirecting Output > 5 
	REDIR_A, //  >>  6 
	HEREDOC, // Here Documents << 7
};

typedef struct	s_token
{        
	char	*value;
	enum	e_tv_type type;
}				t_token;

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
	int		exit_status;
}				t_shell;
#endif