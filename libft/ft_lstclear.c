/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:31:58 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/08 03:29:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void*))
{
	t_list	*balai;
	t_list	*prochain;

	if (!lst)
		return ;
	balai = *lst;
	while (balai)
	{
		prochain = balai->next;
		del(balai->content);
		free(balai);
		balai = prochain;
	}
	*lst = NULL;
}
