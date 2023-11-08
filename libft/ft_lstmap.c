/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:29:57 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/08 04:39:42 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*balai;
	t_list	*new;

	balai = lst;
	new = ft_lstnew(lst->content);
	if (!new)
		return (0);
	new = new->next;
	while (balai)
	{
		if (f(balai->content))
		{
			new->next = ft_lstnew(balai->content);
			new = new->next;
		}
		balai = balai->next;
	}
	return (new);
}
