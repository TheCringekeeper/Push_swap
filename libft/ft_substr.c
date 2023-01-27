/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:44:27 by ankhabar          #+#    #+#             */
/*   Updated: 2022/12/02 20:06:14 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	int		j;
	size_t	slen;
	char	*chaine;

	i = start;
	j = 0;
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	if (start + len > slen)
		len -= start;
	if (!s || start > slen)
		len = 0;
	chaine = (char *)malloc(sizeof(char) * (len + 1));
	if (len > 0 && start < slen)
	{
		while (i < start + len && s[i])
			chaine[j++] = s[i++];
	}
	chaine[j] = '\0';
	return (chaine);
}
