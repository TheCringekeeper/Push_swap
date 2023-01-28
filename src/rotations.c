/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:40:15 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 17:54:55 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotations_a(t_data *data, int i_needle)
{
	int	len_a;
	int	correct_needle;

	correct_needle = i_needle - data->index_a;
	len_a = data->stack_size - data->index_a;
	if (correct_needle <= (len_a / 2))
		return (1); //ra
	return (0); //rra
}

int	rotations_b(t_data *data, int i_needle)
{
	int	len_b;

	len_b = data->index_a;
	if (i_needle <= (len_b / 2))
		return (1); //rb
	return (0); //rrb
}

void	rotations(t_data *data)
{
	while (a_moves)
	{
		if (rotations_a(data, i_needle))
			ft_ra(data);
		else
			ft_rra(data);
		a_moves--;
	}
	while (b_moves)
	{
		if (rotations_b(data, i_needle))
			ft_rb(data);
		else
			ft_rrb(data);
		b_moves--;
	}
}
