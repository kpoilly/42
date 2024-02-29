/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:52 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/14 16:05:01 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//BUILT-IN
//Removes a var from envp.
int	bi_unset(t_shell *sh, char *var)
{
	int	i;
	int	last;

	if (!check_word(var, "_", 0) && get_var(sh, var))
	{
		i = get_env_index(sh, var);
		if (i < 0)
			return (0);
		last = ft_strtablen(sh->envp) - 1;
		if (sh->envp[i])
			free(sh->envp[i]);
		sh->envp[i] = sh->envp[last];
		sh->envp[last] = NULL;
	}
	return (0);
}
