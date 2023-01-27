/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankhabar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:48:33 by ankhabar          #+#    #+#             */
/*   Updated: 2022/11/19 15:29:38 by ankhabar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (lst && f)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			return (NULL);
		tmp = new;
		while (lst->next)
		{
			lst = lst->next;
			tmp->next = ft_lstnew(f(lst->content));
			if (!(tmp->next))
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			tmp = tmp->next;
		}
		return (new);
	}
	return (NULL);
	del(lst->content);
}
