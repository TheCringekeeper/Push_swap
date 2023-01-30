/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:00:01 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/30 14:09:29 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_data *data)
{
	int	a;
	int	b;

	a = data->stack_size - 1;
	b = a - 1;
	while (b >= data->index_a)
	{
		data->stack[a] ^= data->stack[b];
		data->stack[b] ^= data->stack[a];
		data->stack[a] ^= data->stack[b];
		b--;
		a--;
	}
	write(1, "rra\n", 4);
}

void	ft_rrb(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (b < data->index_a)
	{
		data->stack[a] ^= data->stack[b];
		data->stack[b] ^= data->stack[a];
		data->stack[a] ^= data->stack[b];
		b++;
		a++;
	}
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_data *data)
{
	int	a;
	int	b;

	a = data->stack_size - 1;
	b = a - 1;
	while (b >= data->index_a)
	{
		data->stack[a] ^= data->stack[b];
		data->stack[b] ^= data->stack[a];
		data->stack[a] ^= data->stack[b];
		b--;
		a--;
	}
	a = 0;
	b = 1;
	while (b < data->index_a)
	{
		data->stack[a] ^= data->stack[b];
		data->stack[b] ^= data->stack[a];
		data->stack[a] ^= data->stack[b];
		b++;
		a++;
	}
	write(1, "rrr\n", 4);
}

/* po chasovoi */
// void	ft_rra(t_data *data)
// {
// 	int	tmp;
// 	int	i;

// 	i = data->stack_size - 1;
// 	if (data->stack_size - data->index_a > 1)
// 	{
// 		tmp = data->stack[data->stack_size - 1];
// 		while (i > data->index_a)
// 		{
// 			data->stack[i] = data->stack[i - 1];
// 			i--;
// 		}
// 		data->stack[data->index_a] = tmp;
// 		write(1, "rra\n", 4);
// 	}
// }

// void	ft_rrb(t_data *data)
// {
// 	int	tmp;
// 	int	i;

// 	i = data->index_a - 1;
// 	if (data->index_a > 1)
// 	{
// 		tmp = data->stack[data->index_a - 1];
// 		while (i > 0)
// 		{
// 			data->stack[i] = data->stack[i - 1];
// 			i--;
// 		}
// 		data->stack[0] = tmp;
// 		write(1, "rrb\n", 4);
// 	}
// }

// void	ft_rrr(t_data *data)
// {
// 	int	tmp;
// 	int	i;

// 	i = data->stack_size - 1;
// 	if (data->stack_size - data->index_a > 1 && data->index_a > 1)
// 	{
// 		tmp = data->stack[data->stack_size - 1];
// 		while (i > data->index_a)
// 		{
// 			data->stack[i] = data->stack[i - 1];
// 			i--;
// 		}
// 		data->stack[data->index_a] = tmp;
// 	}
// 	i = data->index_a - 1;
// 	if (data->stack_size - data->index_a > 1 && data->index_a > 1)
// 	{
// 		tmp = data->stack[data->index_a - 1];
// 		while (i > 0)
// 		{
// 			data->stack[i] = data->stack[i - 1];
// 			i--;
// 		}
// 		data->stack[0] = tmp;
// 		write(1, "rrr\n", 4);
// 	}
// }
