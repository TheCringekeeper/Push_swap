/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:16:25 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 12:41:46 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* if the stack is already sorted, returns (1) */
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

int	ft_max(t_data *data)
{
	int	max;
	int	i;

	i = 0;
	max = data->stack[i];
	while (++i < data->stack_size)
	{
		if (max < data->stack[i])
			max = data->stack[i];
	}
	return (max);
}

int	max_index_in_a(t_data *data)
{
	int	max;
	int	index;
	int	i;

	i = data->index_a;
	index = 0;
	max = data->stack[i];
	while (++i < data->stack_size)
	{
		if (max < data->stack[i])
		{
			max = data->stack[i];
			index = i - data->index_a;
		}
	}
	return (index);
}

int	min_index_in_a(t_data *data)
{
	int	min;
	int	index;
	int	i;

	i = data->index_a;
	index = 0;
	min = data->stack[i];
	while (++i < data->stack_size)
	{
		if (min > data->stack[i])
		{
			min = data->stack[i];
			index = i - data->index_a;
		}
	}
	return (index);
}
