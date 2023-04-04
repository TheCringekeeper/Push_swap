/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:04:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/04/04 16:46:06 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	final_rotations(t_data *data)
{
	int	min;

	min = min_index_in_a(data);
	if (min < (data->stack_size / 2))
	{
		while (min > 0)
		{
			ft_ra(data);
			min--;
		}
	}
	else
	{
		while (min < data->stack_size)
		{
			ft_rra(data);
			min++;
		}
	}
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

void	sorting_everything(t_data *data, char *argv[], int ref)
{
	if (!median_sorting(data))
	{
		free_stack(data);
		error(argv, ref);
	}
	if (is_sorted(data))
	{
		while (data->index_a > 0)
			ft_pa(data);
	}
	if (!sorting_back(data))
	{
		free_stack(data);
		error(argv, ref);
	}
}
