/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:07:55 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/16 16:56:30 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_h(t_hist *lst)
{
	t_hist	*next;

	if (!lst)
		return ;
	while (lst)
	{
		next = lst->n;
		free(lst->line);
		free(lst);
		lst = next;
	}
}

void	free_sh(t_shell *sh)
{
	if (sh->openf >= 0)
		close(sh->openf);
	if (sh->envp)
		ft_free_strtab(sh->envp);
	if (sh->h)
		ft_free_h(sh->h);
	if (sh->input)
		ft_free_tabtab(sh->input);
	if (sh->hist_path)
		free(sh->hist_path);
	if (sh->prompt)
		free(sh->prompt);
}
