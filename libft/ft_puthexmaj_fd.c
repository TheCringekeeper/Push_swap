/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexmaj_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:47:55 by ankhabar          #+#    #+#             */
/*   Updated: 2022/12/17 13:20:17 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int nb)
{
	size_t			count;
	unsigned int	unb;

	count = 1;
	if (nb < 0)
	{
		nb = nb + 2147483648;
		unb = nb + 2147483648;
		while (unb > 15)
		{
			count++;
			unb /= 16;
		}
	}
	else
	{
		while (nb > 15)
		{
			count++;
			nb /= 16;
		}
	}
	return (count);
}

static void	ft_putunb_fd(unsigned int unb, int fd)
{
	if (unb > 15)
	{
		ft_putunb_fd(unb / 16, fd);
		ft_putunb_fd(unb % 16, fd);
	}
	else
	{
		if (unb < 10)
			ft_putchar_fd(unb + '0', fd);
		else
			ft_putchar_fd(unb + 55, fd);
	}
}

static void	ft_recursive(int nb, int fd)
{
	unsigned int	unb;

	if (nb < 0)
	{
		nb = nb + 2147483648;
		unb = nb + 2147483648;
		ft_putunb_fd(unb, fd);
	}
	else if (nb > 15)
	{
		ft_recursive(nb / 16, fd);
		ft_recursive(nb % 16, fd);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', fd);
		else
			ft_putchar_fd(nb + 55, fd);
	}
}

size_t	ft_puthexmaj_fd(int nb, int fd)
{
	size_t	i;

	i = ft_count(nb);
	ft_recursive(nb, fd);
	return (i);
}
