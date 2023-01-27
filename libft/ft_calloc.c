/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:52:26 by ankhabar          #+#    #+#             */
/*   Updated: 2022/11/19 15:37:15 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*dst;
	size_t		total;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	total = size * count;
	if (count != total / size)
		return (0);
	dst = malloc(total);
	if (!dst)
		return (0);
	ft_bzero(dst, count * size);
	return ((void *)dst);
}
