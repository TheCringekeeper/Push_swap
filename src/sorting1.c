/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:26:16 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 13:27:29 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sorting_3(t_data *data)
{
	int	a;
	int	b;
	int	max;

	if (data->stack_size - data->index_a != 3)
		ft_printf("problem in sorting 3\n");
	a = data->index_a;
	b = a + 1;
	max = max_index_in_a(data);
	if (max == 0)
		ft_ra(data);
	else if (max == 1)
		ft_rra(data);
	if (data->stack[a] > data->stack[b])
		ft_sa(data);
}

void	sorting_izi(t_data *data)
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
	if (data->stack[0] == ft_max(data))
		ft_ra(data);
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
