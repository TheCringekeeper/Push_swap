/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 18:06:22 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*get_stack(int stack_size, char *argv[])
{
	int	*stack;
	int	i;

	i = 0;
	stack = malloc(sizeof(int) * stack_size);
	if (!stack)
		return (NULL);
	while (i < stack_size)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (has_doubles(stack, stack_size))
		return (NULL);
	return (stack);
}

static void	choosing_approach(t_data *data)
{
	if (data->stack_size > 0 && data->stack_size < 4)
		sorting_izi(data);
	// else if (data->stack_size > 3 && data->stack_size < 6)
	// 	sorting_krab(data);
	// nado sozdat odin sorting dlya vseh variantov po factu
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		return (1);
	data.stack_size = argc - 1;
	if (parsing_error(argv))
		error();
	// ft_printf("\033[0;34mparsing OK\n\033[0m");
	data.stack = get_stack(data.stack_size, argv);
	if (!data.stack)
		error();
	// ft_printf("\033[0;34mstack_OK\n\033[0m");
	data.index_a = 0;
	if (is_sorted(&data))
		return (free_stack(&data), 0);
	choosing_approach(&data);
	free_stack(&data);
	return (0);
}
