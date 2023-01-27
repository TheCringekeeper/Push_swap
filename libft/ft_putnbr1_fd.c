/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr1_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:13:04 by ankhabar          #+#    #+#             */
/*   Updated: 2022/12/17 13:14:34 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int nb)
{
	size_t	count;

	count = 1;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb > 9)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

size_t	ft_putnbr1_fd(int nb, int fd)
{
	size_t	i;

	i = ft_count(nb);
	ft_putnbr_fd(nb, fd);
	return (i);
}	
