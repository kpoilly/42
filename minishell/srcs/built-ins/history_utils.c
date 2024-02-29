/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:25:31 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/13 14:41:20 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_histsize(t_hist *lst)
{
	t_hist	*new;
	int		size;

	size = 0;
	new = lst;
	while (new != NULL)
	{
		new = new->n;
		size++;
	}
	return (size);
}

void	ft_history_cap(t_shell *sh)
{
	int		i;
	int		len;
	t_hist	*cursor;
	t_hist	*next;

	i = 0;
	len = ft_histsize(sh->h);
	if (len > HISTORY_SIZE)
	{
		cursor = sh->h;
		while (cursor && cursor->n && i++ < len - HISTORY_SIZE)
			cursor = cursor->n;
		next = cursor->n;
		cursor->n = NULL;
		cursor = next;
		while (sh->h)
		{
			next = sh->h->n;
			free(sh->h->line);
			free(sh->h);
			sh->h = next;
		}
		sh->h = cursor;
	}
}
