/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:33:34 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 12:52:58 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_min(t_data *data)
{
	int	min;
	int	i;

	i = 0;
	min = data->stack[i];
	while (++i < data->stack_size)
	{
		if (min > data->stack[i])
			min = data->stack[i];
	}
	return (min);
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

int	ft_min_index(t_data *data)
{
	int	min;
	int	index;
	int	i;

	i = 0;
	index = 0;
	min = data->stack[i];
	while (++i < data->stack_size)
	{
		if (min > data->stack[i])
		{
			min = data->stack[i];
			index = i;
		}
	}
	return (index);
}

int	ft_max_index(t_data *data)
{
	int	max;
	int	index;
	int	i;

	i = 0;
	index = 0;
	max = data->stack[i];
	while (++i < data->stack_size)
	{
		if (max < data->stack[i])
		{
			max = data->stack[i];
			index = i;
		}
	}
	return (index);
}
