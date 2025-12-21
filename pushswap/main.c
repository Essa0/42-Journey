/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:48:48 by  iabiesat         #+#    #+#             */
/*   Updated: 2025/12/22 02:04:36 by  iabiesat        ###   ########.fr       */
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
			write(1, "Error in validation\n", 6);
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
		if (!stack_a)
		{
			free(numbers);
			free_full_arr(part);
		}
		stack_b = NULL;

		if (is_sorted(stack_a))
		{
			free_stack(stack_a);
			free(numbers);
			free_full_arr(part);
			return (0);
		}

		idx_stack(&stack_a);
		if (count == 2)
			s_operation("sa", &stack_a, &stack_b);
		else if (count > 2 && count <= 5)
			simple_sort(&stack_a, &stack_b);
		else if(count > 5)
			sort_algo(&stack_a, &stack_b);

		free_stack(stack_a);
		if (stack_b)
			free_stack(stack_b);
		free(numbers);
		free_full_arr(part);
	}
	return (0);
}

