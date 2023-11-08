/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:30:01 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/07 21:38:42 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*balai;

	if (!lst)
		return (NULL);
	balai = lst->next;
	if (!balai)
		return (lst);
	while (balai && balai->next)
		balai = balai->next;
	return (balai);
}
