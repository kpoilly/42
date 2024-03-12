/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:58 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/06 11:04:31 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//BUILT-IN
//Print every env vars.
int	bi_env(t_shell *sh)
{
	size_t	i;

	i = 0;
	while (sh->envp && sh->envp[i])
	{
		if (ft_strchr(sh->envp[i], '=') && sh->envp[i][0] && \
		(sh->envp[i][0] != '0' && sh->envp[i][0] != '-' && \
		sh->envp[i][0] != '?'))
			ft_printf("%s\n", sh->envp[i]);
		i++;
	}
	return (0);
}
