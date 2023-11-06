/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:30:01 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/06 15:41:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*balai;
	t_list	*lst_last;

	if (!lst)
		return (NULL);
	lst_last = ft_lstnew(NULL);
	balai = lst->next;
	while (balai->next)
		balai = balai->next;
	balai->next = lst_last;
	return (lst_last);
}
