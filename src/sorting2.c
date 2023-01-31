/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:04:45 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/31 13:31:09 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*get_tmp_stack(t_data *data, int size)
{
	int	*stack;
	int	i;

	i = 0;
	stack = malloc(sizeof(int) * size);
	if (!stack)
		return (NULL);
	while (i < size)
	{
		stack[i] = data->stack[data->index_a + i];
		ft_printf("%i ", stack[i]);
		i++;
	}
	if (has_doubles(stack, size))
		return (NULL);
	return (stack);
}

static int	find_median(t_data *data)
{
	int	*test_stack;
	int	median;
	int	size;

	size = (data->stack_size - data->index_a);
	test_stack = get_tmp_stack(data, size);
	ft_quicksort(test_stack, 0, size - 1);
	median = test_stack[(size - 1) / 2];
	free(test_stack);
	ft_printf("median: %i\n", median);
	return (median);
}

static int	part1_median(t_data *data)
{
	int	median;
	int	i;

	median = 0;
	while ((data->stack_size - data->index_a) > 3)
	{
		median = find_median(data);
		i = 0;
		while (i < (data->stack_size - data->index_a))
		{
			if (data->stack[data->index_a] < median)
				ft_pb(data);
			else
			{
				i++;
				ft_ra(data);
			}
		}
	}
	sorting_3(data);
	return (1);
}

// int	count_moves(t_data *data, int i)
// {
// 	find_place_in_a();
// 	count_ops();
// }

// void	part2_sorting(t_data *data)
// {
// 	int	min_moves;
// 	int	cur_moves;
// 	int	i;

// 	i = 0;
// 	while (data->index_a - i > 0)
// 	{
// 		cur_moves = count_moves(data, i);
// 		if (i == 0)
// 			min_moves = count_moves(data, i);
// 		if (min_moves > cur_moves)
// 			min_moves = cur_moves;
// 		i++;
// 	}
// 	execute(data, min_moves);
// }

/* dobavit part2 sorting from b to a
*  dobavit move cost i sravnivat s kajdim novim
*  while(1)
*     if (min_cost > current_cost)
*        min_cost = current_cost;
*  tipa takovo
*  a v konce execute_command(min_cost) */
void	sorting_everything(t_data *data)
{
	if (!part1_median(data))
		error();
	if (is_sorted(data))
	{
		while (data->index_a > 0)
			ft_pa(data);
	}
	// part2_sorting(data);
	int	i = 0;
	while (i < data->stack_size)
	{
		ft_printf("%i ", data->stack[i]);
		i++;
	}
}
