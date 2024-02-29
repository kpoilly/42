/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_crash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:59:37 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/13 13:06:01 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Call me when something is wrong.
//Exits on crash.
void	on_crash(t_shell *sh)
{
	free_sh(sh);
	exit(0);
}
