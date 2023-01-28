/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:26:16 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 13:27:42 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->stack_size - 1)
	{
		if (data->stack[i] > data->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sorting_3(t_data *data)
{
	int	max;

	if (data->stack_size == 1)
		return ;
	else if (data->stack_size == 2)
	{
		if (data->stack[0] > data->stack[1])
			ft_sa(data);
		return ;
	}
	else if (data->stack_size == 3)
	{
		max = ft_max_index(data);
		if (max == 0)
			ft_ra(data);
		else if (max == 1)
			ft_rra(data);
		if (data->stack[0] > data->stack[1])
			ft_sa(data);
	}
}
