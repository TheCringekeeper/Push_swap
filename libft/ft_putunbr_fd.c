/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:47:14 by ankhabar          #+#    #+#             */
/*   Updated: 2022/12/17 13:14:03 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(unsigned int unb1)
{
	size_t	count;

	count = 1;
	while (unb1 > 9)
	{
		count++;
		unb1 /= 10;
	}
	return (count);
}

static void	ft_recursive(unsigned int unb, int fd)
{
	if (unb > 9)
	{
		ft_recursive(unb / 10, fd);
		ft_recursive(unb % 10, fd);
	}
	else
		ft_putchar_fd(unb + '0', fd);
}

int	ft_putunbr_fd(unsigned int unb, int fd)
{
	int				i;
	unsigned int	unb1;

	unb1 = unb;
	i = ft_count(unb1);
	ft_recursive(unb, fd);
	return (i);
}
