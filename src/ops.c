/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:53:42 by ankhabar          #+#    #+#             */
/*   Updated: 2023/04/04 16:46:13 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_pa(t_data *data)
{
	if (data->index_a > 0)
	{
		data->index_a--;
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_data *data)
{
	if (data->stack_size - data->index_a > 0)
	{
		data->index_a++;
		write(1, "pb\n", 3);
	}
}

void	ft_sa(t_data *data)
{
	int	swap;

	if ((data->stack_size - data->index_a) > 1)
	{
		swap = data->stack[data->index_a];
		data->stack[data->index_a] = data->stack[data->index_a + 1];
		data->stack[data->index_a + 1] = swap;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_data *data)
{
	int	swap;

	if (data->index_a > 1)
	{
		swap = data->stack[data->index_a - 1];
		data->stack[data->index_a - 1] = data->stack[data->index_a - 2];
		data->stack[data->index_a - 2] = swap;
		write(1, "sa\n", 3);
	}
}

void	ft_ss(t_data *data)
{
	int	swap;

	if (data->index_a > 1 && (data->stack_size - data->index_a) > 1)
	{
		swap = data->stack[data->index_a - 1];
		data->stack[data->index_a - 1] = data->stack[data->index_a - 2];
		data->stack[data->index_a - 2] = swap;
		swap = data->stack[data->index_a];
		data->stack[data->index_a] = data->stack[data->index_a + 1];
		data->stack[data->index_a + 1] = swap;
		write(1, "ss\n", 3);
	}
}
