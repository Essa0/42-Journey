/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:24:58 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:31:06 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// done zeyad
#include "../../include/minishell.h"

static int	num_args(t_nodes *start)
{
	t_nodes	*temp;
	int		i;

	temp = start;
	i = 0;
	while (temp != NULL)
	{
		if (temp->data->type == TOKEN_PIPE)
			break ;
		if (temp->data->type >= 4 && temp->data->type <= 7)
		{
			if (!temp->next || temp->next->data->type == TOKEN_PIPE)
				break ;
			temp = temp->next->next;
			continue ;
		}
		i++;
		temp = temp->next;
	}
	return (i);
}
static int	num_redir(t_nodes *start)
{
	t_nodes	*temp;
	int		i;

	i = 0;
	temp = start;
	while (temp != NULL)
	{
		if (temp->data->type == TOKEN_PIPE)
			break ;
		if (temp->data->type >= 4 && temp->data->type <= 7)
			i++;
		temp = temp->next;
	}
	return (i);
}

static int	alloc_args_types(t_nodes *start, t_cmd **cmd)
{
	int	na;

	na = num_args(start);
	(*cmd)->args = ft_calloc(na + 1, sizeof(char *));
	(*cmd)->types = ft_calloc(na + 1, sizeof(int));
	if (!(*cmd)->args || !(*cmd)->types)
	{
		free((*cmd)->args);
		free((*cmd)->types);
		(*cmd)->args = NULL;
		(*cmd)->types = NULL;
		return (1);
	}
	return (0);
}

static int	alloc_redirs(t_nodes *start, t_cmd **cmd)
{
	int	nr;

	nr = num_redir(start);
	if (nr <= 0)
		return (0);
	(*cmd)->redirs = ft_calloc(nr + 1, sizeof(t_redir));
	if (!(*cmd)->redirs)
	{
		free((*cmd)->args);
		free((*cmd)->types);
		(*cmd)->args = NULL;
		(*cmd)->types = NULL;
		return (1);
	}
	return (0);
}

static int	init_cmd(t_nodes *start, t_cmd **cmd)
{
	if (alloc_args_types(start, cmd))
		return (1);
	if (alloc_redirs(start, cmd))
		return (1);
	return (0);
}

static void	set_value(t_nodes *node, int *ai, int *ri, t_cmd **cmd)
{
	t_nodes	*temp;

	temp = NULL;
	if (node->data->type >= 0 && node->data->type <= 2)
	{
		(*cmd)->args[*ai] = ft_strdup(node->data->value);
		(*cmd)->types[*ai] = node->data->type;
		(*ai)++;
	}
	if (node->data->type >= 4 && node->data->type <= 7)
	{
		if (!node->next || node->next->data->type == TOKEN_PIPE)
			return ;
		(*cmd)->redirs[*ri].type = node->data->type;
		temp = node->next;
		(*cmd)->redirs[*ri].file = ft_strdup(temp->data->value);
		(*ri)++;
	}
}

static int	handle_redir_step(t_nodes **temp)
{
	if ((*temp)->data->type < TOKEN_REDIR_IN
		|| (*temp)->data->type > TOKEN_HEREDOC)
		return (0);
	if (!(*temp)->next || (*temp)->next->data->type == TOKEN_PIPE)
		return (1);
	*temp = (*temp)->next->next;
	return (2);
}

void	build_cmd(t_nodes *start, t_cmd **cmd)
{
	t_nodes	*temp;
	int		ai;
	int		ri;
	int		step;

	if (init_cmd(start, cmd) == 1)
		return ;
	temp = start;
	ai = 0;
	ri = 0;
	while (temp != NULL)
	{
		if (temp->data->type == TOKEN_PIPE)
			break ;
		set_value(temp, &ai, &ri, cmd);
		step = handle_redir_step(&temp);
		if (step == 1)
			break ;
		if (step == 2)
			continue ;
		temp = temp->next;
	}
	(*cmd)->args[ai] = NULL;
	(*cmd)->types[ai] = 0;
}
