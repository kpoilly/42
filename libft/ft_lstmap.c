/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:29:57 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/09 16:50:50 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*toreturn;

	toreturn = ft_lstnew(f(lst->content));
	if (!toreturn)
	{
		ft_lstclear(&toreturn, del);
		return (NULL);
	}
	new = toreturn;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->content));
		lst = lst->next;
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new = new->next;
	}
	lst = NULL;
	return (toreturn);
}
