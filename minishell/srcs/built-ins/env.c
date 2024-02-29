/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:58 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/14 16:04:28 by jdoukhan         ###   ########.fr       */
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
		ft_printf("%s\n", sh->envp[i++]);
	return (0);
}
