/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:43:21 by ankhabar          #+#    #+#             */
/*   Updated: 2022/12/17 13:18:45 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr1_fd(char *s, int fd)
{
	if (fd < 0)
		return (0);
	if (s == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

static int	ft_printf_deep(char c, va_list arg)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		return (1);
	}
	else if (c == 's')
		return (ft_putstr1_fd(va_arg(arg, char *), 1));
	else if (c == 'p')
		return (ft_putptr_fd(va_arg(arg, void *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr1_fd(va_arg(arg, int), 1));
	else if (c == 'u')
		return (ft_putunbr_fd(va_arg(arg, int), 1));
	else if (c == 'x')
		return (ft_puthexmin_fd(va_arg(arg, int), 1));
	else if (c == 'X')
		return (ft_puthexmaj_fd(va_arg(arg, int), 1));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	size_t		count;
	va_list		arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_printf_deep(str[i], arg);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
			i++;
		}
	}
	va_end(arg);
	return (count);
}
