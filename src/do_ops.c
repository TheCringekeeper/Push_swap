/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:50:26 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 19:37:24 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_operation_ra_rb(t_data *data, int cost_ra, int cost_rb)
{
	while (cost_ra != 0 && cost_rb != 0)
	{
		ft_rr(data);
		cost_ra--;
		cost_rb--;
	}
	while (cost_ra != 0)
	{
		ft_ra(data);
		cost_ra--;
	}
	while (cost_rb != 0)
	{
		ft_rb(data);
		cost_rb--;
	}
	ft_pa(data);
}

void	ft_operation_ra_rrb(t_data *data, int cost_ra, int cost_rrb)
{
	while (cost_ra != 0)
	{
		ft_ra(data);
		cost_ra--;
	}
	while (cost_rrb != 0)
	{
		ft_rrb(data);
		cost_rrb--;
	}
	ft_pa(data);
}

void	ft_operation_rra_rb(t_data *data, int cost_rra, int cost_rb)
{
	while (cost_rra != 0)
	{
		ft_rra(data);
		cost_rra--;
	}
	while (cost_rb != 0)
	{
		ft_rb(data);
		cost_rb--;
	}
	ft_pa(data);
}

void	ft_operation_rra_rrb(t_data *data, int cost_rra, int cost_rrb)
{
	while (cost_rra != 0 && cost_rrb != 0)
	{
		ft_rrr(data);
		cost_rra--;
		cost_rrb--;
	}
	while (cost_rra != 0)
	{
		ft_rra(data);
		cost_rra--;
	}
	while (cost_rrb != 0)
	{
		ft_rrb(data);
		cost_rrb--;
	}
	ft_pa(data);
}

void	do_ops(t_data *data, int i)
{
	int	cost_ra;
	int	cost_rb;
	int	cost_rra;
	int	cost_rrb;
	int	the_most_opt;

	cost_ra = ft_cost_ra(data, data->stack[data->index_a - i - 1]);
	cost_rra = ft_cost_rra(data, data->stack[data->index_a - i - 1]);
	cost_rb = ft_cost_rb(data, data->stack[data->index_a - i - 1]);
	cost_rrb = ft_cost_rrb(data, data->stack[data->index_a - i - 1]);
	the_most_opt = ft_find_most_optimal(cost_ra, cost_rb, cost_rra, cost_rrb);
	if (the_most_opt == 1)
		ft_operation_ra_rb(data, cost_ra, cost_rb);
	else if (the_most_opt == 2)
		ft_operation_ra_rrb(data, cost_ra, cost_rrb);
	else if (the_most_opt == 3)
		ft_operation_rra_rb(data, cost_rra, cost_rb);
	else
		ft_operation_rra_rrb(data, cost_rra, cost_rrb);
}
