/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:56:48 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 16:11:23 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
}					t_node;

int			min_idx(t_node *stack);
int			max_idx(t_node *stack);
int			stack_size(t_node *stack);
int			is_sorted(t_node *stack);
int			validate_input(char **arg);
int			ft_strcmp(const char *s1, const char *s2);
int			check_for_duplicate(int *numbers, int size);
int			*convert_to_integer(char **part, int *count);
void		idx_stack(t_node **stack);
void		free_full_arr(char **arr);
void		simple_sort(t_node **stack_a, t_node **stack_b);
void		sort_algo(t_node **stack_a, t_node **stack_b);
void		s_operation(char *operation, t_node **a, t_node **b);
void		p_operation(char *operation, t_node **a, t_node **b);
void		r_operation(char *operation, t_node **a, t_node **b);
void		rr_operation(char *operation, t_node **a, t_node **b);
void		free_stack(t_node *stack);
char		**free_partial_arr(char **result, int i);
char		**split_and_store(int argc, char **argv);
t_node		*init_stack(int *num, int count);
long long	ft_atoll(char *c);
#endif