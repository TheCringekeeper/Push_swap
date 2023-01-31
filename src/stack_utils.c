/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:16:25 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 21:22:57 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

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

/* searches for min index value in the stack_a */
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
