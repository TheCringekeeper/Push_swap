/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:58:26 by ankhabar          #+#    #+#             */
/*   Updated: 2022/12/17 13:41:11 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chaine;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	chaine = malloc(sizeof(char) * (len + 1));
	if (!chaine)
		return (NULL);
	while (*s1)
		*chaine++ = *s1++;
	while (*s2)
		*chaine++ = *s2++;
	*chaine = '\0';
	return (chaine - len);
}
