/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:26:25 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 18:41:17 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* protiv chasovoi */
void	ft_ra(t_data *data)
{
	int	tmp;
	int	i;

	i = data->index_a + 1;
	if (data->stack_size - data->index_a > 1)
	{
		tmp = data->stack[data->index_a];
		while (i <= (data->stack_size - data->index_a))
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

	i = 1;
	if (data->index_a > 1)
	{
		tmp = data->stack[data->index_a - 1];
		while (i < data->index_a)
		{
			data->stack[i - 1] = data->stack[i];
			i++;
		}
		data->stack[0] = tmp;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_data *data)
{
	int	tmp;
	int	i;

	i = data->index_a + 1;
	if (data->stack_size - data->index_a > 1 && data->index_a > 1)
	{
		tmp = data->stack[data->index_a];
		while (i <= (data->stack_size - data->index_a))
		{
			data->stack[i - 1] = data->stack[i];
			i++;
		}
		data->stack[data->stack_size - 1] = tmp;
	}
	i = 1;
	if (data->stack_size - data->index_a > 1 && data->index_a > 1)
	{
		tmp = data->stack[data->index_a - 1];
		while (i < data->index_a)
		{
			data->stack[i - 1] = data->stack[i];
			i++;
		}
		data->stack[0] = tmp;
		write(1, "rr\n", 3);
	}
}
