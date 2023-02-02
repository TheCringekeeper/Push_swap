/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/02 13:19:40 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

/* initializing and filling int	*stack */
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
		return (free(stack), NULL);
	return (stack);
}

int	data_init_error(t_data *data, int argc, char *argv[], int ref)
{
	data->stack_size = argc - 1;
	if (parsing_error(argv))
		error(argv, ref);
	data->stack = get_stack(data->stack_size, argv);
	if (!data->stack)
		error(argv, ref);
	data->index_a = 0;
	if (is_sorted(data))
	{
		if (ref)
			free_argv(argv);
		free_stack(data);
		return (1);
	}
	return (0);
}
