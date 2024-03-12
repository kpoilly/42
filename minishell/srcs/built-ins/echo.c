/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:23:00 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/05 08:56:11 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_parse_flag(t_shell *sh, char **tab)
{
	int	j;
	int	i;
	int	flag;

	flag = 0;
	if (!tab)
		on_crash(sh);
	while (tab[1] && tab[1][0] && tab[1][0] == '-' && \
			tab[1][1] && tab[1][1] == 'n')
	{
		j = 1;
		while (tab[1][j])
			if (tab[1][j++] != 'n')
				return (flag);
		i = 0;
		free(tab[1]);
		while (tab[++i] && tab[i + 1])
			tab[i] = tab[i + 1];
		tab[i] = NULL;
		flag = 1;
	}
	return (flag);
}

//BUILT-IN
//Prints a string, -n flag possible only.
int	bi_echo(t_shell *sh, char **cmd)
{
	int	i;
	int	flag;
	int	len;

	i = 1;
	flag = ft_parse_flag(sh, cmd);
	len = ft_strtablen(cmd);
	while (i < len)
	{
		ft_printf("%s", cmd[i++]);
		if (i < len)
			write(1, " ", 1);
	}
	if (!flag)
		write(1, "\n", 1);
	return (0);
}
