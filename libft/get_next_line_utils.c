/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:00:57 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/29 14:35:35 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean_stash(char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
	{
		while (stash[++i])
		{
			stash[j] = stash[i];
			j++;
		}
		stash[j] = '\0';
		return ;
	}
	stash[0] = '\0';
	return ;
}
