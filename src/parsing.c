/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:45:53 by ankhabar          #+#    #+#             */
/*   Updated: 2023/04/04 16:46:10 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	checks(char **str, char **flag)
{
	if (*str[0] == '+')
		(*str)++;
	if (*str[0] == '-')
	{
		(*str)++;
		*flag = "-";
	}
	while (*str[0] == '0' && ft_strcmp(*str + 1, ""))
		(*str)++;
	if (*str[0] == '0' && !ft_strcmp(*str + 1, ""))
		*flag = "";
}

/* tests for:
	nb > INT_MAX  ; (invalid)
	nb < INT_MIN  ; (invalid)
	nb == - / +   ; (invalid)
	nb == +0 / -0 ; (valid)
	nb == 00000nb ; (valid)
	nb == +0000nb ; (valid)
/!\ nb == -0000nb ; (valid)
/!\ nb == -000000 ; (valid)*/
static int	is_invalid(char *str)
{
	char	*itoa_test;
	char	*flag;
	char	*test;
	int		nb;

	flag = "";
	nb = ft_atoi(str);
	if ((!ft_strcmp(str, "-0") || !ft_strcmp(str, "+0")
			|| !ft_strcmp(str, "0")) && nb == 0)
		return (0);
	if (nb == -2147483648)
	{
		if (str[0] == '-')
			return (0);
		return (1);
	}
	itoa_test = ft_itoa(nb);
	checks(&str, &flag);
	test = ft_strjoin(flag, str);
	if (ft_strcmp(itoa_test, test) != 0)
		return (free(test), free(itoa_test), 1);
	return (free(test), free(itoa_test), 0);
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
