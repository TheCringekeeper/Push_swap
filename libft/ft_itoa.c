/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:59:09 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/28 15:05:07 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while ((n / 10) > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;

	numlen = ft_numlen(n);
	str = malloc(sizeof(char) * (numlen + 1));
	if (!str)
		return (NULL);
	str[numlen] = '\0';
	if (n == 0)
		str[--numlen] = (n + '0');
	if (n == -2147483648)
		return ("-2147483648");
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[--numlen] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
