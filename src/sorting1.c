/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:26:16 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/02 16:51:38 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sorting_3(t_data *data)
{
	int	a;
	int	b;
	int	max;
	int	tmp;

	a = data->index_a;
	max = 0;
	tmp = data->stack[a];
	while (++a < data->stack_size)
	{
		if (tmp < data->stack[a])
		{
			tmp = data->stack[a];
			max = a - data->index_a;
		}
	}
	a = data->index_a;
	b = a + 1;
	if (max == 0)
		ft_ra(data);
	else if (max == 1)
		ft_rra(data);
	if (data->stack[a] > data->stack[b])
		ft_sa(data);
}

void	sorting_smol(t_data *data)
{
	if (data->stack_size == 2)
	{
		if (data->stack[0] > data->stack[1])
			ft_sa(data);
		return ;
	}
	else if (data->stack_size == 3)
		sorting_3(data);
}

void	sorting_4(t_data *data)
{
	int	min;

	min = min_index_in_a(data);
	if (min == 1)
		ft_sa(data);
	else if (min == 2)
	{
		ft_rra(data);
		ft_rra(data);
	}
	else if (min == 3)
		ft_rra(data);
	ft_pb(data);
	sorting_3(data);
	ft_pa(data);
}

static void	ultimate_5_sorting(t_data *data)
{
	int	min;

	min = min_index_in_a(data);
	if (min == 1)
		ft_sa(data);
	else if (min == 2)
	{
		ft_ra(data);
		ft_ra(data);
	}
	else if (min == 3)
	{
		ft_rra(data);
		ft_rra(data);
	}
	else if (min == 4)
		ft_rra(data);
	ft_pb(data);
}

void	sorting_5(t_data *data)
{
	int	min;

	ultimate_5_sorting(data);
	min = min_index_in_a(data);
	if (min == 1)
		ft_sa(data);
	else if (min == 2)
	{
		ft_rra(data);
		ft_rra(data);
	}
	else if (min == 3)
		ft_rra(data);
	ft_pb(data);
	sorting_3(data);
	ft_pa(data);
	if (data->stack[data->index_a] > data->stack[data->stack_size - 1])
		ft_ra(data);
	ft_pa(data);
	if (data->stack[data->index_a] > data->stack[data->stack_size - 1])
		ft_ra(data);
}
