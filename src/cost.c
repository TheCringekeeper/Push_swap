/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:16:17 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/01 16:24:01 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_best_move(int ra, int rb, int rra, int rrb)
{
	int	rr;
	int	ra_rrb;
	int	rra_rb;
	int	rrr;

	if (ra > rb)
		rr = ra;
	else
		rr = rb;
	ra_rrb = ra + rrb;
	rra_rb = rra + rb;
	if (rra > rrb)
		rrr = rra;
	else
		rrr = rrb;
	if (rr <= ra_rrb && rr <= rra_rb && rr <= rrr)
		return (1);
	else if (ra_rrb <= rr && ra_rrb <= rra_rb && ra_rrb <= rrr)
		return (2);
	else if (rra_rb <= rr && rra_rb <= ra_rrb && rra_rb <= rrr)
		return (3);
	return (4);
}

int	find_cost(t_data *data, int i)
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
	{
		if (cost_ra > cost_rb)
			return (cost_ra);
		return (cost_rb);
	}
	else if (best == 2)
		return (cost_ra + cost_rrb);
	else if (best == 3)
		return (cost_rra + cost_rb);
	if (cost_rra > cost_rrb)
		return (cost_rra);
	return (cost_rrb);
}
