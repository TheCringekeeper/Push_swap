/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:33:34 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 17:06:26 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
