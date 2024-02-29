/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:58:35 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/31 10:28:08 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Duplicates envp inside sh.envp.
//Allows envp editing.
//Check free for errors with mallocs
void	dup_envp(t_shell *sh, char **envp)
{
	size_t	i;
	size_t	lenvp;

	i = 0;
	lenvp = ft_strtablen(envp);
	sh->envp = malloc((lenvp + 1) * sizeof (char *));
	if (!sh->envp)
		on_crash(sh);
	while (i < lenvp)
	{
		sh->envp[i] = ft_strdup(envp[i]);
		if (!sh->envp[i])
			on_crash(sh);
		i++;
	}
	sh->envp[i] = NULL;
}
