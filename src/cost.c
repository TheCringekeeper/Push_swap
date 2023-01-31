/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:27:56 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 20:17:39 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_find_most_optimal(int cost_ra, int cost_rb, int cost_rra, int cost_rrb)
{
	int	cost_ra_rb;
	int	cost_ra_rrb;
	int	cost_rra_rb;
	int	cost_rra_rrb;

	cost_ra_rb = get_max(cost_ra, cost_rb);
	cost_ra_rrb = cost_ra + cost_rrb;
	cost_rra_rb = cost_rra + cost_rb;
	cost_rra_rrb = get_max(cost_rra, cost_rrb);
	if (cost_ra_rb <= cost_ra_rrb && cost_ra_rb <= cost_rra_rb \
		&& cost_ra_rb <= cost_rra_rrb)
		return (1);
	else if (cost_ra_rrb <= cost_ra_rb && cost_ra_rrb <= cost_rra_rb \
			&& cost_ra_rrb <= cost_rra_rrb)
		return (2);
	else if (cost_rra_rb <= cost_ra_rb && cost_rra_rb <= cost_ra_rrb \
			&& cost_rra_rb <= cost_rra_rrb)
		return (3);
	else
		return (4);
}

int	find_cost(t_data *data, int i)
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
		return (get_max(cost_ra, cost_rb));
	else if (the_most_opt == 2)
		return (cost_ra + cost_rrb);
	else if (the_most_opt == 3)
		return (cost_rra + cost_rb);
	else
		return (get_max(cost_rra, cost_rrb));
}
