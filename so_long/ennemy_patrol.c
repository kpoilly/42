/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_patrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:57:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/03 15:57:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

void	set_lastdir(t_global *global, char dir)
{
		global->last_gobdir = dir;
}

//Patrouille de maniere aleatoire
void	patrol(t_global *global, int x, int y)
{
	int	dir;

	dir = rand() % 4;
	if (dir == 0 && global->last_gobdir != 'R')
		search_left(global, x, y);
	else if (dir == 1 && global->last_gobdir != 'L')
		search_right(global, x, y);
	else if (dir == 2 && global->last_gobdir != 'D')
		search_up(global, x, y);
	else if (dir == 3 && global->last_gobdir != 'U')
		search_down(global, x, y);
	else
	{
		set_lastdir(global, 'W');
		patrol(global, x, y);
	}
}
