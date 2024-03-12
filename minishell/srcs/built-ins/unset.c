/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:52 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/05 08:55:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//BUILT-IN
//Removes a var from envp.
int	bi_unset(t_shell *sh, char **vars)
{
	int	i;
	int	last;
	int	k;

	k = 1;
	while (vars && vars[k] && !check_word(vars[k], "_", 0)
		&& get_var(sh, vars[k]))
	{
		i = get_env_index(sh, vars[k]);
		if (i < 0)
			return (0);
		last = ft_strtablen(sh->envp) - 1;
		if (sh->envp[i])
			free(sh->envp[i]);
		sh->envp[i] = sh->envp[last];
		sh->envp[last] = NULL;
		k++;
	}
	return (0);
}
