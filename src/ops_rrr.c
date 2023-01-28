/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:00:01 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 13:26:42 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* po chasovoi */
void	ft_rra(t_data *data)
{
	int	tmp;
	int	i;

	i = data->stack_size - 1;
	if (data->stack_size - data->index_a > 0)
	{
		tmp = data->stack[data->stack_size - 1];
		while (i > data->index_a)
		{
			data->stack[i] = data->stack[i - 1];
			i--;
		}
		data->stack[data->index_a] = tmp;
		write(1, "rra\n", 4);
	}
}
