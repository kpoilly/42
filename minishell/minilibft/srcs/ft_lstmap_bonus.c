/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:15:36 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/13 11:01:25 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lmore(t_list *dest, void (*del)(void *))
{
	ft_lstclear(&dest, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*ndest;

	if (!lst)
		return (NULL);
	dest = ft_lstnew(f(lst->content));
	if (!dest)
		return (ft_lmore(dest, del));
	ndest = dest;
	lst = lst->next;
	while (lst)
	{
		ndest->next = ft_lstnew(f(lst->content));
		lst = lst->next;
		if (!(ndest->next))
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		ndest = ndest->next;
		ndest->next = NULL;
	}
	return (dest);
}
