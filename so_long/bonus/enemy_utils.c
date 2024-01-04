/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:11:38 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 12:32:10 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//Déplace le G dans le tableau
void	move_enemy_tab(t_global *global, char *dest, char *src)
{
	if (*dest && *dest == '0')
	{
		*dest = global->enemy.chara;
		*src = '0';
	}
	else if (*dest && *dest == 'P')
	{
		*dest = global->enemy.chara;
		*src = '0';
		game_over(global);
	}
}

//Recupere la coordonne du joueur (ou ennemy) dans la map
void	set_coord(t_global *global, t_ent *target)
{
	int	x;
	int	y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == target->chara)
			{
				target->x = x;
				target->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

//Verifie si le joueur se trouve dans la range de vision de l'ennemi
int	in_range(int player_x, int player_y, int x, int y)
{
	return ((player_x >= x - 3 && player_x <= x + 3)
		&& (player_y >= y - 3 && player_y <= y + 3));
}
