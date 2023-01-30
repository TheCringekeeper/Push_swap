/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/30 12:50:14 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->stack_size - 1)
	{
		if (data->stack[i] > data->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
	if (data->stack_size > 1 && data->stack_size < 4)
		sorting_izi(data);
	else if (data->stack_size == 4)
		sorting_4(data);
	else if (data->stack_size == 5)
		sorting_5(data);
	// else
	// 	sorting_everything(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*tmp;

	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		tmp = ft_strjoin("./push_swap ", argv[1]);
		argv = ft_split(tmp, ' ');
		argc = 0;
		while (argv && argv[argc])
			argc++;
	}
	data.stack_size = argc - 1;
	if (parsing_error(argv))
		error();
	data.stack = get_stack(data.stack_size, argv);
	if (!data.stack)
		error();
	data.index_a = 0;
	if (is_sorted(&data))
		return (free_stack(&data), 0);
	choosing_approach(&data);
	free_stack(&data);
	return (0);
}
