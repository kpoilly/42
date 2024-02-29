/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_underscore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:01:35 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/14 15:17:18 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_underscore(t_shell *sh)
{
	int	npipes;
	int	tablen;

	npipes = ft_tabtablen(sh->input);
	if (npipes < 1)
		return ;
	tablen = ft_strtablen(sh->input[npipes - 1]);
	if (tablen < 1)
		return ;
	bi_export(sh, "_", sh->input[npipes - 1][tablen - 1]);
}
