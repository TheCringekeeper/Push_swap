/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:13:07 by ankhabar          #+#    #+#             */
/*   Updated: 2022/12/17 13:13:41 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(void *ptr)
{
	size_t			count;
	unsigned int	unb;
	long long int	nb;

	nb = (long long int)ptr;
	count = 3;
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

static void	ft_putulnbr_fd(long long int nb, int fd)
{
	if (nb > 15)
	{
		ft_putulnbr_fd(nb / 16, fd);
		ft_putulnbr_fd(nb % 16, fd);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', fd);
		else
			ft_putchar_fd(nb + 87, fd);
	}
}

static void	ft_recursive(void *ptr, int fd)
{
	long long int	nb;

	nb = (long long int)ptr;
	ft_putstr1_fd("0x", fd);
	if (nb > 15)
	{
		ft_putulnbr_fd(nb / 16, fd);
		ft_putulnbr_fd(nb % 16, fd);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', fd);
		else
			ft_putchar_fd(nb + 87, fd);
	}
}

static void	ft_recursive_long(void *ptr, int fd)
{
	long long unsigned int	nb;

	nb = (long long unsigned int)ptr;
	ft_putstr1_fd("0x", fd);
	if (nb > 15)
	{
		ft_putulnbr_fd(nb / 16, fd);
		ft_putulnbr_fd(nb % 16, fd);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', fd);
		else
			ft_putchar_fd(nb + 87, fd);
	}
}

size_t	ft_putptr_fd(void *ptr, int fd)
{
	size_t					count;
	long long unsigned int	nb;

	nb = (long long unsigned int)ptr;
	if (ptr == 0)
		return (ft_putstr1_fd("(nil)", fd));
	else if ((long long int)ptr < -9223372036854775807)
		return (ft_putstr1_fd("0x8000000000000000", fd));
	else if ((long long unsigned int)ptr > 9223372036854775807)
	{
		ft_recursive_long(ptr, fd);
		count = 3;
		while (nb > 15)
		{
			count++;
			nb /= 16;
		}
		return (count);
	}
	ft_recursive(ptr, fd);
	return (ft_count(ptr));
}
