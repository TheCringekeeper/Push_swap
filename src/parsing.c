/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:45:53 by ankhabar          #+#    #+#             */
/*   Updated: 2023/02/02 13:48:47 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* tests for:
	nb > INT_MAX  ; (invalid)
	nb < INT_MIN  ; (invalid)
	nb == - / +   ; (invalid)
	nb == +0 / -0 ; (valid)
	nb == 00000nb ; (valid)*/
static int	is_invalid(char *str)
{
	char	*itoa_test;
	int		nb;
	int		i;

	i = 0;
	nb = ft_atoi(str);
	if ((!ft_strcmp(str, "-0") || !ft_strcmp(str, "+0")
			|| !ft_strcmp(str, "0")) && nb == 0)
		return (0);
	if (nb == 0 && ft_strcmp(str, "0"))
		return (1);
	if (nb == -2147483648)
	{
		if (ft_strcmp(str, "-2147483648"))
			return (1);
		return (0);
	}
	itoa_test = ft_itoa(nb);
	if (str[0] == '+')
		str++;
	while (str[i] == '0')
		str++;
	if (ft_strcmp(itoa_test, str) != 0)
		return (free(itoa_test), 1);
	return (free(itoa_test), 0);
}

int	parsing_error(char *argv[])
{
	int	i;

	i = 1;
	if (!argv[i])
		return (1);
	while (argv[i])
	{
		if (is_invalid(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	found_equals(int *lst, int to_compare, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (lst[i] == to_compare)
			return (1);
		i++;
	}
	return (0);
}

int	has_doubles(int *stack, int stack_len)
{
	int	i;

	i = 0;
	while (i < stack_len)
	{
		if (found_equals(stack, stack[i], i))
			return (1);
		i++;
	}
	return (0);
}
