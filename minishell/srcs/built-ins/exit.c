/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:36 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 15:15:43 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	if (full_cmd[1] && full_cmd[2])
		return (ft_putstr_fd("exit: too many arguments\n", 2), 1);
	else if (full_cmd[1] && full_cmd[1][0] && ft_isalpha(full_cmd[1][0]))
		return (ft_putstr_fd("exit: numeric argument required\n", 2), 2);
	else if (full_cmd[1])
		exit_code = ft_atoi(full_cmd[1]);
	else
		exit_code = 0;
	if (exit_code < 0)
		return (156);
	save_history(sh);
	free_sh(sh);
	printf("exit\n");
	exit(exit_code);
}
