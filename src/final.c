/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:59:28 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 16:04:10 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min(t_data *data)
{
	int	i;
	int	min;

	i = 1;
	min = data->stack[0];
	while (i < data->stack_size)
	{
		if (data->stack[i] < min)
			min = data->stack[i];
		i++;
	}
	return (min);
}

void	final_rotations(t_data *data)
{
	int	min;
	int	pos;
	int	i;

	min = find_min(data);
	pos = data->index_a;
	while (data->stack[pos] != min)
		pos++;
	i = 0;
	if (pos < data->stack_size - pos)
	{
		while (i < pos)
		{
			ft_ra(data);
			i++;
		}
		return ;
	}
	while (i < data->stack_size - pos)
	{
		ft_rra(data);
		i++;
	}
}
