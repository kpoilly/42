/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:25:07 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 16:45:58 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_perror(t_shell *sh, char *cmd, char *var, char *msg)
{
	(void) sh;
	ft_putstr_fd("minishell: ", 2);
	if (cmd)
		ft_putstr_fd(cmd, 2);
	if (var)
		ft_putstr_fd(var, 2);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		write(2, "\n", 1);
	}
}
