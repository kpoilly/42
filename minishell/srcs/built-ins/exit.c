/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:36 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/13 13:31:48 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_num(char	*arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg && arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_stat_quotes_remover(char *str)
{
	int		k;
	int		ret_code;

	k = 0;
	if (str[0] && str[0] == '"')
		ret_code = 1;
	while (str[k] && str[k + 1])
	{
		str[k] = str[k + 1];
		k++;
	}
	while (str[k] && str[k + 1] && str[k + 2])
	{
		str[k] = str[k + 2];
		k++;
	}
	str[k] = 0;
}

//BUILT-IN
//Exits with passed exit-code.
int	bi_exit(t_shell *sh, char **full_cmd)
{
	int	exit_code;

	exit_code = 0;
	if (ft_strtablen(full_cmd) > 1)
	{
		if (is_num(full_cmd[1]) && ft_strtablen(full_cmd) == 2)
			exit_code = ft_atoi(full_cmd[1]);
		else if (is_num(full_cmd[1]) && ft_strtablen(full_cmd) > 2)
			return (ft_perror(sh, "exit: ", NULL, "too many arguments"), 1);
		else if (!is_num(full_cmd[1]))
		{
			exit_code = 2;
			ft_perror(sh, "exit: ", full_cmd[1],
				": numeric argument required");
		}
	}
	if (exit_code < 0)
		exit_code = 156;
	save_history(sh);
	free_sh(sh);
	printf("exit\n");
	exit(exit_code);
}
