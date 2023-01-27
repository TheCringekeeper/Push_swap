/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/27 21:30:34 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*get_stack(int stack_size, char *argv[])
{
	int	*stack;
	int	i;

	i = 0;
	ft_printf("stack_len: %i\n", stack_size);
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

// static void	choosing_approach(t_data data)
// {
// 	pre_sorting(data.stack, data.stack_size);
// 	if (data.stack_size == 3)
// 		sorting_troitsa(&data);
// 	else if (data.stack_size == 5)
// 		sorting_krab(&data);
// 	else if (data.stack_size == 100)
// 		sorting_sotka(&data);
// 	else if (data.stack_size == 500)
// 		sorting_pyatihat(&data);
// }

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		return (1);
	data.stack_size = argc - 1;
	if (parsing_error(argv))
		error();
	ft_printf("\033[0;34mparsing OK\n\033[0m");
	data.stack = get_stack(data.stack_size, argv);
	if (!data.stack)
		error();
	ft_printf("\033[0;34mstack_OK\n\033[0m");
	data.index_a = data.stack[0];
	// choosing_approach(&data);
	return (0);
}
