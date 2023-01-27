/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:53:42 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/27 21:00:37 by ankhabar         ###   ########.fr       */
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
