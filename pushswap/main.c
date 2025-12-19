/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:48:48 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/19 23:38:31 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void print_stack(t_node *node)
// {
// 	while (node)
// 	{
// 		printf("%d ", node->val);
// 		node = node->next;
// 	}
// 	printf("\n");
// }

int	main(int argc, char **argv)
{
	int count = 0;
	int *numbers;
	char **part;
	t_node *stack_a;
	t_node *stack_b;

	if (argc > 1)
	{
		part = split_and_store(argc, argv);
		if (!part || !part[0])
		{
			write(1, "Error in split\n", 6);
			return (1);
		}
		if (!validateInput(part))
		{
			free_full_arr(part);
			write(1, "Error in split\n", 6);
			return (1);
		}

		numbers = convert_to_integer(part, &count);

		if (!numbers)
		{
			printf("Error Numbers\n");
			free_full_arr(part);
			return (1);
		}
		if (!check_for_duplicate(numbers, count))
		{
			printf("there are duplicate");
			free(numbers);
			free_full_arr(part);
			return (1);
		}

		stack_a = init_stack(numbers, count);
		stack_b = NULL;

		// printf("before sort\n");
		// print_stack(stack_a);
		// printf("\n");

		simple_sort(&stack_a, &stack_b);

		// printf("after sort\n");
		// print_stack(stack_a);
		// printf("\n");

		// if (is_sorted(stack_a))
		// 	printf("sort is done\n");
		// else
		// 	printf("error sort\n");

		free_stack(stack_a);
		if (stack_b)
			free_stack(stack_b);
		free(numbers);
		free_full_arr(part);
	}
	return (0);
}

