/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:19:16 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:19:57 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../libft/libft.h"

typedef struct	s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

int		add_next(t_node **head, t_node *next);
t_node	*new_node(void *cont);
void	free_ldl(t_node *head);

#endif