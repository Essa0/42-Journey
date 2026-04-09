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

#include "../../include/minishell.h"

static int	num_args(t_node *start)
{
	t_token	*t;
	t_node	*temp;
	int		i;

	temp = start;
	i = 0;
	while (temp != NULL ) // get num of tokens 
	{
		t = (t_token *)temp->content;
		if (t->type == 3)
			break;
		if (t->type >= 4 && t->type <= 7)
		{
			temp = temp->next->next;
			continue ;
		}
		i++;
		temp = temp->next;
	}
	return (i);
}
static int	num_redir(t_node *start)
{
	t_node	*temp;
	t_token	*t;
	int		i;

	i = 0;
	temp = start;
	while (temp != NULL)
	{
		t = (t_token *)temp->content;
		if (t->type == PIPE)
			break ;
		if (t->type >= 4 && t->type <= 7)
			i++;
		temp = temp->next;
	}
	return (i);
}
static int	init_cmd(t_node *start, t_cmd **cmd)
{
	int	na;
	int	nr;

	na = num_args(start);    
	(*cmd)->args = ft_calloc(na + 1, sizeof(char *));
	(*cmd)->types = ft_calloc(na + 1, sizeof(int));
	if (!(*cmd)->args || !(*cmd)->types)
		return (1);
	nr = num_redir(start);
	if (nr > 0)
		(*cmd)->redirs = ft_calloc(nr + 1, sizeof(t_redir));
	return (0);
}
static void	set_value(t_node *node, int *ai, int *ri, t_cmd **cmd)
{
	t_token	*t;

	t = (t_token *)node->content;
	if (t->type >= 0 && t->type <= 2)
	{
		(*cmd)->args[*ai] = ft_strdup(t->value);
		(*cmd)->types[*ai] = t->type;
		(*ai)++;
	}
	if (t->type >= 4 && t->type <= 7)
	{
		(*cmd)->redirs[*ri].type = t->type;
		t = (t_token *)node->next->content;
		(*cmd)->redirs[*ri].file = ft_strdup(t->value);
		(*ri)++;
	}
}
void	build_cmd(t_node *start, t_cmd **cmd)
{
	t_token	*t;
	t_node	*temp;
	int		ai;
	int		ri;

   if (init_cmd(start, cmd) == 1) // init struct 
		return ;
	temp = start;
	ai = 0;
	ri = 0;
	while (temp != NULL)
	{
		t = (t_token *)temp->content;
		if (t->type == PIPE)
			break ;
		set_value(temp, &ai, &ri, cmd); // set value indepentend on type token
		if (t->type >= 4 && t->type <= 7)
			temp = temp->next;
		temp = temp->next;
	}
	(*cmd)->args[ai] = NULL;
	(*cmd)->types[ai] = 0;
}
