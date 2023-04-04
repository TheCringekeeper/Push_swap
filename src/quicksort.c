/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:01:41 by ankhabar          #+#    #+#             */
/*   Updated: 2023/04/04 16:46:08 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	ft_partition(int *array, int _l_pos, int _r_pos)
{
	int	pivot;
	int	i;
	int	j;

	i = _l_pos;
	pivot = array[_r_pos];
	j = _l_pos;
	while (j < _r_pos)
	{
		if (array[j] <= pivot)
		{
			ft_swap(&array[i], &array[j]);
			i++;
		}
		j++;
	}
	ft_swap(&array[i], &array[j]);
	return (i);
}

/* classic quicksort program */
void	ft_quicksort(int *array, int l_pos, int r_pos)
{
	int	pi;

	if (l_pos < r_pos)
	{
		pi = ft_partition(array, l_pos, r_pos);
		ft_quicksort(array, l_pos, pi - 1);
		ft_quicksort(array, pi + 1, r_pos);
	}
}
