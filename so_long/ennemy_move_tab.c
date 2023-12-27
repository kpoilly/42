/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:18 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/27 20:43:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Déplace le G dans le tableau
void	move_ennemy_tab(t_global *global, char *dest, char *src)
{
	if (*dest == '0')
	{
		*dest = 'G';
		*src = '0';
	}
	else if (*dest == 'P')
	{
		*dest = 'G';
		*src = '0';
		game_over(global);
	}
}
