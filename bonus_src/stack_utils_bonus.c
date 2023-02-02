/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:16:25 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/02 13:19:21 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

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

/* searches for the min value in the stack_a */
int	min_value_in_a(t_data *data)
{
	int	min;
	int	i;

	i = data->index_a;
	min = data->stack[i];
	while (++i < data->stack_size)
	{
		if (min > data->stack[i])
			min = data->stack[i];
	}
	return (min);
}

/* searches for index of the min value in the stack_a */
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
