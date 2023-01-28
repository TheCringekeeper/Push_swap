/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:26:25 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 13:10:03 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* protiv chasovoi */
void	ft_ra(t_data *data)
{
	int	tmp;
	int	i;

	i = data->index_a + 1;
	if (data->stack_size - data->index_a > 0)
	{
		tmp = data->stack[data->index_a];
		while (i < (data->stack_size - data->index_a))
		{
			data->stack[i - 1] = data->stack[i];
			i++;
		}
		data->stack[data->stack_size - 1] = tmp;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_data *data)
{
	int	tmp;
	int	i;

	i = data->index_a - 1;
	if (data->index_a > 0)
	{
		tmp = data->stack[data->index_a - 1];
		while (i > 0)
		{
			data->stack[i] = data->stack[i - 1];
			i--;
		}
		data->stack[0] = tmp;
		write(1, "ra\n", 3);
	}
}
