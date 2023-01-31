/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:16:57 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 21:08:07 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min_in_a(t_data *data)
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

/* if the value is the new min, count moves to reach current min to replace it
*    which is equivalent to search for min index in stack a
*  else if the value shold be somewhere in the middle of the stack,
*    I go through the list and compare the value with two numbers next to it
*    until I find the right place */
int	ft_cost_ra(t_data *data, int value)
{
	int	min;
	int	num1;
	int	num2;
	int	count;

	count = 0;
	min = find_min_in_a(data);
	if (min > value)
		return (min_index_in_a(data));
	else
	{
		num1 = data->index_a;
		num2 = data->stack_size - 1;
		while (data->stack[num1] < value || value < data->stack[num2])
		{
			count++;
			num1++;
			num2++;
			if (num2 == data->stack_size)
				num2 = data->index_a;
		}
	}
	return (count);
}

/* if the value is the new min, count moves to reach current min to replace it
*    which is equivalent to search for min index in stack a, but from the end
*  else if the value shold be somewhere in the middle of the stack,
*    I go through the list and compare the value with two numbers next to it
*    until I find the right place */
int	ft_cost_rra(t_data *data, int value)
{
	int	min;
	int	num1;
	int	num2;
	int	count;

	count = data->stack_size - data->index_a;
	min = find_min_in_a(data);
	if (min > value)
		return (data->stack_size - data->index_a - min_index_in_a(data));
	else
	{
		num1 = data->index_a;
		num2 = data->stack_size - 1;
		while (data->stack[num1] < value || value < data->stack[num2])
		{
			count--;
			num1--;
			num2--;
			if (num1 == data->index_a - 1)
				num1 = data->stack_size - 1;
		}
	}
	return (data->stack_size - data->index_a - count);
}

int	ft_cost_rb(t_data *data, int value)
{
	int	ptr;
	int	count;

	count = 0;
	ptr = data->index_a - 1;
	while (data->stack[ptr] != value)
	{
		ptr--;
		count++;
	}
	return (count);
}

int	ft_cost_rrb(t_data *data, int value)
{
	int	ptr;
	int	count;

	count = data->index_a - 1;
	ptr = 0;
	while (data->stack[ptr] != value)
	{
		count--;
		ptr++;
	}
	return (data->index_a - count);
}
