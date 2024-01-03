/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:11:38 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/03 16:42:00 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Déplace le G dans le tableau
void	move_ennemy_tab(t_global *global, char *dest, char *src)
{
	if (*dest && *dest == '0')
	{
		*dest = 'G';
		*src = '0';
	}
	else if (*dest && *dest == 'P')
	{
		*dest = 'G';
		*src = '0';
		game_over(global);
	}
}

//Recupere la coordonne du joueur dans la map
void	get_target(t_global *global, t_ent *target)
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

//choisi la direction du gobelin en fonction de si le joueur est dans sa range
void	ennemy_move(t_global *global)
{
	if (!in_range(global->player.x, global->player.y,
			global->ennemy.x, global->ennemy.y))
		return (patrol(global, global->ennemy.x, global->ennemy.y));
	else
		return (track_player(global, global->ennemy.x, global->ennemy.y));
}
