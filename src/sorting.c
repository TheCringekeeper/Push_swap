/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:26:16 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 16:55:09 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static void	sorting_3(t_data *data)
{
	int	max;

	max = max_index_in_a(data);
	if (max == 0)
		ft_ra(data);
	else if (max == 1)
		ft_rra(data);
	if (data->stack[data->index_a] > data->stack[data->index_a + 1])
		ft_sa(data);
}

void	sorting_izi(t_data *data)
{
	if (data->stack_size == 1)
		return ;
	else if (data->stack_size == 2)
	{
		if (data->stack[0] > data->stack[1])
			ft_sa(data);
		return ;
	}
	else if (data->stack_size == 3)
		sorting_3(data);
}

void	sorting_krab(t_data *data)
{
	if (data->stack_size == 4)
	{
		ft_pb(data);
		sorting_3(data);
		ft_pa(data);
		if (data->stack[0] == ft_max(data))
			ft_ra(data);
	}
	else if (data->stack_size == 5)
	{
		ft_pb(data);
		ft_pb(data);
		sorting_3(data);
		ft_pa(data);
		if (data->stack[data->index_a] > data->stack[data->stack_size - 1])
			ft_ra(data);
		ft_pa(data);
		if (data->stack[data->index_a] > data->stack[data->stack_size - 1])
			ft_ra(data);
	}
}
