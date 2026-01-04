/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:48:48 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/24 17:23:42 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_fun(char **part, int *numbers, t_node *a, t_node *b)
{
	if (part)
		free_full_arr(part);
	if (numbers)
		free(numbers);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

static void	sort_stack(t_node **stack_a, t_node **stack_b, int count)
{
	idx_stack(stack_a);
	if (count == 2)
		s_operation("sa", stack_a, stack_b);
	else if (count > 2 && count <= 5)
		simple_sort(stack_a, stack_b);
	else if (count > 5)
		sort_algo(stack_a, stack_b);
}

static void	init_and_sort(char **part, int *number, int count)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = init_stack(number, count);
	if (!stack_a)
	{
		clean_fun(part, number, NULL, NULL);
		write(2, "Error\n", 6);
		return ;
	}
	stack_b = NULL;
	if (is_sorted(stack_a))
	{
		clean_fun(part, number, stack_a, stack_b);
		return ;
	}
	sort_stack(&stack_a, &stack_b, count);
	clean_fun(part, number, stack_a, stack_b);
}

static int	valid_fun(char **part, int **number, int *count)
{
	if (!validate_input(part))
	{
		free_full_arr(part);
		write(2, "Error\n", 6);
		return (0);
	}
	*number = convert_to_integer(part, count);
	if (!*number)
	{
		free_full_arr(part);
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_for_duplicate(*number, *count))
	{
		free(*number);
		free_full_arr(part);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		count;
	int		*numbers;
	char	**part;

	if (argc > 1)
	{
		part = split_and_store(argc, argv);
		if (!part || !part[0])
		{
			if (part)
				free_full_arr(part);
			write(2, "Error\n", 6);
			return (1);
		}
		count = 0;
		numbers = NULL;
		if (!valid_fun(part, &numbers, &count))
			return (1);
		init_and_sort(part, numbers, count);
	}
	return (0);
}
