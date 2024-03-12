/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:09:10 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/16 12:24:20 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(t_shell *sh, char *prompt)
{
	char	***pipes;
	char	**tmp;
	int		i;
	int		tablen;

	i = 0;
	if (sh->input)
	{
		ft_free_tabtab(sh->input);
		sh->input = NULL;
	}
	tmp = ft_split_skip(prompt, '|', "\"'");
	if (!tmp)
		on_crash(sh);
	tablen = ft_strtablen(tmp);
	pipes = malloc (sizeof(char **) * (tablen + 1));
	while (i < tablen)
	{
		pipes[i] = ft_split_skip(tmp[i], ' ', "\"'");
		if (!pipes[i++])
			(ft_free_tabtab(pipes), on_crash(sh));
	}
	free(tmp);
	pipes[i] = NULL;
	sh->input = pipes;
}
