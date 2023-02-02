/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:10:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/02 15:36:44 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static void	choosing_approach(t_data *data, char *argv[], int ref)
{
	if (data->stack_size > 1 && data->stack_size < 4)
		sorting_smol(data);
	else if (data->stack_size == 4)
		sorting_4(data);
	else if (data->stack_size == 5)
		sorting_5(data);
	else
		sorting_everything(data, argv, ref);
}

static int	data_init_error(t_data *data, int argc, char *argv[], int ref)
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

/* ya ne znayu kak eto ispravit >:( */
int	main(int argc, char *argv[])
{
	t_data	data;
	char	*tmp;
	int		ref;

	ref = 0;
	if (argc > 1)
	{
		if (argc == 2 && argv[1][0] && ft_strcmp(argv[1], "-2147483648"))
		{
			tmp = ft_strjoin("./push_swap ", argv[1]);
			argv = ft_split(tmp, ' ');
			free(tmp);
			ref = 1;
			argc = 0;
			while (argv && argv[argc])
				argc++;
		}
		if (data_init_error(&data, argc, argv, ref))
			return (1);
		choosing_approach(&data, argv, ref);
		if (ref)
			free_argv(argv);
		free_stack(&data);
	}
	return (0);
}
