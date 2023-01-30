/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:04:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/30 20:05:41 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*get_tmp_stack(t_data *data, int size)
{
	int	*stack;
	int	i;

	i = 0;
	stack = malloc(sizeof(int) * size);
	if (!stack)
		return (NULL);
	while (i < size)
	{
		stack[i] = data->stack[data->index_a + i];
		printf("%i ", stack[i]);
		i++;
	}
	if (has_doubles(stack, size))
		return (NULL);
	return (stack);
}

static int	find_median(t_data *data)
{
	int	*test_stack;
	int	median;
	int	size;

	size = (data->stack_size - data->index_a);
	test_stack = get_tmp_stack(data, size);
	ft_quicksort(test_stack, 0, size - 1);
	median = test_stack[size / 2];
	free(test_stack);
	printf("median: %i\n", median);
	return (median);
}

static int	part1_median(t_data *data)
{
	int	median;
	int	i;

	median = 0;
	while ((data->stack_size - data->index_a) > 3)
	{
		median = find_median(data);
		i = 0;
		while (i < (data->stack_size - data->index_a))
		{
			if (data->stack[data->index_a] < median)
				ft_pb(data);
			else
			{
				i++;
				ft_ra(data);
			}
		}
	}
	sorting_3(data);
	return (1);
}

/* dobavit part2 sorting from b to a
*  dobavit move cost i sravnivat s kajdim novim
*  while(1)
*     if (min_cost > current_cost)
*        min_cost = current_cost;
*  tipa takovo
*  a v konce execute_command(min_cost) */
void	sorting_everything(t_data *data)
{
	if (!part1_median(data))
		error();
	int i = 0;
	while (i < data->stack_size)
	{
		printf("%i ", data->stack[i]);
		i++;
	}
}
