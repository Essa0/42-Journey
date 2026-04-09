/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:50 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:17:51 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_data
{
	char	**env;
	int		exit_status;
}				t_data;

void	free_env(char **env);
void	handle_interrupt_signal(int sig);
void	exec_cmd(t_data *data, t_cmd *cmd);
void    exec_pipe(t_data *data, t_cmd *cmd);
void	external_cmd(t_data *data, t_cmd *cmd);
int		ft_pwd(void);
int		ft_echo(char **av);
int		ft_cd(t_data *data, char **av);
int		ft_unset(t_data *data, char **av);
int		ft_export(t_data *data, char **av);
int		exec_builtin(t_data *data, char **av);
char	*get_cur_path(void);
char	*get_cmd_path(char **env, char *cmd);
char	**set_env(char **env, char *key, char *val);
#endif
