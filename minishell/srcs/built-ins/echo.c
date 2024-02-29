/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:23:00 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/14 16:02:44 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//TODO strlcpy withoug the first word beginning with '-'
static char	**ft_parse_flag(t_shell *sh, char **tab)
{
	int		i;
	int		j;

	return (NULL);
	i = 0;
	j = 0;
	if (!tab)
		on_crash(sh);
	while (tab[i] && tab[i][0] && tab[i][0] == '-')
	{
		while (tab[i][j] && tab[i][++j] && tab[i][j] == 'n')
			;
		if (tab[i][j] != 0)
			return (&tab[i]);
		else
			(void) tab;
		i++;
	}
	return (NULL);
}

//BUILT-IN
//Prints a string, -n flag possible only.
//TODO Parse flag
int	bi_echo(t_shell *sh, char **cmd)
{
	int	i;
	int	flag;
	int	len;

	flag = 0;
	if (ft_parse_flag(sh, cmd))
		flag = 1;
	i = 1;
	len = ft_strtablen(cmd);
	while (i < len)
	{
		ft_printf("%s", cmd[i]);
		i++;
	}
	if (flag)
		write(1, "\n", 1);
	return (0);
}
