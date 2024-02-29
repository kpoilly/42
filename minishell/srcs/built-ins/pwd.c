/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:53:38 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/14 16:05:50 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//BUILT-IN
//Prints current directory.
int	bi_pwd(t_shell *sh)
{
	ft_printf("%s\n", get_var(sh, "PWD"));
	return (0);
}
