/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <ankhabar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:32:32 by ankhabar          #+#    #+#             */
/*   Updated: 2023/01/06 16:01:02 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char chr, char c)
{
	if (chr == c)
		return (1);
	return (0);
}

int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (s[i])
			count++;
		while (s[i] && !(is_sep(s[i], c)))
			i++;
	}
	return (count);
}

int	word_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(is_sep(s[i], c)))
		i++;
	return (i);
}

char	*ft_word(char *s, char c)
{
	int		i;
	int		wordlen;
	char	*word;

	i = 0;
	wordlen = word_len(s, c);
	word = malloc(sizeof(char) * (wordlen + 1));
	if (!word)
		return (NULL);
	while (i < wordlen)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * (word_count((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s)
		{
			tab[i] = ft_word((char *)s, c);
			i++;
		}
		while (*s && !(is_sep(*s, c)))
			s++;
	}
	tab[i] = 0;
	return (tab);
}
