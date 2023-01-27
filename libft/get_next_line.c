/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:01:01 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/23 13:29:10 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_readline(char *stash, int *ref, int fd)
{
	char	*bu;
	int		i;

	bu = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!bu)
		return (NULL);
	i = read(fd, bu, BUFFER_SIZE);
	if (i > -1)
	{
		bu[i] = '\0';
		i = 0;
		while (bu[i] && bu[i] != '\n')
			i++;
		*ref = ((!bu[0]) || (!bu[i] && i < BUFFER_SIZE) || (bu[i] == '\n'));
		if (bu[i] == '\n')
		{
			ft_strcpy(stash, bu);
			bu[i + 1] = '\0';
		}
		ft_clean_stash(stash);
		return (bu);
	}
	free(bu);
	*ref = 1;
	return (NULL);
}

static char	*ft_line(char *stash, int *ref)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		*ref = 1;
	i += *ref;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = stash[i];
	ft_clean_stash(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	char		*bu;
	int			ref;

	ref = 0;
	if (fd >= 0 && fd <= FOPEN_MAX && BUFFER_SIZE > 0)
	{
		stash[fd][BUFFER_SIZE] = '\0';
		line = ft_line(stash[fd], &ref);
		while (ref == 0)
		{
			bu = ft_readline(stash[fd], &ref, fd);
			tmp = ft_strjoin(line, bu);
			free(line);
			line = ft_strdup(tmp);
			free(bu);
		}
		if (line && !line[0])
			return (free(line), NULL);
		return (line);
	}
	return (NULL);
}
