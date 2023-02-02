/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:53:42 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/02 13:19:36 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ft_pa(t_data *data)
{
	if (data->index_a > 0)
		data->index_a--;
}

void	ft_pb(t_data *data)
{
	if (data->stack_size - data->index_a > 0)
		data->index_a++;
}

void	ft_sa(t_data *data)
{
	int	swap;

	if ((data->stack_size - data->index_a) > 1)
	{
		swap = data->stack[data->index_a];
		data->stack[data->index_a] = data->stack[data->index_a + 1];
		data->stack[data->index_a + 1] = swap;
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
	}
}
