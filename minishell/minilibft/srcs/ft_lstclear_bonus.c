/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:15:59 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/13 10:45:50 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*next;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		next = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = next;
	}
}
