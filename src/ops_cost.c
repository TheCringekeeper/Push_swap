/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:43:08 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/01 16:25:24 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_cost_ra(t_data *data, int value)
{
	int	count;
	int	lim1;
	int	lim2;
	int	min;

	count = 0;
	min = min_value_in_a(data);
	if (min > value)
		return (min_index_in_a(data));
	else
	{
		lim1 = data->index_a;
		lim2 = data->stack_size - 1;
		while (value > data->stack[lim1] || data->stack[lim2] > value)
		{
			count++;
			lim1++;
			lim2++;
			if (lim2 == data->stack_size)
				lim2 = data->index_a;
		}
	}
	return (count);
}

int	get_cost_rra(t_data *data, int value)
{
	int	count;
	int	lim1;
	int	lim2;
	int	min;

	count = 0;
	min = min_value_in_a(data);
	if (min > value)
		return (data->stack_size - data->index_a - min_index_in_a(data));
	else
	{
		lim1 = data->index_a;
		lim2 = data->stack_size - 1;
		while (value > data->stack[lim1] || data->stack[lim2] > value)
		{
			count++;
			lim1--;
			lim2--;
			if (lim1 == data->index_a - 1)
				lim1 = data->stack_size - 1;
		}
	}
	return (count);
}

int	get_cost_rb(t_data *data, int value)
{
	int	count;
	int	ptr;

	ptr = data->index_a - 1;
	count = 0;
	while (data->stack[ptr] != value)
	{
		ptr--;
		count++;
	}
	return (count);
}

int	get_cost_rrb(t_data *data, int value)
{
	int	count;
	int	ptr;

	ptr = data->index_a - 1;
	count = 0;
	while (data->stack[ptr] != value)
	{
		count++;
		ptr++;
		if (ptr == data->index_a)
			ptr = 0;
	}
	return (count);
}
