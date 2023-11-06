/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:03:34 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/06 15:29:13 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*balai;
	int		size;

	if (!lst)
		return (0);
	balai = lst->next;
	size = 1;
	while (balai)
	{
		size++;
		balai = balai->next;
	}
	return (size);
}
