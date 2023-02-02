/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:45:09 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/01 15:24:06 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_rr(t_data *data, int ra, int rb)
{
	while (ra && rb)
	{
		ft_rr(data);
		ra--;
		rb--;
	}
	while (ra)
	{
		ft_ra(data);
		ra--;
	}
	while (rb)
	{
		ft_rb(data);
		rb--;
	}
	ft_pa(data);
}

void	do_ra_rrb(t_data *data, int ra, int rrb)
{
	while (ra)
	{
		ft_ra(data);
		ra--;
	}
	while (rrb)
	{
		ft_rrb(data);
		rrb--;
	}
	ft_pa(data);
}

void	do_rra_rb(t_data *data, int rra, int rb)
{
	while (rra)
	{
		ft_rra(data);
		rra--;
	}
	while (rb)
	{
		ft_rb(data);
		rb--;
	}
	ft_pa(data);
}

void	do_rrr(t_data *data, int rra, int rrb)
{
	while (rra && rrb)
	{
		ft_rrr(data);
		rra--;
		rrb--;
	}
	while (rra)
	{
		ft_rra(data);
		rra--;
	}
	while (rrb)
	{
		ft_rrb(data);
		rrb--;
	}
	ft_pa(data);
}

void	do_ops(t_data *data, int i)
{
	int	cost_ra;
	int	cost_rra;
	int	cost_rb;
	int	cost_rrb;
	int	best;

	cost_ra = get_cost_ra(data, data->stack[i]);
	cost_rra = get_cost_rra(data, data->stack[i]);
	cost_rb = get_cost_rb(data, data->stack[i]);
	cost_rrb = get_cost_rrb(data, data->stack[i]);
	best = get_best_move(cost_ra, cost_rb, cost_rra, cost_rrb);
	if (best == 1)
		do_rr(data, cost_ra, cost_rb);
	else if (best == 2)
		do_ra_rrb(data, cost_ra, cost_rrb);
	else if (best == 3)
		do_rra_rb(data, cost_rra, cost_rb);
	else
		do_rrr(data, cost_rra, cost_rrb);
}
