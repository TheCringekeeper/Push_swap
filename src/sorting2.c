/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:04:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 19:37:51 by ankhabar         ###   ########.fr       */
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
	median = test_stack[(size - 1) / 2];
	free(test_stack);
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

int	sorting_back(t_data *data)
{
	int	*costs;
	int	min_cost;
	int	i;

	while (data->index_a > 0)
	{
		min_cost = 0;
		costs = malloc(sizeof(int) * (data->index_a));
		if (!costs)
			return (0);
		i = 0;
		while (i < data->index_a)
		{
			costs[i] = find_cost(data, i);
			if (costs[i] < costs[min_cost])
				min_cost = i;
			i++;
		}
		do_ops(data, min_cost);
		free(costs);
	}
	final_rotations(data);
	return (1);
}

void	sorting_everything(t_data *data)
{
	if (!part1_median(data))
		error();
	if (is_sorted(data))
	{
		while (data->index_a > 0)
			ft_pa(data);
	}
	if (!sorting_back(data))
		error();
}
